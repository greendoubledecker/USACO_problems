#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<pair<int, int>> spot;

vector<vector<bool>> spots;

void dfs(int x, int y){
	//cout << "in function, x = " << x << " and y = " << y << "." << endl;
	//cout << "spots is " << spots.size() <<  " by " << spots[0].size() << "." << endl;
	if(x != spots.size() - 1 && spots[x + 1][y]){
		spots[x + 1][y] = false;
		spot.push_back({x + 1, y});
		dfs(x + 1, y);
	}
	if(y != spots[0].size() - 1 && spots[x][y + 1]){
		spots[x][y + 1] = false;
		spot.push_back({x, y + 1});
		dfs(x, y + 1);
	}
	if(x != 0 && spots[x - 1][y]){
		spots[x - 1][y] = false;
		spot.push_back({x - 1, y});
		dfs(x - 1, y);
	}
	if(y != 0 && spots[x][y - 1]){
		spots[x][y - 1] = false;
		spot.push_back({x, y - 1});
		dfs(x, y - 1);
	}
}

int main(){
	int height, width;
	cin >> height >> width;
	vector<vector<bool>> Xs(height, vector<bool>(width, false)); //1 means X, 0 means .
	spots = Xs;
	pair<int, int> start;
	for(int i = 0; i < height; ++i){
		for(int j = 0; j < width; ++j){
			char c;
			cin >> c;
			if(c == 'X'){
				spots[i][j] = true;
				start = {i, j};
			}
		}
	}
	//cout << "got input" << endl;
	dfs(start.first, start.second);
	vector<pair<int, int>> spot1 = spot;
	spot1.push_back(start);
	vector<pair<int, int>> spot2;
	for(int i = 0; i < height; ++i){
		for(int j = 0; j < width; ++j){
			pair<int, int> loc = {i, j};
			auto r = find(spot1.begin(), spot1.end(), loc);
			if(spots[i][j] && r == spot1.end()){
				spot2.push_back({i, j});
			}
		}
	}
	//cout << "spotted" << endl;
	int min = 100;
	//cout << spot1.size() << endl;
	for(pair<int, int> loc1 : spot1){
		for(pair<int, int> loc2 : spot2){
			//cout << "loc1 is " << loc1.first << ", " << loc1.second << endl;
			//cout << "loc2 is " << loc2.first << ", " << loc2.second << endl;
			int dist = abs(loc1.first - loc2.first) + abs(loc1.second - loc2.second) - 1;
			if(dist < min) min = dist;
		}
	}
	cout << min << endl;
}
