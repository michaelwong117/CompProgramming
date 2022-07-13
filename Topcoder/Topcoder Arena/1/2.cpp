#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define ll long long

using namespace std;

class OvercookedDiv2 {
    public:
    	int minStale(vector<int> start, vector<int> time);
};

int OvercookedDiv2::minStale(vector<int> start, vector<int> time) {
    //step 0 to n
    //step[i] takes time[i]
    //step[i] can only be started when stopwatch reaches start[i]
    //steps can only be started on ints
    //the waiting time for step 2 is the idle time after executing step 1 
    //to the time it takes for step 2 to start
    int minWait = start[0], pastWait = minWait;
    for(int i = 0; i < start.size()-1; i++){
        int pass = start[i] + time[i];
        if(pass < start[i+1]){
            int avg = (start[i+1] - pass + pastWait) / 2;
            if((start[i+1] - pass + pastWait) % 2 != 0){
                avg++;
            }
            // cout << avg << endl;
            if(start[i+1] - pass > minWait){
                
                if(start[i+1] - pass > avg){
                    minWait = avg;
                    pastWait = minWait;

                }
                else{
                    minWait = start[i+1] - pass;
                    pastWait = minWait;
                }
            
            }
            else{
                pastWait = 0;
            }
        }


    }
    return minWait;


}

