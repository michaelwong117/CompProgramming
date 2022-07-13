#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, x, k;
	cin >> n >> x >> k;
	vector<int> a(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	sort(a.begin(), a.end());
	
	long long cnt = 0;
	
	for (int i = 0; i < n; i++) {
		vector<int>::iterator l = lower_bound(a.begin(), a.end(), max((long long)a[i], (long long)x * (k + (a[i] - 1) / x)));
		vector<int>::iterator r = lower_bound(a.begin(), a.end(), max((long long)a[i], (long long)x * (k + 1 + (a[i] - 1) / x)));
		
		cnt += r - l;
	}
	
	cout << cnt;
}