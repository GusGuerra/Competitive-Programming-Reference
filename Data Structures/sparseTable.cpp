const int MAXN = 101010;
const int LOGN = 25;

int logue[MAXN + 1];
int st[MAXN][LOGN + 1];
int v[MAXN];

void solve(){
	
	// Precompute log
	logue[1] = 0;
	for(int i = 2 ; i <= MAXN ; i ++)
		logue[i] = logue[i/2] + 1;
	
	for(int i = 0 ; i < n ; i ++)
		st[i][0] = v[i];
	
	for(int j = 1 ; j <= LOGN ; j ++) // Going through powers
		for(int i = 0 ; i + (1<<j) < n ; i ++)
			st[i][j] = min(st[i][j - 1] , st[i + (1<<(j - 1))][j - 1]);
	
	// Answering queries
	for(int i = 0 ; i < q ; i ++){
		int l, r;
		cin >> l >> r;
		
		int len = logue[r - l + 1];
		cout << min(st[l][len] , st[r - (1<<len) + 1][len]) << "\n";
	}
}
