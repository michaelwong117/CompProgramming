#include <iostream>
#include <queue>
#include <fstream>
#include <vector>


using namespace std;

int main()
{
    ifstream fin("input.in");
    int n, m;
    fin >> n >> m;

    vector<int> c(n);
    for (int i=0;i<n;i++)
      fin >> c[i];

    vector<vector<int> > G(n);
    vector<bool> F(n);
    for (int i=0;i<m;i++){
        int a,b;
        fin >> a >> b;
        G[a-1].push_back(b-1);
        cout << a-1 << " " << b-1 << endl;
        G[b-1].push_back(a-1);
        cout << b-1 << " " << a-1 << endl;
    } 
    
    long long ans = 0;
    int flr = 0;
    while(1){
      int first = -1;
      for (int i=flr;i<n;i++)
        if (!F[i]){
          // cout << i << endl;
          first = i;
          break;
        }
      if (first == -1) break;
      flr = first+1;

      queue<int> q;
      q.push(first);
      cout << "first of q "  << first << endl;
      long long cost = c[first];
      while(!q.empty()){

        int v=q.front();
        cout << "front of q " << v << endl;
        q.pop();
        cout << "comparing " << c[v] << " and " << cost << endl; 
        cost = (cost < c[v] ? cost:c[v]);
        cout << "cost = " << cost << endl;
        if (!F[v]){
          F[v]=1;
          for (int j=0;j<G[v].size();j++){
            cout << "friends of " << v << " " << G[v][j] << endl;
            q.push(G[v][j]);
          }
        }
      }
      ans += cost;
    }

    cout << ans << "\n";

    return 0;
}
