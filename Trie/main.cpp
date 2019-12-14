/*
Assuming all characters are a-z 
*/

#include <iostream>
#include <string>

struct node{
	bool is_end;
	node *next[26];
	node(){
		is_end = false;
		for(int i = 0; i < 26; i++){
			next[i] = nullptr;
		}
	}
};


class trie{
private:
	node *root;
public:
	trie(){
		root = new node();
	}
	void insert(string s){
		node *temp = root;
		for(char ch : s){
			int level = ch - 'a';
			if(temp->next[level] == nullptr) {
				temp->next[level] = new node(); 
			}
			temp = temp->next[level];
		}
		temp->is_end = true;
	}
	bool search(string s){
		node *temp = root;
		for(char ch: s){
			int level = ch - 'a';
			if(temp->next[level] == nullptr)
				return false;
			temp = temp->next[level];
			
		}
		return temp->is_end;
	}

};


int main(){
	return 0;
}
