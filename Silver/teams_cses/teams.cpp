#include <iostream>
#include <vector>

using namespace std;

struct Pupil{
	vector<Pupil*> friends;
	int team = 0; //0: not assigned, 1: team 1, 2: team 2
};

//level is useless
bool recurse(Pupil* start, int setTeam, int level){ //immediatele stop if impossible
	start->team = setTeam;
	//check validity
	for(Pupil* f : start->friends){
		if(setTeam == f->team){
			return false;
		}
	}
	//valid,recurse next level.
	if(setTeam == 1){
		for(Pupil* f : start->friends){
			if(!f->team){
				if(!recurse(f, 2, level + 1)){
					return false;
				}
			}
		}
	}
	if(setTeam == 2){
		for(Pupil* f : start->friends){
			if(!f->team){
				if(!recurse(f, 1, level + 1)){
					return false;
				}
			}
		}
	}
	return true;
}

int main(){
	int numPupils, numFriendships;
	cin >> numPupils >> numFriendships;
	vector<Pupil*> pupils(numPupils);
	for(int i = 0; i < numPupils; ++i){
		pupils[i] = new Pupil;
	}
	for(int i = 0; i < numFriendships; ++i){
		int a, b;
		cin >> a >> b;
		pupils[a - 1]->friends.push_back(pupils[b - 1]);
		pupils[b - 1]->friends.push_back(pupils[a - 1]);
	}
	for(int i = 0; i < numPupils; ++i){
		if(pupils[i]->team == 0){
			if(!recurse(pupils[i], 1, 0)){
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
		}
	}
	for(Pupil* p : pupils){
		cout << p->team << " ";
	}
	return 0;
}
