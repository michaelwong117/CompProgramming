template<int SZ> struct DSU {
    int par[SZ], sz[SZ];
    DSU() {
        for(int i = 0; i < SZ; i++) par[i] = i, sz[i] = 1;
    }
    int get(int x) { // path compression
        if (par[x] != x) par[x] = get(par[x]);
        return par[x];
    }
    bool unite(int x, int y) { // union-by-rank
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (sz[x] < sz[y]) swap(x,y);
        sz[x] += sz[y], par[y] = x;
        return 1;
    }
};
//slightly faster? 
template<int SZ> struct DSU {
    int par[SZ], rank[SZ];
    DSU() {
        for(int i = 0; i < SZ; i++) par[i] = i, rank[i] = 0;
    }
    int get(int x) { // path compression
        if (par[x] != x) par[x] = get(par[x]);
        return par[x];
    }
    bool unite(int x, int y) { // union-by-rank
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (rank[x] < rank[y]) swap(x,y);
        par[y] = x;
        if(rank[x] == rank[y]) rank[y]++;
        return 1;
    }
};
