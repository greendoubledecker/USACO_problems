#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> v(n);
		for(ll i = 0; i < n; ++i){
			cin >> v[i];
		}
		v.push_back(0);
		if(n % 2){
			ll sum = 0;
			for(ll i = 1; i < n-1; i += 2){
				sum += max(0ll, max(v[i-1] - v[i], v[i+1] - v[i]) + 1);
			}
			cout << sum << endl;
		}else{
			ll total = 0;
			for(ll i = 1; i < n-1; i += 2){
				total += max(0ll, max(v[i-1] - v[i], v[i+1] - v[i]) + 1);
			}
			//cout << "IUSHUYEDBJHWEBHKEG\n";
			ll ans = total;
			for(ll i = n - 2; i > 0; i -= 2){
				total -= max(0ll, max(v[i-2] - v[i-1], v[i] - v[i-1]) + 1);
				total += max(0ll, max(v[i-1] - v[i], v[i+1] - v[i]) + 1);
				ans = min(ans, total);
			}
			cout <<ans << endl;
		}
	}
}
//if n is odd, I can just choose every other building to be cool, as that maximises cool buildings.
//if n is even, there will be two consecutive non-cool buildings.
//I can just iterate through and add and subtract to find the cost of having those two consecutive buildings at a specific location.
