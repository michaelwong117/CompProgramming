#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>

#define ll long long
#define fir first
#define sec second


using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;

class GoldMine {
	public:
   		vector<int> getAllocation(vector<string> mines, int miners);
        
};

vector<int> GoldMine::getAllocation(vector<string> mines, int miners) {
    //1 2 3 4 5 6
    vector<vector<int>> v (mines.size());
    for(int i = 0; i < mines.size(); i++){
		for(int j = 0; j < mines[i].size(); j+=5){
			string s = " ";
			for(int k = j; k < j+3; k++){
				s += mines[i][k];
			}
			int c = stoi(s);
			v[i].push_back(c);
		}
	}
	vector<int> index (v.size());
	vector<int> val (v.size());
	while(miners != 0){
		//iterating through all the mines
		int m = -100000000, mine;
		for(int i = 0; i < v.size(); i++){
			int high = 0;
			//the mine is full
			if(index[i] == 6) continue;
			// cout << "num of miners " << index[i]+1 << endl;
			// cout << "in " << i << " mine, " << index[i] << " miners delivered ";
			// cout << val[i] << endl;
			//traversing through chances of 0, 1, 2..6 ore
			for(int j = 0; j < v[i].size(); j++){
				// cout << v[i][j] << endl;
				//if there are more miners than ore
				if(index[i]+1 > j){
					//chance * outcome of price
					// cout << (v[i][j]*(-20*(index[i]+1 - j) + 50 * j)) / 100 << endl;
					high += (v[i][j]*(-2*(index[i]+1 - j) + 5 * j)) / 10;
				}
				else if(index[i]+1 == j){
					// cout << (v[i][j]*(50 * j)) / 100 << endl;
					high += (v[i][j]*(5 * j)) / 10;
				}
				else{
					// cout << (v[i][j]*(60 * (index[i]+1)) / 100) << endl;
					high += (v[i][j]*(6 * (index[i]+1))) / 10;
				}

			}
			high -= val[i];
			// cout << "high = " << high << endl;
			// cout << endl;
			if(high > m){
				// cout << high << endl;
				m = high;
				mine = i;
			}

		}
		// cout << m << " " << mine << endl;
		val[mine] += m;
		index[mine]++;
		miners--;
	}
	//each vector in v has percentages
	//allocate miners one by one
	//get the maximum increase each time
	return index;
}


int main(){
	GoldMine instanceOfClass;
	// vector<string> in = {"000, 030, 030, 040, 000, 000, 000", "020, 020, 020, 010, 010, 010, 010"};
	vector<int> out = instanceOfClass.getAllocation({"002, 006, 016, 033, 012, 028, 003", "009, 015, 010, 012, 028, 026, 000", "009, 038, 001, 015, 008, 016, 013", "002, 027, 015, 011, 003, 041, 001", "002, 057, 001, 013, 004, 002, 021", "007, 004, 009, 005, 002, 053, 020", "012, 008, 017, 014, 018, 016, 015", "021, 029, 020, 006, 015, 003, 006", "002, 005, 019, 010, 004, 040, 020", "037, 006, 021, 004, 009, 007, 016", "002, 031, 023, 010, 029, 004, 001", "037, 010, 009, 002, 004, 009, 029", "006, 012, 036, 007, 029, 008, 002", "006, 001, 002, 017, 025, 028, 021", "028, 005, 026, 017, 001, 019, 004", "015, 037, 002, 011, 003, 024, 008", "023, 006, 003, 001, 007, 031, 029", "014, 013, 013, 002, 002, 008, 048", "012, 003, 001, 013, 062, 003, 006", "001, 001, 007, 004, 025, 054, 008", "002, 016, 026, 003, 014, 024, 015", "006, 014, 024, 011, 022, 010, 013", "021, 014, 004, 045, 004, 008, 004", "021, 026, 003, 008, 028, 004, 010", "022, 017, 014, 003, 034, 008, 002", "034, 002, 004, 016, 002, 004, 038", "019, 024, 035, 003, 010, 003, 006", "019, 025, 004, 023, 012, 014, 003", "024, 006, 012, 003, 008, 046, 001", "009, 020, 001, 014, 042, 013, 001", "004, 014, 010, 002, 021, 029, 020", "003, 023, 006, 004, 013, 020, 031", "011, 001, 017, 021, 022, 027, 001", "021, 026, 012, 006, 008, 005, 022", "017, 009, 007, 003, 015, 024, 025", "002, 021, 001, 008, 001, 013, 054", "023, 004, 009, 025, 015, 016, 008", "025, 012, 014, 006, 003, 008, 032", "008, 016, 005, 039, 016, 015, 001", "013, 006, 013, 004, 058, 005, 001", "002, 017, 034, 008, 002, 032, 005", "002, 038, 042, 001, 004, 011, 002", "008, 028, 003, 016, 008, 025, 012", "008, 003, 007, 015, 007, 032, 028", "013, 011, 004, 011, 005, 037, 019", "013, 017, 002, 023, 032, 009, 004", "014, 021, 014, 020, 011, 013, 007", "026, 011, 009, 006, 005, 030, 013", "026, 002, 022, 006, 003, 039, 002", "009, 009, 008, 014, 012, 023, 025"}, 64);
	for(auto a: out){
		cout << a << " ";
	}
	cout << endl;
	for(auto a: {2, 1, 1, 1, 1, 3, 2, 1, 2, 0, 1, 0, 1, 3, 0, 1, 1, 1, 3, 3, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 0, 2, 2, 1, 1, 1, 3, 2, 1, 1, 0, 0, 2}){
		cout << a << " ";
	}
	cout << endl;

}

