/*
ID: michaelwong11
PROG: ariprog
LANG: C++14     
*/
#include <iostream> 
#include <fstream>
// #include <set>
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
	vector<int> bisquares;
	char arr[125000] = {};
	fin >> N >> M;
	for(int i = 0; i <= M; i++){
		for(int j = 0; j <= i; j++){
			arr[i*i+j*j] = 1;

			bisquares.push_back(i*i+j*j);


		}
	}
	sort(bisquares.begin(), bisquares.end());

	//if the element in the arithmetic progressions is greater or equal to the 
	//the last element, stop searching

	for(auto a: bisquares){
		for(b = 1; (b*(N-1))+a <= (2 * M*M); b++){
			vector<int> aprg;
			for(int n = 0; n < N; n++){
				// cout << a+i*b << endl;
				if(arr[a+(n*b)] == 1){
					// cout << a+n*b << endl;
					
					aprg.push_back(a+(n*b));
				}

			}
			// cout << aprg.size() << endl;
			if(aprg.size() == N){
				sequences.push_back(aprg);
			}

		}
	}

	
	for(auto seq: sequences){
		output.push_back({seq[0], seq[1] - seq[0]});
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





