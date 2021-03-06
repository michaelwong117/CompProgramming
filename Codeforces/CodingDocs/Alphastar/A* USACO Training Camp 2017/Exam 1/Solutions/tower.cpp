// solution written by Monika Steinova
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
        long long N, D;
        cin >> N >> D;

        vector<long long> V(N);
        for (int i=0; i<N; ++i) cin >> V[i];
        sort(V.begin(),V.end());

        long long answer = 1;
        for (int lo=0, hi=1; hi<N; ++hi) {
                while (V[hi]-V[lo] > D) ++lo;
                answer = (answer * (hi-lo+1)) % 1000000009;
        }
        cout << answer << endl;
}
