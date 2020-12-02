#include<iostream>
using namespace std;

template <typename T, typename V>

class Pair{
	T x;
	V y;
	
	public:
		void setX(T x){
			this-> x = x; 
		}
		
		T getX(){
			return x;
		}
		
		void setY(V y){
			this-> y = y; 
		}
		
		V getY(){
			return y;
		}		
};

int main(){
	Pair<int, double> p1; // T is replaced by int & V by double
	p1.setX(100.34); // As T is now int data type and x is an int variable, therefore, the x will store approx intger value of 100.34
	p1.setY(100.34);
	
	cout<< p1.getX()<< " "<< p1.getY()<< endl;
}




