#include <bits/stdc++.h>
using namespace std;
bool subseq(string haystack, string needle) {
	int j = 0;
	for(int i = 0; i < haystack.size() && j < needle.size(); i++) {
		if(haystack[i] == needle[j]) {
			j++;
		}
	}
	return (j == needle.size());
}
int main() {
	string s,t;
	cin >> s >> t;
	int cs[26] = {0}, ct[26] = {0};
	bool automaton = 0, array = 0, tree = 0;
	for(int i = 0; i < s.size(); i++) {
		cs[s[i]-'a']++;
	}
	for(int i = 0; i < t.size(); i++) {
		ct[t[i]-'a']++;
	}
	for(int i = 0; i < 26; i++) {
		if(cs[i] > ct[i]) {
			automaton = 1;	
		}
		else if(cs[i] < ct[i]) {
			tree = 1;
		}	
	}
	if(!automaton && !tree) {
		cout << "array" << endl;
	}
	else if(tree) {
		cout << "need tree" << endl;
	}
	else if(subseq(s,t) && automaton) {
		cout << "automaton" << endl;
	}
	else {
		cout << "both" << endl;
	}
    return 0;
} 

