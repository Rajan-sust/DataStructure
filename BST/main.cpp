#include <iostream>

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
		
	void preorder(node<T> *current){
		if(current == nullptr)
			return;
		std::cout<<current->data<<'\n';
		preorder(current->left);
		preorder(current->right);
	}
	void inorder(node<T> *current){
		if(current == nullptr)
			return;
		inorder(current->left);
		std::cout<<current->data<<'\n';
		inorder(current->right);
	}
	void postorder(node<T> *current){
		if(current == nullptr)
			return;
		postorder(current->left);
		postorder(current->right);
		std::cout<<current->data<<std::endl;
	}
	

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
	void preorder(){
		preorder(root);
	}
	void inorder(){
		inorder(root);
	}
	void postorder(){
		postorder(root);
	}
};

int main(){

	tree<int> t;
	int nodes[] = {50,30,20,40,70,60,80};
	for(int i = 0; i < 7; i++){
		t.insert(nodes[i]);
	}
	t.postorder();

	return 0;
}

