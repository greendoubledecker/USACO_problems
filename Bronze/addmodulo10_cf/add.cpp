#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int p;
		cin>>p;--n;
		int c;
		bool b=1;
		while(n--){
			cin>>c;
			if((bool)(c%5)!=(bool)(p%5)){b=0;continue;}
			if(c%5==0&&p%5==0){
				if((c+5)/10!=(p+5)/10)b=0;
			}else{
				int q=p;
				int d=c;
				while(q%10!=2||d%10!=2){
					if(q%10!=2)q+=q%10;
					if(d%10!=2)d+=d%10;
				}
				if(q%20!=d%20){
					b=0;
				}
			}
			p=c;
		}
		cout<<(b?"Yes\n":"No\n");
	}
}
