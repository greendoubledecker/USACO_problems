#include <iostream>
#include <vector>
#include <string>
#define ll long long

using namespace std;

int main(){
	ll n, m;
	string s;
	cin >> n >> m >> s;
	for(ll x = 0; x < m; ++x){
		ll a, b;
		cin >> a >> b;
		--a;
		--b;
		ll max = -1;
		for(ll j = a + 1; j < b; ++j){
			ll ans = 1;
			bool found = false;
			for(ll i = a; i < j; ++i){
				if(s[i] != s[j]){
					ans *= j - i;
					found = true;
					break;
				}
			}
			if(!found){
				continue;
			}
			found = false;
			for(ll k = b; k > j; --k){
				if(s[j] == s[k]){
					ans *= k - j;
					found = true;
					break;
				}
			}
			if(!found){
				continue;
			}
			if(ans > max){
				max = ans;
			}
		}
		cout << max << endl;
	}
}
