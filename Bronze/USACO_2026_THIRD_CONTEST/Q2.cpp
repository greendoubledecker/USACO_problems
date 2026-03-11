#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		vector<ll> bits(s.size() + 2, 0);
		bool notBinary = false;
		for(char c : s){
			if(c-'0' > 1){
				notBinary = true;
				break;
			}
		}
		if(notBinary){
			for(char &c : s){
				ll mod2 = (c - '0') % 2;
				c = '0' + mod2;
			}
		}
		//cout << "binary: " << s << endl;
		for(ll i = 0; i < s.size(); ++i){
			bits[i] = s[s.size() - 1 - i] - '0';
		}
		for(ll i = bits.size() - 1; i > 0; --i){ //x3
			bits[i] += bits[i - 1];
		}
		for(ll i = 1; i < bits.size() - 1; ++i){ //handle carry
			if(bits[i] > 1){
				bits[i + 1] += (bits[i] - (bits[i] % 2))/2;
				bits[i] %= 2;
			}
		}
		ll ans = 0;
		ll pow = 1;
		//cout << "end: " << bits[0];
		for(ll i = 1; i < bits.size(); ++i){ //start at 1 to divide by 2
			//cout << bits[i];
			ans += pow * bits[i];
			ans %= 1'000'000'007;
			pow *= 2;
			pow %= 1'000'000'007;
		}
		//cout << '\n';
		cout << (ans + notBinary) % 1'000'000'007 << endl;
	}
}
