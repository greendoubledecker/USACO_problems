#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		
		//keep track of where each letter occurs
		vector<vector<ll>> occ(26);
		map<char, ll> count;
		for(ll i = 0; i < 26; ++i){
			count[(char)('a' + i)] = 0;
		}
		for(ll i = 0; i < n; ++i){
			char acter; //character
			cin >> acter;
			++count[acter];
			occ[acter - 'a'].push_back(i); 
		}
		
		//convert to vector and sort
		vector<pair<char, ll>> countv(count.begin(), count.end());
		sort(countv.begin(), countv.end(), [](const auto& a, const auto& b) {
			return a.second > b.second; 
		});
		
		
		//cout << "erygufgkurkstregyegriyuuiwe" << endl;
		vector<pair<string, ll>> strings;
		//every number of distinct letters that is possible
		for(ll numDistinct = 1; numDistinct <= 26; ++numDistinct){
			if(n % numDistinct){
				continue;
			}
			ll availablePos = n / numDistinct; //the number of positions to put the letter in
			
			//keep track of number of matches and the final string
			ll matches = 0;
			string fina1(n, ' ');
			vector<char> leftOver;
			for(ll i = 0; i < numDistinct; ++i){ //choose the letters with the highest frequency to keep
				ll charNum = countv[i].first - 'a';
				for(ll pos = 0; pos < availablePos; ++pos){
					if(pos < occ[charNum].size()){
						fina1[occ[charNum][pos]] = (char)('a' + charNum);
						++matches;
					}else{
						leftOver.push_back((char)('a' + charNum));
					}
				}
			}
			//cout <<"asj" << endl;
			for(char& c : fina1){
				if(c == ' '){
					c = leftOver.back();
					leftOver.pop_back();
				}
			}
			strings.push_back({fina1, matches});
			//cout << "6try" << endl;
		}
		
		sort(strings.begin(), strings.end(), [](const auto& a, const auto& b) {
			return a.second > b.second; 
		});
		cout << n - strings[0].second << endl << strings[0].first << endl;
	}
}
