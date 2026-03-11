#include <bits/stdc++.h>

using namespace std;

set<char> blocks[4];
string tgt;

bool recurse(vector<bool> visited, string s){
	if(s.size() == tgt.size()) return s == tgt;
	bool works = false;
	for(int i = 0; i < 4; ++i){
		if(visited[i]) continue;
		visited[i] = true;
		for(char c : blocks[i]){
			s.push_back(c);
			works = works || recurse(visited, s);
			s.pop_back();
		}
		visited[i] = false;
	}
	return works;
}

int main(){
	int a;
	cin >> a;
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 6; ++j){
			char c;
			cin >> c;
			blocks[i].insert(c);
		}
	}
	while(a--){
		cin >> tgt;
		cout << (recurse({0,0,0,0}, "") ? "YES" : "NO") << endl;
	}
}
