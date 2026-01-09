#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void tc(){
	int rows, cols;
	cin >> rows >> cols;
	int radius;
	cin >> radius;
	--radius;
	vector<vector<int>> ps(rows + 1, vector<int>(cols + 1, 0));
	vector<vector<bool>> valid(rows, vector<bool>(cols));
	
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			char c;
			cin >> c;
			if(c == '.'){
				valid [i][j] = true;
				ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j];
			}else if(c == 'g'){
				valid[i][j] = false;
				ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + 1;
			}else{
				valid[i][j] = false;
				ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j];
			}
		}
	}
	int minn = 2000000000;
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			if(!valid[i][j]){
				continue;
			}
			int bot = min(rows, i + radius + 1);
			int top = max(0, i - radius);
			int lft = max(0, j - radius);
			int rgt = min(cols, j + radius + 1);
			
			int br = ps[bot][rgt];
			int bl = ps[bot][lft];
			int tr = ps[top][rgt];
			int tl = ps[top][lft];
			int disappeared = br - bl - tr + tl;
			minn = min(disappeared, minn);
		}
	}
	cout << max(ps[rows][cols] - minn, 0) << endl;
	return;
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		tc();
	}
}
