#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	int n,k;
	cin>>n>>k;
	int count[k+1] = {0};
	while(n--){
		int c;
		cin>>c;
		++count[c];
	}
	for(int i=1;i<k;++i){
		if(count[i]%(i+1)){
			cout<<"No";return 0;
		}
		count[i+1]+=count[i]/(i+1);
	}
	cout<<"Yes";
}
