#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, ll> primeFactorize(ll n){
	map<ll, ll> ans;
	while(n % 2 == 0){
		++ans[2];
		n /= 2;
	}
	for(ll i = 3; i < sqrt(n); i += 2){
		while(n % i == 0){
			++ans[i];
			n /= i;
		}
	}
	if(n == 1) return ans;
	++ans[n];
	return ans;
}
int main(){
	//cout << __cplusplus << endl;
	ll n;
	cin >> n;
	ll first = 1, second = 0;
	bool needMult = false;
	map<ll, ll> fact = primeFactorize(n);
	for(auto pair : fact){
		first *= pair.first;
		second = max(second, pair.second);
	}
	needMult = second && (second - 1);
	for(auto pair : fact){
		needMult = needMult || pair.second < second;
	}
	if(n == first){
		cout << first << " 0\n";
		return 0;
	}
	second = 64 - __builtin_clzll(second - 1);
	cout << first << " " << second + needMult << '\n';
}
