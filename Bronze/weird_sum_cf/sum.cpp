#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll n, m;
	cin >> n >> m;
	
	//keep track of x- and y-coordinates of each colour
	vector<vector<ll>> xCoords(100001);
	vector<vector<ll>> yCoords(100001);
	for(ll i = 0; i < n; ++i){
		for(ll j = 0; j < m; ++j){
			ll colour;
			cin >> colour;
			xCoords[colour].push_back(j);
			yCoords[colour].push_back(i);
		}
	}
	
	ll totalSum = 0;
	
	//for every colour
	for(ll colour = 1; colour <= 100000; ++colour){
		//sort x coordinates(y coordinates are already sorted)
		sort(xCoords[colour].begin(), xCoords[colour].end());
		
		//compute sum of x-distances
		ll xSum = 0;
		ll prefix = 0; //keep a prefix sum of the previous values to subtract from xCoords[colour][i] * i
		for(ll i = 0; i < xCoords[colour].size(); ++i){
			xSum += i * xCoords[colour][i] - prefix; //subtract the prefix sum
			/* Diagram:
			 * i = 6
			 * xCoords[colour] = 0 0 2 3 3 4 5 7 7 (for example)
			 *                   -------------
			 *                     -----------
			 *                       ---------
			 *                         -------
			 *                           -----
			 *                             ---
			 * sum = 5 * 6 - (0 + 0 + 2 + 3 + 3 + 4)
			 * = 5 * 6 - prefix sum
			 */
			 prefix += xCoords[colour][i];
		}
		totalSum += xSum;
		
		
		
		//calculate y sum
		ll ySum = 0;
		prefix = 0;
		for(ll i = 0; i < yCoords[colour].size(); ++i){
			ySum += i * yCoords[colour][i] - prefix;
			prefix += yCoords[colour][i];
		}
		totalSum += ySum;
	}
	
	//output total sum
	cout << totalSum << endl;
}
