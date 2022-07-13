/*
ID: michaelwong11
PROG: castle
LANG: C++14
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>


using namespace std;


int m, n;

string walls(int a){
	// west north east south
	if(a == 0){
		return "0000";
	}
	if(a == 1){
		return "1000";
	}
	else if(a == 2){
		return "0100";
	}
	else if(a == 3){
		return "1100";
	}
	else if(a == 4){
		return "0010";
	}
	else if(a == 5){
		return "1010";
	}
	else if(a == 6){
		return "0110";
	}
	else if(a == 7){
		return "1110";
	}
	else if(a == 8){
		return "0001";
	}
	else if(a == 9){
		return "1001";
	}
	else if(a == 10){
		return "0101";
	}
	else if(a == 11){
		return "1101";
	}
	else if(a == 12){
		return "0011";
	}
	else if(a == 13){
		return "1011";
	}
	else if(a == 14){
		return "0111";
	}
	else{
		return "1111";
	}

}

//checking if a square isn't just four walls
bool isOpen(const string & s){
	if(s.find('0') != string::npos){
		return true;
	}
	return false;
}

bool isRight(const string & x, const string & y){
	//if there's a east well open for x, y must have a west wall open
	if((x[2] == '0')&&(y[0] == '0')){
		return true;
	}
	return false;
}
bool isLeft(const string & x, const string & y){
	//if there's a west wall open for x, y must have a east wall open
	if((x[0] == '0')&&(y[2] == '0')){
		return true;
	}
	return false;
}
bool isDown(const string & x, const string & y){
	//if there's a south wall open for x, y must have a north wall open
	if((x[3] == '0')&&(y[1] == '0')){
		return true;
	}
	return false;
}
bool isUp(const string & x, const string & y){
	//if there's a north wall open for x, y must have a south wall open
	if((x[1] == '0')&&(y[3] == '0')){
		return true;
	}
	return false;
}
bool findS(const set<int> & s, int i, int j){
	if(s.find(i*1000+j) != s.end()){
		return true;
	}
	return false;
}


int roomSize = 0, extraRoomSize = 0;


set<int> seenCoords, localCoords, extraCoords;
//allow each path to trace one module where no path exists
//count the extra amount of space in extraRoomSize
//find the max of extraRoomSize + roomSize (the two linked rooms)

//find the westmost then southmost wall to remove that links 

//extraRoomSize and roomSize
//If it's tied, choose N before E (direction)

// int r = 1;

void extraPath(const vector<string> & modules, int i, int j){

	if((i < n)&&(j < m)&&(i >= 0)&&(j >= 0)){


		if(!findS(localCoords, i, j) && !findS(extraCoords, i, j)){

			extraCoords.insert(i*1000 + j);
			
			
			// cout << r << ": " << i+1 << "," << j+1 << endl;
			// r++;
			extraRoomSize++;
			if(i*m+j+1 < n*m){
				if(isRight(modules[i*m+j], modules[i*m+j+1])){
					extraPath(modules, i, j+1);
				}
			}
			if(i*m+j-1 >= 0){
				if(isLeft(modules[i*m+j], modules[i*m+j-1])){
					extraPath(modules, i, j-1);
				}
			}
			if((i+1)*m+j < n*m){
				if(isDown(modules[i*m+j], modules[(i+1)*m+j])){
					extraPath(modules, i+1, j);
				}
			}
			if((i-1)*m+j >= 0){
				if(isUp(modules[i*m+j], modules[(i-1)*m+j])){
					extraPath(modules, i-1, j);
				}
			}
	
		
			
	
		}
		

	}


}

vector<vector<string>> extra;
void findPath(const vector<string> & modules, int i, int j){
	
	if((i < n)&&(j < m)&&(i >= 0)&&(j >= 0)){


		if(!findS(localCoords, i, j)){

			seenCoords.insert(i*1000 + j);
			localCoords.insert(i*1000 + j);
		
			roomSize++;

			// cout << i*m+j+1 << endl;
			// cout << i*m+j-1 << endl;
			// cout << (i+1)*m+j << endl;
			// cout << (i-1)*m+j+1 << endl;
			
			if(i*m+j+1 < n*m){
				if(isRight(modules[i*m+j], modules[i*m+j+1])){
					findPath(modules, i, j+1);
				}
				else if(!isRight(modules[i*m+j], modules[i*m+j+1])){
					extra.push_back({to_string(i), to_string(j+1), "W"});
					
			
				}
			}
			if(i*m+j-1 >= 0){
				if(isLeft(modules[i*m+j], modules[i*m+j-1])){
					findPath(modules, i, j-1);
				}
				else if(!isLeft(modules[i*m+j], modules[i*m+j-1])){
					extra.push_back({to_string(i), to_string(j-1), "E"});
					

				}
			}
			if((i+1)*m+j < n*m){
				if(isDown(modules[i*m+j], modules[(i+1)*m+j])){
					findPath(modules, i+1, j);
				}
				else if(!isDown(modules[i*m+j], modules[(i+1)*m+j])){
					extra.push_back({to_string(i+1), to_string(j), "N"});
					
				}
			}
			if((i-1)*m+j >= 0){
				if(isUp(modules[i*m+j], modules[(i-1)*m+j])){
					findPath(modules, i-1, j);
				}
				else if(!isUp(modules[i*m+j], modules[(i-1)*m+j])){
					extra.push_back({to_string(i-1), to_string(j), "S"});
					
				}
			}
			
			//don't start looking for extra paths until you've checked the whole room.
	
		
			
	
		}
		

	}
}

vector<string> compare(const vector<string> & a, vector<string>&  b){
	if(b.empty()){
		return a;
	}
	if(stoi(a[1]) < stoi(b[1])){
		return a;
	}
	else if(stoi(a[1]) > stoi(b[1])){
		return b;
	}
	else if(stoi(a[0]) > stoi(b[0])){
		return a;
	}
	else if(stoi(a[0]) < stoi(b[0])){
		return b;
	}
	else if(a[2] == "N"){
		return a;
	}
	else{
		return b;
	}

}


string chooseWall(const set<vector<string>> & walls){
	vector<string> base;
	string output;
	for(auto s: walls){
		if(compare(s, base) == s){
			// cout << s[0] - '0' + 1 << " " << s[1] - '0' + 1 << " " << s[2] << endl;
			base = s;
		}

	}

	
	output += to_string(stoi(base[0])  + 1);
	output += " ";
	output += to_string(stoi(base[1]) + 1);
	output += " ";
	output += base[2];

	return output;
}


int main(){	
	ifstream fin("castle.in");
	ofstream fout("castle.out");
	fin >> m >> n;
	vector<string> modules;
	set<vector<string>> removeWalls;
	//m is num of columns
	//n is num of rows
	
	for(int i = 0; i < m*n; i++){
		int a;
		fin >> a;
		modules.push_back(walls(a));
	}

	int roomCount = 0;
	int largestRoom = 0;
	int largestCombo = 0;
	string remove;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			
			//if you haven't seen the square i, j before
			
			if(!findS(seenCoords, i, j)){
				

				//recurse on the square and find all the paths off it
				findPath(modules, i, j);

				// cout << "room = " << roomCount+1 << endl;
				// cout << i << " " << j << endl;
				// cout << roomSize << endl;
			

				// 	cout << i << " " << j << endl;
				// 	cout << modules[i*m+j] << endl;
				// 	cout << modules[i*m+j+1] << " " << i << " " << j+1 << endl;
					
				// 	cout << modules[i*m+j-1] << " " << i << " " << j-1 << endl;
					
				// 	cout << modules[(i+1)*m+j] << " " << i+1 << " " << j << endl;
					
				// 	cout << modules[(i-1)*m+j] << " " << i-1 << " " << j << endl;
					
				// 	// cout << seenCoords << endl;
				
				roomCount++;
				// cout << roomSize << endl;
				if(roomSize > largestRoom){

					largestRoom = roomSize;

				}

				for(auto coord: extra){
					extraPath(modules, stoi(coord[0]), stoi(coord[1]));
				
					if(extraRoomSize + roomSize > largestCombo){

						largestCombo = extraRoomSize + roomSize;
						removeWalls.clear();
						vector<string> remove = {coord[0], coord[1], coord[2]};
						removeWalls.insert(remove);
						// cout << extraRoomSize + roomSize << " " << largestCombo << endl;
						// cout << stoi(coord[0]) + 1 << " " << stoi(coord[1]) + 1 << " " << coord[2] << endl;
 					}
					else if(extraRoomSize + roomSize == largestCombo){
						vector<string> remove = {coord[0], coord[1], coord[2]};
						removeWalls.insert(remove);
						// cout << extraRoomSize + roomSize << " " << largestCombo << endl;
						// cout << stoi(coord[0]) + 1 << " " << stoi(coord[1]) + 1 << " " << coord[2] << endl;
					}

					extraRoomSize = 0;
				
					extraCoords.clear();
					

				}
				
				roomSize = 0;
				localCoords.clear();
				extra.clear();
				

	
				
				
			}


			

		}
	}

	fout << roomCount << endl;
	fout << largestRoom << endl;

	// cout << "Program ended" << endl;
	fout << largestCombo << endl;
	// for(auto c: removeWalls){
	// 	cout << stoi(c[0]) + 1  << " " << stoi(c[1]) + 1 << " " << c[2] << endl;
	// }

	fout << chooseWall(removeWalls) << endl;

}

//finding amount of rooms, size of rooms.

//recurse on each open square you haven't seen before. 
//trace the path from the square. Every square you encounter should be marked as seen.
//if the path encounters a square you've seen before, ignore that square while counting.
//if the path of a square encounters two or more possible paths it can go, recurse on the new squares
//start the new recursion on 2+ paths with the starting count of the squares you've already seen
//when you have no new paths to go, exit the function and return the room size
//return the max count

//the two largest rooms adjacent in any square is the size of the largest without a wall










