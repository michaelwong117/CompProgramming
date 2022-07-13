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
  
// A job has start time, finish time and profit. 
struct Job 
{ 
    int start, finish, profit; 
}; 
  
// A utility function that is used for sorting events 
// according to finish time 
bool myfunction(Job s1, Job s2) 
{ 
    return (s1.finish < s2.finish); 
} 
  
// A Binary Search based function to find the latest job 
// (before current job) that doesn't conflict with current 
// job.  "index" is index of the current job.  This function 
// returns -1 if all jobs before index conflict with it. 
// The array jobs[] is sorted in increasing order of finish 
// time. 
int binarySearch(Job jobs[], int index) 
{ 
    // Initialize 'lo' and 'hi' for Binary Search 
    int lo = 0, hi = index - 1; 
  
    // Perform binary Search iteratively 
    while (lo <= hi) 
    { 
        int mid = (lo + hi) / 2; 
        if (jobs[mid].finish <= jobs[index].start) 
        { 
            if (jobs[mid + 1].finish <= jobs[index].start) 
                lo = mid + 1; 
            else
                return mid; 
        } 
        else
            hi = mid - 1; 
    } 
  
    return -1; 
} 
  
// The main function that returns the maximum possible 
// profit from given array of jobs 
int findMaxProfit(Job arr[], int n) 
{ 
    // Sort jobs according to finish time 
    sort(arr, arr+n, myfunction); 
  
    // Create an array to store solutions of subproblems.  table[i] 
    // stores the profit for jobs till arr[i] (including arr[i]) 
    int *table = new int[n]; 
    table[0] = arr[0].profit; 
  
    // Fill entries in table[] using recursive property 
    for (int i=1; i<n; i++) 
    { 
        // Find profit including the current job 
        int inclProf = arr[i].profit; 
        int l = binarySearch(arr, i); 
        if (l != -1) 
            inclProf += table[l]; 
  
        // Store maximum of including and excluding 
        table[i] = max(inclProf, table[i-1]); 
    } 
  
    // Store result and free dynamic memory allocated for table[] 
    int result = table[n-1]; 
    delete[] table; 
  
    return result; 
} 
  
// Driver program 
int main() 
{ 
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("input.in","r",stdin); //freopen("input.out","w",stdout);
    int m; int n; cin >> m >> n;   
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Optimal profit is " << findMaxProfit(arr, n); 
    return 0; 
} 