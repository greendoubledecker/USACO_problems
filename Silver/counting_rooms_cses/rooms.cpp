#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<bool>> seen;
void dfs(ll x, ll y){
	seen[x][y] = true;
	if(!seen[x - 1][y]){
		dfs(x-1,y);
	}
	if(!seen[x][y - 1]){
		dfs(x,y-1);
	}
	if(!seen[x + 1][y]){
		dfs(x+1,y);
	}
	if(!seen[x][y + 1]){
		dfs(x,y+1);
	}
}
int main(){
	ll n, m;
	cin >> n >> m;
	seen.push_back(vector<bool>(m + 2, 1));
	for(ll i = 0; i < n; ++i){
		vector<bool> row(1, 1);
		for(ll j = 0; j < m; ++j){
			char x;
			cin >> x;
			row.push_back(x == '#');
		}
		row.push_back(1);
		seen.push_back(row);
	}
	seen.push_back(vector<bool>(m + 2, 1));
	ll ans = 0;
	for(ll x = 1; x < n + 1; ++x){
		for(ll y = 1; y < m + 1; ++y){
			if(!seen[x][y]){
				++ans;
				dfs(x, y);
			}
		}
	}
	cout << ans << endl;
}
