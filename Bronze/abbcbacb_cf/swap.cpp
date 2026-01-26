#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		
		//count total number of A's
		int ACount = 0;
		for(int i = 0; i < n; ++i){
			if(s[i] == 'A'){
				++ACount;
			}
		}
		
		//count min length of a substring of only A's
		int minLen = 1000000000;
		int curLen = 0;
		for(int i = 0; i < n; ++i){
			if(s[i] == 'A'){
				++curLen;
			}
			if(s[i] == 'B'){
				minLen = min(minLen, curLen);
				curLen = 0;
			}
		}
		minLen = min(minLen, curLen);
		
		//the answer is the total number of A's minus the length of the shortest substring of only A's
		//because each B converts a substring of A's to its left or to its right (but not both) into C's
		cout << ACount - minLen << endl;
	}
}
