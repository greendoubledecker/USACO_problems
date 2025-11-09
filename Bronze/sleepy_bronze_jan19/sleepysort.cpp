#include <iostream>
#include <vector>
using namespace std;

int main(){
	int num;
	cin >> num;
	vector<int> cows(num);
	for(int i = 0; i < num; ++i){
		cin >> cows[i];
	}
	int start = 0;
	for(int i = num - 1; i > 0; --i){
		if(cows[i - 1] > cows[i]){
			start = i;
			break;
		}
	}
	cout << start << endl;
}
