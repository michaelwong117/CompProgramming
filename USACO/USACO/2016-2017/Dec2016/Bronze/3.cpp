
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){

	ofstream fout("cowsignal.out");
	ifstream fin("cowsignal.in");

	int M, N, K;
	fin >> M >> N >> K;
	vector<string> inputSig;
	vector<string> enlargedSig;
	for(int i = 0; i < M; i++){
		string line;
		fin >> line;
		inputSig.push_back(line);

	}
	for(auto l: inputSig){
		string row;
		for(char c: l){

			if(K == 1){
				row += c;
			}
			else if(K == 2){
				row += c;
				row += c;
			}
			else if(K == 3){
				row += c;
				row += c;
				row += c;
			}
			else if(K == 4){
				row += c;
				row += c;
				row += c;
				row += c;

			}
			else if(K == 5){
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;

			}
			else if(K == 6){
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;

			}
			else if(K == 7){
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;

			}
			else if(K == 8){
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
			}
			else if(K == 9){
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
			}
			else if(K == 10){
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
				row += c;
			}
		}
		if(K == 1){
			enlargedSig.push_back(row);
		}
		else if(K == 2){
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
		}
		else if(K == 3){
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
		}
		else if(K == 4){
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
		}
		else if(K == 5){
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
		}
		else if(K == 6){
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);

		}
		else if(K == 7){
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
		}
		else if(K == 8){
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);

		}
		else if(K == 9){
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);

		}
		else{
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
			enlargedSig.push_back(row);
		}
	}
	for(auto l: enlargedSig){
		fout << l << endl;
	}

}