#include <iostream>
#include <vector>

using namespace std;

void tc(){
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	vector<vector<int>> stars(n, vector<int>(n)); //[y][x]
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			char c;
			cin >> c;
			if(c == 'B'){
				stars[i][j] = 2;
			}else if(c == 'G'){
				stars[i][j] = 1;
			}else{
				stars[i][j] = 0;
			}
		}
	}
	int count = 0;
	for(int y = 0; y < n; ++y){
		for(int x = 0; x < n; ++x){
			if(stars[y][x] == 2){
				if(y < b || x < a){
					cout << -1 << endl;
					return;
				}else if(stars[y - b][x - a] == 0){
					cout << -1 << endl;
					return;
				}else{
					++count;
					--stars[y - b][x - a];
					--stars[y][x];
				}
			}
		}
	}
	
	for(int y = 0; y < n; ++y){
		for(int x = 0; x < n; ++x){
			if(stars[y][x] == 1){
				if(y < b || x < a){
					continue;
				}else if(stars[y - b][x - a] == 0){
					continue;
				}else{
					++count;
					--stars[y - b][x - a];
					--stars[y][x];
				}
			}
		}
	}
	
	for(int y = 0; y < n; ++y){
		for(int x = 0; x < n; ++x){
			if(stars[y][x] == 1){
				++count;
			}
		}
	}
	cout << count << endl;
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		tc();
	}
}
