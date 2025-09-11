#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void gymnastics() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> grid[i][j];
		}
	}
	int consistent = 0;
	for (int cow1 = 1; cow1 < m + 1; ++cow1){
		for (int cow2 = 1; cow2 < m + 1; ++cow2){
			bool pairConsistent = true;
			for(int day = 0; day < n; ++day){
				if (find (grid[day].begin(), grid[day].end(), cow1) < find (grid[day].begin(), grid[day].end(), cow2)){
					pairConsistent = false;
					break;
				}
			}
			if (pairConsistent){
				consistent ++;
			}
		}
	}
	cout << consistent - m << endl;
}

int main (){
	gymnastics();
	return 0;
}
