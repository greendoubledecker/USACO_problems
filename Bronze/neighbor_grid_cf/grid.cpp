#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int r,c;
		cin>>r>>c;
		int n[r][c];
		fill(&n[0][0],&n[0][0]+(r*c),4);
		for(int i=0;i<r;++i){
			--n[i][0];
			--n[i][c-1];
		}
		for(int i=0;i<c;++i){
			--n[0][i];
			--n[r-1][i];
		}
		bool b=true;
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				int a;
				cin>>a;
				if(a>n[i][j])b=false;
			}
		}
		if(b){
			cout<<"YES\n";
			for(int i=0;i<r;++i){
				for(int j=0;j<c;++j){
					cout<<n[i][j]<<' ';
				}
				cout<<endl;
			}
		}else cout<<"NO"<<endl;
	}
}
