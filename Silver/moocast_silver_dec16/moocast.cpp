#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

struct Cow{
	vector<int> neighbors; //the indices of the neighbors
	int x;
	int y;
	int p;
};

vector<Cow*> cows;
vector<bool> visited;

int recurse(int start){ //the index
	int canTransmit = 1;
	visited[start] = true;
	for(int cow : cows[start]->neighbors){
		if(!visited[cow]){
			canTransmit += recurse(cow);
		}
	}
	return canTransmit;
}

bool canSend(Cow* sender, Cow* receiver){
	double xDiff = abs(static_cast<double>(receiver->x) - sender->x);
	double yDiff = abs(static_cast<double>(receiver->y) - sender->y);
	double distance = sqrt(xDiff * xDiff + yDiff * yDiff);
	return distance <= static_cast<double>(sender->p);
}

int main(){
	freopen("moocast.out", "w", stdout);
	freopen("moocast.in", "r", stdin);
	int numCows;
	cin >> numCows;
	for(int i = 0; i < numCows; ++i){
		int x, y, p;
		cin >> x >> y >> p;
		cows.push_back(new Cow);
		cows[i]->x = x;
		cows[i]->y = y;
		cows[i]->p = p;
	}
	for(int i = 0; i < numCows; ++i){
		for(int j = 0; j < numCows; ++j){
			if(i != j){
				if(canSend(cows[i], cows[j])){
					cows[i]->neighbors.push_back(j);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < numCows; ++i){
		visited.push_back(false);
	}
	for(int i = 0; i < numCows; ++i){
		int receivers = recurse(i);
		ans = max(ans, receivers);
		for(int j = 0; j < numCows; ++j){
			visited[j] = false;
		}
	}
	cout << ans << endl;
	return 0;
}
