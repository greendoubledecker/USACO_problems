#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		map<int,int> c;
		vector<int> v;
		while(n--){
			int e;
			cin>>e;
			++c[e];
			if(c[e]>1){v.push_back(e);c[e]=0;}
		}
		sort(v.begin(),v.end());
		int x=v.size();
		if(x<4){cout<<"NO\n";continue;}
		cout<<"YES\n"<<v[0]<<' '<<v[1]<<' '<<v[x-2]<<' '<<v[x-1]<<' '<<v[0]<<' '<<v[x-1]<<' '<<v[x-2]<<' '<<v[1]<<'\n';
	}
}
