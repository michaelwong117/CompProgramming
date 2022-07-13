//g++-7 filename.cpp -std=c++14
//SPOJ TSORT, 1/23/19
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
#define pq priority_queue<int, vector<int>, greater<int>> //min pq
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

const int N = 1e6+1;

int t;
vi v;

//https://www.learncpp.com/cpp-tutorial/74a-returning-values-by-value-reference-and-address/

vi merge(const vi &loA, const vi &hiA){
	vi res;
	int i = 0, j = 0;
	while(i + j < loA.size() + hiA.size()){
		if(i >= loA.size()){
			res.pb(hiA[j]); j++; 
		}
		else if(j >= hiA.size()){
			res.pb(loA[i]); i++;
		}
		else{
			if(loA[i] < hiA[j]){
				res.pb(loA[i]); i++; 
			}
			else{
				res.pb(hiA[j]); j++; 
			}
		}
	}
	return res;
}

vi mergesort(vi &arr, int lo, int hi){
	if(lo == hi) return {arr[lo]};
	int p = (lo+hi) / 2;
	const vi &loA = mergesort(arr, lo, p);
	const vi &hiA = mergesort(arr, p+1, hi);
	return merge(loA, hiA);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> t;
	for(int i = 0; i < t; i++){
		int x; cin >> x; v.pb(x);
	}
	const vi &res = mergesort(v, 0, t-1);
	for(auto a: res){
		cout << a << endl;
	}
}
