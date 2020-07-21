const int MAXN = 201010;

int base_array[MAXN + 16]; // self-explanatory
int st[8*MAXN]; //segment tree array
int lazy[8*MAXN]; // lazy propagation array

void propagate(int node){
	
	int nxt = node*2;
	
	if(lazy[node]){
		st[nxt] += lazy[node];
		lazy[nxt] += lazy[node];
		
		st[nxt + 1] += lazy[node];
		lazy[nxt + 1] += lazy[node];
		
		lazy[node] = 0;
	}
	
	return;
}

int query(int node, int l, int r, int lq, int rq){
	
	int nxt = node*2;
	int mid = (l + r)/2;
	
	if(lq > r || l > rq) return 0;
	if(lq <= l && r <= rq) return st[node];
	
	propagate(node);
	
	return max(query(nxt, l, mid, lq, rq) , query(nxt + 1, mid + 1, r, lq, rq));
}

void update(int node, int l, int r, int lu, int ru, int val){
	
	int nxt = node*2;
	int mid = (l + r)/2;
	
	if(lu <= l && r <= ru){
		st[node] += val;
		lazy[node] += val;
		return;
	}
	
	if(lu > r) return;
	if(ru < l) return;
	
	propagate(node);
	update(nxt, l, mid, lu, ru, val);
	update(nxt + 1, mid + 1, r, lu, ru, val);
	
	st[node] = max(st[nxt], st[nxt + 1]);

	return;
}

void build(int node, int l, int r){
	
	if(l == r){
		st[node] = base_array[l];
		return;
	}
	
	int mid = (l + r)/2;
	int nxt = node*2;
	
	build(nxt, l, mid);
	build(nxt + 1, mid + 1, r);
	
	st[node] = max(st[nxt], st[nxt + 1]);
	
	return;
}
