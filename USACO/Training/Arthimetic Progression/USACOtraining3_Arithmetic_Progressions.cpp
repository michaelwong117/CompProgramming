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
#include <map>

using namespace std;
//rightmost pivot
int partition(int *a, int start, int end){
//rearrange array from start to end so that all elements less than pivot are left and all elements
//greater are right
	int pivot = a[end];
	int pIndex = start;
	for(int i = 1; i < end; i++){
		if(a[i] <= pivot){
			swap(a[pIndex], a[i]);
			pIndex++;
		}
	}
	swap(a[pIndex], a[end]);
	return pIndex;

}

void quickSort(int *a, int start, int end){
	//intiially start will be 0 and end will be length-1

	//base case handles if there is one element, and if invalid

	if(start < end){

		int pIndex = partition(a, start, end);
		quickSort(a, start, pIndex-1);
		quickSort(a, pIndex+1, end);
	}

}




int main(){

	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	int N, M;
	int b;
	vector<vector<int>> sequences;
	vector<vector<int>> output;
	// vector<int> bisquares;
	int arr[125001] = {};
	fin >> N >> M;
	for(int i = 0; i <= M; i++){
		for(int j = 0; j <= i; j++){
			arr[i*i+j*j] = 1;

			// bisquares.push_back(i*i+j*j);
			// cout << i*i+j*j << endl;


		}
	}
	// sort(bisquares.begin(), bisquares.end());


	//if the element in the arithmetic progressions is greater or equal to the 
	//the last element, stop searching

	// for(int i = 0; i < bisquares.size(); i++){
	// 	bool valid = true;
	// 	int commonDiff = bisquares[i+1] - bisquares[i];
	// 	for(int n = i+1; n < N+i; n++){
	// 		if(bisquares[n] - bisquares[i] != commonDiff*(n-i)){
	// 			valid = false;
	// 			break;
	// 		}
	// 	}
	// 	if(valid){
	// 		sequences.push_back({bisquares[i], commonDiff});
	// 	}
	// }
	for(int i = 0; i < 125001; i++){
		if(arr[i] == 0){
			continue;
		}
		int j = (125000 - i) / (N-1);
		for(j = j; j > 0; j--){
			for(int a = 0; a < N; a++){
				if(arr[i+(a*j)] == 0){
					break;
				}
				if(a == N-1){
					output.push_back({i, j});
				}
			}
		}
	}

	
	for(auto seq: sequences){
		output.push_back({seq[0], seq[1]});
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





