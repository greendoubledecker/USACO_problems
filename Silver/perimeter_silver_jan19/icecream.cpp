/*  Ice   ###   Cream
 *    ###########
 *   #############
 *   #############
 *    ###########
 *     \^^^^^^^/
 *      \^^^^^/
 *       \^^^/
 *        \^/
 *         V
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<bool>> vis; //Add a wall on outside
void dfs(ll x, ll y, vector<pair<ll,ll>> &component){
	if(vis[x][y]) return;
	vis[x][y] = true;
	component.push_back({x-1, y-1});
	dfs(x - 1, y, component);
	dfs(x + 1, y, component);
	dfs(x, y - 1, component);
	dfs(x, y + 1, component);
}
int main(){
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	ll n;
	cin >> n;
	vis.assign(n + 2, vector<bool>(n + 2));
	vector<vector<bool>> v(n, vector<bool>(n));
	for(ll i = 0; i < n; ++i){
		for(ll j = 0; j < n; ++j){
			char c;
			cin >> c;
			v[i][j] = c == '#';
			vis[i + 1][j + 1] = c != '#';
		}
	}
	for(ll i = 0; i <= n + 1; ++i){
		vis[0][i] = true;
		vis[i][0] = true;
		vis[n+1][i] = true;
		vis[i][n+1] = true;
	}
	ll maxarea = 0, minperimeter = 10000000000000;
	for(ll i = 1; i < n + 1; ++i){
		for(ll j = 1; j < n + 1; ++j){
			if(!vis[i][j]){
				vector<pair<ll, ll>> ans = {};
				dfs(i, j, ans);
				//cout << "dfs" << endl;
				ll area = ans.size();
				ll perimeter = 0;
				for(pair<ll,ll> p : ans){
					ll x = p.first;
					ll y = p.second;
					if( x == n - 1 || !v[x + 1][y]){
						++perimeter;
					}
					if(x == 0 || !v[x - 1][y]){
						++perimeter;
					}
					if(y == n - 1 || !v[x][y + 1]){
						++perimeter;
					}
					if(y == 0 || !v[x][y - 1]){
						++perimeter;
					}
				}
				if(area > maxarea){
					maxarea = area;
					minperimeter = 10000000000000;
				}
				if(area == maxarea){
					minperimeter = min(minperimeter, perimeter);
				}
			}
		}
	}
	cout << maxarea << ' ' << minperimeter << endl;
}
