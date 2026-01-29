#include <iostream>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int x,y;
cin>>x>>y;
int d=x+y;
if(d%2){cout<<"-1 -1"<<endl;continue;}
if(x<y){
cout<<x<<" "<<y-d/2;
}else{
cout<<d/2<<" 0";
}
cout<<endl;
}
}
