#include<iostream>
using namespace std;

//to remove x
void removeX(char str[]){
	if(str[0] == '\0'){
		return;
	}
	
	if(str[0] != 'x'){
	removeX(str+1);
	}
	else{
		int i;
		for(i=1; str[i] != '\0'; i++){
			str[i-1] = str[i];
		}
		str[i-1] = '\0';
		removeX(str);
	}
	
}
//fxn to find lenght of string recursively
int length(char str[]){
	if(str[0] == '\0'){
		return 0;
	}
	int s = length(str+1);
	return 1+s;
}

int main(){
	char str[100];
	cin>>str;
	
	int l = length (str);
	cout<<l<<endl;
	removeX(str);
	cout<<str<<endl;
}
