#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector <string> recurse (int level, string word, vector <int> currentWord){
	if (level == word.size()){
		string newWord;
		for (int i = 0; i < currentWord.size(); ++i){
			newWord.push_back(word[currentWord[i]]);
		}
		return {newWord};
	}else{
		vector <string> words = {};
		vector <string> childWords = {};
		for (int i = 0; i < word.size(); ++i){
			if (find(currentWord.begin(), currentWord.end(), i) == currentWord.end()){
				currentWord.push_back(i);
				childWords = recurse(level + 1, word, currentWord);
				words.insert(words.end(), childWords.begin(), childWords.end());
				currentWord.pop_back();
			}
		}
		return words;
	}
}

vector <string> strings(string word){
	vector <string> words = recurse (0, word, {});
	sort(words.begin(), words.end());
	auto last = unique(words.begin(), words.end());
	words.erase(last, words.end());
	return words;
}

int main(){
	string word;
	cin >> word;
	vector <string> words = strings(word);
	cout << words.size() << endl;
	for (int i = 0; i < words.size(); ++i){
		cout << words[i] << endl;
	}
	return 0;
}
