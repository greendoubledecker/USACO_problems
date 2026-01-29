#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool works(ll size, vector<ll> stripes){
	ll sum = 0; //max number of rows/cols that I can cover
	bool allTwo = true; //size has to be even if they are all 0,1,or 2
	for(ll s : stripes){
		if(s >= 2){ //stripes must be at least 2-wide
			if(s > 2){
				allTwo = false;
			}
			sum += s;
		}
	}
	//cout << "sum= "<< sum << " size = " << size << endl;
	if(allTwo){
		return sum >= size && !(size % 2);
	}else{
		return sum >= size;
	}
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		ll k;
		cin >> k;
		vector<ll> pigments(k);
		for(ll i = 0; i < k; ++i){
			cin >> pigments[i];
		}
		vector<ll> horStripes(k); //width of the horizontal stripes
		//cout << "horizontal" << endl;
		for(ll i = 0; i < k; ++i){
			horStripes[i] = pigments[i] / m; //divide by row length
			//cout << horStripes[i] << " ";
		}
		vector<ll> verStripes(k); //vertical stripes
		//cout << "\nvertical" << endl;
		for(ll i = 0; i < k; ++i){
			verStripes[i] = pigments[i] / n;
			//cout << verStripes[i] << " ";
		}
		if(works(n, horStripes) || works(m, verStripes)){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}
}
