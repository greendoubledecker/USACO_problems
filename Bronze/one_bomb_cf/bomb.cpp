//roll down the stairs on your bike!
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll h, w;
	cin >> h >> w;
	
	//store the grid
	vector<vector<bool>> wall(h, vector<bool>(w));
	for(ll y = 0; y < h; ++y){
		for(ll x = 0; x < w; ++x){
			char c;
			cin >> c;
			wall[y][x] = c == '*'; //set the boolean to true if cell is a wall
		}
	}
	
	//count walls in each row
	vector<ll> rowCount;
	for(ll y = 0; y < h; ++y){
		ll count = 0; //keep a count of the number of walls
		for(ll x = 0; x < w; ++x){
			if(wall[y][x]){
				++count; //add 1 to count if it is a wall
			}
		}
		rowCount.push_back(count);
	}
	
	
	//count walls in each column
	vector<ll> colCount;
	for(ll x = 0; x < w; ++x){
		ll count = 0; //keep a count of the number of walls
		for(ll y = 0; y < h; ++y){
			if(wall[y][x]){
				++count; //add 1 to count if it is a wall
			}
		}
		colCount.push_back(count);
	}
	
	//count total walls
	ll total = 0;
	for(ll y = 0; y < h; ++y){
		for(ll x = 0; x < w; ++x){
			total += wall[y][x];
		}
	}
	 //check each cell
	for(ll y = 0; y < h; ++y){
		for(ll x = 0; x < w; ++x){
			ll count = rowCount[y] + colCount[x] - wall[y][x]; //add the number of walls in the row and the number of walls in the column and subtract 1 if the bomb is on a wall
			if(count == total){
				cout << "YES\n" << y + 1 << " " << x + 1;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
