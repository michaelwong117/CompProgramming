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


using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int removeDuplicates(int arr[], int n)
{
    if (n==0 || n==1)
        return n;
    int j = 0, i;
    for (i = 0; i < n-1; i++)
        // cout << arr[i] << " " << arr[i+1] << endl;
        if (arr[i] != arr[i+1]){
            // cout << arr[i] << " " << arr[i+1] << endl;
            // cout << arr[j+1] << " " << arr[i] << endl;
            arr[j++] = arr[i];
        }
    arr[j++] = arr[n-1];
    // cout << j << endl;
    return j;
}

int main() {
    ofstream fout ("lifeguards.out");
    ifstream fin ("lifeguards.in");
    int N;
    fin >> N;
    int times[2*N];
    for (int i=0; i<2*N; i++){
        fin >> times[i];
    }
    int order[2*N];
    for (int i=0; i<2*N; i++){
        order[i]=times[i];
    }
    mergeSort(times, 0, 2*N-1);
    // for(auto a: times){
    //     cout << a << endl;
    // }
    int length= removeDuplicates(times, 2*N);
    int first [N], second[N];
    int timecount[length-1];
    for (int i=0; i<length-1; i++){
        timecount[i]=0;
    }
    for (int i=0; i <N; i++){
        first[i]=binarySearch(times, 0, length-1, order[2*i]);
        second[i]=binarySearch(times, 0, length, order[2*i+1]);
        for (int k=first[i]; k<second[i]; k++){
            timecount[k]=timecount[k]+1;
        }
    }
    int total=0;
    for (int i=0; i<length-1; i++){
        if (timecount[i]!=0){
            total=total+times[i+1]-times[i];
        }
    }
    int ans=0;
    for (int k=0; k<N; k++){
        int time=total;
        for (int i=first[k]; i<second[k]; i++){
            if (timecount[i]==1){
                time=time-times[i+1]+times[i];
            }
        }
        if (time > ans){
            ans=time;
        }
    }
    fout << ans << endl;
    return 0;
}


