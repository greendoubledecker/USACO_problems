/*s   e m  s g
 * e r   e  a
 *     t      e
 *  c     s
 *secretmessage
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll striplen, num;
		cin >> striplen >> num;
		vector<string> message(num);
		for(ll i = 0; i < num; ++i){
			cin >> message[i];
		}
		bool done = false;
		for(ll len = 1; len <= striplen/2; ++len){
			//cout << "testing len " << len << endl;
			if(striplen % len)continue;
			vector<vector<ll>> modResidues(len, vector<ll>(26, 0)); //a fancy way of saying grouped by remainder when divided by len
			for(ll col = 0; col < striplen; ++col){
				vector<bool> seen(26);
				for(ll row = 0; row < num; ++row){
					if(seen[message[row][col] - 'a']) continue;
					++modResidues[col % len][message[row][col] - 'a'];
					seen[message[row][col] - 'a'] = true;
				}
			}
			string ans;
			//cout << "len " << len;
			for(ll res = 0; res < len; ++res){
				//cout << "\nresidue " << res << endl;
				for(ll c = 0; c < 26; ++c){
					//cout << modResidues[res][c];
					if(modResidues[res][c] == striplen / len){
						ans.push_back('a' + c);
						break;
					}
				}
			}
			if(ans.size() < len)continue;
			for(ll i = 0; i < striplen / len; ++i){
				cout << ans;
			}
			done = true;
			break;
		}
		if(!done){
			cout << message[0];
		}
		cout << '\n';
	}
}
