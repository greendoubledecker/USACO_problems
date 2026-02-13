#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int	n;
		cin>>n;
		vector<int>v(n);
		vector<bool>b(n-1,true);
		int s=0;
		for(int i=0;i<n;++i){
			cin>>v[i];
			s+=v[i];
		}if(s%2)cout<<"-1\n";
		else{
			if(s>0){
				int i=1,j=0;
				for(;i<n;++i){
					if(v[i]==1){
						b[i-1]=false;
						++j;
						++i;
					}
					if(j>=s/2)break;
				}
			}else if(s<0){
				int i=1,j=0;
				for(;i<n;++i){
					if(v[i]==-1){
						b[i-1]=false;
						++j;
						++i;
					}
					if(j>=-s/2)break;
				}
			}
			vector<int>c;
			for(int i=0;i<n-1;++i){
				if(b[i])c.push_back(i);
			}
			if(c.size() == 0){
				cout<<"1\n1 "<<n<<'\n';continue;
			}
			cout<<c.size()+1<<endl;
			cout<<"1 "<<c[0]+1<<'\n';
			for(int i=1;i<c.size();++i){
				cout<<c[i-1]+2<<' '<<c[i]+1<<'\n';
			}
			cout<<c[c.size()-1]+2<<' '<<n<<'\n';
		}
	}
}
