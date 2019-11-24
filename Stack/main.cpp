#include <iostream>

template<typename T>
struct node{
	T data;
	node *next;
	node(T data) : data(data), next(nullptr){}
};

template<typename T>
class stack{
private:
	node<T> *head;
public:
	stack(): head(nullptr){}
	void push(T data) {
		node<T> *new_node = new node<T>(data);
		if(head == nullptr) {
			head = new_node;
		} else {
			new_node->next = head;
			head = new_node;
		}

	}
	T top() {
		return head->data;
	} 
	void pop() {
		/*if stack contain only one element 
		  then head->next == nullptr */

		if(head->next == nullptr) {
			delete head;
			head = nullptr;
		} else {
			node<T> *temp = head;
			head = head->next;
			delete temp;
		}

	}
	bool empty() {
		return (head == nullptr) ? true : false;
	}
};

int main() {
	stack<int> st;
	st.push(5);
	st.push(7);
	st.push(13);
	st.push(11);
	while(not st.empty()) {
		std::cout<<st.top()<<std::endl;
		st.pop();
	}


	return 0;
}
