#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//g++-7 filename.cpp -std=c++14
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>>
#define mpq priority_queue<int>
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

const int maxN = 1e6;
int N, A[maxN], counter = 0;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("sort.in"); ofstream fout("sort.out");
	fin >> N;
	for(int i = 0; i < N; i++) fin >> A[i];
	bool sorted = false;
	while(!sorted){
	   sorted = true;
	   counter++;
	   for(int i = 0; i < N-1; i++){
	      if(A[i+1] < A[i]) swap(A[i], A[i+1]);
	   }
	   for(int i = N-2; i >= 0; i--){
	      if(A[i+1] < A[i])
	         swap(A[i], A[i+1]);
	   }
	   for(int i = 0; i < N-1; i++){
	      if(A[i+1] < A[i]) sorted = false;
	   }
	}
	fout << counter << endl;
}