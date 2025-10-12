#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

int main(){
	int N, M, D, S;
	cin >> N >> M >> D >> S;
	vector<pair<int, int>> sick;
	vector<vector<int>> drink;
	for(int i = 0; i < D; ++i){
		int p, m, t;
		cin >> p >> m >> t;
		drink.push_back(vector<int>{p, m, t});
	}
	for(int i = 0; i < S; ++i){
		pair<int, int> sickEvent;
		cin >> sickEvent.first >> sickEvent.second;
		sick.push_back(sickEvent);
	}
	sort(drink.begin(), drink.end(), [](vector<int> a, vector<int> b){
		return a[2] < b[2];
	});
	sort(sick.begin(), sick.end(), [](pair<int, int> a, pair<int, int> b){
		return a.second < b.second;
	});
	vector<set<int>> possiblyBad;
	for(pair<int, int> sickEvent : sick){
		set<int> sickDrink;
		for(int drinkIndex = 0; drinkIndex < drink.size(); drinkIndex++){
			if(drink[drinkIndex][0] == sickEvent.first && drink[drinkIndex][2] < sickEvent.second){
				sickDrink.insert(drink[drinkIndex][1]);
			} 
		}
		possiblyBad.push_back(sickDrink);
	}
	set<int> intersect = possiblyBad[0];
	for(int bad = 1; bad < possiblyBad.size(); ++bad){
		set<int> temp;
		set_intersection(intersect.begin(), intersect.end(), possiblyBad[bad].begin(), possiblyBad[bad].end(), inserter(temp, temp.begin()));
		intersect = temp;
	}
	int max = 0;
	for(int milk : intersect){
		set<int> sickPeople;
		for(int drinkIndex = 0; drinkIndex < drink.size(); drinkIndex++){
			if(drink[drinkIndex][1] == milk){
				sickPeople.insert(drink[drinkIndex][0]);
			}
		}
		if(sickPeople.size() > max){
			max = sickPeople.size();
		}
	}
	cout << max;
	return 0;
}
