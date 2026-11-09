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
int main(){
	ll n,x;
	cin >> n >> x;
	vector<ll> dp(x+1, 0);
	vector<ll> h(n),s(n);
	for(ll &i : h) cin >> i;
	for(ll &i : s) cin >> i;
	for(ll i = 0; i < n; ++i){
		ll hi = h[i],si = s[i];
		vector<ll> next = dp;
		for(ll cost = 0; cost <= x-hi; ++cost){
			next[cost + hi] = max(dp[cost] + si, next[cost+hi]);
		}
		debugVec(next);
		swap(next,dp);
	}
	cout << dp[x] << endl;
}
