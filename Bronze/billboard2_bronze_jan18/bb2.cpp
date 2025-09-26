#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bb2(int fl, int fb, int fr, int ft, int ll, int lb, int lr, int lt){ //add 1000
	int right, left, up, down;
	if(fr < lr){
		right = lr;
	}else{
		if(fb > lb || ft < lt){
			right = lr;
		}else{
			right = fl;
		}
	}
	
	if(fb > lb){
		down = lb;
	}else{
		if(fl > ll || fr < lr){
			down = lb;
		}else{
			down = ft;
		}
	}
	
	if(fl > ll){
		left = ll;
	}else{
		if(fb > lb || ft < lt){
			left = ll;
		}else{
			left = fr;
		}
	}
	
	if(ft < lt){
		up = lt;
	}else{
		if(fl > ll || fr < lr){
			up = lt;
		}else{
			up = fb;
		}
	}
	int width = max(0, right - left);
	int height = max(0, up - down);
	int ans = width * height;
	return ans;
}

int main(){
	int fl, fb, fr, ft, ll, lb, lr, lt;
	cin >> ll >> lb >> lr >> lt >> fl >> fb >> fr >> ft;
	cout << bb2(fl + 1000, fb + 1000, fr + 1000, ft + 1000, ll + 1000, lb + 1000, lr + 1000, lt + 1000);
	return 0;
}
