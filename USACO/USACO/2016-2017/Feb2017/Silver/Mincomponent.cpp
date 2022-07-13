int main(){  
  vector<vector<int> >adj(2000);

  //for each edge
  //adj[from].push_back(to);
  
  
  vector<int> D(2000);
  int fl=0;
  int ans=0;
  while(1) {
    queue<int> q;
    int i;
    for (i=fl;i<2000;i++)
      if (D[i]==0) break;
    if (i==2000) break;
    ans++;
    fl = i;

    q.push(fl);
    while(!q.empty()) {
      int v = q.front();
      q.pop();
      if (D[v] == 0) {
        D[v] = 1;
        for (int j = 0; j < adj[v].size(); j++)
          q.push(adj[v][j]);
      }
    }
  }
  cout << ans << "\n";


  in.close();
  return 0;
}