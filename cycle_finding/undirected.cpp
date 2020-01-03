#include <iostream>

template<typename T>
class vector {
private:
	int idx;
	T *container;
public:
	vector() : idx(0), container(new T[1]) {}
	~vector() {
		delete[] container;
	}
	void push_back(T num) {
		container[idx] = num;
		idx += 1;
		if((idx & (idx-1)) == 0) {
			T *temp = new T[(idx<<1)];
			for(int i = 0; i < idx; i++) {
				temp[i] = container[i];
			}
			delete[] container;
			container = temp;
		}
		return;
	}
	void pop_back() {
		idx -= 1;
		return;
	}
	T operator[](int k) {
		return container[k];
	}
	int size() {
		return idx;
	}
};


class cycle_find {
private:
	int nodes;
	int edges;
	int *visit;
	vector<int> *adj;
public:
	//cycle_find(){}

	cycle_find(int _nodes, int _edges) {
	       	nodes = _nodes;
		edges = _edges; 
		visit = new int[nodes+1];
	       	adj = new vector<int>[nodes+1];
		for(int i = 1; i <= nodes; i++) {
			visit[i] = 0;
		}
	}
	
	~cycle_find() {
		delete[] visit;
		delete[] adj;
	}

	void build() {
		for(int i = 0; i < edges; i++) {
			int u,v;
			std::cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	void bktrk(int cur, int par = -1) {
		//std::cout<<cur<<" "<<par<<std::endl;		
		for(int i = 0; i < adj[cur].size(); i++) {
			int child = adj[cur][i];
			if(visit[child] == 0) {
				visit[child] = 1;
				bktrk(child, cur);
				visit[child] = 0;	
			} else if(visit[child] == 1 and child != par) {
				std::cout<<"cycle "<<child<<" "<<cur<<'\n';
			}
			
		}	
	}
	void call_bktrk() {
		visit[1] = 1;
		bktrk(1);
		visit[1] = 0;
	}
};

int main() {
	int n,e;
	std::cin>>n>>e;
	cycle_find graph(n,e);
	graph.build();
	graph.call_bktrk();
	return 0;
}
