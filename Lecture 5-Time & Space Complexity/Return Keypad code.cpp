#include<iostream>
#include <string.h>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
 
    if(num==0||num==1)
    {
        output[0]="";
        return 1;
    }
    string str="a";
    int z=num/10;
    int smalloutput=keypad(z,output);
    int ld=num%10;
    switch(ld)
    {
        case 2:
            {str="abc";
            break;}
        case 3:
            {str="def";
            break;}
        case 4:
            {str="ghi";
            break;}
        case 5:
            {str="jkl";
            break;}
        case 6:
            {str="mno";
            break;}
        case 7:
            { str="pqrs";
            break;}
        case 8:
            {str="tuv";
            break;}
        case 9:
            {str="wxyz";
            break;}    
    }
    if(ld==7||ld==9)
    {
        int x=smalloutput;
        int j=1;
        while(j<=3){
            for(int i=0;i<smalloutput;i++){
                output[x+i]=output[i]+str[j];
            }
            j++;
            x=j*smalloutput;
        }
        for (int i=0; i<smalloutput; i++) {
                          output[i]=output[i]+str[0];
                      }
         return 4*smalloutput;
    }
               
    else{
        int x=smalloutput;
        int j=1;
        while(j<=2){
          for(int i=0;i<smalloutput;i++){
            output[x+i]=output[i]+str[j];
          }
            j++;
            x=j*smalloutput;    
        }
        
        for (int i=0; i<smalloutput; i++) {
            output[i]=output[i]+str[0];
        }
        return 3*smalloutput;
    }
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
