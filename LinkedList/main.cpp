#include <iostream>


template<typename T>
struct node {
	T data;
	node *next;
	node(T data): data(data), next(nullptr){}
};

template<typename T>
class list {
private:
	node<T> *head, *tail;
public:
	list() {
		head = tail = nullptr;
	}
	void push_back(int data) {
		node<T> *new_node = new node<T>(data);
		if(head == nullptr) {
			head = tail = new_node;
		}else {
			tail->next = new_node;
			tail = new_node;
		}
	}
	T back() {
		return tail->data;
	}

};

int main() {
	list<int> l;
	l.push_back(5);
	l.push_back(10);
	l.push_back(15);
	std::cout<<l.back()<<std::endl;

	return 0;
}
