#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> airconOn;
vector<vector<int>> cows, aircon; //cows: 0 = start, 1 = end, 2 = temperature. ac: 0 = start, 1 = end, 2 = temperature, 3 = price.
int minCost = 10000;
int N, M;

void recurse(int level){
	if(level == M){
		//cout << "combination: ";
		bool works = true;
		vector<int> cooling(100, 0);
		int cost = 0;
		for(vector<int> ac : airconOn){
			//cout << ac[0] << ", " << ac[1] << ", " << ac[2] << ", " << ac[3] << endl;
			cost += ac[3];
			for(int stall = ac[0]; stall <= ac[1]; ++stall){
				cooling[stall] += ac[2];
			}
		}
		for(vector<int> cow : cows){
			//check if cow is comfortable
			bool comfortable = true;
			for(int stall = cow[0]; stall <= cow[1]; ++stall){
				if(cooling[stall] < cow[2]){
					comfortable = false;
					break;
				}
			}
			if(!comfortable){
				works = false;
				break;
			}
		}
		if(works){
			//cout << "this works" << endl;
			//cout << "cost: " << cost << endl;
			if(cost < minCost){
				minCost = cost;
			}
		}else{
			//cout << "does not work" << endl;
		}
	}else{
		recurse(level + 1);
		airconOn.push_back(aircon[level]);
		recurse(level + 1);
		airconOn.pop_back();
	}
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; ++i){
		int start, end, temp;
		cin >> start >> end >> temp;
		cows.push_back(vector<int>{start, end, temp});
	}
	for(int i = 0; i < M; ++i){
		int start, end, temp, cost;
		cin >> start >> end >> temp >> cost;
		aircon.push_back(vector<int>{start, end, temp, cost});
	}
	recurse(0);
	cout << minCost << endl;
	return 0;
}
