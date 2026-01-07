#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, m; 
	cin >> n >> m;
	vector<vector<int>> plays(n, vector<int>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= i; ++j){
			char c;
			cin >> c;
			if(c == 'W'){
				plays[i][j] = 1;
				plays[j][i] = -1;
			}
			if(c == 'D'){
				plays[i][j] = 0;
				plays[j][i] = 0;
			}
			if(c == 'L'){
				plays[i][j] = -1;
				plays[j][i] = 1;
			}
		}
	}
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		int num = 0;
		for(int j = 0; j < n; ++j){
			if(plays[j][a - 1] == 1 && plays[j][b - 1] == 1){
				++num;
			}
		}
		//cout << "num is " << num << endl;
		int ans = 0;
		ans += num * (n - num) * 2;
		ans += num * (num - 1);
		ans += num;
		cout << ans << endl;
	}
}
