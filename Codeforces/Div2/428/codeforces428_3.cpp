#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


int main() {
    int n;
    vector<vector<int>> cities;
    map<int,int> visited;
    cin >> n;
    for(int i = 0; i<n-1; i++){
        int start;
        int end;
        cin >> start >> end;
        cities.push_back({start, end});
        if(visited.count(start) != 0){
            visited[start]++;
            // cout << "start = " << start << endl;
        }
        else if(visited.count(end) == 0){
            visited[end] = 1;
            // cout << "end = " << end << endl;
        }
        
        //if you've already visited the city before, increment the count if you see that same city as the starting point.
        //if you haven't visited the city before, start a new count for that specific path.



    }
    int i = 0;
    for(auto x: visited){
        i += x.second;
    }
    double expectedValue = i / (double) visited.size();
    cout << expectedValue << endl;

}