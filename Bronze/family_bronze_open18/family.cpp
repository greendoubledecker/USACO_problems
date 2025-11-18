#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

#define umap unordered_map

using namespace std;

int main(){
	freopen("family.out", "w", stdout);
	freopen("family.in", "r", stdin);
	umap<string, string> par;
	int n;
	cin >> n;
	string bessie, elsie;
	cin >> bessie >> elsie;
	for(int i = 0; i < n; ++i){
		string mother, child;
		cin >> mother >> child;
		par[child] = mother;
	}
	//sisters
	//cout << "WTF" << endl;
	if(par[bessie] == par[elsie]){
		cout << "SIBLINGS" << endl;
		return 0;
	}
	//direct descendants
	int gens = 0;
	string b = bessie, e = elsie;
	while(true){
		if(b == "" && e == ""){
			break;
		}
		b = par[b];
		e = par[e];
		++gens;
		if(e == bessie){
			cout << bessie << " is the ";
			if(gens == 1){
				cout << "mother of " << elsie << endl;
				return 0;
			}else{
				for(int i = 2; i < gens; ++i){
					cout << "great-";
				}
				cout << "grand-mother of " << elsie << endl;
				return 0;
			}
		}
		if(b == elsie){
			cout << elsie << " is the ";
			if(gens == 1){
				cout << "mother of " << bessie << endl;
				return 0;
			}else{
				for(int i = 2; i < gens; ++i){
					cout << "great-";
				}
				cout << "grand-mother of " << bessie << endl;
				return 0;
			}
		}
	}
	//cout << "GGMA" << endl;
	// aunt
	gens = 1;
	b = par[bessie], e = par[elsie];
	if(b != "" && e != ""){
		while(true){
			if(b == "" && e == ""){
				break;
			}
			b = par[b];
			e = par[e];
			++gens;
			if(b == par[elsie]){
				cout << elsie << " is the ";
				for(int i = 2; i < gens; ++i){
					cout << "great-";
				}
				cout << "aunt of " << bessie << endl;
				return 0;
			}
			if(e == par[bessie]){
				cout << bessie << " is the ";
				for(int i = 2; i < gens; ++i){
					cout << "great-";
				}
				cout << "aunt of " << elsie << endl;
				return 0;
			}
		}
	}
	//cout << "aunt check" << endl;
	//cousin
	string bRoot = bessie, eRoot = elsie;
	while(true){
		if(par[bRoot] != ""){
			bRoot = par[bRoot];
		}
		if(par[eRoot] != ""){
			eRoot = par[eRoot];
		}
		if(par[bRoot] == "" && par[eRoot] == "") break;
	}
	//cout << "here?" << endl;
	if(bRoot == eRoot){
		cout << "COUSINS" << endl;
		return 0;
	}
	cout << "NOT RELATED" << endl;
	return 0;
}
