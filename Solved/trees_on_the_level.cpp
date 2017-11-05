#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node* left;
    Node* right;
    int value;
    Node() {
        left = right = 0;
        value = -1;
    }
};
struct BS {
    Node* root;
    vector<vector<int> > level_order;
    bool ok;
    int mx_level;
    BS() {
        root = new Node();
        ok = 1;
        mx_level = 1;
    }
    
    void insert(int val, string path) {
        Node* cur = root;
        for(int i = 0; i < path.size(); i++) {
            if(path[i] == 'L') {
                if(cur->left == 0) {
                    cur->left = new Node();
                }
                cur = cur->left;
            }
            else {
                if(cur->right == 0) {
                    cur->right = new Node();
                }
                cur = cur->right;
            }
        }
        mx_level = max(mx_level, (int)path.size()+1);
        if(cur->value != -1) {
            ok = 0;
        }
        else {
            cur->value = val;
        }
    }
    void traverse() {
        level_order.resize(mx_level);
        dfs(root, 0);
    }
    void dfs(Node* cur, int l) {
        if(cur->value == -1) {
            ok = 0;
            return;
        }
        level_order[l].push_back(cur->value);
        if(cur->left != 0) {
            dfs(cur->left, l + 1);
        }
        if(cur->right != 0) {
            dfs(cur->right, l + 1);
        }
    }
};
pair<int,string> parse(string in) {
    int k = 0;
    string args[2];
    for(int i = 1; i < in.size() - 1; i++) {
        string tmp;
        while(in[i] != ',' && i < in.size() - 1) {
            tmp += in[i++];
        }
        args[k++] = tmp; 
    }
    return make_pair(stoi(args[0].c_str()), args[1]);
}
int main() {
    string in;
    freopen("output.txt", "w", stdout);
    while(cin >> in) {
        vector<string> commands;
        commands.push_back(in);
        while(cin >> in) {
            if(in == "()") {
                break;
            }
            commands.push_back(in);
        }
        BS bs;
        for(int i = 0; i < commands.size(); i++) {
            pair<int,string> cur_command = parse(commands[i]);
            bs.insert(cur_command.first, cur_command.second);
        }
        bs.traverse();
        if(!bs.ok) {
            cout << "not complete" << endl;
        }
        else {
            for(int i = 0; i < bs.level_order.size(); i++) {
                if(i) {
                    cout << ' ';
                }
                for(int j = 0; j < bs.level_order[i].size(); j++) {
                    if(j) {
                        cout << ' ';
                    }
                    cout << bs.level_order[i][j];
                }
            }
            cout << endl;
        }
    }
	return 0;
} 

