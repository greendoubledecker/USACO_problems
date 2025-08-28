#include <iostream>

using namespace std;

int pails(){
	int pail1 = 0;
	int pail2 = 0;
	int pail3 = 0;
	cin >> pail1 >> pail2 >> pail3;
	int max = 0;
	for (int i = 0; i <= pail3; i += pail1){
		for (int j = i; j <= pail3; j += pail2){
			if (j > max){
				max = j;
			}
		}
	}
	return max;
}

int main(){
	int maxmilk = pails();
	cout << maxmilk << endl;
	return 0;
}
