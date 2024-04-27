#include<iostream>
#include<omp.h>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r){

    int n1 = m-l+1;
    int n2= r-m;

    vector<int> L(n1);
    vector<int> R(n2);

    for(int i = 0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = arr[m+i+1];
    }

    int i,j,k;

    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2){

        if ( L[i]<=R[j]){
            arr[k]=L[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=R[i];
            j++;
            k++;
        }
        if(i<n1){
            arr[k]=L[i];
            i++;
            k++;
        }
        else{
            arr[k]=R[i];
            j++;
            k++;
        }
    }
}

void mergeSort(vector<int> &arr, int l, int r){
    if(l<r){


        int m = l + (r-1)/2;

        mergeSort(arr,l, m-1);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);

    }
}