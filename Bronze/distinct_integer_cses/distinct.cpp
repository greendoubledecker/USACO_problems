#include <iostream>
#include <set>

using namespace std;

int main(){
	set<int> moos;
	int numMoos;
	cin >> numMoos;
	for(int i = 0; i < numMoos; ++i){
		int moo;
		cin >> moo;
		moos.insert(moo);
	}
	cout << moos.size() << endl;
	return 0;
}
