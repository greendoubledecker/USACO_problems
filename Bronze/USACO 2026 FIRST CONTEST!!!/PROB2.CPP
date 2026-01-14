#include <iostream>
#include <vector>
#include <string>

using namespace std;


void tc(){
	int N;
	cin >> N;
	string s;
	cin >> s;
	if(N % 2 == 1){
		cout << -1 << endl;
	}else{
		string left = s.substr(0, 3 * N / 2);
		string right = s.substr(3 * N / 2);
		if(left == right){
			cout << 1 << endl;
			for(int i = 0; i < 3 * N; ++i){
				cout << 1;
				if(i != 3 * N - 1){
					cout << " ";
				}
			}
			cout << endl;
			return;
		}else{
			//all except C go in group 1.
			string g1;
			for(int i = 0; i < 3 * N; ++i){
				if(s[i] != 'C'){
					g1.push_back(s[i]);
				}
			}
			string firstHalf = g1.substr(0, g1.size() / 2);
			string secHalf = g1.substr(g1.size() / 2);
			if(firstHalf == secHalf){
				cout << 2 << endl;
				for(int i = 0; i < 3 * N - 1; ++i){
					if(s[i] != 'C'){
						cout << 1 << " ";
					}else{
						cout << 2 << " ";
					}
				}
				int i = 3 * N - 1;
				if(s[i] != 'C'){
					cout << 1 << endl;
				}else{
					cout << 2 << endl;
				}
				return;
			}
			
			//all except O go in group 1.
			g1 = "";
			for(int i = 0; i < 3 * N; ++i){
				if(s[i] != 'O'){
					g1.push_back(s[i]);
				}
			}
			firstHalf = g1.substr(0, g1.size() / 2);
			secHalf = g1.substr(g1.size() / 2);
			if(firstHalf == secHalf){
				cout << 2 << endl;
				for(int i = 0; i < 3 * N - 1; ++i){
					if(s[i] != 'O'){
						cout << 1 << " ";
					}else{
						cout << 2 << " ";
					}
				}
				int i = 3 * N - 1;
				if(s[i] != 'O'){
					cout << 1 << endl;
				}else{
					cout << 2 << endl;
				}
				return;
			}
			
			//all except W go in group 1.
			g1 = "";
			for(int i = 0; i < 3 * N; ++i){
				if(s[i] != 'W'){
					g1.push_back(s[i]);
				}
			}
			firstHalf = g1.substr(0, g1.size() / 2);
			secHalf = g1.substr(g1.size() / 2);
			if(firstHalf == secHalf){
				cout << 2 << endl;
				for(int i = 0; i < 3 * N - 1; ++i){
					if(s[i] != 'W'){
						cout << 1 << " ";
					}else{
						cout << 2 << " ";
					}
				}
				int i = 3 * N - 1;
				if(s[i] != 'W'){
					cout << 1 << endl;
				}else{
					cout << 2 << endl;
				}
				return;
			}
			
			cout << 3 << endl;
			for(int i = 0; i < 3 * N - 1; ++i){
				if(s[i] == 'C'){
					cout << 1 << " ";
				}
				if(s[i] == 'O'){
					cout << 2 << " ";
				}
				if(s[i] == 'W'){
					cout << 3 << " ";
				}
			}
			int i = 3 * N - 1;
			if(s[i] == 'C'){
				cout << 1 << " ";
			}
			if(s[i] == 'O'){
				cout << 2 << " ";
			}
			if(s[i] == 'W'){
				cout << 3 << " ";
			}
			cout << endl;
		}
	}
}

int main(){
	int t, k;
	cin >> t >> k;
	while(t--){
		tc();
	}
}
