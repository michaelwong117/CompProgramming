#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;



int main() {
    int n;
    int k;
    int remain;
    int leftoverSeats;
    vector<int> groups;
	cin >> n >> k;
    
	for(int i = 0; i<k; i++){
        int a;
        cin >> a;
        groups.push_back(a);
    }
    for(int group: groups){
        remain = group % 8;
        if(remain == 0){
            continue;
        }
        else{
            
        }
    }
}