#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		
		//count occurences
		map<ll, ll> count;
		for(int i = 0; i < n; ++i){
			ll a;
			cin >> a;
			++count[a];
		}
		
		//find mex
		ll mex;
		for(ll i = 0; i <= n; ++i){
			if(count[i] == 0){
				mex = i;
				break;
			}
		}
		
		//keep track of numbers that appear some # of times
		map<ll, vector<ll>> inverse;
		for(pair<ll, ll> p : count){
			inverse[p.second].push_back(p.first);
		}
		
		//keep trak of what mexes are possible
		set<ll> possibleMex;
		possibleMex.insert(mex);
		for(ll k = 0; k <= n; ++k){
			possibleMex.erase(n - k + 1); //this is now impossible because too many elements have been removed and mex <= array size
			for(ll i : inverse[k]){
				if(i <= mex && i <= n - k){ //has to be <= to the overall mex and <= to the size of the new array
					possibleMex.insert(i);
				}
			}
			cout << possibleMex.size() << " ";
		}
		cout << endl;
	}
}
