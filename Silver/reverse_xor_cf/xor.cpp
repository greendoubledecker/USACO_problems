#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		if(n == 0){
			cout << "YES\n";
			continue;
		}
		while(n % 2 == 0){
			n/=2;
		}
		bitset<64> bs(n);
		string s = bs.to_string();
		ll first = s.find_first_not_of('0');
		s.erase(0, min(first, (ll)s.size() - 1));
		//cout << "size: " << s.size() << endl;
		bool fleg = false;
		for(ll i = 0; i < s.size(); ++i){
			if(s[i] != s[s.size() - i - 1]){
				cout << "NO" << endl;
				fleg = true;
				break;
			}
		}
		if(fleg){
			continue;
		}
		if(s.size() % 2){
			if(s[s.size() / 2] == '1'){
				cout << "NO" << endl;
				continue;
			}
		}
		cout << "YES" << endl;
	}
}
