#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if(s[s.size() - 1] - '0'){
			cout << "B\n";
		}else{
			cout << "E\n";
		}
	}
}
