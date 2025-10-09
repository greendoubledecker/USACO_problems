#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void fireLifeguard(vector<pair<int, int>> lifeguards){
	int maxTime = 0;
	for(int fire = 0; fire < lifeguards.size(); ++fire){
		int time = 0;
		cout << "fire: " << fire << endl << "Timesteps: ";
		for(int step = 0; step < 1000; ++step){
			for(int lifeguard = 0; lifeguard < lifeguards.size(); ++lifeguard){
				if(lifeguard != fire && lifeguards[lifeguard].first <= step && step < lifeguards[lifeguard].second){
					time++;
					cout << step << " ";
					break;
				}
			}
		}
		cout << endl;
		if(time > maxTime){
			maxTime = time;
		}
	}
	cout << maxTime;
}

int main(){
	int lg;
	vector<pair<int, int>> lifeguards;
	cin >> lg;
	for(int i = 0; i < lg; ++i){
		pair<int, int> lifeguard;
		cin >> lifeguard.first >> lifeguard.second;
		lifeguards.push_back(lifeguard); 
	}
	fireLifeguard(lifeguards);
	return 1;
}
