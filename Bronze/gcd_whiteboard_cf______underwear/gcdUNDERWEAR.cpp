#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		map<ll,ll>c;
		ll m=1e18;
		for(ll i=0;i<n;++i){
			ll x;
			cin>>x;
			++c[x];
			m=min(m,x);
		}
		map<ll,ll>p;
		p[0]=c[0];
		for(ll i=1;i<n;++i){
			p[i]=p[i-1]+c[i];
		}
		for(ll g=n;g>0;--g){
			ll r=p[4*g-1];
			if(4*g-1>=n)r=n;
			r-=c[g]+c[2*g]+c[3*g];
			if(r<=k){cout<<g<<'\n';break;}
		}
	}
}
