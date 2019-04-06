/*
 given a circular linked list and an integer k, 
 you need to traverse the list till index k (first index is 1) and delete the node at the kth index.
 Do this repeatedly until only a single node is left and return this node.
*/

#include<iostream>
using namespace std;

struct node{
	int key;
	struct node* next;
};

class linkedList{
	private:
		 node *head, *tail;
		
	public:
		linkedList(){
			this->head=NULL;
			this->tail=NULL;
		}
		
		void addNode(int n){
			node *temp=new node;
			temp->key=n;
			temp->next=NULL;
			
			if(head==NULL){
				head=temp;
				tail=temp;
			}
			tail->next=temp;
			tail=tail->next;
		}
		
		void display(node *head){
			if(head==NULL){
				cout<<"\nNULL\n";
			}else{
				cout<<head->key<<"\t";
				display(head->next);
			}
		}
		
		node* getHead(){
			return head;
		}
		node* getTail(){
			return tail;
		}		
		void freeList(node *head, node *tail){
			head=NULL;
			tail=NULL;
		}
		
		void del(int k, node *head, node *tail){
				node* ptr=head; 
				node* prev=NULL;
				
				if(k==1){
					freeList(head, tail);
				}
				int count=0;
				
				while(ptr!=NULL){
					count++;
					cout<<"\n iter \t"<<count<<"\n";
					if(count==k){
						//delete that node
						cout<<"\n deleted \n"<<prev->next<<"\n";
						delete(prev->next);
						
						prev->next=ptr->next;	
						count=0;
					}
					
					if(count!=0){
						prev=ptr;
					}
					ptr=prev->next;
				}
		}
};
int main(){
	
	linkedList a;
	int n;
	cin>>n;
	int tem;
	for(int i=0;i<n;i++){
		cin>>tem;
		a.addNode(tem);
	}
	a.display(a.getHead());
	int k;
	cin>>k;
	a.del(k, a.getHead(), a.getTail());
	a.display(a.getHead());
}
