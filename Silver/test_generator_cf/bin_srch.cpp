#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool ansGTguess(bitset<64> m, bitset<64> sBits, ll guess){
	vector<ll> s;
	for(ll i = 0; i < 64; ++i){
		s.push_back(sBits[i]);
	}
	for(ll i = s.size() - 1; i > 0; --i){
		if(!m[i]){
			s[i - 1] += s[i] << 1;
			s[i] = 0;
		}else{
			if(s[i] > guess){
				s[i - 1] += (s[i] - guess) << 1;
				s[i] = guess;
			}
		}
	}
	if(!m[0] && s[0]){
		return true;
	}
	if(s[0] > guess){
		return true;
	}
	return false;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll s, m;
		cin >> s >> m;
		bitset<64> sBin(s);
		bitset<64> mBin(m);
		ll low = -1LL;
		ll high = 1'000'000'000'000'000'001;
		while(low < high){
			//cout << "low = " << low << " high = " << high << endl;
			ll mid = low + (high - low) / 2;
			if(ansGTguess(mBin, sBin, mid)){
				low = mid + 1;
			}else{
				high = mid;
			}
		}
		if(low > 1'000'000'000'000'000'000){
			cout << -1 << endl;
			continue;
		}
		cout << low << endl;
	}
}
