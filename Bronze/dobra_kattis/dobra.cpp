#include <iostream> // "unpleasant" is unpleasant and "pleasant" is pleasant!
#include <string> //     ~~~

using namespace std;

string input;

long long recurse(bool l, int prevType, int streak, int index){ //type: 0 = vowel, 1 = consonant
    if(streak == 3){
        return 0;
    }
    if(index == input.size()){
        return l;
    }
    char c = input[index];
    
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        if(prevType == 0){
            return recurse(l, 0, streak + 1, index + 1);
        }else{
            return recurse(l, 0, 1, index + 1);
        }
    }else if(c == 'L'){
        if(prevType == 1){
            return recurse(true, 1, streak + 1, index + 1);
        }else{
            return recurse(true, 1, 1, index + 1);
        }
    }else if(c == '_'){
        long long solutions = 0;
        if(prevType == 0){
            solutions += recurse(l, 0, streak + 1, index + 1) * 5; //vowel
            solutions += recurse(l, 1, 1, index + 1) * 20;         //consonant
            solutions += recurse(true, 1, 1, index + 1);           //letter l
        }else{
            solutions += recurse(l, 0, 1, index + 1) * 5;          //vowel
            solutions += recurse(l, 1, streak + 1, index + 1) * 20;//consonant
            solutions += recurse(true, 1, streak + 1, index + 1);  //letter l
        }
        return solutions;
    }else{
        if(prevType == 1){
            return recurse(l, 1, streak + 1, index + 1);
        }else{
            return recurse(l, 1, 1, index + 1);
        }
    }
}

int main(){
    cin >> input;
    cout << recurse(false, 0, 0, 0) << endl;
    return 0;
}
