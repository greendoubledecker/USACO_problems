//this code has quite a long filename!
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ll n;
vector<ll> x,v;
ld check(ld pos){
	ld ans = 0;
	for(ll i = 0; i < n; ++i){
		ans = max(ans, abs(x[i]-pos)/v[i]);
	}
	return ans;
}
int main(){
	cout << fixed << setprecision(20);
	cin >> n;
	for(ll i = 0; i < n; ++i){
		ll position;
		cin >> position;
		x.push_back(position);
	}
	for(ll i = 0; i < n; ++i){
		ll speed;
		cin >> speed;
		v.push_back(speed);
	}
	ld l = 0.000, h = 1e18;
	for(ll i = 0; i < 1000; ++i){
		//cout << l << ' ' << h << endl;
		ld delta = (h-l)/3.0;
		ld m1 = l+delta;
		ld m2 = h-delta;
		if(check(m1) > check(m2)){
			l = m1;
		}else{
			h = m2;
		}
	}
	//cout << "debuguggguuguguug: " << check(5.0) << endl;
	cout << check((l+h)/2.000) << endl;
}







/*Lightning McQueen reference*
  Olympic swimmers at the pool:
  I am speed.
  Other people at the pool:
  I     peed.
*/
