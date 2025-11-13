#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	int length, num, fj, bessie;
	cin >> length >> num >> fj >> bessie;
	int gain = fj - bessie;
	vector<pair<long long, long long>> stops;
	for(int i = 0; i < num; ++i){
		long long h, a;
		cin >> h >> a;
		stops.push_back({h, a});
	}
	long long loc = 0, taste = 0;
	while(stops.size() > 0){
		int max = 0, pos;
		long long removeInd;
		for(long long i = 0; i < stops.size(); ++i){
			pair<long long, long long> stop = stops[i];
			if(stop.second > max){
				max = stop.second;
				pos = stop.first;
				removeInd = i + 1;
			}
		}
		taste += max * (pos - loc) * gain;
		loc = pos;
		stops.erase(stops.begin(), stops.begin() + removeInd);
	}
	cout << taste << endl;
}
