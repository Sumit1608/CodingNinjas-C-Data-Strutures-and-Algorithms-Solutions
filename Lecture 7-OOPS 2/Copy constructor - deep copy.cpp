#include<iostream>
using namespace std;
#include<cstring>

class Student{
	int age;

	public:
		char *name;
		Student(int age, char *name){
			this -> age = age;
			//Shallow copy - this means to copy first index of an array
			//this -> name = name;
			
			//Deep copy - to copy whole array
			this -> name = new char[strlen(name) + 1];
			strcpy(this -> name, name);
		}
		
		// Copy Constructor
		Student(Student const &s){
			this -> age = s.age;
			// this -> name = name;   // This is shallow copy
			
			// Deep copy
			this -> name = new char[strlen(name) + 1];
			strcpy(this -> name, s.name);
		}
		
		void display(){
			cout<<name <<" "<<age<<endl;
		}
};

int main(){
	char name[] = "abcd";
	Student s1(20,name);
	s1.display();
	
	Student s2(s1); // using copy constructor, s2 is a copy of s1
	// now as name is a pointer in s1
	s2.name[0] = 'x'; // thus, this will reflect changes in s1 also
	s1.display();
	s2.display();
	
}
