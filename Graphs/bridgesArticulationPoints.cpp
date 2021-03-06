const int MAXN = 201010;
#define INF 0x3f3f3f3f

int V, E;
vector<int>G[MAXN];

vector<int>low(MAXN, INF);
vector<int>in(MAXN);
vector<int>out(MAXN);

map<int,bool> vertice_corte;
map<pair<int,int>, bool> ponte;

int tempo = 1;

void mini(int& a, int b){
	a = min(a,b);
}

void dfs(int v, int pai){
	
	in[v] = low[v] = tempo++;
	
	bool corte = false;
	int filhos = 0;
	
	for(int u : G[v]){
		
		if(!in[u]){
			
			dfs(u, v);
			filhos++;
			
			if(low[u] >= in[v]) corte = true;
			mini(low[v] , low[u]);
		}
		else if(u != pai) mini(low[v],in[u]);
	}
	
	if(!pai && filhos >= 2) vertice_corte[v] = true;
	else if(pai && corte) vertice_corte[v] = true;
	
	if(low[v] == in[v] && pai){
		ponte[make_pair(pai,v)] = true;
		ponte[make_pair(v,pai)] = true;
	}
	
	out[v] = tempo++;
}
