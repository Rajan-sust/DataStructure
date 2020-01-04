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
	
	T operator[](int k) {
		return container[k];
	}
	int size() {
		return idx;
	}
};


class bi_color {
private:
	int nodes;
	int edges;
	int *color;
	vector<int> *adj;
	bool ok;
public:
	bi_color(int _nodes, int _edges) {
		nodes = _nodes;
		edges = _edges;
		color = new int[nodes];
		adj = new vector<int>[nodes];
		ok = true;

		for(int i = 0; i < nodes; i++) {
			color[i] = -1;
		}
	}
	~bi_color() {
		delete[] color;
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
	void dfs(int cur) {
		if(not ok){
			return;
		}
		for(int i = 0; i < adj[cur].size(); i++){
			int child = adj[cur][i];
			if(color[child] == -1) {
				color[child] = (color[cur] == 0) ? 1 : 0;
				dfs(child);
			} else if(color[child] == color[cur]) {
				ok = false;
			}
		}

	}

	void call_dfs() {
		color[0] = 0;
		dfs(0);
	}

	void show_output() {
		if(ok){
			std::cout<<"BICOLORABLE.\n";
		} else{
			std::cout<<"NOT BICOLORABLE.\n";
		}
	}



	
};

int main(int argc, char const *argv[]) {

	int n;
	while(std::cin>> n and n) {
		int e;
		std::cin>>e;
		bi_color graph(n,e);
		graph.build();
		graph.call_dfs();
		graph.show_output();

	}


	/* code */
	return 0;
}