template<int SZ> struct Tarjan {

	int time = 0; stack<int> S;

	vector<vi> adj, SCCs;
	vi visit, link;
	vector<bool> instack; 


	Tarjan(vector<vi> &adjT) {
		adj = adjT; visit.resize(SZ, -1); link.resize(SZ); instack.resize(SZ);
	}
	void strongC(int u){
		time++;
		visit[u] = time; link[u] = visit[u];
		S.push(u); instack[u] = 1;
		for(auto v: adj[u]){
			if(visit[v] == -1){ //if you haven't visited v
				strongC(v); //visit v
				link[u] = min(link[u], link[v]); //if v or v's children had back edges, update u
			}
			else if(instack[v]){ //cross edge case
				link[u] = min(link[u], visit[v]); //v is in component, acts as back edge
				//visit[v] or link[v] will work here for Tarjan
				//but for biconnected components you must use visit[v]
				//you are comparing >= in bcc
			}
			//if you've already visited v and it's not in stack, do nothing
		}
		if(visit[u] == link[u]){
			vi SCC;
			while(1){
				int v = S.top(); S.pop();
				SCC.pb(v); instack[v] = 0;
				if(u == v) break;
			}
			SCCs.pb(SCC);	
		}
	}
    
};
//finding all SCCs
for(int i = 1; i <= n; i++){
	if(T.visit[i] == -1){
		T.strongC(i);
	}
}
