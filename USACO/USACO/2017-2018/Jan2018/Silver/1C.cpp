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

int b_search(vector<int> &a, int key) {
  int lo = 0, hi = a.size() - 1;

  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] == key)
      return mid;
    else if (a[mid] < key)
      lo = mid+1;
    else
      hi = mid-1;
  }

  return -1;
}


int main() {
    ofstream fout ("lifeguards.out");
    ifstream fin ("lifeguards.in");
    int N;
    fin >> N;
    vector<int> times(2*N);
    for (int i=0; i<2*N; i++){
        fin >> times[i];
    }
    vector<int> order(2*N); 
    for (int i=0; i<2*N; i++){
        order[i]=times[i];
    }
   	sort(times.begin(), times.end());
    // for(auto a: times){
    //     cout << a << endl;
    // }
   	int length = times.size();
    vector<int> first (N), second (N);
    vector<int> timecount (length-1);
    for (int i=0; i<length-1; i++){
        timecount[i]=0;
    }
    for (int i=0; i < N; i++){
    	// cout << i << " " << N << endl;
        first[i]=b_search(times, order[2*i]);
        second[i]=b_search(times, order[2*i+1]);
        // cout << first[i] << " " << second[i] << endl;
        // cout << order[2*i] << " " << first[i] << endl;
        // cout << order[2*i+1] << " " << second[i] << endl;
        for (int k=first[i]; k<second[i]; k++){
        	// cout << k << endl;
            timecount[k]=timecount[k]+1;
        }
    }
   //  for(auto a: times){
   //  	cout << a << " ";
   //  }
   //  cout << endl;
   //  for(auto a: timecount){
	 	// cout << a << " ";
   //  }
   //  cout << endl;
    int total=0;
    for (int i=0; i<length-1; i++){
        if (timecount[i]!=0){
            total=total+times[i+1]-times[i];
        }
    }
    int ans=0;
    for (int k=0; k<N; k++){
        int time=total;
        for (int i=first[k]; i<second[k]; i++){
            if (timecount[i]==1){
                time=time-times[i+1]+times[i];
            }
        }
        if (time > ans){
            ans=time;
        }
    }
    fout << ans << endl;
    return 0;
}


