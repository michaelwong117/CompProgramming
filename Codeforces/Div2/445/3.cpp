#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <map> 


using namespace std;
int findRooms(vector<int> & rooms){
	int roomCount = 1;
	//if the room does not have a time that has been seen before
	//it is a new room, set its time to i
	//else update the old rooms time to i and continue
	//0 if not explored
	vector<int> explored;
	//first "room" is set to one
	explored.push_back(1);

	for(int i = 1; i < rooms.size(); i++){

		if(find(explored.begin(), explored.end(), rooms[i]) == explored.end()){
			roomCount++;
			explored.push_back(i+1);
		}
		else{
			explored[find(explored.begin(), explored.end(), rooms[i]) - explored.begin()] = i+1;
		}
	}
	return roomCount;
}

int main(){

	int n;
	// n = 2;

	// vector<int> rooms = {0, 0};

	vector<int> rooms;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		rooms.push_back(t);


	}

	cout << findRooms(rooms) << endl;
	
	



}