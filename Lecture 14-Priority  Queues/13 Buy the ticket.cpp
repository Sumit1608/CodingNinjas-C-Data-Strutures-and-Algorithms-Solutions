#include <iostream>
#include <vector>
using namespace std;

#include<queue>



int buyTicket (int *arr, int n, int k){
    queue<int> q;
    //MAX priority queue
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        q.push(arr[i]);
    }
    
    int time=0;
    while(!pq.empty()){
        if(q.front() == pq.top()){
            if(k ==0)
                return time+1;
            else{
                q.pop();
                pq.pop();
                time++;
                k--;
            }
        }
        else{
            q.push(q.front());
            q.pop();
            if(k==0)
                k = q.size()-1;
            else
                k--;
        }
    }
    return time;
}




int main(){
    int n, k, s;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> k;
    cout << buyTicket(arr, n, k) << endl;
}
