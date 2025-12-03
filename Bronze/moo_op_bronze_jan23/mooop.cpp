#include <iostream>
#include <string>

using namespace std;

int main(){
	int tc;
	cin >> tc;
	for(int i = 0; i < tc; ++i){
		string s;
		cin >> s;
		if(s.find("MOO") != string::npos){
			cout << s.size() - 3 << endl;
			continue;
		}
		if(s.find("MOM") != string::npos || s.find("OOO") != string::npos){
			cout << s.size() - 2 << endl;
			continue;
		}
		if(s.find("OOM") != string::npos){
			cout << s.size() - 1 << endl;
			continue;
		}
		cout << -1 << endl;
	}
	return 0;
}
