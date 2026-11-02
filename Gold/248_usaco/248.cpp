#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef LOCAL
#define debug(x) cout << #x << " is " << x << endl;
#define debugVec(x) cout << #x << ": "; for(auto moo : x) cout << moo << ' '; cout << endl;
#define debug2d(x) cout << #x << ":\n"; for(auto moo : x){for(auto mooo : moo) cout << mooo << ' ';cout << endl;}
#define printLocal(x) cout << x << '\n';
#else
#define debug(x)
#define debugVec(x)
#define debug2d(x)
#define printLocal(x)
#endif
ll n;
vector<vector<ll>> dp; //dp[l][r] = max score in the range
ll rec(ll l, ll r){
	if(dp[l][r] > -2){
		return dp[l][r];
	}else{
		ll maxx = -1;
		for(ll split = l; split < r; ++split){
			if(rec(l, split) == rec(split + 1, r) && dp[l][split] > -1){
				maxx = max(maxx, dp[l][split] + 1);
			}
		}
		dp[l][r] = maxx;
		return maxx;
	}
}
int main(){
	ifstream in("248.in");
	ofstream out("248.out");
	in >> n;
	vector<ll> v(n);
	dp.assign(n, vector<ll>(n, -2));
	for(ll i = 0; i < n; ++i){
		in >> v[i];
		dp[i][i] = v[i];
	}
	ll maxx = rec(0, n-1);
	for(ll l = 0; l < n; ++l) for(ll r = l; r < n; ++r){
		maxx = max(maxx, dp[l][r]);
	}
	out << maxx << endl;
}
