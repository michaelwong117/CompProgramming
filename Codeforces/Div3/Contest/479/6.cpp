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

 
// Function for LIS
int findLIS(int A[], int n)
{
    unordered_map<int, int> hash;
 
    // Initialize result
    int LIS_size = 1;
    int LIS_index = 0;
 
    hash[A[0]] = 1;
 
    // iterate through array and find
    // end index of LIS and its Size
    for (int i = 1; i < n; i++) {
        hash[A[i]] = hash[A[i] - 1] + 1;
        if (LIS_size < hash[A[i]]) {
            LIS_size = hash[A[i]];
            LIS_index = A[i];
        }
    }
 
    // print LIS size
    cout << "LIS_size = " << LIS_size << "\n";
 
    // print LIS after setting start element
    cout << "LIS : ";
    int start = LIS_index - LIS_size + 1;
    while (start <= LIS_index) {
        cout << start << " ";
        start++;
    }
}
 
// driver
int main(){
	int n; cin >> n;
	int A[n];
	rep(i, n){
		cin >> A[i];
	}
    n = sizeof(A) / sizeof(A[0]);
    findLIS(A, n);
    return 0;
}