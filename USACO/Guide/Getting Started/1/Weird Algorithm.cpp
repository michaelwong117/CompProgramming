//g++ filename.cpp -std=c++14
#include <bits/stdc++.h>
using namespace std;
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

int main()
{
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	ll n; cin >> n;
	while(1){
		if(n == 1){
			cout << n << endl;
			break;
		}
		cout << n << " ";
		if(n % 2 == 0){
			n /= 2;
		}
		else{
			n *= 3;
			n += 1;
		}
	}
}
