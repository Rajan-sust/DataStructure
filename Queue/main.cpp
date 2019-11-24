#include <iostream>

template<typename T>
struct node{
	T data;
	node *next;
	node(T data): data(data), next(nullptr){};
};

template<typename T>
class queue{
private:
	node<T> *head, *tail;
	int size;
public:
	queue() {
		head = tail = nullptr;
	}
	void push(T data) {
		node<T> *temp = new node<T>(data);
		if (head == nullptr) {
			head = tail = temp;
		} else{
			tail->next = temp;
			tail = temp; 	
		}
	}

	T front() {
		return head->data;
	}

	void pop() {
		/* If queue is not empty and head and tail point same
		   element that means only one element remain */
		if(head == tail) {
			delete head;
			head = tail = nullptr;
		} else {
			/*After changing pointer deleting unreferenced object*/
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
	
	queue<int> q;
	q.push(5);
	q.push(7);
	q.push(11);

	while(not q.empty()) {
		std::cout<<q.front()<<std::endl;
		q.pop();
	}
	return 0;

}
