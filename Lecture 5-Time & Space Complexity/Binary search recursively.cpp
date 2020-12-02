#include <iostream>
using namespace std;

int binary(int a[], int si, int ei, int x){
    if(si>ei){
        return -1;
    }
    int mid = (si +ei)/2;
    if(a[mid] == x){
        return mid;
    }
    else if(a[mid] > x){
        ei = mid-1;
    }
    else{
        si = mid+1;
    }
    return binary(a,si,ei,x);
}

int binarySearch(int input[], int size, int element) {
    return binary(input,0,size-1,element);
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
