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
#define pq priority_queue<int, vector<int>, greater<int>> //min pq
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

int p[2000001];

vi findALL(int max){
    vi primes;
    char *sieve;
    sieve = new char[max/8+1];
    memset(sieve, 0xFF, (max/8+1) * sizeof(char));
    for(int x = 2; x <= max; x++)
     if(sieve[x/8] & (0x01 << (x % 8))){
         primes.push_back(x);
         for(int j = 2*x; j <= max; j += x)
	      sieve[j/8] &= ~(0x01 << (j % 8));
     }
    delete[] sieve;
    return primes;
}
int t; 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	vi v = findALL(2000000);
	for(int i = 0; i < v.size(); i++){
		p[v[i]] =1;
	}
	cin >> t;
	for(int i = 0; i < t; i++){
		int n; cin >> n;
		for(int j = 0; j < v.size(); j++){
			if(p[2*n - v[j]]){
				cout << v[j] << " " << 2*n - v[j] << endl;
				break;
			}
		}
	}

}
