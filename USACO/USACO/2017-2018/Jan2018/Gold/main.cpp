#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include <iostream>
#include <fstream>
#include <string>

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
void mergeSort(int arr[],int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void mergetwo(int arr[], int arr2[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    int L2[n1], R2[n2];
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
        L2[i]= arr2[l+i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];
        R2[j]= arr2[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            arr2[k]=L2[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            arr2[k]= R2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        arr2[k]=L2[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        arr2[k]= R2[j];
        j++;
        k++;
    }
}
void mergeSorttwo(int arr[], int arr2[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSorttwo(arr, arr2, l, m);
        mergeSorttwo(arr, arr2, m+1, r);

        mergetwo(arr, arr2, l, m, r);
    }
}

int binarybetween(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  return mid;
        if (arr[mid] > x) {
            if (arr[mid-1]<x){
                return mid-1;
            }
            return binarybetween(arr, l, mid-1, x);
        }
        if (arr[mid] < x) {
            if (arr[mid+1]>x){
                return mid;
            }
            return binarybetween(arr, mid+1, r, x);
        }
   }
   return 0;
}

int main() {
    ofstream fout ("rental.out");
    ifstream fin ("rental.in");
    int N,M,R;
    fin >> N >> M >> R;
    int cow[N], gallon[M], price[M], rent[R];
    for (int i=0; i<N; i++){
        fin >> cow[i];
    }
    mergeSort(cow, 0,N-1);
    for (int i=0; i<M; i++){
        fin >> gallon[i] >> price [i];
    }
    mergeSorttwo(price, gallon, 0, M-1);
    for (int i=0; i<R; i++){
        fin >> rent[i];
    }
    mergeSort(rent, 0, R-1);
     int cummilk[N+1];
    cummilk[0]=0;
    for (int i=1; i<N+1; i++){
        cummilk[i]=cummilk[i-1]+cow[N-i];
    }
    int cumgallon[M+1];
    cumgallon[0]=0;
    for (int i=1; i<M+1; i++){
        cumgallon[i]=cumgallon[i-1]+gallon[M-i];
    }
    int cumprice[M+1];
    cumprice[0]=0;
    for (int i=1; i<M+1; i++){
        cumprice[i]=cumprice[i-1]+price[M-i]*gallon[M-i];
    }
    int sellprice[N+1];
    sellprice[0]=0;
    for (int i=1; i<N+1; i++){
        if (cummilk[i]>cumgallon[M]){
            sellprice[i]=cumprice[M];
        }
        else{
            int k= binarybetween(cumgallon, 0, M, cummilk[i]);
            sellprice[i]=cumprice[k]+price[M-k-1]*(cummilk[i]-cumgallon[k]);
        }
    }
    int rentfee[R+1];
    rentfee[0]=0;
    for (int i=1; i<R+1; i++){
        rentfee[i]=rentfee[i-1]+rent[R-i];
    }
    int ans=0;
    for (int i=0; i<N+1; i++){
        if(i<R+1){
            if (ans< (rentfee[i]+sellprice[N-i])){
                ans= rentfee[i]+sellprice[N-i];
            }
        }
    }
    fout << ans << endl;
    return 0;
}
