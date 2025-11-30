//Hippity Hoppity, get off my property. Bippity Boppity, I'll call the Coppity.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool overlap(int num, int top, vector<vector<int>>grid){
	int topEdge = 0;
	for(; topEdge < grid.size(); ++topEdge){
		bool stop = false;
		for(int color : grid[topEdge]){
			if(color == num){
				stop = true;
				break;
			}
		}
		if(stop) break;
	}
	int bottomEdge = grid.size() - 1;
	for(; bottomEdge > -1; --bottomEdge){
		bool stop = false;
		for(int color : grid[bottomEdge]){
			if(color == num){
				stop = true;
				break;
			}
		}
		if(stop) break;
	}
	int leftEdge = 0;
	for(; leftEdge < grid.size(); ++leftEdge){
		bool stop = false;
		for(int i = 0; i < grid.size(); ++i){
			if(grid[i][leftEdge] == num){
				stop = true;
				break;
			}
		}
		if(stop) break;
	}
	int rightEdge = grid.size() - 1;
	for(; rightEdge > -1; --rightEdge){
		bool stop = false;
		for(int i = 0; i < grid.size(); ++i){
			if(grid[i][rightEdge] == num){
				stop = true;
				break;
			}
		}
		if(stop) break;
	}
	unordered_set<int> overlap;
	for(int i = topEdge; i <= bottomEdge; ++i){
		for(int j = leftEdge; j <= rightEdge; ++j){
			if(grid[i][j] == top) return true;
		}
	}
	return false;
}

int main(){
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	int num; cin >> num;
	unordered_set<int> appears;
	vector<vector<int>> grid(num, vector<int>(num));
	for(int i = 0; i < num; ++i){
		string s;
		cin >> s;
		for(int j = 0; j < num; ++j){
			grid[i][j] = s[j] - '0';
			if(s[j] != '0'){
				appears.insert(s[j] - '0');
			}
		}
	}
	int count = 0;
	for(int c1 : appears){
		bool possible = true;
		for(int c2 : appears){
			if(c2 != c1){
				if(overlap(c2, c1, grid) == true) possible = false;
			}
		}
		if(possible) ++count;
	}
	cout << count << endl;
	return 0;
}
