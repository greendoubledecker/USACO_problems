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
	vector<ll> coins(n);
	for(ll& i : coins) cin >> i;
	vector<ll> dp(x+1, 1e15);
	dp[0] = 0;
	for(ll i = 1; i <= x; ++i){
		for(ll coin : coins){
			if(coin <= i){
				dp[i] = min(dp[i], dp[i-coin] + 1);
			}
		}
	}
	if(dp[x] == 1e15){
		cout << "-1\n";
		return 0;
	}
	cout << dp[x] << endl;
}
