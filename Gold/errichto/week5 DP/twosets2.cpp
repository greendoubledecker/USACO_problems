#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef LOCAL
#define debug(x) cout << #x << " is " << x << endl;
#define debugVec(x) cout << #x << ": "; for(auto moo : x) cout << moo << ' '; cout << endl;
#define debug2d(x) cout << #x << ":\n"; for(auto moo : x){for(auto mooo : moo) cout << mooo << ' ';cout << endl;}
#else
#define debug(x)
#define debugVec(x)
#define debug2d(x)
#endif
const ll MOD = 1'000'000'007;
struct mi{
	ll val;
	mi() : val(0) {}
	mi(ll v){
		val = v % MOD;
		if(val < 0) val += MOD;
	}
	mi& operator+=(const mi o){
		val = (val + o.val) % MOD;
		return *this;
	}
	mi& operator-=(const mi o){
		val = (val - o.val + MOD) % MOD;
		return *this;
	}
	bool operator<(const mi o)const{
		return val < o.val;
	}
	bool operator>(const mi o)const{
		return o < *this;
	}
	bool operator>=(const mi o)const{
		return !(*this < o);
	}
	bool operator<=(const mi o)const{
		return !(*this > o);
	}
	bool operator==(const mi o)const{
		return *this >= o && *this <= o;
	}
	bool operator!=(const mi o)const{
		return !(*this == o);
	}
	friend ostream& operator<<(ostream& os, const mi& m){
		return os << m.val;
	}
	friend istream& operator>>(istream& is, mi& m){
		is >> m.val;
		m.val %= MOD;
		return is;
	}
};

int main(){
	ll n; cin >> n;
	mi diffs[125252], nextdiffs[125252]; //[125252]
	diffs[0] = 1;
	for(ll i = 1; i <= n; ++i){
		for(ll j = 0; j < 125252; ++j){
			nextdiffs[j] = 0;
		}
		for(ll j = 0; j < 125252 - i; ++j){
			nextdiffs[j+i] += diffs[j];
			nextdiffs[abs(j-i)] += diffs[j];
		}
		swap(diffs, nextdiffs);
		//debugVec(diffs);
	}
	cout << (diffs[0].val*500000004)%MOD << endl;
}
