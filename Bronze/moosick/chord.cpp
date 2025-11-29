#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int notes = 88;

int main(){
	int length;
	cin >> length;
	vector<int> song(length);
	for(int i = 0; i < length; ++i){
		cin >> song[i];
	}
	int chordSize;
	cin >> chordSize;
	unordered_set<int> chord;
	for(int i = 0; i < chordSize; ++i){
		int note;
		cin >> note;
		chord.insert(note);
	}
	int min = notes, max = 1;
	for(int val : chord){
		if(val < min) min = val;
		if(val > max) max = val;
	}
	vector<unordered_set<int>> rsc;
	for(int i = 1 - min; i <= notes - max; ++i){
		//cout << "i is " << i << endl;
		unordered_set<int> newrsc;
		for(int num : chord){
			//cout << "num = " << num << endl;
			//cout << "num - i = " << num - i << endl;
			newrsc.insert(num + i);
		}
		rsc.push_back(newrsc);
	}
	vector<int> locs;
	for(int i = 0; i <= length - chordSize; ++i){
		unordered_set<int> current;
		for(int j = 0; j < chordSize; ++j){
			current.insert(song[i + j]);
		}
		for(unordered_set<int> illChord : rsc){
			if(current == illChord){
				locs.push_back(i + 1);
			}
		}
	}
	cout << locs.size() << endl;
	for(int loc : locs){
		cout << loc << endl;
	}
	/*
	for(unordered_set c : rsc){
		cout << "chord: ";
		for(int n : c){
			cout << n << " ";
		}
		cout << endl;
	}
	cout << "min " << min << " max " << max << endl;
	*/
}
