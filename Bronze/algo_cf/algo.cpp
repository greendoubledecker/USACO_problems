#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int num, time;
	cin >> num >> time;
	vector<int> algos;
	for(int i = 0; i < num; ++i){
		int algo;
		cin >> algo;
		algos.push_back(algo);
	}
	sort(algos.begin(), algos.end());
	int most = 0;
	for(int algo : algos){
		if(time < algo){
			break;
		}else{
			//cout << "time remaining: " << time << ", Amount learned: " << most << endl;
			most++;
			time -= algo;
		}
	}
	cout << most;
	return 0;
}
