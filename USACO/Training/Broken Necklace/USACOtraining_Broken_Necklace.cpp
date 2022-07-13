/*
ID: michaelwong11
PROG: beads
LANG: C++     
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;


int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int beads;
    int redConsCounter = 0;
    int blueConsCounter = 0;
    int maxr = 0;
    int maxb = 0;
    int k = 0;
    string necklace;
    fin >> beads;
    fin >> necklace;
    //for (char & ch: necklace){

    for (int i = 0; i < beads; ++i){
    	char ch = necklace[i];

    	if (ch == 'b'){
    		blueConsCounter++;
    		redConsCounter = 0;
    		if (i == beads-1){
    			while (necklace[k] == 'b' || necklace[k] == 'w'){
    				k++;
    				blueConsCounter++;
    			}
    			k = 0;
    		}
    	}
    	if (ch == 'r'){
    		redConsCounter++;
    		blueConsCounter = 0;
    		if (i == beads-1){
    			while (necklace[k] == 'r' || necklace[k] == 'w'){
    				k++;
    				redConsCounter++;
    			}
    			k = 0;
    		}
    	}
    	//if it's white
    	if (ch == 'w'){
    		redConsCounter++;
    		blueConsCounter++;
    		if (i == beads-1){
    			if (necklace[k] == 'r'){
    				while (necklace[k] == 'r' || necklace[k] == 'w'){
    				k++;
    				redConsCounter++;
    				}
    			k = 0;
    			}
    			if (necklace[k] == 'b'){
    				while (necklace[k] == 'b' || necklace[k] == 'w'){
    				k++;
    				blueConsCounter++;
    				}
    			k = 0;
    			}
    			if (necklace[k] == 'w'){
    				redConsCounter++;
    				blueConsCounter++;

    			}

    	}
    	if (redConsCounter > maxr){
    		maxr = redConsCounter;
    	}
    	if (blueConsCounter > maxb){
    		maxb = blueConsCounter;
    	}
    	//cout << "maxr = " << maxr << endl;
    	//cout << "maxb = " << maxb << endl;
    	//cout << blueConsCounter << endl;
    	//cout << maxb << endl;
    	//cout << maxr << " " << maxb<< endl;
    	//cout << redConsCounter << " " << blueConsCounter << endl;
    }
    //fout << maxr + maxb << endl;
    //cout << "maxr = " << maxr << endl;
   // cout << "maxb = " << maxb << endl;
}
