#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct City{
	vector<City*> neighbors;
	bool visited = false;
};

void recurse(City* start){
	start->visited = true;
	for(City* c : start->neighbors){
		if(!c->visited){
			recurse(c);
		}
	}
}

int main(){
	int numCities;
	cin >> numCities;
	int numRoads;
	cin >> numRoads;
	vector<City*> cities;
	for(int i = 0; i < numCities; ++i){
		City* c = new City;
		cities.push_back(c);
	}
	
	for(int i = 0; i < numRoads; ++i){
		int a, b;
		cin >> a >> b;
		cities[a - 1]->neighbors.push_back(cities[b - 1]);
		cities[b - 1]->neighbors.push_back(cities[a - 1]);
	}
	
	vector<int> connect;
	for(int i = 0; i < numCities; ++i){
		if(!cities[i]->visited){
			recurse(cities[i]);
			connect.push_back(i);
		}
	}
	cout << connect.size() - 1 << endl;
	for(int i = 0; i < connect.size() - 1; ++i){
		cout << connect[i] + 1 << " " << connect[i + 1] + 1 << endl;
	}
	return 0;
}
