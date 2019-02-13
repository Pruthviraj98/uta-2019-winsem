#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};



node* push(struct node* top, int item)
{
    node *nptr = new node;
    nptr->data = item;
    nptr->next = top;
    top = nptr;
}

void display(struct node* top)
{
    struct node *temp;
    temp = top;
    while (temp != NULL)
    {
        cout<<"\n"<<temp->data;
        temp = temp->next;
    }
}

node* pop(struct node* top)
{
    if (top== NULL)
    {
        cout<<"\n\nStack is empty ";
        return top;
    }
    else
    {
    	if(top->next==NULL){
    	cout<<top->data<<"\n";
    	top=NULL;
		return top;	
		}
        struct node *temp;
        temp = top;
        top = top->next;
        cout<<"\n\n deleted"<<temp->data;
        delete(temp);
        return top;
    }
}

node* PrintStack(struct node* top){
	if (top==NULL){
		cout<<"\n"<<"EMPTY";
        return top; 
    }
    int x = top->data;   
    // Pop the top element of the stack 
    top=pop(top); 
    // Recursively call the function PrintStack 
    top=PrintStack(top); 
    // Print the stack element starting 
    // from the bottom 
    cout << x << " "; 
    // Push the same element onto the stack 
    // to preserve the order 
    top=push(top, x); 
}


int main(){
	struct node *top = NULL;
    int n, ch;
    do
    {
        cout<<"\n\nStack Menu\n1. Push \n2. Pop\n3. Display\n0. Exit";
        cout<<"\nEnter Choice 0-3? : ";
        cin>>ch;
        switch (ch)
        {
            case 1:
                cout<<"\nEnter number ";
                cin>>n;
                top=push(top, n);
                break;
            case 2:
                top=pop(top);
                break;
            case 3:
                display(top);
                break;
        }
    }while (ch != 0);
	top=PrintStack(top);
}

