#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> vis;
set<ll> possible;
ll x, y, k;
void dfs(ll a, ll b, ll level){
	if(level > k) return;
	if(vis[a][b] <= level) return;
	vis[a][b] = level;
	possible.insert(a + b);
	dfs(x, b, level + 1);
	dfs(a, y, level + 1);

	ll diff = min(a, y - b);
	dfs(a - diff, b + diff, level + 1);
	diff = min(x - a, b);
	dfs(a + diff, b - diff, level + 1);

	dfs(a, 0, level + 1);
	dfs(0, b, level + 1);
}
int main(){
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
	cin >> x >> y >> k;
	ll m;
	cin >> m;
	vis.assign(x + 1, vector<ll>(y + 1, 10000000000));
	//cout << "POOP\n";
	dfs(0,0,0);
	//cout << "FART\n";
	//cout << "possible: \n";
	ll ans = 100000000000;
	for(ll i : possible){
		//cout << "-->" << i << endl;
		ans = min(ans, abs(m - i));
	}
	cout << ans << endl;
}
