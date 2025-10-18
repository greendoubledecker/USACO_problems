#include <iostream>
#include <vector>

using namespace std;

int main(){
	int sl;
	const long long MOD = 1000000007;
	cin >> sl;
	vector<vector<bool>> grid(sl, vector<bool>(sl));
	for(int i = 0; i < sl; ++i){
		for(int j = 0; j < sl; ++j){
			char tile;
			cin >> tile;
			if(tile == '*'){
				grid[i][j] = false;
			}else{
				grid[i][j] = true;
			}
		}
	}
	if(grid[0][0] == false || grid[sl - 1][sl - 1] == false){
		cout << 0 << endl;
		return 0;
	}else{
		vector<vector<long long>> dp(sl + 1, vector<long long>(sl + 1, 0));
		for(int i = 0; i < sl; ++i){
			dp[0][i] = 0;
			dp[i][0] = 0;
		}
		for(int i = 1; i < sl + 1; ++i){
			for(int j = 1; j < sl + 1; ++j){
				//cout << "i " << i << " j " << j << endl;
				if(grid[i - 1][j - 1]){
					if(i == 1 && j == 1){
						//cout << "i, j = 1" << endl;
						dp[1][1] = 1;
						continue;
					}
					dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
					//cout << "There are " << dp[i][j] << "  paths at [" << i << "][" << j << "]." << endl;
				}
			}
		}
		cout << dp[sl][sl] << endl;
		return 0;
	}
}
