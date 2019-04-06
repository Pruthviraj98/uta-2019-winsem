#include<iostream>
using namespace std;
#define SIZE 5
 
class STACK
{
    private:
        int num[SIZE];
        int top;
    public:
        STACK();    //defualt constructor
        int push(int);
        int pop();
        int isEmpty();
        int isFull();
        void displayItems();
        
        //added later
        void PrintStack(STACK); 
        bool pairWiseConsecutive(STACK);
        
};
STACK::STACK(){
    top=-1;
}
 
void STACK::PrintStack(STACK s){
    if (s.isEmpty())  
        return; 
    int x = s.num[s.top];   
    // Pop the top element of the stack 
    s.pop(); 
    // Recursively call the function PrintStack 
    PrintStack(s); 
    // Print the stack element starting 
    // from the bottom 
    cout << x << " "; 
    // Push the same element onto the stack 
    // to preserve the order 
    s.push(x); 
}

bool STACK::pairWiseConsecutive(STACK s){
	  // Transfer elements of s to aux. 
    STACK aux; 
    while (!s.isEmpty()) { 
        aux.push(s.num[s.top]); 
        s.pop(); 
    } 
  
    // Traverse aux and see if elements are pairwise sorted or not. We also need to make sure that original content is retained. 
    bool result = true; 
    while (!aux.isEmpty()) { 
  
        // Fetch current top two 
        // elements of aux and check 
        // if they are sorted. 
        int x = aux.num[aux.top]; 
        aux.pop(); 
        int y = aux.num[aux.top]; 
        aux.pop(); 
        if (x > y) 
            result = false; 
  
        // Push the elements to original 
        // stack. 
        s.push(x); 
        s.push(y); 
    } 
  
    if (aux.top==0) 
        s.push(aux.num[aux.top]); 
    return result; 
}
int STACK::isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;   
}
 
int STACK::isFull(){
    if(top==(SIZE-1))
        return 1;
    else
        return 0;
}
 
int STACK::push(int n){
    //check stack is full or not
    if(isFull()){
        return 0;
    }
    ++top;
    num[top]=n;
    return n;
}
 
int STACK::pop(){
    //to store and print which number
    //is deleted
    int temp;
    //check for empty
    if(isEmpty())
        return 0;
    temp=num[top];
    --top;
    return temp;
     
}
 
void STACK::displayItems(){
    int i; //for loop
    cout<<"STACK is: ";
    for(i=(top); i>=0; i--)
        cout<<num[i]<<" ";
    cout<<endl;
}
 
int main(){
    //declare object
    STACK stk;
    int choice, n,temp;
     
    do
    {
        cout<<endl;
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - Display Items (Print STACK)."<<endl;
         
        cout<<"Enter your choice: ";
        cin>>choice;
         
        switch(choice){
            case 0: break;
             
            case 1:
                cout<<"Enter item to insert: ";
                cin>>n;
                temp=stk.push(n);
                if(temp==0)
                    cout<<"STACK is FULL."<<endl;
                else
                    cout<<temp<<" inserted."<<endl;
            break;
                 
            case 2:
                temp=stk.pop();
                if(temp==0)
                    cout<<"STACK IS EMPTY."<<endl;
                else
                    cout<<temp<<" is removed (popped)."<<endl;
            break;
             
            case 3:
                stk.displayItems();
                break;
             
            default:
                cout<<"An Invalid choice."<<endl;
        }   
    }while(choice!=0);
 	stk.PrintStack(stk);
    
    if (stk.pairWiseConsecutive(stk)) 
        cout << "Yes" << endl; 
    else
        cout << "No" << endl;  
    return 0;
     
}
