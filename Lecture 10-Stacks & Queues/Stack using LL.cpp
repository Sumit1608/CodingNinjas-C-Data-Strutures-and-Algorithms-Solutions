#include<iostream>
using namespace std;

template <typename T>
class Node{
	public:
	T data;
	Node<T> *next;
	
	Node(T data){
		this->data = data;
		this->next = NULL;
	}
};

template <typename T>
class Stack{
	Node<T> *head;
	int size; //no of elements present in stack
	
	public:
		Stack(){
			head = NULL;
			size =0;
		}
		
		int getSize(){
			return size;
		}
		
		bool isEmpty(){
			return size==0;
		}
		
		void push(T element){
			Node<T> *temp = new Node<T>(element);
			if(head == NULL){
				head = temp;
				delete temp;
			}
			else{
				temp -> next = head;
				head = temp;
				delete temp;
			}
			size++;
		}
		
		T pop(){
			if(head == NULL){
				return 0;
			}
			else{
				size--;
				int a = head-> data;
				head= head-> next;
				return a;
			}
		}
		
		T top(){
			if(head == NULL){
				return 0;
			}
			else{
				return head->data;
			}
		}
};

int main() {
    Stack<int> st;
	cout<<"Enter the choices for the following opertaons :"<<endl;
	cout<<"1. Push, then enter the element"<<endl<<"2. Pop"<<endl<<"3. Top element"<<endl<<"4. Size of stack"<<endl<<"5. To check empty stack"<<endl<<"Enter -1 o exit"<<endl;
	    
    int choice;
    cin >> choice;
	int input;
        
    while (choice !=-1) {
        if(choice == 1) {
            cin >> input;
            st.push(input);
        }
        else if(choice == 2) {
            int ans = st.pop();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 3) {
            int ans = st.top();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 4) {
            cout << st.getSize() << endl;
        }
        else if(choice == 5) {
			if(st.isEmpty()){
                cout << "true" << endl;
			}
			else{
				cout << "false" << endl;
			}
        }
        cin >> choice;
    }
}
