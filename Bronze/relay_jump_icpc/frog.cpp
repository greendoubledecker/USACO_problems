#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
	int n, s;
	cin >> n >> s;
	--s;
	int totalx = 0;
	int totaly = 0;
	vector<pair<int, int>> start, end;
	
	for(int i = 0; i < n; ++i){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		totalx += c - a;
		totaly += d - b;
		start.push_back({a, b});
		end.push_back({c, d});
	}
	
	int endx, endy;
	endx = totalx;
	endy = totaly;
	endx += 2 * start[s].first;
	endy += 2 * start[s].second;
	endx /= 2;
	endy /= 2;
	
	for(int i = 0; i < n; ++i){
		if(end[i].first == endx && end[i].second == endy){
			cout << i + 1 << endl;
			return 0;
		}
	}
}
