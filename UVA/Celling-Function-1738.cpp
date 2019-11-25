#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;


template<typename T>
struct node{
	T data;
	node *left, *right;
	node(T data): data(data), left(nullptr), right(nullptr){}
};

template<typename T>
class tree{
private:
	node<T> *root;
	vector< pair<char,int> > path;
public:
	tree(): root(nullptr){}
	void insert(T data){
		node<T> *new_node = new node<T>(data);
		if(root == nullptr){
			root = new_node;
			return;
		}
		node<T> *temp = root;
		while(temp != nullptr){
			if(data == temp->data)
				return;
			else if(data > temp->data){
				if(temp->right == nullptr){
					temp->right = new_node;
					return;
				}
				temp = temp->right;
			} else{
				if(temp->left == nullptr){
					temp->left = new_node;
					return;
				}
				temp = temp->left;
			}
		}	
	}
	void post_order(node<T> *current, char ch, int level){
		if(current == nullptr)
			return;
		path.emplace_back(ch,level);
		post_order(current->left,'l',level+1);
		post_order(current->right,'r',level+1);

	}
	vector< pair<char,int> > traverse(){
		path.clear();
		post_order(root, 'o', 0);
		return path;
	}


};

int main(){

	int n,nodes;
	cin>>n>>nodes;
	set< vector< pair<char,int> > > s;
	while(n--){
		tree<int> t;
		for(int i = 0; i < nodes; i++){
			int num;
			cin>>num;
			t.insert(num);
		}
		s.insert(t.traverse());
	}
	cout<<s.size()<<'\n';

	return 0;
}

