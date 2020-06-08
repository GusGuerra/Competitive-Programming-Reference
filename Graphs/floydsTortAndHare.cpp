typedef long long ll;

// Takes a sequence calculated by an iterated function f
// outputs cycle length, start index

void floyd(ll x0, ll& startIndex, ll& cycleLen){
	
	ll T = f(x0);
	ll L = f(f(x0));
	
	while(T != L){
		T = f(T);
		L = f(f(L));
	}
	
	T = x0;
	startIndex = 0;
	
	while(T != L){
		T = f(T);
		L = f(L);
		startIndex++;
	}
	
	cycleLen = 1;
	L = f(T);
	while(L != T){
		cycleLen++;
		L = f(L);
	}
	
	return;
}
