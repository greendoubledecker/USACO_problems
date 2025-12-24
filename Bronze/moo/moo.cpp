#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main(){
	int n, moos;
	cin >> n >> moos;
	string s;
	cin >> s;
	unordered_map<string, int> threeLetters;
	for(int k = 0; k < n - 2; ++k){
		string ss = s.substr(k, 3);
		if(ss[1] == ss[2] && ss[0] != ss[1]){
			++threeLetters[ss];
		}
	}
	set<string> possible;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 26; ++j){
			unordered_map<string, int> m = threeLetters;
			if(i >= 2){
				char c1 = s[i - 2];
				char c2 = s[i - 1];
				char c3 = s[i    ];
				string subtract = string(1, c1) + c2 + c3;
				--m[subtract];
				c3 = alphabet[j];
				string add = string(1, c1) + c2 + c3;
				++m[add];
			}
			if(i <= n - 3){
				char c1 = s[i    ];
				char c2 = s[i + 1];
				char c3 = s[i + 2];
				string subtract = string(1, c1) + c2 + c3;
				--m[subtract];
				c1 = alphabet[j];
				string add = string(1, c1) + c2 + c3;
				++m[add];
			}
			if(i >= 1 && i <= n - 2){
				char c1 = s[i - 1];
				char c2 = s[i    ];
				char c3 = s[i + 1];
				string subtract = string(1, c1) + c2 + c3;
				--m[subtract];
				c2 = alphabet[j];
				string add = string(1, c1) + c2 + c3;
				++m[add];
			}
			for(pair<string, int> moo : m){
				if(moo.second >= moos && moo.first[0] != moo.first[1] && moo.first[1] == moo.first[2]){
					possible.insert(moo.first);
				}
			}
		}
	}
	cout << possible.size() << endl;
	for(string s : possible){
		cout << s << endl;
	}
	return 0;
}
