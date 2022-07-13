#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;


int GCD(int a, int b)
{
   if (b==0) return a;

   return GCD(b,a%b);
}

int LCM(int a, int b)
{
   return b*a/GCD(a,b);
}

int main(){
    cout << GCD(12, 512) << endl;
    cout << LCM(12, 512) << endl;

}

