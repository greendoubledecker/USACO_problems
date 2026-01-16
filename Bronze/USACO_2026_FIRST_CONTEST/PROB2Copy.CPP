#include <iostream>
#include <vector>
#include <string>

using namespace std;


void tc(){
	int N;
	cin >> N;
	
	string s;
	cin >> s;
	
	if(N % 2 == 1){
		cout << -1 << endl;
	}else{
		bool one = true;
		for(int i = 0; i < 3 * N / 2; ++i){
			if(s[i] != s[3 * N / 2 + i]){
				one = false;
			}
		}
		if(one){
			cout << 1 << endl;
			for(int i = 0; i < 3 * N; ++i){
				if(i == 3 * N - 1){
					cout << 1 << endl;
				}else{
					cout << "1 ";
				}
			}
			return;
		}
		
		vector<int> ans(3 * N);
		for(int i = 0; i < N / 2; ++i){
			string a = "", b = "";
			for(int j = 0; j < 3; ++j){
				a += s[3 * i + j];
			}
			for(int j = 0; j < 3; ++j){
				b += s[3 * (i + N / 2) + j];
			}
			if(b[0] == a[0]  || b[0] == a[1]){
				ans[3 * i] = 2;
				ans[3 * i + 1] = 1;
				ans[3 * i + 2] = 1;
				
				ans[3 * i + 3 * N / 2] = 1;
				ans[3 * i + 3 * N / 2 + 1] = 1;
				ans[3 * i + 3 * N / 2 + 2] = 2;
			}else{
				ans[3 * i] = 1;
				ans[3 * i + 1] = 1;
				ans[3 * i + 2] = 2;
				
				ans[3 * i + 3 * N / 2] = 2;
				ans[3 * i + 3 * N / 2 + 1] = 1;
				ans[3 * i + 3 * N / 2 + 2] = 1;
			}
		}
		for(int i = 0; i < 3 * N; ++i){
			if(i == 3 * N - 1){
				cout << ans[i] << endl;
			}else{
				cout << ans[i] << " ";
			}
		}
	}
}

int main(){
	int t, k;
	cin >> t >> k;
	while(t--){
		tc();
	}
}
