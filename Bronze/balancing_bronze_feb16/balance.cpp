#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void balance(vector<pair<int, int>> cows){
	int currCows = 0;
	int horInd = 0; // east-west fence
	int horPlus;
	int plusCows;
	long long sum = 0;
	for(pair<int, int> cow : cows){
		sum += cow.second;
	}
	while (currCows < sum / cows.size()){
		horInd += 2;
		for(pair<int, int> cow : cows){
			if(cow.second == horInd - 1){
				currCows ++;
			}
		}
		//cout << "index: " << horInd << "horInd currentcows: " << currCows << endl;
	}
	plusCows = currCows;
	horPlus = horInd;
	while (plusCows < sum / cows.size() + 1){
		horPlus += 2;
		for(pair<int, int> cow : cows){
			if(cow.second == horPlus - 1){
				plusCows ++;
			}
		}
	}
	cout << "currCows" << currCows << " plusCows" << plusCows << endl;
	currCows = 0;
	sum = 0;
	for(pair<int, int> cow : cows){
		sum += cow.first;
	}
	int vertInd = 0; // north-south fence
	int vertPlus;
	while (currCows < sum / cows.size()){
		vertInd += 2;
		for(pair<int, int> cow : cows){
			if(cow.first == vertInd - 1){
				currCows ++;
			}
		}
		cout << "index: " << vertInd << "vertInd currentcows: " << currCows << endl;
	}
	plusCows = currCows;
	vertPlus = vertInd;
	while (plusCows < sum / cows.size() + 1){
		cout << "more things already" << endl;
		vertPlus += 2;
		for(pair<int, int> cow : cows){
			if(cow.first == vertPlus - 1){
				plusCows ++;
			}
		}
		cout << "index: " << vertPlus << "vertPlus currentcows: " << plusCows << endl;
	}
	cout << "currCows" << currCows << " plusCows" << plusCows << endl;
	
	cout << "horInd: " << horInd << endl << "vertInd: " << vertInd << endl << "horPlus: " << horPlus << endl << "vertPlus: " << vertPlus << endl;
	int NE = 0, NW = 0, SE = 0, SW = 0;
	for(pair<int, int> cow : cows){
		if(cow.first > vertInd){
			if(cow.second > horInd){
				NW ++;
			}else{
				SW ++;
			}
		}else{
			if(cow.second > horInd){
				NE ++;
			}else{
				SE ++;
			}
		}
	}
	cout << "AA-" << NE << " " << NW << " " << SE << " " << SW << endl; 
	int AA = max({NE, NW, SE, SW});
	
	NE = 0, NW = 0, SE = 0, SW = 0;
	for(pair<int, int> cow : cows){
		if(cow.first > vertPlus){
			if(cow.second > horInd){
				NW ++;
			}else{
				SW ++;
			}
		}else{
			if(cow.second > horInd){
				NE ++;
			}else{
				SE ++;
			}
		}
	}
	cout << "AB-" << NE << " " << NW << " " << SE << " " << SW << endl; 
	int AB = max({NE, NW, SE, SW});
	
	NE = 0, NW = 0, SE = 0, SW = 0;
	for(pair<int, int> cow : cows){
		if(cow.first > vertInd){
			if(cow.second > horPlus){
				NW ++;
			}else{
				SW ++;
			}
		}else{
			if(cow.second > horPlus){
				NE ++;
			}else{
				SE ++;
			}
		}
	}
	cout << "BA-" << NE << " " << NW << " " << SE << " " << SW << endl; 
	int BA = max({NE, NW, SE, SW});
	
	NE = 0, NW = 0, SE = 0, SW = 0;
	for(pair<int, int> cow : cows){
		if(cow.first > vertPlus){
			if(cow.second > horPlus){
				NW ++;
			}else{
				SW ++;
			}
		}else{
			if(cow.second > horPlus){
				NE ++;
			}else{
				SE ++;
			}
		}
	}
	cout << "BB-" << NE << " " << NW << " " << SE << " " << SW << endl; 
	int BB = max({NE, NW, SE, SW});
	cout << min({AA, AB, BA, BB}) << endl;
}

int main(){
	int numCows, max;
	cin >> numCows >> max;
	vector<pair<int, int>> cows;
	for(int i = 0; i < numCows; ++i){
		pair<int, int> cow;
		cin >> cow.first >> cow.second;
		cows.push_back(cow);
	}
	balance(cows);
	return 0;
}
