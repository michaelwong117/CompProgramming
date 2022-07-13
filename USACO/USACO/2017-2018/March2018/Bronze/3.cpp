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
const int maxN = 102;
int N;
string daughter[maxN], mother[maxN];
 
// returns mother of cow, or "" if mother does not exist
string mothers(string cow){
	for(int i=0;i<N;i++)
		if(cow == daughter[i]) return mother[i];
	return "";
}
 
// returns number of generations by which cow1 is removed from cow2
// if cow1 is a direct ancestor of cow2.
// returns -1 otherwise.
int ancestor(string cow1, string cow2){
	int c = 0;
	while(cow2 != ""){
		if(cow1 == cow2) return c;
		cow2 = mothers(cow2);
		c++;
	}
	return -1;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("family.in"); ofstream fout("family.out");
	string u, v;
	fin >> N >> u >> v;
	for(int i=0;i<N;i++) fin >> mother[i] >> daughter[i];
	string cow = u;
	int b = 0;
	while(cow != ""){
		if(ancestor(cow, v) != -1) break;
		cow = mothers(cow);
		b++;
	}
	if(cow == ""){
		fout << "NOT RELATED" << endl;
		return 0;
	}
	int a = ancestor(cow, v);
	if(a == 1 && b == 1) fout << "SIBLINGS" << endl;
	else if(a > 1 && b > 1) fout << "COUSINS" << endl;
	else{
		if(a > b) swap(v, u), swap(a, b);
		fout << v << " is the ";
		for(int i=0;i<b-2;i++) fout << "great-";
		if(b > 1 && a == 0) fout << "grand-";
		if(a == 0) fout << "mother";
		else fout << "aunt";
		fout << " of " << u << endl;
	}
}