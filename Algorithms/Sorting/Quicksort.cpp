#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int partition(long long a[], int startIndex,int endIndex){
    long long pivot = a[endIndex];
    int pIndex = startIndex;
    for(int j = startIndex; j < endIndex; j++){
        if(a[j] <= pivot){
            swap(a[j], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[endIndex]);
    
    return pIndex;
}
//end is v.size()-1
void quickSort(long long a[], int startIndex, int endIndex){
    if(startIndex < endIndex){
        int pIndex = partition(a, startIndex, endIndex);
        quickSort(a, startIndex, pIndex-1);
        quickSort(a, pIndex+1, endIndex);
    }
  
}


int main(){
    long long a[10] = {1,4,8,4,3,57,9,5,11,36};
    quickSort(a, 0, 10);
    for(auto elem: a){
        cout << elem << endl;
    }

}