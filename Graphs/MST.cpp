const int MAXN = 101010;

typedef struct node{
    int x, y, w;
    node(){};
    node (int _x, int _y, int _w){
        x = _x;
        y = _y;
        w = _w;
    }
    bool operator < (const node comp) const{
        return w < comp.w;
    }
} edge;

int n;
vector<edge> g;
int root [MAXN];

void ini(){
    for (int i = 0 ; i < MAXN ; i++)
        root[i]=i;
}

int find(int x){
    if (root[x] == x) return x;
    return root[x] = find(root[x]);
}

long long int kruskal(){
    
    ini();
    sort(g.begin() , g.end());
    
    long long int mst=0;
    
    for (int i = 0 ; i < graph.size() ; i ++){
        int x = g[i].x;
        int y = g[i].y;
        int w = g[i].w;
        int rx = find(x);
        int ry = find(y);

        if (rx!=ry){ //doesn't pick edges if it forms a cycle
            root[rx] = ry;
            mst += w;
        }
    }
    return mst;
}
// inserting nodes: g.push_back(node(x, y, w));
