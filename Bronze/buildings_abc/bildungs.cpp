#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(){
	int n;
	cin>>n;
	vi h(n);
	vi a(n);
	vi s;
	for(int i=0;i<n;++i){
		cin >> h[i];
	}
	for(int i=n-1;i>=0;--i){
		a[i]=s.size();
		while(s.size()&&s[s.size()-1]<h[i])s.pop_back();
		s.push_back(h[i]);
	}
	for(int i=0;i<n;++i){
		cout<<a[i];
		if(n-1-i)cout<<' ';
	}
}
