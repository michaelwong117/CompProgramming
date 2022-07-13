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
#define fir first
#define sec second


using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;

//set tab size to 3

bool overlapping(x1,x2,y1,y2){

    return max(x1,y1) <= min(x2,y2)
}

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("lifeguards.in");
	ofstream fout("lifeguards.out");
	int N;
	fin >> N;
	vector<pii> v;
	vector<pii> overlap (N);
	int a, b, temp;
	for(int i = 0; i < N; i++){
		fin >> a >> b;
		v.push_back(pii(a, b));
	}
	sort(v.begin(), v.end());
	overlap[0] = pii(0, 0);
	for(int i = 1; i < v.size(); i++){
		if(v[i-1].sec >= v[i].fir){
			overlap[i-1].sec += v[i-1].sec - v[i].fir + 1;
			overlap[i].fir += v[i-1].sec - v[i].fir + 1;
		}
	}
	vector<pii> cont;
	int start = 0;
	for(int i = 0; i < overlap.size(); i++){
		if(overlap[i].sec == 0 || i == overlap.size()-1){
			cont.push_back(pii(start, i));
			start = i+1;
		}
	}
	// for(auto a: cont){
	// 	cout << a.fir << " " << a.sec << endl;
	// }
	int max = 0;
	for(auto a: cont){
		if(a.sec - a.fir + 1 < N){
			if(v[a.sec].sec - v[a.fir].fir > max){
				max = v[a.sec].sec - v[a.fir].fir;
			}
		}
		else{
			for(int i = a.fir; i < a.sec; i++){
				for(int j = 0; j < a.sec; j++){
					if(i == j) continue;
					
				}
			}
		}
		// cout << a.fir << " " << a.sec << endl;
	}
	fout << max << endl;









}