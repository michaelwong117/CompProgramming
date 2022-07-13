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
	vector<pii> pairs;
	for(int i = 0; i < C; i++){
		fin >> T[i];
		// cout << T[i] << endl;
	}
	for(int i = 0; i < N; i++){
		int A, B;
		fin >> A >> B;
		pairs.push_back(pii(A, B));

	}
	sort(pairs.begin(), pairs.end());
	sort(T.begin(), T.end());
	// for(auto a: pairs){
	// 	cout << a.first << " " << a.second << endl;
	// }



	//while all is have not been viewed and last j has not been paired
	//if you can pair it, pair them and move up one on each side
	//if you can't pair it, move up the A and B constraints
	//if you can pair it now, move both up again
	//if you still can't pair it, move up the i
	
	int i = 0, j = 0, lp = 0;
	while(i < T.size() && j < pairs.size()){
		cout << pairs[j].first << " " << T[i] << " " << pairs[j].second << endl;
		if(pairs[j].first <= T[i] && T[i] <= pairs[j].second){
			lp = j+1;
			// cout << lp << endl;
			count++;
			i++;
			j++;
		}
		else{
			if(j < pairs.size()-1){
				j++;
			}
			else{
				i++;
				j = lp;
			}
		}
	}



	fout << count << endl;

}






