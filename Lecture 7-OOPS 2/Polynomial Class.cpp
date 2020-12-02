#include<iostream>
using namespace std;

// It has unidentified error
//CN compiler is running this code successfully but not Dev C++ 
class Polynomial {
    // Complete the class
    public:
    int *degCoeff;
    int capacity;
    //Default constructor
    Polynomial(int cap =10){
        degCoeff = new int[cap];
        capacity = cap;
        for(int i=0; i< capacity; i++){
            degCoeff[i] = 0;
        }
    }
    
    //Copy constructor
    Polynomial(Polynomial const &p){
         //Deep copy
        this -> capacity = p.capacity;
        this->degCoeff = new int[p.capacity];
        for(int i=0; i<capacity; i++){
            this -> degCoeff[i] = p.degCoeff[i];
        } 
    }
    
    //Copy Assignment operator
    void operator=(Polynomial const &p){
         //Deep copy
        this -> capacity = p.capacity;
        delete []degCoeff;
        this->degCoeff = new int[capacity];
        for(int i=0; i<capacity; i++){
            this -> degCoeff[i] = p.degCoeff[i];
        }       
    }
    
    //print
    void print(){
        for(int i=0; i< this->capacity; ++i){
            if(this->degCoeff[i] != 0){
                cout<< this->degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
    
    //Set coefficient
    void setCoefficient(int degree, int coeff){
        if(degree <= this -> capacity){
            degCoeff[degree] = coeff;
        }
        else{
            int *temp = new int[degree+1];
            for(int i=0; i<=degree; ++i){
                temp[i] = 0;
            }
            for(int i=0; i<capacity; ++i){
                temp[i] = this->degCoeff[i];
            }
            delete []degCoeff;
            degCoeff = temp;
            degCoeff[degree] = coeff;
            this->capacity = degree+1;
        }
    }
    
    //Add
    Polynomial operator+(Polynomial const &p){
        if(this->capacity >= p.capacity){
            Polynomial pnew(*this);
            for(int i=0; i<p.capacity; ++i){
                pnew.degCoeff[i] += p.degCoeff[i];
            }
            return pnew;
        }
        else{
            Polynomial pnew(p);
            for(int i=0; i< capacity; i++){
                pnew.degCoeff[i] += degCoeff[i];
            }
            return pnew;
        }
    }
    
    //Subtract
    Polynomial operator-(Polynomial const &p){
        Polynomial pnew;
        if(this->capacity >= p.capacity){
            pnew.capacity = this-> capacity;
        }
        else{
            pnew.capacity = p.capacity;
        }
        pnew.degCoeff = new int[pnew.capacity];
        
        for(int i=0; i<pnew.capacity;i++){
            pnew.degCoeff[i] = 0;
        }
        for(int i=0; i<pnew.capacity; i++){
            pnew.degCoeff[i] = this-> degCoeff[i] - p.degCoeff[i];
        }
        return pnew;
    }
        
    //Multiply
    Polynomial operator*(Polynomial const &p){
        Polynomial pnew;
        pnew.capacity = this->capacity + p.capacity-1;
        delete[] pnew.degCoeff;
        pnew.degCoeff = new int[pnew.capacity];
        for(int i=0; i<pnew.capacity; i++){
            pnew.degCoeff[i] =0;
        }
        for(int i=0;i<this->capacity; i++){
            for(int j=0; j<p.capacity; j++){
                pnew.degCoeff[i+j] += this->degCoeff[i]*p.degCoeff[j];
            }
        }
        return pnew;
    }
    
};

int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
