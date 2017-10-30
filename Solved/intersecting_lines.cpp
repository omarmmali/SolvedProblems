#include <bits/stdc++.h>
using namespace std;

#define Point pair<double,double>
#define x first
#define y second

const double EPS = 1e-9;
const double INF = numeric_limits<double>::max();

int gcd(int a, int b) {
    if(!b) {
        return a;
    }
    return gcd(b, a%b);
}
double gcd_floats(double x, double y) {
    return gcd( int(x*1000), int(y*1000) ) / 1000;
}

struct Line
{
    double a, b, c;

    explicit Line() : a(0), b(0), c(0) {
    }

    Line(const Point& A, const Point& B)
    {
        this->a = +(B.y - A.y);
        this->b = -(B.x - A.x);
        this->c = -A.x * B.y + B.x * A.y;
        double com = gcd_floats(this->a, this->b);
        com = gcd_floats(com, this->c);
        this->a /= com;
        this->b /= com;
        this->c /= com;
    }
};

struct Segment
{
    Point A, B;

    explicit Segment() : A(), B() {
    }

    Segment(const Point& _A, const Point& _B) : A(_A), B(_B) {
    }
};

double dist(const Point& A, const Point& B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

double modul(double a)
{
    if (a > EPS)
        return a;
    else
        return -a;
}

double CCW(const Point& A, const Point& B, const Point& C)
{
    return (C.x - A.x) * (B.y - A.y) - (C.y - A.y) * (B.x - A.x);
}

/// P is on segment S <=> d(S.A,P) + d(P,S.B) == d(S.A, S.B)
bool onSegment(const Segment& S, const Point& P)
{
    if (modul(CCW(S.A, S.B, P)) > EPS)
        return false; /// not collinear

    if ( !(min(S.A.x, S.B.x) <= P.x && P.x <= max(S.A.x, S.B.x)) )
        return false;

    if ( !(min(S.A.y, S.B.y) <= P.y && P.y <= max(S.A.y, S.B.y)) )
        return false;

    return true;
}

Point lineToLineIntersection(const Line& A, const Line& B)
{
    double det = A.a * B.b - A.b * B.a;

    if (modul(det) < EPS) /// det == 0
        return Point(INF, INF); /// no intersection
    else
    {
        double x = -(A.c * B.b - A.b * B.c) / det;
        double y = -(A.a * B.c - A.c * B.a) / det;

        return Point(x, y);
    }
}

Point lineToSegmentIntersection(const Line& A, const Segment& S)
{
    Point I = lineToLineIntersection(A, Line(S.A, S.B));

    /// check if I exists and is on segment
    if (I != Point(INF, INF) && onSegment(S, I))
        return I;
    else
        return Point(INF, INF); /// no intersection
}

Point segmentToSegmentIntersection(const Segment& A, const Segment& B)
{
    Point I = lineToLineIntersection(Line(A.A, A.B), Line(B.A, B.B));

    /// check if I exists and is on both segments
    if (I != Point(INF, INF) && onSegment(A, I) && onSegment(B, I))
        return I;
    else
        Point(INF, INF); /// no intersection
}

bool lineToLineParrallel(Line l1, Line l2) {
    return (abs(l1.a - l2.a) < EPS && (abs(l1.b - l2.b) < EPS));
}

bool lineToLineCoincide(Line l1, Line l2) {
    return (lineToLineParrallel(l1,l2) && (abs(l1.c - l2.c) < EPS));
}

int main() {
    int t;
    cin >> t;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while(t--) {
        Point p[4];
        int x,y;
        for(int i = 0; i < 4; i++) {
            cin >> x >> y;
            p[i] = Point(x,y);
        } 
        Line l1 = Line(p[0],p[1]);
        Line l2 = Line(p[2],p[3]);
        Point res =  lineToLineIntersection(l1,l2);
        if(res != Point(INF, INF)) {
            printf("POINT %.2f %.2f\n", (abs(res.x) < EPS ? 0.00 : res.x), (abs(res.y) < EPS ? 0.00 : res.y));
        }
        else {
            if(lineToLineCoincide(l1,l2)) {
                printf("LINE\n");
            }
            else {
                printf("NONE\n");
            }
        }
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
} 
