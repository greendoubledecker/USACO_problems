#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	int Q;
	cin >> Q;
	vector<vector<int>> photos(N-K+1, vector<int>(N-K+1, 0));
	vector<vector<int>> field(N, vector<int>(N, 0));
	int max = 0;
	for(int i = 0; i < Q; ++i){
		int R, C, V;
		cin >> R >> C >> V;
		--R;
		--C;
		for(int i = R - K + 1; i <= R; ++i){
			for(int j = C - K + 1; j <= C; ++j){
				if(i > -1 && j > -1 && i < photos.size() && j < photos.size()){
					photos[i][j] += V - field[R][C];
					if(photos[i][j] > max){
						max = photos[i][j];
					}
				}
			}
		}
		cout << max << endl;
		field[R][C] = V;
	}
}
