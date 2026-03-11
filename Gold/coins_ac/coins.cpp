#include <bits/stdc++.h>
using namespace std;
using L=long;
using D=double;
int main(){
	L n;
	cin>>n;
	vector<vector<D>> p(n+1,vector<D>(n+1,0));
	p[0][0]=1;
	for(L i=1;i<=n;++i){
		D d;
		cin>>d;
		for(L j=0;j<=n;++j){
			p[i][j]=p[i-1][j]*(1-d);
			if(j)p[i][j]+=p[i-1][j-1]*d;
		}
	}
	D a=0.0;
	for(L i=n/2+1;i<=n;++i){
		a+=p[n][i];
	}
	cout<<fixed<<setprecision(9)<<a<<'\n';
}
