/*
Sort explorers by e
Iterate from low e to high e
  Form groups with lowest values of e
  If there is a group that cannot be finished by the end, terminate the loop.

e.g. for sample 2 3 1 2 2:
Sort array: 1 2 2 2 3
First group: 1 2 2 2 3
             *
Second group: 1 2 2 2 3
                ***

Proof:
Let G be a group in an optimal solution.
Let x be the maximum e within that group.
If x is less than the size of G, we can remove unnecessary members.
This process does not decrease the number of groups, and also frees up other members to include in other groups.
Therefore, this process does not hurt optimality.
After removing G, we can see the remaining groups as a subproblem and repeat this strategy.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> e(n);
		for(ll &x : e){
			cin >> x;
		}
		sort(e.begin(), e.end());
		ll ans = 0;
		for(ll i = 0; i < n; ){
			ll maxe = e[i];
			ll right = i + e[i] - 1; //inclusive
			if(right >= n) break;
			bool flag = false;
			while(e[right] > maxe){
				maxe = e[right];
				right = i + maxe - 1;
				if(right >= n){
					flag = true;
					break;
				}
			}
			if(flag) break;
			++ans;
			i = right + 1;
		}
		cout << ans << endl;
	}
}
