#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	freopen("cowqueue.in", "r", stdin);
	freopen("cowqueue.out", "w", stdout);
	int num;
	cin >> num;
	vector<pair<int, int>> cows;
	for(int i = 0; i < num; ++i){
		int arrive, time;
		cin >> arrive >> time;
		cows.push_back({arrive, time});
	}
	sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b){
		return a.first < b.first;
	});
	//cout << "size is " << cows.size() << endl;
	int time = 0;
	for(int i = 0; i < num; ++i){
		//cout << "i is " << i << endl;
		time = max(time, cows[i].first) + cows[i].second;
		//cout << "after" << endl;
	}
	cout << time << endl;
}
