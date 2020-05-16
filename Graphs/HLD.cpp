// this code uses LCA and segment tree

const int MAXN = 101010;
const int LOGN = 20;

int n ,t, cnt;
int h[MAXN]; // height
int vis[MAXN]; // visit time
int st[4*MAXN]; // segment tree
int head[LOGN]; // stores the head of each chain
int chain[MAXN]; // stores the chain of each vertex
int subsz[MAXN]; // subtree size
vector<int> g[MAXN];

void dfsSub(int v){
	
	subsz[v] = 1;
	h[v] = h[p[v][0]] + 1;
	
	for(int i = 0 ; i < (int)g[v].size() ; i ++){
		if(g[v][i] == p[v][0]) continue;
		
		p[g[v][i]][0] = v;
		dfsSub(g[v][i]);
		
		subsz[v] += subsz[g[v][i]];
		if((subsz[g[v][i]] > subsz[g[v][0]]) || (g[v][0] == p[v][0]))
		   swap(g[v][i], g[v][0]);
	}
	
	return;
}

void dfsHLD(int v){
	
	if(!head[cnt]) head[cnt] = v;
	chain[v] = cnt;
	vis[v] = t++;
	
	if(subsz[v] == 1) return;
	
	dfsHLD(g[v][0]);
	
	for(int i = 1 ; i < (int)g[v].size() ; i ++){
		if(g[v][i] == p[v][0]) continue;
		cnt++;
		dfsHLD(g[v][i]);
	}
	
	return;
}

int walk(int u, int v){
	
	int mx = 0;
	
	while(chain[u] != chain[v]){
		mx = max(mx, query(1, 0, t, vis[head[chain[u]]], vis[u]));
		u = head[chain[u]];
		u = p[u][0];
	}
	
	mx = max(mx, query(1, 0, t, vis[v], vis[u]));
	
	return mx;
}
