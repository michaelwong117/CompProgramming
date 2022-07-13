//g++ filename.cpp -std=c++14 -DH
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define endl '\n'
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<pi, vector<pi>, greater<pi>>
#define mpq priority_queue<pi>
 
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int mx = 1e3+1;
int a[mx], b[mx];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("filename.in"); ofstream fout("filename.out");
	int n, k1, k2; cin >> n >> k1 >> k2;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	mpq q;
	for(int i = 0; i < n; i++){
		q.push({abs(a[i]-b[i]),i});
	}
	int cont = max(k1, k2);
	while(cont){
		pi ft = q.top(); q.pop();
		int i = ft.s; 
		min(abs(a[i]-b[i]),max(k1,k2));
		if(a[i] > b[i]){
			if(k1 > 0){
				a[i]--;
				k1--;
			}
			else if(k2 > 0){
				b[i]++;
				k2--;
			}
		}
		else if(a[i] < b[i]){
			if(k1 > 0){
				a[i]++;
				k1--;
			}
			else if(k2 > 0){
				b[i]--;
				k2--;
			}
		}
		else{
			if(k1 > 0){
				a[i]++;
				k1--;
			}
			else if(k2 > 0){
				b[i]++;
				k2--;
			}
		}
		q.push({abs(a[i]-b[i]),i});
		cont = max(k1, k2);
	} 
	ll sum = 0;
	for(int i = 0; i < n; i++){
		sum += (ll)(a[i]-b[i])*(ll)(a[i]-b[i]);
	}
	cout << sum << endl;


	
}