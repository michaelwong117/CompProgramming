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
const int N = 1e5+1;
const int K = 17;

struct sfx {
	int rank[2], idx;
};

bool cmp(sfx &a, sfx &b){
	return(a.rank[0] == b.rank[0] ? (a.rank[1] < b.rank[1]) : (a.rank[0] < b.rank[0]));
}


sfx SA[N];
int order[K][N], n;
string s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> s; n = s.size();
	for(int i = 0; i < n; i++){
		order[0][i] = s[i] - 'a';
	}
	int k, jump;
	//building up from powers of two
	//k goes up to ceil(log2(n))
	for(k = 1, jump = 1; jump < n; k++, (jump <<= 1)){
		//jump is 2^(k-1)
		for(int i = 0; i < n; i++){
			//the rank of the first half of the 2^k string from i
			//is the previous final ordering of the 2^(k-1) string from i
			SA[i].rank[0] = order[k-1][i];
			//i will always be less than n, and even if i+k ends up > n
			//that would have already been considered **** (-1e9)
			//in the previous final ordering

			//but if i + jump is out of bounds for N it would not have 
			//been considered in the previous ordering, so just mark it as ****
			if(i + jump >= n) SA[i].rank[1] = -1e9;
			//else the rank of the second half of the 2^k string from i
			//is the previous final ordering of the 2^(k-1) string from i + 2^(k-1)
			else SA[i].rank[1] = order[k-1][i + jump];
			SA[i].idx = i;
		}
		sort(SA, SA + n, cmp);
		for(int i = 0; i < n; i++){
			int I = SA[i].idx, prev = SA[i-1].idx;

			if(i > 0 && SA[i].rank[0] == SA[i-1].rank[0] && SA[i].rank[1] == SA[i-1].rank[1]){
				order[k][I] = order[k][prev];
			}
			else order[k][I] = i;
		}
	}
	int mx = ceil(log2(n)), p = pow(2,k);
	for(int i = 0; i < n; i++){
		cout << order[mx][i] << " " << s.substr(i, p) << endl;
	}
	//"abcd" and "abdd"
	//compare "ab" with "ab", then "cd" with "dd"
	//{"abcd", "abdd"}
	//"abcd" = 1, "abdd" = 2;


}
