#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>


#define ll long long
#define fir first
#define sec second

using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;


int main() {
    ofstream fout ("lifeguards.out");
    ifstream fin ("lifeguards.in");
    int N;
    fin >> N;
    set<int> shifts;
    vector<pii> times (2*N);
    for (int i=0; i<N; i++){
        int start, end;
        fin >> start >> end;
        times[2*i] = pii(start, i);
        times[2*i+1] = pii(end, i);
    }
   	sort(times.begin(), times.end());
   	// for(auto a: times){
   	// 	cout << a.fir << " " << a.sec << endl;
   	// }
   	// cout << endl;
   	int covered = 0, last = 0;
   	vector<int> isolated (N);
   	for(int i = 0; i < times.size(); i++){
   		//fir is actual time, sec is index in array
   		// cout << shifts.size() << endl;
   		// cout << times[i].fir << " " << times[i].sec << endl;
   		// cout << last << endl;
   		set<int>::iterator it = shifts.find(times[i].sec);
   		if(shifts.size() == 1){
   			// cout << "isolated " << *shifts.begin() << " += "<< times[i].fir - last << endl;
   			isolated[*shifts.begin()] += times[i].fir - last;
   		}
   		if(!shifts.empty()){
   			covered += times[i].fir - last;
   			// cout << "covered += " << times[i].fir - last << endl;
   		}
   		if(it != shifts.end()){
   			shifts.erase(it);
   			// cout << "erasing " << *it << endl;
   		}
   		else{
   			shifts.insert(times[i].sec);
   			// cout << "inserting " << times[i].sec << endl;
   		}
   		// cout << endl;
   		last = times[i].fir;
   	}
   	int m = -1;
   	for(int i = 0; i < isolated.size(); i++){
   		m = max(m, covered - isolated[i]);
   	}	
   	fout << m << endl;


}
