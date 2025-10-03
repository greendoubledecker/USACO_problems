#include <iostream>
#include <vector>

using namespace std;

int speeding(vector<int> bessie, vector<int> limit){
	int record = 0;
	for(int i = 0; i < 100; ++i){
		if(bessie[i] - limit[i] > record){
			record = bessie[i] - limit[i];
		}
	}
	return record;
}

vector<int> construct(vector<int> dists, vector<int> lims){
	vector<int> vals;
	for(int i = 0; i < dists.size(); ++i){
		for(int j = 0; j < dists[i]; ++j){
			vals.push_back(lims[i]);
		}
	}
	return vals;
}

int main(){
	int N, M;
	vector<int> limdists, lims, bessdists, bessie;
	cin >> N >> M;
	for(int i = 0; i < N; ++i){
		int dist, lim;
		cin >> dist >> lim;
		limdists.push_back(dist);
		lims.push_back(lim);
	}
	for(int i = 0; i < M; ++i){
		int bessdist, bess;
		cin >> bessdist >> bess;
		bessdists.push_back(bessdist);
		bessie.push_back(bess);
	}
	cout << speeding(construct(bessdists, bessie), construct(limdists, lims)) << endl;
}
