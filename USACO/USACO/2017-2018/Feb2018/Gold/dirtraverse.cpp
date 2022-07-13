#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, files = 0;
ll ans = 0;

vector<vector<int>> child;
vector<int> ccount, depth;
vector<string> names;

int dfs(int u) {
  if (!child[u].size()) return ccount[u] = 1;

  int r = 0;
  for (int i = 0; i < child[u].size(); i++) {
    depth[child[u][i]] = depth[u] + 1;
    r += dfs(child[u][i]);
  }

  return ccount[u] = r;
}

void godown(int u, ll cost) {
  if (!child[u].size()) return;

  cost -= 1ll * ccount[u] * (names[u].size() + 1);
  cost += (files - ccount[u]) * 3ll;

  ans = min(ans, cost);

  for (int i = 0; i < child[u].size(); i++)
    godown(child[u][i], cost);
}

int main() {
  freopen("dirtraverse.in", "r", stdin);
  freopen("dirtraverse.out", "w", stdout);

  int a, k;
  cin >> n;

  names.resize(n);
  child.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> names[i] >> k;
    for (int j = 0; j < k; j++) {
      cin >> a;
      child[i].push_back(a - 1);
    }
  }

  ccount = vector<int>(n, -1);
  depth.resize(n);
  dfs(0);

  for (int i = 0; i < n; i++) {
    if (!child[i].size()) {
      ans += depth[i];
      files++;
    }
    ans += ccount[i] * names[i].size();
  }

  godown(0, ans);

  cout << ans << "\n";

  return 0;
}
