#include <iostream>
using namespace std;


template<typename T>
struct node {
	T data;
	node *next;
	node(T data): data(data), next(nullptr){}
};

template<typename T>
class queue {
private:
	node<T> *head, *tail;
public:
	queue(){
		head = tail = nullptr;
	}
	void push(T data){
		node<T> *new_node = new node<T>(data);
		if(head == nullptr){
			head = tail = new_node;
		}
		else{
			tail->next = new_node;
			tail = new_node;
		}
	}
	void pop(){
		if(head == tail) {
			delete head;
			head = tail = nullptr;
		} else{
			node<T> *temp = head;
			head = head->next;
			delete temp;

		}

	}
	T front(){
		return head->data;
	} 
	bool empty(){
		return (head == nullptr) ? true : false;
	}
};

template<typename T>
class vector{
private:
	T *container;
	int size;
public:
	vector(){
		container = new T[1];
		size = 0;
	}
	void push_back(T data){
		container[size] = data;
		size += 1;
		if((size & (size-1)) == 0){
			T *temp = new T[(size<<1)];
			for(int i = 0; i < size; i++){
				temp[i] = container[i];
			}
			delete[] container;
			container = temp;
		}
	}
	T operator [](int idx){
		return container[idx];
	}
	int length(){
		return size;
	}

};

bool bfs(int node, int edges){
	vector<int> adj[node];
	for(int i = 0; i<edges; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int color[node];
	for(int i=0; i<node; i++){
		color[i] = -1;
	}
	queue<int>q;
	int src = 0;
	q.push(src);
	color[0] = 0;

	while(not q.empty()) {
		int u = q.front();
		q.pop();
		int parent_clr = color[u];
		for(int i = 0; i<adj[u].length(); i++) {
			int v = adj[u][i];
			if(color[v] == -1){
				color[v] = (parent_clr == 0)?1:0;
				q.push(v);
			} else{
				if(color[v] == parent_clr)
					return  false;

			}
		
		}
	}
	return true;
}


int main(){

	
	int node;
	while(cin>>node && node) {
		int edges;
		cin>>edges;
		if(not bfs(node,edges))
		
			cout<<"NOT BICOLORABLE.\n";
		else
			cout<<"BICOLORABLE.\n";

	}
	return 0;
}

