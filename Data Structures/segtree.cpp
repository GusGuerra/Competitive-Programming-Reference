void update(int nd, int l, int r, int pos){
	
	if(l == r){
		st[nd]++;
		return;
	}
	
	int mid = (l + r)/2;
	int nxt = nd*2;
	
	if(pos <= mid) update(nxt, l, mid, pos);
	if(pos > mid) update(nxt + 1, mid + 1, r, pos);
	
	st[nd] = st[nxt] + st[nxt + 1];
}
 
int query(int nd, int l, int r, int lq, int rq){
	
	if(r < lq || rq < l) return 0;
	if(lq <= l && r <= rq) return st[nd];
	
	int mid = (l + r)/2;
	int nxt = nd*2;
	
	return query(nxt, l, mid, lq, rq) + query(nxt + 1, mid + 1, r, lq, rq);
}
