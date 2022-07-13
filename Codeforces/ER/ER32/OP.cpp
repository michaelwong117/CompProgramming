#include <bits/stdc++.h>
using namespace std;

int max_mod_sum(const vector<int>& A, int M) {
    vector<int> P(A.size());
    for (int i = 0; i < A.size(); ++i)
        P[i] = (A[i] + (i > 0 ? P[i-1] : 0)) % M;
    set<int> S;
    int res = 0;
    for (int i = A.size() - 1; i >= 0; --i) {
        S.insert(P[i]);
        int a = (A[i] - P[i] + M) % M;
        auto it = S.lower_bound(M - a);
        if (it != begin(S))
            res = max(res, *prev(it) + a);
        res = max(res, (*prev(end(S)) + a) % M);
    }
    return res;
}

int main() {
    // random testing to the rescue
    for (int i = 0; i < 1000; ++i) {
        int M = rand() % 1000 + 1, n = rand() % 1000 + 1;
        vector<int> A(n);
        for (int i = 0; i< n; ++i)
            A[i] = rand() % M;
        int should_be = 0;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum = (sum + A[j]) % M;
                should_be = max(should_be, sum);
            }
        }
        assert(should_be == max_mod_sum(A, M));
    }
}