#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits>

using namespace std;

int calcDist(int barnSize, int start, int end) {
    if (end - start >= 0){
		return end - start;
	}else{
		return barnSize - start + end;
	}
}

vector<int> getInput(){
    int numRooms;
    cin >> numRooms;
    vector<int> cowNumbers(numRooms);
    for(int i = 0; i < numRooms; i++){
        cin >> cowNumbers[i];
    }
    return cowNumbers;
}

int cbarn(){
    vector<int> input = getInput();
    int inpSize = (int)input.size();
    int minDist = numeric_limits<int>::max();
    int sum = 0;
    for(int i = 0; i < inpSize; i++){
	    for(int j = 0; j < inpSize; j++){
			sum += input[j] * calcDist(inpSize, i, j);
		}
		
		if(sum < minDist){
			minDist = sum;
		}
		sum = 0;
	}
	return minDist;
}

int main(){
	cout << cbarn() << endl;
	return 0;
}
