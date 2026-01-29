#include <bits/stdc++.h>
using namespace std;
int main(){
	string a, b;
	cin >> a >> b;
	if(a.size() != b.size()){
		cout << "NO\n";
		return 0;
	}
	bool aHasOnes = false, bHasOnes = false;
	for(int i = 0; i < a.size(); ++i){
		if(a[i] - '0'){
			aHasOnes = true;
		}
		if(b[i] - '0'){
			bHasOnes = true;
		}
	}
	if(aHasOnes == bHasOnes){
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
}
