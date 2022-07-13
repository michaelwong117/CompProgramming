#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;


int ubound(vector<int> &v, int key){
	int low = 0, high = v.size()-1;
	while(low < high){

		int mid = (high+low)/2;
		if(v[mid] == key){

			return mid;
		}

		if(v[mid] < key){
			low = mid+1;
		}
		else{
			high = mid;
		}
	}
	if(v[low] > key){
		return low-1;
	}

	return low;

}
int lbound(vector<int> &v, int key){
	int low = 0, high = v.size()-1;
	while(low < high){

		int mid = (high+low)/2;
		if(v[mid] == key){

			return mid;
		}

		if(v[mid] < key){
			low = mid+1;
		}
		else{
			high = mid;
		}
	}
	if(v[low] < key){
		return low+1;
	}

	return low;


}
// first element >= x
// int l = lower_bound(haybales, 0, haybales.size()-1, a);
// search index for everything greater than or equal to b  
// v = lower_bound(haybales, 0, haybales.size()-1, b+1);
// find index for everything less than or equal b
int lower_bound(vector<int> &v, int low, int high, int key){
	while(low < high){

		int mid = (high+low)/2;
		if(v[mid] == key){

			return mid;
		}

		if(v[mid] < key){
			low = mid+1;
		}
		else{
			high = mid;
		}
	}
	if(v[low] < key){
		return low+1;
	}

	return low;


}
//first element > x
int upper_bound(vector<int> &v, int low, int high, int key){
	while(low < high){

		int mid = (high+low)/2;
		if(v[mid] == key){

			return mid;
		}

		if(v[mid] < key){
			low = mid+1;
		}
		else{
			high = mid;
		}
	}
	if(v[low] <= key){
		return low+1;
	}

	return low;
}

int findBetween(vector<int> &v, int a, int b){


	return ubound(v, b) - lbound(v, a) + 1;




}

int main(){

	ifstream fin("haybales.in");
	ofstream fout("haybales.out");
	// vector<int> v = {2, 3, 5, 7};
	// cout << findBetween(v, 1, 6) << endl;
	int N, Q;
	fin >> N >> Q;
	vector<int> haybales;
	for(int i = 0; i < N; i++){
		int coord;
		fin >> coord;
		haybales.push_back(coord);
	}

	sort(haybales.begin(), haybales.end());

	for(int i = 0; i < Q; i++){
		int a, b;
		fin >> a >> b;
		// fout << ubound(haybales, b) - ubound(haybales, a) << endl;
		// fout << findBetween(haybales, a, b) << endl;
		int l = lower_bound(haybales, 0, haybales.size()-1, a);
		// int v = upper_bound(haybales, 0, haybales.size()-1, b);
		//includes left of interval as a bale 
		//query 2 3 is 2 because 3 is counted as well
		//the reason you can't just add one because if it is in between two haybales
		//and goes up one, it can't change more than one.
		//query 2 4 gives 2 because v will still go to 5, but if you add one 
		//v will go to 5 with an additional 1
		int v = lower_bound(haybales, 0, haybales.size()-1, b+1);
		fout << v - l << endl;
	}


}