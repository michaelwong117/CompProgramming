#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
//remember to use fin and fout

struct Rect {
	int l;
	int r;
	int t;
	int b;
	Rect(int l, int r, int t, int b) : l(l), r(r), t(t), b(b) { }

	// Is point (x, y) inside this Rect.
	// bool isPointInside(int x, int y) {
	// 	if((l <= x) && (r >= x)){
	// 		if((t >= y) && (b <= y)){
	// 			return true;
	// 		}
	// 	}
	// 	return false;
	// }


	bool checkOverlap(const Rect & rect2){

	//check whether rect2 overlaps rect1
		if(l <= rect2.r){
			if(r >= rect2.l){
				if(t <= rect2.b){
					if(b >= rect2.t){
						return true;
					}
				}
			}
		}
		return false;
	
	}


};


int main(){

	ofstream fout("art.out");
	ifstream fin("art.in");
	int n;
	fin >> n;
	vector<string> paintingRows;
	vector<string> paintingCols;
	map<char, int> colorToRight;
	map<char, int> colorToLeft;
	map<char, int> colorToBot;
	map<char, int> colorToTop;
	string colors = "123456789";
	for(char c: colors){
		colorToRight[c] = -1;
		colorToBot[c] = -1;
		colorToTop[c] = 11;
		colorToLeft[c] = 11;
	}
	for(int i = 0; i < n; i++){
		string line;
		fin >> line;
		paintingRows.push_back(line);
	}
	for(int i = 0; i < n; i++){
		string col;
		for(string line: paintingRows){
			col += line[i];
		}
		paintingCols.push_back(col);
	}

	// if a color crosses over into another rectangle, it isn't valid
	// if a color is a single cell that does not cross over to another rectangle, it is a valid first
	// if a color's rectangle is bigger than anothers and the other color crosses over into the larger one
	// the larger one came first
	for(auto x: colorToRight){
		for(string line: paintingRows){
			// if it's the rightmost value seen, set it in colorToRight)

			if(line.find_last_of(x.first) != string::npos){
				int right = line.find_last_of(x.first);
				if(right > colorToRight[x.first]){
					// cout << right << " " << x.second << endl;
					colorToRight[x.first] = right;
					// cout << "key, value: " << x.first << ", " << colorToRight[x.first] << endl;
					// cout << colorToRight[x.first] << endl; 
				}
			}
		}
	}
	for(auto x: colorToLeft){
		for(string line: paintingRows){
			// same with left (colorToLeft)
			if(line.find_first_of(x.first) != string::npos){
				int left = line.find_first_of(x.first);
				if(left < colorToLeft[x.first]){
					colorToLeft[x.first] = left;
					// cout << "key, value: " << x.first << ", " << colorToLeft[x.first] << endl; 
					// cout << colorToLeft[x.first] << endl;
				}
			}



		}
	}

			


	for(auto x: colorToTop){
		// if it's the topmost value seen, set it in colorToTop
		// same with bottom (colorToBot)
		for(string line: paintingCols){
			if(line.find_first_of(x.first) != string::npos){
				int top = line.find_first_of(x.first);
				if(top < colorToTop[x.first]){
					colorToTop[x.first] = top;
					// cout << "key, value: " << x.first << ", " << colorToTop[x.first] << endl;
					// cout << colorToTop[x.first] << endl;
				}
			}
		}

	}
	for(auto x: colorToBot){
		// if it's the topmost value seen, set it in colorToTop
		// same with bottom (colorToBot)
		for(string line: paintingCols){
			if(line.find_last_of(x.first) != string::npos){
				int bot = line.find_last_of(x.first);
				if(bot > colorToBot[x.first]){
					colorToBot[x.first] = bot;
					// cout << "key, value: " << x.first << ", " << colorToBot[x.first] << endl;
					// cout << colorToBot[x.first] << endl;
				}
			}
		}

	}
	int startingColors = 0;
	string colorsI = colors;
	for(char a: colors){
		for(char b: colorsI){
			if(a != b){
				if((colorToLeft[b] != 11)&&(colorToLeft[a] != 11)){
					Rect rect1(colorToLeft[a], colorToRight[a], colorToTop[a], colorToBot[a]);
					Rect rect2(colorToLeft[b], colorToRight[b], colorToTop[b], colorToBot[b]);
					if(rect1.checkOverlap(rect2)){
						
					}
					else{
						cout << colorToLeft[a] << " " << colorToRight[a] << " " << colorToTop[a] << " " << colorToBot[a] << endl;
						cout << colorToLeft[b] << " " << colorToRight[b] << " " << colorToTop[b] << " " << colorToBot[b] << endl;
						startingColors++;
					}


				}


			}

		}
		colorsI.erase(0,1);
	}
	fout << startingColors << endl;




}