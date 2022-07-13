#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

 
const int INF = 1000000;
 
int bt( vector<int> t, int s )
{
    for (int i = 0; i < t.size(); i++)
  if (t[i] >= s)
      return t[i];
    return INF;
}
 
int int_comp( const void *a, const void *b )
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y)
  return -1;
    else if (x > y)
  return 1;
    else
  return 0;
}
 
class Boxing {
public:
    int maxCredit(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> e) {
  int count = 0;
  for (int s = 0; s <= 180000; s++) {
      int best_time[5];
      best_time[0] = bt( a, s );
      best_time[1] = bt( b, s );
      best_time[2] = bt( c, s );
      best_time[3] = bt( d, s );
      best_time[4] = bt( e, s );
      qsort( best_time, 5, sizeof(int), int_comp );
      if (best_time[2] <= s + 1000) {
          cout << best_time[0] << " " << best_time[1] << " " << best_time[2] << endl;
    count++;
    s = best_time[2];
    //fprintf( stderr, "s = %d\n", s );
      }
  }
  return count;
    }
};

int main(){
  Boxing instanceOfClass;
  // vector<int> a = {10000000, 30000000, 40000000};
  // vector<int> b = {};
  // vector<int> c = {2, 3};
  // vector<int> d = {};
  // vector<int> e = {1, 5};
  int out = instanceOfClass.maxCredit({180000}, {1, 2, 3, 4, 5, 6, 179000, 179500, 179800}, {5, 10, 1000, 10000}, {5, 10, 1000, 10000}, {6, 9000});
  cout << out << endl;

}