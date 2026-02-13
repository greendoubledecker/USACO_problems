#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int n;cin>>n;
bool g=0;
int a;cin>>a;
--n;
while(n--){int x;cin>>x;g=g||x<a;}
cout<<(g?"alice\n":"bob\n");
}
}
