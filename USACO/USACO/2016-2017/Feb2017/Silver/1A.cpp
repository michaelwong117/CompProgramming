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

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b){
    return (a.second < b.second);
}

int l_bound(vector<int> a, int key) {
  if (key > a[a.size()-1])
    return -1;

  int lo = 0, hi = a.size() - 1;

  while(lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (a[mid] == key)
      return mid;
    else if (a[mid] < key)
      lo = mid;
    else
      hi = mid - 1;
  }

  return lo;
}

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
	sort(pairs.begin(), pairs.end(), sortbysec);
	sort(T.begin(), T.end());

	for(auto a: pairs){
		cout << a.first << " " << a.second << endl;
	}
	for(auto a: T){
		cout << a << endl;
	}

	//find the first element that satisfies the lowest number

	int j = 0;
	for(int i = 0; i < T.size(); i++){
		//finds first pair that satisfies b condition
		while(j < pairs.size() || T[i] > pairs[j].sec){
			cout << T[i] << " " << pairs[j].fir << " " << pairs[j].sec << endl;
			j++;
		}
		if(T[i] < pairs[j].fir){
			l_bound(T, pairs[j].fir);
		}
		if(i == T.size() || j == pairs.size()){
			break;
		}
		if(pairs[j].fir <= T[i] && 
			T[i] <= pairs[j].sec){
			j++;
			count++;
		}
		

	}
	

	
	cout << count << endl;





	//while all is have not been viewed and last j has not been paired
	//if you can pair it, pair them and move up one on each side
	//if you can't pair it, move up the A and B constraints
	//if you can pair it now, move both up again
	//if you still can't pair it, move up the i
	
	



	fout << count << endl;

}






