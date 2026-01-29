#include <iostream>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,m,r,c;
		cin>>n>>m>>r>>c;
		cout<<(m-1)*(n-r)+n*m-((r-1)*m+c)<<endl;
	}
}
