/*check a string is palindrome or not using recursion*/

#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(int l, int r, string str){
	if(r-l+1 <= 1){
		return true;
	}
	if(str[l] != str[r]){
		return false;
	}else{
		return is_palindrome(l+1, r-1, str);
	}

}

int main(){
	string str("madam");
	//cout<<str<<endl;
	cout<<is_palindrome(0,4,str)<<endl;
	return 0;
}
