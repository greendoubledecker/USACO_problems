#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n;
	cin >> n;
	set<ll> st;
	ll ans = 0;
	for(ll i = 1; i <= n; ++i){
		ll x;
		cin >> x;
		if(x== i){
			++ans;
		}else{
			st.insert(x);
		}
	}
	ans += st.size() / 2;
	cout << ans << endl;
}
