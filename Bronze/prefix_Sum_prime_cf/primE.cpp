#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int c1=0;
int c2=0;
int i=0;
for(;i<n;++i){
int f;
cin>>f;
if(f-1){
++c2;
}
}
c1=n-c2;
if(c2){
cout<<"2 ";
--c2;
}
for(i=0;i<c1-!(c1%2);++i){
cout<<"1 ";
}
for(i=0;i<c2;++i){
cout<<"2 ";
}
if(!(c1%2)&&c1){
cout<<"1";
}
cout<<endl;
}
