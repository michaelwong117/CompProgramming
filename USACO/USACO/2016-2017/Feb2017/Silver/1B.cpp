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


//2 seconds runtime
//256 megabytes
//X - incorrect, T - time limit, ! - runtime or memory
//E = empty output file, M - missing output file
//make sure that you have correct finder/terminal directories

int main(){
	ifstream fin ("helpcross.in");
	ofstream fout ("helpcross.out");
	int C, N, count = 0;
	fin >> C >> N;
	vector<int> T (C);
	map<int, set<int>> m;
	for(int i = 0; i < C; i++){
		fin >> T[i];
		// cout << T[i] << endl;
	}
	for(int i = 0; i < N; i++){
		int A, B;
		fin >> A >> B;
		if(m.count(A) == 0){
			m[A] = {B};
		}
		else{
			m[A].insert(B);
		}

	}
	sort(T.begin(), T.end(), greater<int>());
	// for(auto t: T){
	// 	cout << t << endl;
	// }
	// for(auto a: pairs){
	// 	cout << a.first << " " << a.second << endl;
	// }



	//while all is have not been viewed and last j has not been paired
	//if you can pair it, pair them and move up one on each side
	//if you can't pair it, move up the A and B constraints
	//if you can pair it now, move both up again
	//if you still can't pair it, move up the i
	for(int i = 0; i < T.size(); i++){
		map<int, set<int>>::iterator it = m.upper_bound(T[i]);
		if(it != m.begin()){
			it--;
			set<int>::iterator sit = m[it->first].lower_bound(T[i]);
			// cout << it->first << " " << *sit << endl;
			if(sit != m[it->first].end()){
				m[it->first].erase(sit);
				if(m[it->first].empty()){
					m.erase(it);
				}
				count++;
			}
		}
	}
	fout << count << endl;

}






