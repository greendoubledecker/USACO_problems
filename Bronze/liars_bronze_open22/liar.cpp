#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main(){
	map<int, bool> isRight;
	int num;
	cin >> num;
	vector<int> testLocs;
	for(int i = 0; i < num; ++i){
		char c;
		cin >> c;
		int n;
		cin >> n;
		if(c == 'G'){
			isRight[n] = true;
		}
		if(c == 'L'){
			isRight[n] = false;
		}
		testLocs.push_back(n);
	}
	int min = 1001;
	for(int i : testLocs){
		int liars = 0;
		for(pair<int, bool> p : isRight){
			if(p.first < i && p.second == false) ++liars;
			if(p.first > i && p.second == true ) ++liars;
		}
		if(liars < min) min = liars;
	}
	cout << min << endl;
	return 0;
}
