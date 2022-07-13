#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define ll long long

using namespace std;

typedef pair<int,int> pii;


int main(){
  ifstream fin ("pairup.in");
  ofstream fout ("pairup.out");
  int n;
  vector<pii> v;
  fin >> n;
  for(int i = 0; i < n; i++){
  	int x, y;
  	fin >> x >> y;
  	v.push_back(pii(y,x));
  }
  sort(v.begin(), v.end());
  int m = 0, i = 0, j = n-1;
  while(i <= j){
  	//which one has the least frequency
  	int smaller = min(v[i].second, v[j].second);
  	//if the sum of the pair is greater than max
  	//set max equal to the sum
  	m = max(m, v[i].first + v[j].first); 
  	if(i == j){
  		v[i].second += smaller;
  		//don't subtract two copies if they are the same
  	}
  	v[i].second -= smaller;
  	v[j].second -= smaller;

  	//here we make sure we're looking at the right pairing
  	if(v[i].second == 0){
  		i++;
  	}
  	if(v[j].second == 0){
  		j--;
  	}

  }
  fout << m << endl;
  
}

