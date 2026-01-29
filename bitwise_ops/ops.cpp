#include <iostream>
using namespace std;
int add(int a, int b){
	int sum = ((a & b) << 1) + (a ^ b);
	return sum;
}

int mul(int a, int b){
	int sum = 0;
	for(int i = 0; i < 32; ++i){
		int bit = (b & (1 << i)) >> i;
		if(bit){
			sum = add(sum, a << i);
		}
	}
	return sum;
}

int sub(int a, int b){
	return add(a, ~b + 1);
}

int quo(int a, int b){
	int count = 0;
	while(true){
		if((a & (1 << 31)) >> 31){
			break;
		}else{
			a = sub(a, b);
			count = add(count, 1);
		}
	}
	return sub(count, 1);
}

int mod(int a, int b){
	return a - mul(quo(a, b), b);
}

int main(){
	cout << mod(348539546, 34859692) << endl;
}
