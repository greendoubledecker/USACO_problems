#include <iostream>
#include <vector>

using namespace std;

int main(){
	int num, ind; //input index is 1-based
	cin >> num >> ind;
	ind --;
	int behind = num - ind - 1;
	int infront = ind;
	int steps = 0;
	while(true){
		int stepsToFront = infront/3; //this is the number of FULL steps
		steps += infront + 1;
		behind += stepsToFront;
		infront -= 3 * stepsToFront;
		if(infront == 0){
			cout << "Yes" << endl;
			cout << steps << endl;
			return 0;
		}
		if(infront == 1){
			cout << "No" << endl;
			cout << steps << endl;
			return 0;
		}
		if(infront == 2){
			infront = behind;
			behind = 0;
		}
	}
}
