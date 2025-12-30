#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;

vector<int> reverse(vector<int> input, vector<int> output){
	vector<int> counts(N + 1);
	
	int starting = 0;
	for(int i = 0; i < N; ++i){
		if(input[i] == output[i]){
			++starting;
		}
	}
	counts[starting] = N;
	
	//do r - l is even
	for(int start = 0; start < N; ++start){
		int l = start;
		int r = start;
		int checked = starting;
		--l;
		++r;
		while(l >= 0 && r < N){
			if(input[l] == output[l]){
				if(input[l] != output[r]){
					--checked;
				}
			}else{
				if(input[l] == output[r]){
					++checked;
				}
			}
			if(input[r] == output[r]){
				if(input[r] != output[l]){
					--checked;
				}
			}else{
				if(input[r] == output[l]){
					++checked;
				}
			}
			++counts[checked];
			--l;
			++r;
		}
	}
	/*
	cout << "halfway:" << endl;
	for(int n : counts){
		cout << n << endl;
	}
	cout << endl;
	*/
	//now odd
	for(int start = 1; start < N; ++start){
		int l = start - 1;
		int r = start;
		int checked = starting;
		while(l >= 0 && r < N){
			if(input[l] == output[l]){
				if(input[l] != output[r]){
					--checked;
				}
			}else{
				if(input[l] == output[r]){
					++checked;
				}
			}
			if(input[r] == output[r]){
				if(input[r] != output[l]){
					--checked;
				}
			}else{
				if(input[r] == output[l]){
					++checked;
				}
			}
			++counts[checked];
			--l;
			++r;
		}
	}
	
	return counts;
}

int main(){
	cin >> N;
	vector<int> input(N), output(N);
	for(int i = 0; i < N; ++i){
		cin >> input[i];
	}
	for(int i = 0; i < N; ++i){
		cin >> output[i];
	}
	vector<int> answer = reverse(input, output);
	for(int n : answer){
		cout << n << endl;
	}
}
