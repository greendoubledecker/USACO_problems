#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<bool>> grid;
vector<vector<bool>> visited;

void recurse(int x, int y, int lvl){ //if statements are acctually not nessesssarry
	//for(int i = 0; i < lvl; ++i) cout << ' ';
	//cout << "x y " << x << ' ' << y << endl;
	if(visited[y][x]) return;
	visited[y][x] = true;
	if(grid[y - 1][x]){ //up
		int newy = y;
		while(grid[newy - 1][x]){
			visited[newy][x] = true;
			--newy;
		}
		recurse(x, newy, lvl + 1);
	}
	if(grid[y + 1][x]){ //down
		int newy = y;
		while(grid[newy + 1][x]){
			visited[newy][x] = true;
			++newy;
		}
		recurse(x, newy, lvl + 1);
	}
	if(grid[y][x - 1]){ //left
		int newx = x;
		while(grid[y][newx - 1]){
			visited[y][newx] = true;
			--newx;
		}
		recurse(newx, y, lvl + 1);
	}
	if(grid[y][x + 1]){ //right
		int newx = x;
		while(grid[y][newx + 1]){
			visited[y][newx] = true;
			++newx;
		}
		recurse(newx, y, lvl + 1);
	}
}

signed main(){
	int r, c;
	cin >> r >> c;
	grid.resize(r, vector<bool>(c));
	visited.resize(r, vector<bool>(c));
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			char c;
			cin >> c;
			grid[i][j] = c == '.';
		}
	}
	recurse(1, 1, 0);
	int count = 0;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			count += visited[i][j];
		}
	}
	cout << count << endl;
}
