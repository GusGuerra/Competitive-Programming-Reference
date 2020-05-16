vector<int> g[2020]; // graph
vector<int> rg[2020]; // reverse graph
bool vis[2020];
stack<int>st;
int scc;
int id[2020];

// get topological ordering of nodes
// and goes through it on the reverse graph

void dfs(int x){
	
	vis[x] = true;
	
	for(int i = 0 ; i < g[x].size() ; i ++)
		if(!vis[g[x][i]]) dfs(g[x][i]);
	
	st.push(x);
}

void dfs2(int x){
	
	id[x] = scc;
	
	for(int i = 0 ; i < rg[x].size() ; i ++)
		if(id[rg[x][i]] == -1) dfs2(rg[x][i]);
}

void kosaraju(){
	
	for(int i = 1 ; i <= n ; i ++)
		if(!vis[i]) dfs(i); // adding everyone to the stack
	
	while(!st.empty()){
		
		int u = st.top();
		st.pop();
		
		if(id[u] != -1) continue;
		
		id[u] = scc;
		
		dfs2(u);
		scc++;
	}
		
}
