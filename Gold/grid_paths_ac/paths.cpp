//it's the same as https://cses.fi/problemset/task/1638, go check it out.
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int w,h;
	const long long MOD = 1000000007;
	cin >> h>>w;
	vector<vector<bool>> grid(h, vector<bool>(w));
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			char tile;
			cin >> tile;
			if(tile == '#'){
				grid[i][j] = false;
			}else{
				grid[i][j] = true;
			}
		}
	}
	if(grid[0][0] == false || grid[h - 1][w - 1] == false){
		cout << 0 << endl;
		return 0;
	}else{
		vector<vector<long long>> dp(h + 1, vector<long long>(w + 1, 0));
		for(int i = 1; i <= h; ++i){
			for(int j = 1; j <= w; ++j){
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
		cout << dp[h][w] << endl;
		return 0;
	}
}
/*  #                          #                   ##                  ####
 * #                          #                  ##                 ###
 * #                          ###               #                 ##
 * #                   ###    #  ##            #                ##  #
 * #      #          ##      #    #           #               #     #
 *  #     ##       ##              #         #                       #
 *  #     # #     #                #         #                       #
 *   #   #   #   #                  #        #                        #
 *    # #     # #                   #       #                         #
 *     #       #                #########   #################         #
 */
