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
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

int dig[10], iter[10];
ll fac[19];

void genfac(){
	fac[0] = 1;
	for(int i = 1; i <= 18; i++){
		fac[i] = i*fac[i-1];
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	string s; cin >> s;
	int uniq = 0;
	rep(i, s.size()){
		dig[s[i] - '0']++;
		if(dig[s[i]- '0'] == 1) iter[s[i] - '0'] = 1;
	}
	genfac();
	ll pos = 0;
	for(int z = 1; z <= 9; z++){
		if(dig[z] == 0) continue;
		dig[z]--;
		iter[z] = 0;
		// cout << z << " " << dig[z] << " " << iter[z] << endl;
		for(int a = iter[0]; a <= dig[0]; a++){
			for(int b = iter[1]; b <= dig[1]; b++)
				for(int c = iter[2]; c <= dig[2]; c++)
					for(int d = iter[3]; d <= dig[3]; d++)
						for(int e = iter[4]; e <= dig[4]; e++)
							for(int f = iter[5]; f <= dig[5]; f++)
								for(int g = iter[6]; g <= dig[6]; g++)
									for(int h = iter[7]; h <= dig[7]; h++)
										for(int i = iter[8]; i <= dig[8]; i++)
											for(int j = iter[9]; j <= dig[9]; j++){
												// cout<<a<<b<<c<<d<<e<<f<<g<<h<<i<<j<<endl;
												// cout << a+b+c+d+e+f+g+h+i+j << " " << fac[a+b+c+d+e+f+g+h+i+j] << endl;
												// cout << fac[a]*fac[b]*fac[c]*fac[d]*fac[e]*fac[f]*fac[g]*fac[h]*fac[i]*fac[j] << endl;
												pos += fac[a+b+c+d+e+f+g+h+i+j] / (fac[a]*fac[b]*fac[c]*fac[d]*fac[e]*fac[f]*fac[g]*fac[h]*fac[i]*fac[j]);
											}


		}
		iter[z] = 1;
		dig[z]++;
	}
	out(pos);


}