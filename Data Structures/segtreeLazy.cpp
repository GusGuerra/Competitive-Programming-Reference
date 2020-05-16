int st[800004];
int lazy[800004];
 
int query(int node, int l, int r, int pos){
	
	int nxt = node<<1;
	int mid = (l + r)>>1;
	
	if(l == r) return st[node] + lazy[node];
 
	if(lazy[node] != 0){
		lazy[nxt] += lazy[node];
		lazy[nxt + 1] += lazy[node];
		lazy[node] = 0;
	}
 
	if(pos <= mid) return query(nxt, l, mid, pos);
	return query(nxt + 1, mid + 1, r, pos);
}
 
void update(int node, int l, int r, int lu, int ru){
 
	int nxt = node<<1;
	int mid = (l + r)>>1;
	
	if(r < lu) return;
	if(l > ru) return;
 
	if(lu <= l && r <= ru){
		lazy[node] += 1;
		return;
	}
 
	update(nxt, l, mid, lu, ru);
	update(nxt + 1, mid + 1, r, lu, ru);
 
	return;
}
