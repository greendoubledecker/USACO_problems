#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll sum = n * (n + 1) / 2;
		cout << "2 1 " << n << endl;
		ll newSum;
		cin >> newSum;
		ll length = newSum - sum;
		ll l = 0;
		ll r = n - 1;
		while(true){
			//cout << "l = " << l << " r = " << r << endl;
			if(r - l == length){
				cout << "! " << l + 2 << " " << r + 1 << endl;
				break;
			}
			ll leftDiff;
			ll a, b;
			cout << "1 " << l + 1 << " " << (r + l) / 2 + 1 << endl << "2 " << l + 1 << " " << (r + l) / 2 + 1 << endl;
			cin >> a >> b;
			leftDiff = b - a;
			ll rightDiff = length - leftDiff;
			if(leftDiff != 0 && rightDiff != 0){
				cout << "! " << (r + l) / 2 - leftDiff + 2 << " " << (r + l) / 2 + rightDiff + 1 << endl;
				break;
			}
			if(leftDiff == 0){
				l = (r + l) / 2 + 1;
			}else{
				r = (r + l) / 2;
			}
		}
	}
}
