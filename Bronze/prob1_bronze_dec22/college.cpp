#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <functional>
#define lli long long

using namespace std;

int main(){
	lli numCows;
	cin >> numCows;
	vector<lli> cows;
	for(lli i = 0; i < numCows; ++i){
		lli cow;
		cin >> cow;
		cows.push_back(cow);
	}
	sort(cows.begin(), cows.end(), greater<int>());
	cows.push_back(0);
	lli tuition = LLONG_MAX;
	lli maxMoney = 0;
	for(lli i = 0; i < cows.size() - 1; ++i){
		if(cows[i] == cows[i + 1]){
			continue;
		}
		//cout << "charging $" << cows[i] << endl;
		lli money = 0;
		//cout << i + 1 << " cows are willing to pay" << endl;
 		money = (i + 1) * cows[i];
 		//cout << "this makes $" << money << endl;
		if(money >= maxMoney){
			maxMoney = money;
			tuition = cows[i];
		}
	}
	cout << maxMoney << " "  << tuition << endl;
	return 0;
}
