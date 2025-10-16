#include <iostream>
#include <map>

using namespace std;

int main(){
	map<long long, long long> a;
	long long numMoos;
	cin >> numMoos;
	for(int i = 0; i < numMoos; ++i){
		//cout << "i" << i << endl;
		int mooType;
		cin >> mooType;
		if(mooType){
			//cout << "moooo" << endl;
			long long moo;
			cin >> moo;
			cout << a[moo] << endl;
		}else{
			long long mooIndex;
			long long moo;
			cin >> mooIndex >> moo;
			a[mooIndex] = moo;
		}
	}
	return 0;
}
