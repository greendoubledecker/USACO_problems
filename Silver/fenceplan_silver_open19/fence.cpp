#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cow{
	vector<Cow*> neighbors;
	bool visited = false;
	int x = 0;
	int y = 0;
};

vector<int> recurse(Cow* start){
	start->visited = true;
	int left = start->x, right = start->x, top = start->y, bottom = start->y;
	for(Cow* c : start->neighbors){
		if(c->visited) continue;
		vector<int> next = recurse(c);
		left   = min(left  , next[0]);
		right  = max(right , next[1]);
		top    = max(top   , next[2]);
		bottom = min(bottom, next[3]);
	}
	return {left, right, top, bottom};
}

int perimeter(vector<int> coords){
	int height = coords[2] - coords[3];
	int width  = coords[1] - coords[0];
	return 2 * (height + width);
}

int main(){
	freopen("fenceplan.out", "w", stdout);
	freopen("fenceplan.in" , "r", stdin);
	int numCows, numMoos;
	cin >> numCows >> numMoos;
	vector<Cow*> cows;
	for(int i = 0; i < numCows; ++i){
		Cow* creating = new Cow;
		int x, y;
		cin >> x >> y;
		creating->x = x;
		creating->y = y;
		cows.push_back(creating);
	}
	for(int i = 0; i < numMoos; ++i){
		int a, b;
		cin >> a >> b;
		cows[a - 1]->neighbors.push_back(cows[b - 1]);
		cows[b - 1]->neighbors.push_back(cows[a - 1]);
	}
	int minn = 1000000000;
	for(Cow* c : cows){
		//cout << "loop" << endl;
		if(c->visited == false){
			int per = perimeter(recurse(c));
			if(per < minn){
				minn = per;
			}
		}
	}
	cout << minn << endl;
	return 0;
}
