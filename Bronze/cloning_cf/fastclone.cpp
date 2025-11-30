#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	string input;
	long long length, time, cost;
	cin >> length >> time >> cost >> input;
	long long a = 0, b = 0, m = 0, e = 0; //a is the coefficient of p, the amount of cows per click. b is the coefficient of c, the upgrade cost. m is the difference in p before and after. e is the extra cows.
	for(char c : input){
		if(c == 'U'){
			++b;
			++m;
		}else{
			++a;
			e += m;
		}
	}
	//cout << "a "<< a << " b " << b << " m " << m << " e " << e << endl;
	long long fullRounds = time/length;
	long long cows = 0, p = 1;
	for(long long i = 0; i < fullRounds; ++i){
		cows += a * p;
		cows += e;
		cows -= b * cost;
		p += m;
	}
	for(long long i = 0; i < time % length; ++i){
		if(input[i] == 'U'){
			++p;
			cows -= cost;
		}else{
			cows += p;
		}
	}
	cout << cows << endl;
	return 0;
}
