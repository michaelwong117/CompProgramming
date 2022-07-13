/*

ID: michaelwong11
PROG: numtri
LANG: C++14

*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;


vector<int> calculateHighest(const vector<vector<int>> & numtri, int n){
	vector<int> final;
	if(n < numtri.size()-1){

		vector<int> out = calculateHighest(numtri, n+1);
		vector<int> smallTri = numtri[n];

		//the first elemnt of out is the rightmost sum

		//the last element of out is the leftmost sum

		//any element can only be matched with the elements up to the left and right	



		for(int i = 0; i < out.size()-1; i++){
			//add the elements directly left and right of the position of the number, not the sum
			final.push_back(max(out[i] + smallTri[i], out[i+1] + smallTri[i]));
		}
	}
	else if(n == numtri.size()-1){
		return numtri[n];
	}

	return final;

}


int main(){
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");
	vector<vector<int>> numtri;
	int R;
	fin >> R;
	for(int i = 1; i <= R; i++){
		vector<int> row;
		for(int j = 0; j < i; j++){
			int elem;
			fin >> elem;
	 		row.push_back(elem);
		}
		numtri.push_back(row);
	}
	
	vector<int> finalRow = calculateHighest(numtri, 0);
	// vector<int> test = calculateHighest(numtri, -1);
	// for(auto i: finalRow){
	// 	cout << i << endl;
	// }
	fout << finalRow[0] << endl;











	// for(auto a: numtri){
	// 	for(int i = 0; i < a.size(); i++){
	// 		if(i == a.size()-1){
	// 			fout << a[i] << endl;
	// 		}
	// 		else{
	// 			fout << a[i] << " ";
	// 		}
	// 	}

	// }



	//solve for smaller subtriangles


}









