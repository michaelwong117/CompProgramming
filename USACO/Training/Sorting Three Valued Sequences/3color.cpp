/*
ID: michaelwong11
PROG: sort3
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  ifstream fin("sort3.in");
  ofstream fout("sort3.out");
  int n;
  fin >> n;

  vector<int> count(3), v(n);
  for (int i=0;i<n;i++){
    fin >> v[i];
    count[--v[i]]++;
  }

  vector<vector<int>>in(3, vector<int>(3));
  //in[i][j] = number of j's in second of i's
  for (int i=0;i<count[0];i++)
    in[0][v[i]]++;
  for (int i=count[0];i<count[0]+count[1];i++)
    in[1][v[i]]++;
  for (int i=count[0]+count[1];i<n;i++)
    in[2][v[i]]++;

  int ans = 0;
  for (int i=0;i<3;i++)
    for (int j=0;j<3;j++){
      if (i==j) continue; // 0 swaps

      int m = min(in[i][j],in[j][i]); // 1 swap for each
      ans += m;
      in[i][j] -= m;
      in[j][i] -= m;
    }

  //now left with 1,2,0 or 2,0,1
  int m = min(in[0][1],min(in[1][2],in[2][0]));
  ans += m*2;
  in[0][1] -= m;
  in[1][2] -= m;
  in[2][0] -= m;

  ans += in[0][2]*2;

  fout << ans << "\n";

  return 0;
}
