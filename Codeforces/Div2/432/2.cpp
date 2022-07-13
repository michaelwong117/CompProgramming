#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>


using namespace std;

vector<double> rotatePoint(int px, int py, double ox, double oy, int theta){
	double theta = 3.1415 / 180;
	vector<int> final;

	double x = cos(theta) * (px-ox) - sin(theta) * (py-oy) + ox;

	double y = sin(theta) * (px-ox) + cos(theta) * (py-oy) + oy;
	final.push_back(x);
	final.push_back(y);
	return final;

}

int main(){

	int ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	
}