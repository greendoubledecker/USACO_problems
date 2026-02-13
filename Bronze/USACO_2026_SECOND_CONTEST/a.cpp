#include <bits//stdc++.h>

using namespace std;
int main(){
	int t;
	int k;
	cin >> t >> k;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		cout << "YES" << endl;
		if(k){
			bool flip = false;
			string backwards;
			for(int i = n - 1; i >= 0; --i){
				if(flip){
					if(s[i] == 'M'){
						backwards.push_back('O');
						flip = !flip;
					}else{
						backwards.push_back('M');
					}
				}else{
					if(s[i] == 'M'){
						backwards.push_back('M');
					}else{
						backwards.push_back('O');
						flip = !flip;
					}
				}
			}
			for(int i = n - 1; i >= 0; --i){
				cout << backwards[i];
			}
			cout << endl;
		}
	}
}
