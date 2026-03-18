#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll tc(){
	ll a, b;
	cin >> a >> b;
	vector<ll> v(a);
	for(ll i = 0; i < a; ++i){
		cin >> v[i];
	}
	vector<ll> ps(1, 0), ms(1, 0);
	for(ll i = 1; i <= a; ++i){
		if(i % 2 == 0){
			ps.push_back(ps[i - 1] - v[i - 1]);
			ms.push_back(ms[i - 1] - v[i - 1] * i);
		}else{
			ps.push_back(ps[i - 1] + v[i - 1]);
			ms.push_back(ms[i - 1] + v[i - 1] * i);
		}
	}
	ll total = 0;
	while(b--){
		char c;
		cin >> c;
		if(c == 'Q'){
			ll l, r;
			cin >> l >> r;
			ll ans = ms[r] - ms[l - 1] - (l - 1) * (ps[r] - ps[l - 1]);
			if(l % 2 == 0){
				ans = -ans;
			}
			total += ans;
		}else{
			/*
			for(ll i : ps){
				cout << i << endl;
			}
			cout << endl;
			for(ll i : ms){
				cout << i << endl;
			}
			*/
			ll ind, val;
			cin >> ind >> val;
			--ind;
			v[ind] = val;
			ps.assign(1, 0);
			ms.assign(1, 0);
			for(ll i = 1; i <= a; ++i){
				if(i % 2 == 0){
					ps.push_back(ps[i - 1] - v[i - 1]);
					ms.push_back(ms[i - 1] - v[i - 1] * i);
				}else{
					ps.push_back(ps[i - 1] + v[i - 1]);
					ms.push_back(ms[i - 1] + v[i - 1] * i);
				}
			}
		}
	}
	return total;
}

int main(){
	ll t;
	cin >> t;
	for(ll i = 0; i < t; ++i){
		ll ans = tc();
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
}
