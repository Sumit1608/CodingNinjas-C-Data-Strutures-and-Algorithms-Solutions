#include<iostream>
using namespace std;
#include<cstring>

class Student{
	int age;
	char *name;
	public:
		Student(int age, char *name){
			this -> age = age;
			//Shallow copy - this means to copy first index of an array
			//this -> name = name;
			
			//Deep copy - to copy whole array
			this -> name = new char[strlen(name) + 1];// here +1 is for the null character
			// Ex, if name is"abcd", lenght will be 4, so we add 1 to make lenght 5 and to enter null char at last
			strcpy(this -> name, name);
		}
		
		void display(){
			cout<<name <<" "<<age<<endl;
		}
};

int main(){
	char name[] = "abcd";
	Student s1(20,name);
	
	s1.display();
	
	name[3] = 'e'; // here the name of s1 doesn't change because of using deep copy
	Student s2(24, name);
	s2.display();
	
	s1.display();
}
// there is difference in the output
