#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> cowStop(int eastx, int easty, int northx, int northy){
	int northdist = easty - northy;
	int eastdist = northx - eastx;
	if(northdist < 0 || eastdist < 0){
		return {2, -1}; //no stopping cows
	}
	if(northdist < eastdist){
		return {0, eastdist}; //east stopped
	}
	if(eastdist < northdist){
		return {1, northdist}; //north stopped
	}
	if(eastdist == northdist){
		return {2, -1}; // share the cell
	}
}

void rut(vector<int> northcows, vector<int> eastcows, vector<pair<int, int>> original){
	sort(northcows.begin(), northcows.end(),
	[&original](int cow1, int cow2){
		return original[cow1].first < original[cow2].first;
	});
	sort(eastcows.begin(),  eastcows.end(),
	[&original](int cow1, int cow2){
		return original[cow1].second < original[cow2].second;
	});
	vector<int> outs(original.size(), -1);
	for(auto east : eastcows){
		//cout << "east: " << original[index].first << ", " << original[index].second << endl;
		for(auto north : northcows){
			if(outs[north] == -1){
				pair<int, int> stop = cowStop(original[east].first, original[east].second, original[north].first, original[north].second);
				if(stop.first == 0){
					outs[east] = stop.second;
					break;
				}
				if(stop.first == 1){
					outs[north] = stop.second;
				}
			}
		}
	}
	
	for(int out : outs){
		if(out == -1){
			cout << "Infinity" << endl;
		}else{
			cout << out << endl;
		}
	}
}

int main(){
	int n; 
	cin >> n;
	vector<pair<int, int>> original;
	vector<int> east, north;
	for(int i = 0; i < n; ++i){
		char direction;
		cin >> direction;
		pair<int, int> coords;
		cin >> coords.first >> coords.second;
		original.push_back(coords);
		if(direction == 'E'){
			east.push_back(i);
		}
		if(direction == 'N'){
			north.push_back(i);
		}
	}
	rut(north, east, original);
	return 0;
}
