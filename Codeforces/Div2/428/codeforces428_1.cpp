#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


int main() {
    int n;
    int k;
    vector<int> v;
    int sum = 0;
    int remain = 0;
    int leftover = 0;
	cin >> n >> k;
    for(int i = 0; i<n; i++){
        int curCandy = 0;
        cin >> curCandy;
        v.push_back(curCandy);
    }
    for(int i = 0; i < n; i++){
        remain = v[i];
        if(remain > 8){
            leftover += remain - 8;
            remain -= remain - 8;
        }
        if(remain < 8){
            if(leftover >= 8-remain){
                leftover -= 8-remain;
                remain += 8-remain;
            }
            else{
                remain += leftover;
                leftover = 0;
            }
        }

        sum += remain;
        if(sum >= k){
            cout << i+1 << endl;
            break;
        }


    }
    if(sum < k){
        cout << -1 << endl;
    }

}