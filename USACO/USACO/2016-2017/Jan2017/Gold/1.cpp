#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>>
#define mpq priority_queue<int>
 
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int mx = 1e5;
int N, a[mx], c = 0;
vpi v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("bphoto.in","r",stdin); freopen("bphoto.out","w",stdout);
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]); v.pb({a[i],i+1});
	}
	sort(all(v),greater<pi>());
	for(int i = 0; i < v.size(); i++){
		int x = 0, y = 0;
		for(int j = 0; j < i; j++){
			if(v[j].s < v[i].s) x++;
			else y++;
		}
		if(max(x,y) > min(x,y)*2) c++;
	}
	printf("%d\n", c);



	
}