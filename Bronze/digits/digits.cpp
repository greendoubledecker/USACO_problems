#include <iostream>
#include <vector>
#include <string>

using namespace std;

int binToDec(vector<int> bin){
	int ans = 0;
	int pow2 = 1;
	for(int i = bin.size() - 1; i >= 0; --i){
		ans += bin[i] * pow2;
		pow2 *= 2;
	}
	return ans;
}

int terToDec(vector<int> ter){
	int ans = 0;
	int pow3 = 1;
	for(int i = ter.size() - 1; i >= 0; --i){
		ans += ter[i] * pow3;
		pow3 *= 3;
	}
	return ans;
}

int main(){
	string b2, b3;
	cin >> b2 >> b3;
	vector<int> binary(b2.size());
	for(int i = 0; i < b2.size(); ++i){
		if(b2[i] == '1'){
			binary[i] = 1;
		}else{
			binary[i] = 0;
		}
	}
	vector<int> ternary(b3.size());
	for(int i = 0; i < b3.size(); ++i){
		if(b3[i] == '2'){
			ternary[i] = 2;
		}else if(b3[i] == '1'){
			ternary[i] = 1;
		}else{
			ternary[i] = 0;
		}
	}
	for(int i = 0; i < b2.size(); ++i){
		for(int j = 0; j < b3.size(); ++j){
			vector<int> binWorks = binary;
			binWorks[i] = (binWorks[i] - 0.5) * -1 + 0.5;
			vector<int> terWorks1 = ternary, terWorks2 = ternary;
			if(ternary[j] == 0){
				terWorks1[j] = 1;
				terWorks2[j] = 2;
			}
			if(ternary[j] == 1){
				terWorks1[j] = 0;
				terWorks2[j] = 2;
			}
			if(ternary[j] == 2){
				terWorks1[j] = 0;
				terWorks2[j] = 1;
			}
			int terDec1 = terToDec(terWorks1);
			int terDec2 = terToDec(terWorks2);
			int binDec  = binToDec(binWorks );
			if(binDec == terDec1 || binDec == terDec2){
				cout << binDec << endl;
				return 0;
			}
		}
	}
}
