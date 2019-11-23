/*
Find the left most idx of x if x occurs in array else return -1
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> v{5,5,5,5,5,5,5,5,5,6,6};
//            0,1,2,3,4,5,6,7,8,9,10

int binary_srch(int x){
	int lo = 0, hi = int(v.size()) - 1;
	int ans = -1;
	while(lo <= hi) {
		int mid = lo + (hi-lo)/2;
		if(v[mid] == x) {
			ans = mid;
		}
		if(v[mid] < x) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	cout<<binary_srch(6)<<endl; //returned 9
	
	return 0;
}
