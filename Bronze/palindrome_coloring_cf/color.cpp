//i tumbled down the ramp on my rollerskates
#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		
		//keep track of occurences of each letter
		vector<ll> count(26, 0);
		for(ll i = 0; i < n; ++i){
			++count[s[i] - 'a'];
		}
		
		//count number of letters that appear twice
		ll twice = 0;
		for(ll i = 0; i < 26; ++i){
			twice += count[i] / 2;
		}
		
		//count singles
		ll single = n - 2 * twice;
		
		//count length of palindromes with even length
		ll even = twice / k * 2;
		
		//the pairs that are left over become single
		single += (twice % k) * 2;
		
		//count total length
		ll total = even + (single >= k);
		
		cout << total << endl;
	}
}
