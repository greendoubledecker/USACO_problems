#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> zodiac = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

int main(){
	int num;
	cin >> num;
	string n;
	unordered_map<string, int> years;
	years.insert({"Bessie", 0});
	for(int i = 0; i < num; ++i){
		string cow1, cow2;
		int zod; //index in zodiac
		bool dir; //false is prev, true is next
		string prevnext, zodName;
		
		cin >> cow1 >> n >> n >> prevnext >> zodName >> n >> n >> cow2;
		if(prevnext == "next"){
			dir = true;
		}else{
			dir = false;
		}
		zod = find(zodiac.begin(), zodiac.end(), zodName) - zodiac.begin();
		int val;
		if(dir){
			val = years[cow2] + ((zod - years[cow2]) % 12 + 12) % 12;
			if(val == years[cow2]){
				val += 12;
			}
		}else{
			val = years[cow2] - ((years[cow2] - zod) % 12 + 12) % 12;
			if(val == years[cow2]){
				val -= 12;
			}
		}
		//cout << cow1 << " was born in year " << val << endl;
		if(cow1 == "Elsie"){
			if(val < 0){
				cout << -val << endl;
			}else{
				cout << val << endl;
			}
			return 0;
		}
		years.insert({cow1, val});
	}
}
