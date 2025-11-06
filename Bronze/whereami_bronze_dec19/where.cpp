#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	int num;
	string road;
	cin >> num >> road;
	for(int len = 1; len < num; ++len){
		bool works = true;
		for(int leftSeq = 0; leftSeq < num - len; ++leftSeq){
			for(int rightSeq = leftSeq + 1; rightSeq <= num - len; ++rightSeq){
				string left = road.substr(leftSeq, len);
				string right= road.substr(rightSeq,len);
				if(left == right){
					works = false;
					break;
				}
			}
			if(!works){
				break;
			}
		}
		if(works){
			cout << len << endl;
			return 0;
		}
	}
}
