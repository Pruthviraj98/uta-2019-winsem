#include <iostream>
using namespace std;
#define MAX 10
 
class Que{
	private:
		int queue[MAX];
		int front;
		int rear;
	public:
		Que(){
			front=-1;
			rear=-1;
		}
		void enqueue(int ele);
		void dequeue();
		void display_Q();
};
 
/** enqueue(), to push an item into queue.
**/
void Que::enqueue(int ele)
{
    if(rear==-1)
    {
        front=rear=0;
        queue[rear]=ele;
    }
    else if(rear==MAX-1)
    {
        cout<<"\nQUEUE is full.\n";
        return;
    }
    else
    {
        rear++;
        queue[rear]=ele;
    }
    cout<<"\nItem inserted..";
}
 
/**  display_Q(),to display queue elements
**/
 
void Que:: display_Q()
{   
	int i;
    if(rear==-1)
	 {
	  cout<<"EMPTY QUEUE\n";
	  return;
	 }
    for(i=front;i<=rear;i++)
    { 
    cout<<queue[i]<<"\t";
	}	
}
 
/** dequeue(), to remove (pop) an item from queue.
**/
void Que:: dequeue()
{
    int ele;
    if(front==-1)
    {
        cout<<"\n QUEUE is Empty";
        return;
    }
    else if(front==rear)
    {
        ele=queue[front];
        front=rear=-1;
    }
    else
    {
        ele=queue[front];
        front++;
    }
    cout<<"\nItem removed :"<<ele;
}
int main()
{
    int ele,choice;
    Que queue;
    
	while(1)
	{
	    cout<<"\nQUEUE Elements are :";
	    queue.display_Q();
	    cout<<"\n\nEnter choice (1:Insert,2:Display,3:Remove,0:Exit):";
	    cin>>choice;
	    switch(choice)
	    {
	        case 0:
	            exit(1);
	            break;
	        case 1:
	            cout<<"Enter an element to insert:";
	            cin>>ele;
	            queue.enqueue(ele);
	            break;
	        case 2:
	            queue.display_Q();
	            break;
	        case 3:
	            queue.dequeue();
	            break;
	        default:
	            cout<<"\nInvalid choice\n";
	            break;
	    }
	 
	} 
return 0;
}
