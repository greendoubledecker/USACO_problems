//comment
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n, x;
	cin >> n >> x;
	vector<ll> children(n);
	for(ll i = 0 ;i < n; ++i){
		cin >> children[i];
	}
	sort(children.begin(), children.end());
	ll left = 0;
	ll ans = 0;
	for(ll right = n - 1; right >= left; --right){
		if(children[right] + children[left] <= x){
			++left;
		}
		++ans;
		//cout << "right = " << right << endl;
	}
	//cout << "left: " << left << endl;
	cout << ans << endl;
}
