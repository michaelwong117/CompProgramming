/*
ID: michaelwong11
PROG: ariprog
LANG: C++14     
*/
#include <iostream> 
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// bool subset(set<int> bisquares, set<int> seq){

// 	for(auto s: seq){

// 		if(bisquares.find(s) == bisquares.end()){
// 			//can't find an element of the sequence

// 			return false;
// 		}
	
// 	}
// 	return true;

// }


int main(){

	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	int N, M;
	int b;
	set<int> bisquares;
	vector<set<int>> sequences;
	vector<vector<int>> output;
	fin >> N >> M;
	for(int i = 0; i <= M; i++){
		for(int j = 0; j <= M; j++){
			bisquares.insert((i*i)+(j*j));
			// cout << i*i+j*j << endl;

		}
	}
	// for(auto i: bisquares){
	// 	cout << i << endl;
	// }

	int i = 0;
	//if the element in the arithmetic progressions is greater or equal to the 
	//the last element, stop searching
	// cout << *bisquares.rbegin() << endl;
	// cout << bisquares.size() << endl;
	for(auto a: bisquares){
		// cout << a << endl;
		for(b = 1; (b*(N-1))+a <= (*bisquares.rbegin()); b++){
			set<int> aprg;
			for(int n = 0; n < N; n++){
				// cout << a+i*b << endl;
				if(bisquares.find(a+(n*b)) == bisquares.end()){
					
					break;
				}
				aprg.insert(a+(n*b));

			}
			// for(auto i: aprg){
			// 	cout << i << endl;
			// }
			if(aprg.size() == N){
				sequences.push_back(aprg);
			}

		}
	}

	// for(auto seq: sequences){
	// 	//write subset function
	// 	if(subset(bisquares, seq) == false){
	// 		continue;
	// 	}
	// 	vector<int> diff;
	// 	for(auto s: seq){

	// 		diff.push_back(s);
	// 		if(diff.size()>1){
	// 			break;
	// 		}

	// 	}
	// 	// vector<int> debug;
	// 	// for(auto c: seq){
	// 	// 	debug.push_back(c);
	// 	// }
	// 	// cout << debug[0] << " " << debug[1] << " " << debug[2] << " " << debug[3] << " " << debug[4] << endl;
	// 	// cout << diff[0] << " " << diff[1] - diff[0] << endl;
	// 	if(subset(bisquares, seq)){
	// 		//print in order
	// 		// int x = *next(seq.begin(), 1);
	// 		// fout << diff[0] << " " << diff[1] - diff[0] << endl;
	// 		output.push_back({diff[0], diff[1] - diff[0]});
	// 	}
	// }
	for(auto seq: sequences){
		vector<int> diff;
		for(auto s: seq){

			diff.push_back(s);
			if(diff.size()>1){
				break;
			}

		}
		output.push_back({diff[0], diff[1] - diff[0]});
	}
	for(int j = 0; j < output.size(); j++){
		for(int k = j+1; k < output.size(); k++){
			if(output[j][1] > output[k][1]){
				iter_swap(output.begin() + j, output.begin() + k);

			}
			else if((output[j][1] == output[k][1]) && (output[j][0] > output[k][0])) {

				iter_swap(output.begin() + j, output.begin() + k);
			}
		}
	}
	for(auto v: output){
		fout << v[0] << " " << v[1] << endl;
	}
	if(output.size() == 0){
		fout << "NONE" << endl;
	}

}





