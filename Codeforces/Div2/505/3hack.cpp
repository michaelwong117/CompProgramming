#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("input.in","r",stdin);
	string s; cin >> s;
	s += s;
	int cnt = 1, maxV = -1;
	for(int i = 0; i < s.size()-1; i++){
		if(s[i] != s[i+1]) cnt++;
		else cnt = 1;
		maxV = max(maxV, cnt);
	}
	cout << min(maxV, (int)s.size() / 2) << endl;
}