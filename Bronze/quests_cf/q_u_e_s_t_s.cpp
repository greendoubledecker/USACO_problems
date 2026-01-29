#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,ps[200001];
		cin>>n>>k>>ps[0];
		for(int i=1;i<n;++i){
			int a;
			cin>>a;
			ps[i]=ps[i-1]+a;
		}
		int ans=0;
		int m=0;
		for(int i=0;i<n;++i){
			int b;
			cin>>b;
			if(i>=k)continue;
			m=max(m,b);
			ans=max(ans,ps[i]+(k-i-1)*m);
		}
		cout<<ans<<endl;
	}
}
