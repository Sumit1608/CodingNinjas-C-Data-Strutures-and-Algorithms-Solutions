#include<iostream>
using namespace std;

void swap(int a[], int b, int c){
    int temp = a[b];
    a[b] =a[c];
    a[c] = temp;
}

int partition(int a[],int si,int ei){
    //choose pivot
    int pivot = a[si];
    //count elements smaller than pivot and swap
    int count =0;
    for(int i=si+1; i<=ei; i++){
        if(a[i]<=pivot){
            count++;
        }
    }
    int pivotindex = si + count;
    swap(a, si, pivotindex);
    
    //diving array according to lesser and gretaer no than pivot
    int i=si, j=ei;
    while(i <= pivotindex && j>= pivotindex){
        while(a[i]<=pivot){
            i++;
        }
        while(a[j]> pivot){
            j--;
        }
        if(i < pivotindex && j > pivotindex){
            swap(a,i,j);
            i++;
            j--;
        }
    }
    return pivotindex;
}

void qs(int input [], int si, int ei){
	if(si>=ei){
		return;
	}
    int pi = partition(input,si,ei);
    qs(input,si,pi-1);
    qs(input,pi+1,ei);
}

void quickSort(int input[], int size) {
    qs(input,0,size-1);
}

int main(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    delete [] input;
}
