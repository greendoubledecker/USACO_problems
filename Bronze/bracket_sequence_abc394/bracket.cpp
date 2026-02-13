#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	string stack;
	for(char c : s){
		if(c == ')'){
			if(stack.size() && stack[stack.size() - 1] == '('){
				stack.pop_back();
			}else{
				cout << "No\n";
				return 0;
			}
		}else if(c == ']'){
			if(stack.size() && stack[stack.size() - 1] == '['){
				stack.pop_back();
			}else{
				cout << "No\n";
				return 0;
			}
		}else if(c == '>'){
			if(stack.size() && stack[stack.size() - 1] == '<'){
				stack.pop_back();
			}else{
				cout << "No\n";
				return 0;
			}
		}else{
			stack.push_back(c);
		}
	}
	cout << (stack.size() ? "No\n" : "Yes\n");
}
