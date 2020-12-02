#include<iostream>
using namespace std;

void merge(int a[], int si, int ei){
    int size = ei-si+1;
    int mid = (ei + si)/2;
    int* out = new int[size];
    
    int i=si, j=mid+1, k=0;
    while(i<=mid && j<= ei){
        if(a[i] <a[j]){
            out[k] = a[i];
            i++;
            k++;
        }
        else{
            out[k] = a[j];
            j++;
            k++;
        }
    }
    
    while(i<=mid){
        out[k] = a[i];
        i++;
        k++;
    }
    while(j<=ei){
        out[k] = a[j];
        j++;
        k++;
    }
    int m=0;
    for(int t =si; t<=ei; t++){
        a[t] = out[m];
        m++;
    }
}

void merge_Sorting(int a[], int si, int ei){
    if(si>=ei){
        return;
    }
    int mid = (si+ei)/2;
    merge_Sorting(a,si,mid);
    merge_Sorting(a,mid+1,ei);
    merge(a,si,ei);
}

void mergeSort(int input[], int lenght){
    merge_Sorting(input, 0, lenght-1);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
