#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#define inf 200

using namespace std;

int v[100];

int main() {
  freopen("taming.in", "r", stdin);
  freopen("taming.out", "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> v[i];

  vector<vector<vector<int>>> f(n, vector<vector<int>> (n, vector<int>(n + 1, inf)));
  //f[i][l][b] = min number of tampers to get b breakouts in [0,i], last breakout l

  f[0][0][1] = 1 - (v[0] == 0);

  for(int i = 0; i < n - 1; i++)
    for (int l = 0; l < n - 1; l++)
      for (int b = 0; b < n; b++) {

        bool b0 = v[i + 1] == 0 || v[i + 1] != i + 1 - l;
        bool b1 = v[i + 1] != 0;

        f[i + 1][l][b] = min(f[i + 1][l][b], f[i][l][b] + b0);
        f[i + 1][i + 1][b + 1] = min(f[i + 1][i + 1][b + 1], f[i][l][b] + b1);
      }

  for (int b = 1; b <= n; b++) {
    int ans = inf;
    for (int l = 0; l < n; l++)
      ans = min(ans, f[n - 1][l][b]);
    cout << ans << "\n";
  }

  return 0;
}
