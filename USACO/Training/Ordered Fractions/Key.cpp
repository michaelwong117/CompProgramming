#include <fstream.h>
#include <stdlib.h>

struct fraction {
    int numerator;
    int denominator;
};

bool rprime(int a, int b){
   int r = a % b;
   while(r != 0){
       a = b;
       b = r;
       r = a % b;
   }
   return(b == 1);
}

int fraccompare (struct fraction *p, struct fraction *q) {
   return p->numerator * q->denominator - p->denominator *q->numerator;
}

int main(){
   int found = 0;
   struct fraction fract[25600];

   ifstream filein("frac1.in");
   int n;
   filein >> n;
   filein.close();

   for(int bot = 1; bot <= n; ++bot){
       for(int top = 0; top <= bot; ++top){
           if(rprime(top,bot)){
               fract[found].numerator = top;
               fract[found++].denominator = bot;
           }
       }
   }

   qsort(fract, found, sizeof (struct fraction), fraccompare);

   ofstream fileout("frac1.out");
   for(int i = 0; i < found; ++i)
       fileout << fract[i].numerator << '/' << fract[i].denominator << endl;
   fileout.close();

   exit (0);
}