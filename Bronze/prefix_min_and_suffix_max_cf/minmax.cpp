#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		int m=1e9;
		vector<bool> ans(n);
		int i=0;
		for(;i<n;++i){
			cin>>v[i];
			if(v[i]<m){
				m=v[i];
				ans[i]=true;
			}
		}
		--i;
		for(;i>=0;--i){
			if(v[i]>m){
				m=v[i];
				ans[i]=true;
			}
		}
		++i;
		for(;i<n;++i){
			cout<<ans[i];
		}
		cout<<endl;
	}
}
