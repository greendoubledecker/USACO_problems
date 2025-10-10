#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void balance(vector<pair<int, int>> cows){
	sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    vector<pair<int, int>> xSorted = cows;
    sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    vector<pair<int, int>> ySorted = cows;
    int min = 100;
    for(int i = 0; i < xSorted.size(); ++i){
		int vertLine = xSorted[i].first + 1;
		for(int j = 0; j < ySorted.size(); ++j){
			int horLine = ySorted[j].second + 1;
			int NE = 0, NW = 0, SE = 0, SW = 0;
			for(pair<int, int> cow : cows){
				if(cow.first > vertLine){
					if(cow.second > horLine){
						NW ++;
					}else{
						SW ++;
					}
				}else{
					if(cow.second > horLine){
						NE ++;
					}else{
						SE ++;
					}
				}
			}
			int score = max({NE, NW, SE, SW});
			if(score < min){
				min = score;
			}
		}
	}
	cout << min << endl;
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
