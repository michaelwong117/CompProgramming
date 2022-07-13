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
typedef unsigned long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int N = 150000;

ll GCD(ll a, ll b)
{
   if (b==0) return a;

   return GCD(b,a%b);
}

ll LCM(ll a, ll b)
{
   return b*a/GCD(a,b);
}

ll a[N], b[N];


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, moron, think it through
	ll n; cin >> n >> a[0] >> b[0];
	if(n == 1){
		cout << a[0] << endl;
		return 0;
	}
	ll gcdoflcm = LCM(a[0], b[0]);
	for(int i = 1; i < n; i++){
		cin >> a[i] >> b[i];
		gcdoflcm = GCD(gcdoflcm, LCM(a[i], b[i]));
	}
	//reduce down the gcdoflcm so that it's less than every chosen element in each pair but still 
	//divides said chosen element

	for(int i = 0; i < n; i++){
		if(GCD(gcdoflcm, a[i]) > 1){
			gcdoflcm = GCD(gcdoflcm, a[i]);
		}
		if(GCD(gcdoflcm, b[i]) > 1){
			gcdoflcm = GCD(gcdoflcm, b[i]);
		}
	}

	if(gcdoflcm == 1) cout << -1 << endl;
	else{
		cout << gcdoflcm << endl;
	}
	//literally have to go over things over and over that I clearly knew and can restate but 
	//still feel unsure of

}