#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(){
	int numAnimals;
	cin >> numAnimals;
	vector<set<string>> characteristics;
	for(int i = 0; i < numAnimals; ++i){
		set<string> animalCharacteristics;
		string animal;
		cin >> animal;
		int numCharacteristics;
		cin >> numCharacteristics;
		for(int j = 0; j < numCharacteristics; ++j){
			string characteristic;
			cin >> characteristic;
			animalCharacteristics.insert(characteristic);
		}
		characteristics.push_back(animalCharacteristics);
	}
	int totalMax = 0;
	for(int i = 0; i < characteristics.size(); ++i){
		int max = 0;
		for(int j = 0; j < characteristics.size(); ++j){
			if(j != i){
				vector<string> intersection;
				set_intersection(characteristics[i].begin(), characteristics[i].end(), characteristics[j].begin(), characteristics[j].end(), back_inserter(intersection));
				if(intersection.size() > max){
					max = intersection.size();
				}
			}
		}
		if(max < characteristics[i].size()){
			max++;
		}
		if(max > totalMax){
			totalMax = max;
		}
	}
	cout << totalMax << endl;
	return 0;
}
