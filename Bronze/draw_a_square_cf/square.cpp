#include <bits/stdc++.h>
using namespace std;
void tc(){
	int a,b,c,d;
	cin >> a >>b >> c >> d;
	if(a != b){
		cout << "No\n";
	}else if(a != c){
		cout	 << "No\n";
	}else if(a !=d){
		cout << "No\n";
	}else{
		cout << "Yes\n";
	}
}
int main(){
	int t;
	cin >>t;
	while(t--)tc();
 }
