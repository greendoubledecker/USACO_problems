#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for(ll i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<ll> leftmax(n), rightmax(n);
	ll l = 0, r = 0;
	for(; l < n; ++l){
		while(r < n){
			if(v[r] - v[l] > k){
				break;
			}
			if(r == 0){
				leftmax[r] = r - l + 1;
			}else{
				leftmax[r] = max(r - l + 1, leftmax[r - 1]);
			}
			//cout << "r " << r << " l" << l << " leftmax[r]" << leftmax[r] << endl;
			++r;
		}
	}
	l = n - 1; r = n - 1;
	for(; r > -1; --r){
		while(l > -1){
			if(v[r] - v[l] > k){
				break;
			}
			if(r == n - 1){
				rightmax[l] = r - l + 1;
			}else{
				rightmax[l] = max(r - l + 1, rightmax[l + 1]);
			}
			--l;
		}
	}
	ll ans = 0;
	for(ll i = 0; i < n - 1; ++i){
		//cout << "left "  << leftmax[i]<< " right " <<   rightmax[i + 1] << endl;
		ans = max(ans, leftmax[i] + rightmax[i + 1]);
	}
	cout << ans << endl;
}
