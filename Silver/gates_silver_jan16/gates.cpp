#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<bool>> canGoUp(2026, vector<bool>(2026, true)), canGoDown(2026, vector<bool>(2026, true)), canGoLeft(2026, vector<bool>(2026, true)), canGoRight(2026, vector<bool>(2026, true)); //if you cant tell this code was made in 2026
vector<vector<bool>> visited(2026, vector<bool>(2026, false));
void dfs(ll x, ll y){
	stack<pair<ll, ll>> stc;
	stc.push({x, y});
	while(!stc.empty()){

		pair<ll, ll> next = stc.top();
		stc.pop();
		if(!visited[next.first][next.second]){
			visited[next.first][next.second] = true;
			ll x = next.first;
			ll y = next.second;
			if(canGoUp[x][y] && !visited[x][y+1]){
				stc.push({x, y+1});
			}
			if(canGoDown[x][y] && !visited[x][y-1]){
				stc.push({x,y-1});
			}
			if(canGoLeft[x][y] && !visited[x-1][y]){
				stc.push({x-1,y});
			}
			if(canGoRight[x][y] && !visited[x+1][y]){
				stc.push({x+1,y});
			}
		}
	}
	/*
	cout << "dfs " << x << ' ' << y << endl;
	visited[x][y] = true;
	if(canGoUp[x][y] && !visited[x][y+1]){
		dfs(x,y+1);
	}
	if(canGoDown[x][y] && !visited[x][y-1]){
		dfs(x,y-1);
	}
	if(canGoLeft[x][y] && !visited[x-1][y]){
		dfs(x-1,y);
	}
	if(canGoRight[x][y] && !visited[x+1][y]){
		dfs(x+1,y);
	}
	*/
}

int main(){
	freopen("gates.in", "r", stdin);
	freopen("gates.out", "w", stdout);
	ll n;
	cin >> n;
	ll x = 1013, y = 1013;
	while(n--){
		char c;
		cin >> c; // down left = [x][y] down right = [x + 1][y] up left = [x][y + 1] up right = [x + 1][y + 1]
		if(c == 'N'){
			++y;
			canGoRight[x][y] = false;
			canGoLeft[x + 1][y] = false;
		}
		if(c == 'S'){
			--y;
			canGoRight[x][y + 1] = false;
			canGoLeft[x + 1][y + 1] = false;
		}
		if(c == 'E'){
			++x;
			canGoUp[x][y] = false;
			canGoDown[x][y + 1] = false;
		}
		if(c == 'W'){
			--x;
			canGoUp[x + 1][y] = false;
			canGoDown[x + 1][y + 1] = false;
		}
	}
	//cout << "poop\n";
	for(ll i = 0; i < 2026; ++i){
		canGoLeft[0][i] = false;
		canGoDown[i][0] = false;
		canGoUp[i][2025] = false;
		canGoRight[2025][i] = false;
	}
	//cout << "pee\n";
	ll ans = -1;
	for(ll i = 0; i < 2026; ++i){
		for(ll j = 0; j < 2026; ++j){
			//cout << "in poop...i mean, loop.\n";
			if(!visited[i][j]){
				dfs(i, j);
				++ans;
				//cout << "Ansis " << ans << endl;
			}
		}
	}
	cout << ans << endl;
}
