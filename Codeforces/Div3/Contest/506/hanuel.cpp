#include <bits/stdc++.h>
using namespace std;
int a [200010];
int main() {
    freopen("input.in","r",stdin);
    vector<int> breaks;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    breaks.push_back(-1);
    for(int i = 0; i < n - 1; i++) {
        if(a[i + 1] > a[i] * 2) breaks.push_back(i);
    }
    breaks.push_back(n - 1);
    int ans = -1;
    for(int i = 0; i < breaks.size() - 1; i++) {
        ans = max(ans, breaks[i + 1] - breaks[i]);
    }
    cout << ans << endl;
}