#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int q;
	cin >> q;
	vector<pair<pair<int, int>, char>> ops(q);
	for(int i = 0; i < q; ++i){
		int a, b;
		char c;
		cin >> a >> b >> c;
		ops[i] = {{a, b}, c};
	}
	for(int i = q - 1; i >= 0; --i){
		if(ops[i].first.first > 1){
			ops[i].first.first += 10;
			break;
		}
	}
	for(int i = 0; i < q; ++i){
		if(ops[i].first.first == 1){
			s[ops[i].first.second - 1] = ops[i].second;
		}
		if(ops[i].first.first == 12){
			for(char &c : s){
				c = tolower(c);
			}
		}
		if(ops[i].first.first == 13){
			for(char &c : s){
				c = toupper(c);
			}
		}
	}
	cout << s << endl;
	//Help, the ungelafunder flumpled the kiftiling gilbadingle!
}
