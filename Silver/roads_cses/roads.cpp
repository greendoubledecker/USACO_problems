#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct City{
	int index;
	vector<City*> neighbors;
	bool visited = false;
};

void recurse(City* start){
	//cout << "recursing city " << start->index << endl;
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
		//cout << "setting index to " << i << endl;
		c->index = i;
		cities.push_back(c);
		//cout << "the index is " << cities[i]->index << endl;
	}
	//cout << "first loop done" << endl;
	
	for(int i = 0; i < numRoads; ++i){
		int a, b;
		cin >> a >> b;
		cities[a - 1]->neighbors.push_back(cities[b - 1]);
		cities[b - 1]->neighbors.push_back(cities[a - 1]);
	}
	
	//cout << "setup done" << endl;
	vector<int> connect;
	for(int i = 0; i < numCities; ++i){
		//cout << "city " << i << " has index " << cities[i]->index << endl;
		if(!cities[i]->visited){
			//cout << "city " << i << " has not been visited." << endl;
			//cout << "its index is " << cities[i]->index << endl;
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
