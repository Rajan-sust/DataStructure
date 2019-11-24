#include <iostream>
using namespace std;


struct node {
	int data;
	node *next;
	node(int data): data(data), next(nullptr){}
};

class list {
private:
	node *head, *tail;
public:
	list() {
		head = nullptr;
		tail = nullptr;
	}
	void push_back(int data) {
		node *temp = new node(data);
		if(head == nullptr) {
			head = temp;
			tail = temp;
		}else {
			tail->next = temp;
			tail = temp;
		}

	}

};

int main() {
	list l;
	l.push_back(5);
	l.push_back(10);

	return 0;
}
