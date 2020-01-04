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


class cycle_find {
private:
	int nodes;
	int edges;
	int *color;
	int *parent;
	vector<int> *adj;
public:
	//cycle_find(){}

	cycle_find(int _nodes, int _edges) {
	    nodes = _nodes;
		edges = _edges; 
		color = new int[nodes+1];
		parent = new int[nodes+1];
	    adj = new vector<int>[nodes+1];

		for(int i = 0; i < nodes; i++) {
			color[i] = 0;
			parent[i] = -1;
		}
	}
	
	~cycle_find() {
		delete[] color;
		delete[] parent;
		delete[] adj;
	}

	void build() {
		for(int i = 0; i < edges; i++) {
			int u,v;
			std::cin>>u>>v;
			adj[u].push_back(v);
		} 
	}

	void dfs(int cur) {
		//std::cout<<cur<<'\n';
		for(int i = 0; i < adj[cur].size(); i++) {
			int child = adj[cur][i];
			if(color[child] == 0) {
				color[child] = 1;
				parent[child] = cur;
				dfs(child);
			} else if(color[child] == 1) {
				int cycle_stsart_node = child;
				int temp = cur;
				vector<int> ans;
				ans.push_back(cycle_stsart_node);
				while(true) {
					ans.push_back(temp);
					temp = parent[temp];
					if(temp == cycle_stsart_node){
						//ans.push_back(temp);
						break;
					}
				}
				ans.push_back(cycle_stsart_node);
				for(int i = ans.size()-1; i >= 0; i--) {
					std::cout<<ans[i]<<" \n"[i==0];
				} 
				//std::cout<<"cycle exists!\n";
			}
		}
		color[cur] = 2;

	}
	void call_dfs() {
		for(int i = 0; i < nodes; i++) {
			if(color[i] == 0) {
				color[i] = 1;
				dfs(i);
			}
		}

	}

	
};

int main() {
	int n,e;
	std::cin>>n>>e;
	cycle_find graph(n,e);
	graph.build();
	graph.call_dfs();
	
	return 0;
}