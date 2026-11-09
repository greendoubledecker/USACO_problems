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
	ll a = 1;
	ll b = 0, c = 0, d = 0, e = 0, f = 0;
	for(ll i = 0; i < n; ++i){
		ll temp = a + b + c + d + e + f;
		temp %= 1'000'000'007;
		f = e;
		e = d;
		d = c;
		c = b;
		b = a;
		a = temp;
	}
	cout << a << endl;
}
