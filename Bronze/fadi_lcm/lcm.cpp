//IMPORTANT NOTE: ONLY RUNS IN C++17 OR LATER(e.g. C++23)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n;
	cin>>n;
	for(ll i=sqrt(n);i>0;--i){
		if(lcm(i,n/i)==n){
			cout<<i<<' '<<n/i<<'\n';
			break;
		}
	}
}
