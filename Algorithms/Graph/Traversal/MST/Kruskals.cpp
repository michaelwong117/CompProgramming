//transform graphs into trees

//MINIMIZE the maximum edge in a path between two nodes
//take the mst of the graph
//use lca and binary jumping to find the minimum maximum edge between any two nodes in the graph




struct Edge {
	int w, u, v;
	bool operator < (const Edge &e) const {
		return this->w < e.w;
	}
};


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


vector<Edge> edges, edgesM;

edges.pb({dist, u, v});

void MST(){
	DSU<250001> D;
	sort(all(edges));
	for(int i = 0; i < edges.size(); i++){
		if(!D.unite(edges[i].u, edges[i].v)) continue;
		edgesM.pb({edges[i].w, edges[i].u, edges[i].v});
	}
}
