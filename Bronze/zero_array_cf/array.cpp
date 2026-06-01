#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n;
	cin >> n;
	ll sum = 0;
	ll maxx = 0;
	for(ll i = 0; i < n; ++i){
		ll x;
		cin >> x;
		sum += x;
		maxx = max(maxx,x);
	}
	if(sum % 2 == 0 && maxx <= sum - maxx){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}
//each operation, 2 is subtracted from the sum
//if the sum is odd, the answer is clearly no.
//if maxx > sum-maxx then if this maximum value is always included, it still won't be 0 by the end.
//Else, you can always pair the largest element with the second-largest element and repeat until allelements are 0.
