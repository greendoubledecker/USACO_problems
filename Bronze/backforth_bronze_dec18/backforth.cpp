#include <iostream>
#include <vector>
#include <set>

using namespace std;

void printVec(vector<int> vec){
	for(int element : vec){
		 cout << element;
	}
	cout << endl;
}

int main(){
	vector<int> barn1(10), barn2(10); // can change number
	for(int& bucket : barn1){
		cin >> bucket;
	}
	for(int& bucket : barn2){
		cin >> bucket;
	}
	set<int> numbers;
	for(int tues = 0; tues < 10; ++tues){ //remember to change in loops
		//tuesday
		vector<int> day1barn1 = barn1, day1barn2 = barn2;
		int day1num = 1000 - day1barn1[tues];
		day1barn2.push_back(day1barn1[tues]);
		day1barn1.erase(day1barn1.begin() + tues);
		for(int weds = 0; weds < 11; ++weds){
			//wednesday
			vector<int> day2barn1 = day1barn1, day2barn2 = day1barn2;
			int day2num = day1num + day2barn2[weds];
			day2barn1.push_back(day2barn2[weds]);
			day2barn2.erase(day2barn2.begin() + weds);
			for(int thurs = 0; thurs < 10; ++thurs){
				//thursday
				vector<int> day3barn1 = day2barn1, day3barn2 = day2barn2;
				int day3num = day2num - day3barn1[thurs];
				day3barn2.push_back(day3barn1[thurs]);
				day3barn1.erase(day3barn1.begin() + thurs);
				for(int fri = 0; fri < 11; ++fri){
					//friday
					vector<int> day4barn1 = day3barn1, day4barn2 = day3barn2;
					int day4num = day3num + day4barn2[fri];
					day4barn1.push_back(day4barn2[fri]);
					day4barn2.erase(day4barn2.begin() + fri);
					numbers.insert(day4num);
				}
			}
		}
	}
	cout << numbers.size() << endl;
	return 0;
}
