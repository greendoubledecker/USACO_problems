#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
ll t;
cin>>t;
while(t--){
ll n;
cin>>n;
ll i=2;
while(!(n%i)){++i;}
cout<<i-1<<endl;
}
}
