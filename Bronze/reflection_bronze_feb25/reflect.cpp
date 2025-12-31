#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N;

pair<int, int> map(pair<int, int> c){
	if(c.first >= N/2){
		c.first = N - c.first - 1;
	}
	if(c.second >= N/2){
		c.second = N - c.second - 1;
	}
	return c;
}

int count(int n){
	return min(n, 4 - n);
}

int main(){
	cin >> N;
	int U;
	cin >> U;
	vector<vector<int>> counts(N / 2, vector<int>(N / 2));
	vector<vector<bool>> paint(N, vector<bool>(N, false));
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			char c;
			cin >> c;
			pair<int, int> dest = map({i, j});
			//cout << dest.first << " " << dest.second << endl;
			if(c == '#'){
				paint[i][j] = true;
				++counts[dest.first][dest.second];
			}
		}
	}
	int ans = 0;
	for(vector<int> v : counts){
		for(int n : v){
			ans += count(n);
		}
	}
	cout << ans << endl;
	for(int i = 0; i < U; ++i){
		int y, x;
		cin >> y >> x;
		--y;
		--x;
		pair<int, int> dest = map({y, x});
		if(!paint[y][x]){
			if(counts[dest.first][dest.second] <= 1){
				++ans;
			}else{
				--ans;
			}
			++counts[dest.first][dest.second];
		}else{
			if(counts[dest.first][dest.second] >= 3){
				++ans;
			}else{
				--ans;
			}
			--counts[dest.first][dest.second];
		}
		paint[y][x] = !paint[y][x];
		/*
		for(vector<int> v : counts){
			for(int n : v){
				cout << n << " ";
			}
			cout << endl;
		}
		*/
		cout << ans << endl;
	}
}
