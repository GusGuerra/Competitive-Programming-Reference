
// call a simple DFS first, in order
// to get the direct ancestor of the nodes

void calc(){
	for(int j = 1 ; j < LOGN ; j ++)
		for(int i = 1 ; i <= n ; i ++)
			p[i][j] = p[p[i][j - 1]][j - 1];
	return;
}

int getlca(int v, int u){
	
	if(h[v] > h[u]) swap(u,v);
	
	int d = h[u] - h[v];
	for(int i = 0 ; i < LOGN ; i ++)
		if(d & (1<<i)) u = p[u][i];
	
	if(u == v) return v;
	int lca = p[v][0];
	
	for(int i = LOGN - 1 ; i >= 0 ; i --){
		if(p[v][i] != p[u][i]){
			v = p[v][i];
			u = p[u][i];
			lca = p[v][0];
		}
	}
	
	return lca;
}
