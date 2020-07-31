// This version of Kuhn's Algo may be better than O(|M|*E)

const int MAXN = 1123;

int n;
vector<int> g[MAXN];

bool vis[MAXN];
int match[MAXN];
// store info about both sides of the graph

bool dfs_kuhn(int v){
	
	if(vis[v]) return false;
	vis[v] = true;
	
	for(int u : g[v]){
		if(match[u] < 0 || dfs_kuhn(match[u])){
			match[u] = v;
			match[v] = u;
			return true;
		}
	}
	return false;
}

int kuhn(){
	
	// unmatch entire graph
	// use [0 .. n) and [n .. n*2)
	for(int i = 0 ; i < n*2 ; i ++)
		match[i] = -1;
	
	int maxmt = 0;
	
	for(int run = 1 ; run ; ){
		run = 0; memset(vis, false, sizeof vis);
		for(int i = 0 ; i < n ; i ++){
			if(match[i] < 0 || dfs_kuhn(i)){
				maxmt++;
				run = 1;
			}
		}
	}
	
	return maxmt;
}
