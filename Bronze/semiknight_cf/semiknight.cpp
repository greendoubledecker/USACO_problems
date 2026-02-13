#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int x1=9,y1,x2,y2;
		for(int i=0;i<8;++i){
			for(int j=0;j<8;++j){
				char c;
				cin>>c;
				if(c=='K'&&x1==9){x1=j;y1=i;}
				else if(c=='K'){x2=j;y2=i;}
			}
		}
		cout<<((x1-x2)%4||(y1-y2)%4?"NO\n":"YES\n");
	}
}
