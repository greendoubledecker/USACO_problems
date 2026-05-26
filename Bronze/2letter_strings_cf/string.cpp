#include <bits/stdc++.h>         //Keep count of every possible word
using namespace std;             //For every possible word
using ll = long long;            //  Keep track of a variable cnt
int main(){                      //  Count number of words with same starting and different ending
	ll t;                        //  Add this to cnt
	cin >> t;                    //  Count number of words with different starting and same ending
	while(t--){                  //  Add this to cnt
		ll n;                    //  Multiply cnt by count of current word
		cin >> n;                //  Add cnt to answer
		map<pair<ll, ll>, ll> mp;//  Divide answer by 2
		for(ll i = 0; i < n; ++i){
			string s;            //This works as every possible pair of words is enumerated.
			cin >> s;            //Even though each pair is double-counted,the answer is divided by 2.
			++mp[{s[0] - 'a', s[1] - 'a'}];
		}
		ll ans = 0;
		for(pair<pair<ll, ll>, ll> p : mp){
			ll cnt = 0;
			for(ll i = 0; i < 26; ++i){
				if(i != p.first.first && mp.count({i, p.first.second})){
					cnt += mp[{i, p.first.second}];
				}
				if(i != p.first.second && mp.count({p.first.first, i})){
					cnt += mp[{p.first.first, i}];
				}
			}
			ans += cnt * p.second;
		}
		cout << ans/2 << endl;
	}
}
