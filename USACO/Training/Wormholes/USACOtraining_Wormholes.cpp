/*
ID: michaelwong11
PROG: wormhole
LANG: C++14     
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Wormhole {

	string name;
	int x;
	int y;
	
	Wormhole() {}
	Wormhole(const string & n, int x, int y): name(n), x(x), y(y) { }
	friend ostream& operator<< (ostream& o, Wormhole const& wh);
	bool operator< (const Wormhole & rhs) const {
		if (this->x == rhs.x) {
			return this->y < rhs.y;
		} else {
			return this->x < rhs.x;
		}
	}

	bool operator==(const Wormhole & rhs) const {
		return (name==rhs.name) && (x==rhs.x) && (y==rhs.y);
	}

};

ostream& operator<< (ostream& o, Wormhole const& wh) {
		return o << "(" << wh.name << ", " << wh.x << ", " << wh.y << ")";
}


struct Board {

	vector<Wormhole> wormholes;
	map<Wormhole, Wormhole> pairings;

	void addPair(const Wormhole & wh1, const Wormhole & wh2) {
		wormholes.push_back(wh1);
		wormholes.push_back(wh2);

		// Symmetric.
		pairings[wh1] = wh2;
		pairings[wh2] = wh1;
	}


	bool checkForCycles() {
		for (const auto & w: wormholes) {
			const bool retVal = checkForCycles(w);
			if (retVal == true) { return true; }
		}
		return false;
	}

	// wh1 is the starting point.
	bool checkForCycles(const Wormhole wh1) {
		set< Wormhole > history;
		history.insert(wh1);
		Wormhole curr = wh1;

		cout << "Board::checkForCycles() Starting at Wormhole " << wh1 << endl;

		bool stop = false;
		while (stop == false) {
			// This wormhole is next.
			Wormhole next = pairings[ curr ];
			history.insert(next);
			cout << "next is " << next << endl;

			// Look for wormholes whose y == next.y but not self.
			const int y_target = next.y;
			cout << "y_target = " << y_target << endl;

			// map of < distance, Wormhole >.
			map< int, Wormhole > closest; 

			for (const auto & w: wormholes) {
				if (next == w) {
					// skip
				} else {
					cout << "Inpecting " << w << endl;
					if (w.y == y_target && w.x > next.x) {
						cout << "Found " << w << endl;
						closest[ w.x - next.x ] = w;
					}
				}
			}

			// If not found, return false.
			if ( closest.empty() ) { 
				cout << "The cow will go to x = +infinity" << endl;
				return false; }
			else {
				// Take the first element because it's the closest.
				auto it = closest.begin();
				curr = it->second;

				// If the found wormhole is in history, return true.
				if (history.find(curr) != history.end()) {
					cout << "We have been to Wormhole " << curr << " before." << endl;
					return true;
				}

				cout << "The cow will enter Wormhole " << curr << endl;

			}



		}

		// Not sure.
		return true;
	}

};

int main(){
	// ofstream fout("wormhole.out");
	// ifstream fin("wormhole.in");
	// vector<vector<int>> coords;
	// int N;
	// fin >> N;
	// fout << N << endl;
	// for(int i = 0; i<N; i++){
	// 	int x;
	// 	int y;
	// 	fin >> x >> y;
	// 	coords.push_back({x, y});
	// }

	{
		Board b;
		b.addPair( Wormhole("3", 0, 0), Wormhole("4", 1, 0) );
		b.addPair( Wormhole("1", 0, 1), Wormhole("2", 1, 1) );

		cout << "cycles = " << b.checkForCycles( Wormhole("4", 1, 0) ) << endl;
	}

	{
		Board b;
		b.addPair( Wormhole("3", 0, 0), Wormhole("2", 1, 1) );
		b.addPair( Wormhole("1", 0, 1), Wormhole("4", 1, 0) );

		cout << "cycles = " << b.checkForCycles( Wormhole("3", 0, 0) ) << endl;
	}

	{
		Board b;
		// There should be NO cycles as the Wormholes line up vertically.
		b.addPair( Wormhole("3", 0, 1), Wormhole("2", 0, 2) );
		b.addPair( Wormhole("1", 0, 3), Wormhole("4", 0, 4) );

		cout << "cycles = " << b.checkForCycles( Wormhole("4", 0, 4) ) << endl;
	}

	return 0;

}

