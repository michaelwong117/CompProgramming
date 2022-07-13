template<int SZ> struct Dijkstra {
	priority_queue<pl, vector<pl>, greater<pl>> q;
	ll dist[SZ];
	Dijkstra(int start, vector<vpi> & adj) {
		for(int i = 0; i < SZ; i++) dist[i] = 1e18;
		dist[start] = 0; q.push({0, start});
		while(!q.empty()){
			pl ft = q.top(); q.pop();
			if(dist[ft.s] < ft.f) continue; //never visit a minimum node again
			for(auto a: adj[ft.s]){
				if(dist[a.f] > ft.f + (ll) a.s){
					dist[a.f] = ft.f + (ll) a.s;
					q.push({dist[a.f], a.f});
				}
			}
		}
	}

};

