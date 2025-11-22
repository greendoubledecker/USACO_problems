#include <iostream>
#include <vector>

using namespace std;

int main(){
	int num, reps;
	cin >> num >> reps;
	int a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	--a1;
	--a2;
	--b1;
	--b2;
	vector<vector<int>> steps;
	vector<int> s1;
	for(int i = 0; i < num; ++i){
		s1.push_back(i + 1);
	}
	steps.push_back(s1);
	int step = 1;
	while(true){
		vector<int> next = steps[step - 1];
		for(int i = a1; i <= a2; ++i){
			next[i] = steps[step - 1][a2 - i + a1];
		}
		vector<int> next2 = next;
		for(int i = b1; i <= b2; ++i){
			next2[i] = next[b2 - i + b1];
		}
		steps.push_back(next2);
		++step;
		bool end = true;
		for(int i = 0; i < num; ++i){
			if(steps[step - 1][i] != i + 1){
				end = false;
				break;
			}
		}
		if(end){
			break;
		}
	}
	for(int i = 0; i < steps[0].size(); ++i){
		cout << steps[reps % (steps.size() - 1)][i] << endl;
	}
	return 0;
}
