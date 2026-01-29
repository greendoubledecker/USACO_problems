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
		ll leftl = 0;
		ll rightl = n - 1;
		while(leftl != rightl){
			ll a, b;
			cout << "1 " << leftl + 1 << " " << (leftl + rightl) / 2 + 1 << endl;
			cin >> a;
			cout << "2 " << leftl + 1 << " " << (leftl + rightl) / 2 + 1 << endl;
			cin >> b;
			if(a != b){
				rightl = (leftl + rightl) / 2;
			}else{
				leftl = (leftl + rightl) / 2 + 1;
			}
		}
		ll r = leftl + length - 1;
		cout << "! " << leftl + 1 << " " << r + 1 << endl;
	}
}
