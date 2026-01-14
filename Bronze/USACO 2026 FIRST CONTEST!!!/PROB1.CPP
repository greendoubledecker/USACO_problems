#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

using ll = long long;

void tc(){
	ll A, B, CA, CB, FA;
	cin >> A >> B >> CA >> CB >> FA;
	ll ops = B / CB;
	B -= ops * CB;
	A += ops * CA;
	ll missing = FA - A;
	//ll ans = max(missing, roundedOps * CB - B);
	if(CA >= CB){
		ll ans = missing;
		cout << max(ans, 0ll) << endl;
	}else{
		ll roundedOps = missing / CA;
		if(missing % CA != 0){
			++roundedOps;
		}
		ll ans = roundedOps * CB - B;
		--ans;
		B += ans;
		ops = B / CB;
		B -= ops * CB;
		A += ops * CA;
		missing = FA - A;
		//cout << "need " << ans + 1 << " more B" << endl;
		//cout << max(ans + CA, 0ll) << endl;
		cout << max(ans + missing, 0ll) << endl;
	}
	//cout << "After doing " << ops << " operations, I still need " << missing << " more A chips." << endl;
	//cout << "So, I need to do " << roundedOps << " more operations, and I need " << ans << " more chips." << endl;
	//cout << max(ans, 0ll) << endl;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		tc();
	}
}
