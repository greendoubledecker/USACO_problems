#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	string input;
	int length, time, cost;
	cin >> length >> time >> cost >> input;
	int step = 0;
	int make = 1;//how many cows it makes
	int cows = 0;
	while(true){
		if(input[step % length] == 'C'){
			cows += make;
		}
		if(input[step % length] == 'U'){
			cows -= cost;
			++make;
		}
		if(step == time - 1){
			cout << cows << endl;
			return 0;
		}
		++step;
	}
}
