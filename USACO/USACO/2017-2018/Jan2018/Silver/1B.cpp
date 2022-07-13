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

//set tab size to 3

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b){
    return (a.second < b.second);
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
	int max = 0;
	for(int i = 0; i < N; i++){
		fin >> a >> b;
		v.push_back(pii(a, b));
	}
	sort(v.begin(), v.end());
	vector<pii> cont; 
	pii start;
	for(int i = 0; i < v.size(); i++){
		if(i == 0){
			start = pii(v[i].sec, i);
		}
		else{
			if(v[i].fir <= start.fir){
				if(v[i].sec > start.fir){
					// cout << v[i].sec << " " << start.fir << endl;
					start.fir = v[i].sec;
				}
			}
			if(v[i].fir > start.fir){
				cont.push_back(pii(start.sec, i-1));
				start = pii(v[i].sec, i);
				// cout << start.fir << " " << start.sec << endl;
			}
			if(i == v.size()-1){
				// cout << start.sec << " " << i << endl;
				cont.push_back(pii(start.sec, i));
			}
			
		}
	}
	// for(auto a: cont){
	// 	cout << a.fir << " " << a.sec << endl;
	// 	cout << v[a.sec].sec << " " << v[a.fir].fir << endl;
	// }
	for(auto a: cont){
		// cout << a.sec << " " << a.fir << endl;
		if(a.sec - a.fir + 1 < N){
			// cout << a.sec << " " << a.fir << " " << v[a.sec].sec << " ";
			// cout << v[a.fir].fir << endl;
			if(v[a.sec].sec - v[a.fir].fir + 1 > max){
				max = v[a.sec].sec - v[a.fir].fir + 1;
			}
		}
		else{
			for(int i = a.fir; i < a.sec; i++){
				// cout << "ommiting " << i << endl;
				//calculating the first part's range
				if(i == a.fir){
					// cout << v[a.sec].sec - v[a.fir+1].fir + 1 << endl;
					if(max < v[a.sec].sec - v[a.fir+1].fir + 1){
						// cout << v[a.sec].sec - v[a.fir+1].fir + 1 << endl;
						max = v[a.sec].sec - v[a.fir+1].fir + 1;
						// cout << max << endl;
					}
					continue;
				}
				else if(i == a.sec-1){
					// cout << v[a.sec-1].sec - v[a.fir].fir + 1 << endl;
					if(max < v[a.sec-1].sec - v[a.fir].fir + 1){
						// cout << v[a.sec-1].sec - v[a.fir].fir + 1 << endl;
						max = v[a.sec-1].sec - v[a.fir].fir + 1;
						// cout << max << endl;

					}
					continue;
				}
				pii firstp = pii(a.fir, i-1), secondp = pii(i+1, a.sec);
				if(max < v[firstp.sec].sec - v[firstp.fir].fir + 1){
					// cout << v[firstp.sec].sec << " " << v[firstp.fir].fir << " ";
					// cout << firstp.sec << " " << firstp.fir << endl;
					max = v[firstp.sec].sec - v[firstp.fir].fir + 1;
					// cout << max << endl;

				}
				//calculating the second part's range
				if(max < v[secondp.sec].sec - v[secondp.fir].fir + 1){
					// cout << v[secondp.sec].sec << " " << secondp.sec << " ";
					// cout << v[secondp.fir].fir << " " << secondp.fir << endl;
					max = v[secondp.sec].sec - v[secondp.fir].fir + 1;
					// cout << max << endl;

				}
			
				
			}	
		}
		// cout << a.fir << " " << a.sec << endl;
	}
	fout << max << endl;









}