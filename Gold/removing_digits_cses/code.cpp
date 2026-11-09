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
	ll n;
	cin >> n;
	vector<ll> dp(n+1, 1e15);
	dp[n] = 0;
	for(ll i = n; i >= 0; --i){
		ll digits[] = {i/1'000'000, i/100'000 - i/1'000'000*10, i/10'000 - i/100'000*10, i/1'000 - i/10'000*10, i/100 - i/1000*10, i/10 - i/100*10, i - i/10*10};
		for(ll dig : digits){
			dp[i-dig] = min(dp[i-dig], dp[i]+1);
		}
	}
	cout << dp[0] << endl;
}
