//Kuhn's algorithm to max matching

const long long MOD = 1e9 + 7;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

int in;
string s;
int n, m;

bool vis[256];

vector<int>g[256];
//graph (just one of the 'sides')

int match[256];
//matching array - corresponds to one of the 'sides' (A or B)

bool special_dfs(int v){
	
	if(vis[v]) return false;
	vis[v] = true;
	
	for(int i = 0 ; i < (int)g[v].size() ; i ++){
		
		int u = g[v][i];
		
		if(!match[u] || special_dfs(match[u])){
			//tries to swap edges on the path
			match[u] = v;
			return true;
		}
	}
	
	return false;
}

void solve(){
	
	// KUHN :
	// *remember to reset the visited array, NOT THE MATCHED ONE*
	
	int ans = 0;
	
	//Calls the algorithm for every vertex
	//belonging to one of the 'sides' (A or B)
	for(int i = 1 ; i <= n ; i ++){
		memset(vis, false, sizeof vis);
		if(special_dfs(i)) ans++;
	}
	
	//max matching
	cout<<ans<<"\n";
	
	//which vertexes were matched
	for(int i = 1 ; i <= m ; i ++)
		if(match[i]) cout<<match[i]<<" "<<i<<"\n";
	
}
