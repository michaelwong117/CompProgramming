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
#define pq priority_queue<int, vector<int>, greater<int>>
#define mpq priority_queue<int>
 
typedef long long ll; typedef vector<int> vi;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

const int maxN = 1e5; 
int a[maxN];

int GCD(int a, int b)
{
   if (b==0) return a;

   return GCD(b,a%b);
}
int coprime(int can, int bound, int flag){
	if(flag) bound = 2;
	for(int i = bound; ; i++){
		bool done = 1;
		for(int j = 0; j < can; j++){
			if(GCD(a[j],i) != 1) done = 0;
		}
		if(done && i != bound) return i;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("filename.in"); ofstream fout("filename.out");
	int n; fin >> n;
	for(int i = 0; i < n; i++) fin >> a[i];
	int ft = a[0];
	if(ft < 2) ft = 2;
	cout << ft << " ";
	int flag = 0;
	for(int i = 1; i < n-1; i++){
		int nx = coprime(i, a[i], flag);
		cout << nx << " ";
		if(nx > a[i]) flag = 1;
	}
	cout << coprime(n-2, a[n-1]+1, flag) << endl;
}