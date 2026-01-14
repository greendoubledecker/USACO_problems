#include <iostream>
#include <vector>
#include <string>

using namespace std;


void tc(){
	int N;
	cin >> N;
	vector<int> input;
	vector<bool> has(3);
	for(int i = 0; i < N; ++i){
		char a, b, c;
		cin >> a >> b >> c;
		if(a == 'C'){
			input.push_back(0);
			has[0] = true;
		}else if(a == 'O'){
			input.push_back(1);
			has[1] = true;
		}else{
			input.push_back(2);
			has[2] = true;
		}
	}
	if(N % 2 == 1){
		cout << -1 << endl;
	}else{
		if(has[1] && has[2] && has[3]){
			cout << 3 << endl;
			for(int i = 0; i < N; ++i){
				if(i == N - 1){
					if(input[i] == 0){
						cout << "1 2 3" << endl;
					}else if(input[i] == 1){
						cout << "2 3 1" << endl;
					}else{
						cout << "3 1 2" << endl;
					}
				}else{
					if(input[i] == 0){
						cout << "1 2 3" << " ";
					}else if(input[i] == 1){
						cout << "2 3 1" << " ";
					}else{
						cout << "3 1 2" << " ";
					}
				}
			}
		}else if(has[0] && has[1] && !has[2]){
			cout << 2 << endl;
			for(int i = 0; i < N; ++i){
				if(i == N - 1){
					if(input[i] == 0){
						cout << "2 1 1" << endl;
					}else{
						cout << "1 1 2" << endl;
					}
				}else{
					if(input[i] == 0){
						cout << "2 1 1" << " ";
					}else{
						cout << "1 1 2" << " ";
					}
				}
			}
		}else if(has[0] && !has[1] && has[2]){
			cout << 2 << endl;
			for(int i = 0; i < N; ++i){
				if(i == N - 1){
					if(input[i] == 0){
						cout << "1 1 2" << endl;
					}else{
						cout << "2 1 1" << endl;
					}
				}else{
					if(input[i] == 0){
						cout << "1 1 2" << " ";
					}else{
						cout << "2 1 1" << " ";
					}
				}
			}
		}else if(!has[0] && has[1] && has[2]){
			cout << 2 << endl;
			for(int i = 0; i < N; ++i){
				if(i == N - 1){
					if(input[i] == 1){
						cout << "2 1 1" << endl;
					}else{
						cout << "1 1 2" << endl;
					}
				}else{
					if(input[i] == 1){
						cout << "2 1 1" << " ";
					}else{
						cout << "1 1 2" << " ";
					}
				}
			}
		}else{
			cout << 1 << endl;
			for(int i = 0; i < N; ++i){
				if(i == N - 1){
					cout << "1 1 1" << endl;
				}else{
					cout << "1 1 1 ";
				}
			}
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
