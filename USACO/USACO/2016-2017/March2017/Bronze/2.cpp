#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
//remember to use fin and fout
bool compareCol(string col1, string col2){
	//checks whether columns share a character

	//method1

	for(char a: col1){
		for(char b: col2){
			if(a == b){
				return false;
			}
		}
	}
	return true;

}

int main(){

	ofstream fout("cownomics.out");
	ifstream fin("cownomics.in");
	int n;
	int m;
	fin >> n >> m;
	vector<string> s;
	vector<string> p;
	vector<string> positions_s;
	vector<string> positions_p;
	for(int i = 0; i < n; i++){
		string genome;
		fin >> genome;
		s.push_back(genome);
	}
	for(int i = 0; i < n; i++){
		string genome;
		fin >> genome;
		p.push_back(genome);
	}
	//look through the genomes of the plain cows and if a position of the plain genome has no characters
	//from the spotty genome, count it as an anomaly and increment count
	for(int i = 0; i < m; i++){
		string col;
		for(string a: s){
			col += a[i];
		}
		positions_s.push_back(col);

	}
	for(int i = 0; i < m; i++){
		string col;
		for(string a: p){
			col += a[i];
		}
		positions_p.push_back(col);
	}
	int anomaly = 0;
	//check if position in position_s and position in position_p do not share characters (same index)
	for(int i = 0; i < positions_p.size(); i++){
		if(compareCol(positions_p[i], positions_s[i])){
			anomaly++;
		}
	}
	fout << anomaly << endl;
}