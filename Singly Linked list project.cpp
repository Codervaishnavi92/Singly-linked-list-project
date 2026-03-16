#include<iostream>
using namespace std;
class Node
{
	public:
	    int data;
	    Node* next;
};
class linkedlist
{
	public:
		Node* head;
		linkedlist()
		{
			head=NULL;
		}
		void Insert_at_beg(int item)
		{
			Node* newNode = new Node();
			newNode->data=item;
			newNode->next=head;
			head=newNode;
			cout<<"Value is inserted at first\n";
		}
		void Insert_at_last(int item)
		{
			Node* newNode=new Node();
			newNode->data=item;
			newNode->next=NULL;
			if(head==NULL)
			{
				head=newNode;
			}
			else
			{
				Node* temp =head;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=newNode;
				cout<<"value is inserted at last\n";
			}
		}
		void Insert_at_position(int item, int pos)
		{
			Node* newNode=new Node();
			newNode->data=item;
			newNode->next=NULL;
			if(head==NULL)
			{
				head=newNode;
			}
			else
			{
				Node* temp=head;
				for(int i=0;i<pos-1;i++)
				{
					while(temp==NULL)
					{
						cout<<"out of range\n";
						return;
					}
					temp=temp->next;
				}
				newNode->next=temp->next;
				temp->next=newNode;
				cout<<"value is added at the specific position\n";
			}
		}
		void Insert_before_position(int item,int pos)
		{
            Node* newNode = new Node();
            newNode->data = item;
            newNode->next = NULL;
            if(head==NULL)
			{
            	head = newNode;
            	cout << "Value added before position 1 (at head)\n";
                return;
			}
			else
			{
				Node* temp = head;
                for(int i = 1; i < pos - 1; i++) 
				{
                    if(temp == NULL) 
					{
                        cout << "Out of range\n";
                        return;
                    }
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Value added before position " << pos << "\n";
			}
		}
		void Insert_after_position(int item,int pos)
		{
			Node* newNode=new Node();
			newNode->data=item;
			newNode->next=NULL;
			if(head==NULL)
			{
				head=newNode;
				cout<<"value is added at the first position\n";
			}
			else
			{
				Node* temp=head;
				for(int i=0;i<pos;i++)
				{
					if(head==NULL)
					{
						cout<<"out of range\n";
						return;
					}
					temp=temp->next;
				}
				newNode->next=temp->next;
				temp->next=newNode;
				cout<<"value is added after the specific positon\n";
			}
		}
		void go_back()
		{
			cout<<"go back to the first menu\n";
			return;
		}
		void Delete_at_beg()
		{
			if(head==NULL)
			{
				cout<<"list is empty"<<endl;
			}
			else
			{
				Node *temp=head;
				head=head->next;
				delete temp;
				cout<<"delete first node\n";
			}
		}
		void Delete_at_last()
		{
			if(head==NULL)
			{
				cout<<"list is empty\n";
			}
			else if(head->next==NULL)
			{
				delete head;
				head=NULL;
			}
			else
			{
				Node * temp=head;
				Node* prev=NULL;
				while(temp->next!=NULL)
				{
					prev=temp;
					temp=temp->next;
				}
				prev->next=NULL;
				delete temp;
				cout<<"delete last node\n";
			}
		}
		void Delete_at_position(int pos)
		{
			if(head==NULL)
			{
				cout<<"list is empty\n";
			}
			else if(head->next==NULL)
			{
				delete head;
				head=NULL;
			}
			else
			{
				Node* temp=head;
				for(int i=0;i<pos;i++)
				{
					if(temp->next==NULL)
					{
						cout<<"out of range\n";
						return;
					}
					temp=temp->next;
				}
				Node* delNode=temp->next;
				if(delNode->next==NULL)
				{
					cout<<"node not exist\n";
					return;
				}
				temp->next=delNode->next;
				delete delNode;
				cout<<"node delete at position\n";
			}
		}
		void Delete_before_position(int pos)
		{
			if(head==NULL)
			{
				cout<<"list is empty\n";
			}
			else if(head->next==NULL)
			{
				delete head;
				head=NULL;
			}
			else
			{
				Node* temp=head;
				for(int i=0;i<pos-1;i++)
				{
					if(temp->next==NULL)
					{
						cout<<"out of range\n";
						return;
					}
					temp=temp->next;
				}
				Node* delNode=temp->next;
				if(delNode->next==NULL)
				{
					cout<<"node not exist\n";
					return;
				}
				temp->next=delNode->next;
				delete delNode;
				cout<<"node delete before position\n";
			}
		}
		void Delete_after_position(int pos)
		{
			if(head==NULL)
			{
				cout<<"list is empty\n";
			}
			else if(head->next==NULL)
			{
				delete head;
				head=NULL;
			}
			else
			{
				Node* temp=head;
				for(int i=0;i<pos;i++)
				{
					if(temp->next==NULL)
					{
						cout<<"out of range\n";
						return;
					}
					temp=temp->next;
				}
				Node* delNode=temp->next;
				if(delNode->next==NULL)
				{
					cout<<"node not exist\n";
					return;
				}
				temp->next=delNode->next;
				delete delNode;
				cout<<"node delete after position\n";
			}
		}
		void Edit(int n,int newvalue)
		{
			Node *temp=NULL;
			while(temp!=NULL)
			{
				if(temp->data==n)
				{
					temp->data=newvalue;
					return;
				}
			}
			cout<<"value not found"<<endl;
		}
		void count()
		{
			Node* temp=head;
			int count=0;
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
			cout<<count<<endl;
		}
		void sort() 
		{
            if(head == NULL || head->next == NULL) 
			{
				return;
			} 
            Node* i;
            Node* j;
            int temp;
            for(i = head; i != NULL; i = i->next) 
			{
                for(j = i->next; j != NULL; j = j->next) 
				{
                    if(i->data > j->data) 
					{ 
                        temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }
                }
            }
            cout << "List sorted successfully\n";
        }
		void reverse()
		{
			Node* prev=NULL;
			Node* cur=head;
			Node* next=NULL;
			while(cur!=NULL)
			{
				next=cur->next;
				cur->next=prev;
				prev=cur;
				cur=next;
			}
			head=prev;
		}
		void Exit(){
			cout<<"exit the list\n";
			return;
		}
		void display()
		{
			if(head==NULL)
			{
				cout<<"list is empty\n";
			}
			else
			{
				Node* temp=head;
				while(temp!=NULL)
				{
					cout<<temp->data<<"-->";
					temp=temp->next;
				}
				cout<<endl;
			}
		}
};
int main()
{
	linkedlist obj;
	int choice,value,choice1,position,choice2,n,newValue;
	do
	{
		cout<<"1. Insert\n";
		cout<<"2. Display\n";
		cout<<"3. Delete\n";
		cout<<"4. Edit\n";
		cout<<"5. count Nodes\n";
		cout<<"6. Sorting\n";
		cout<<"7. Reverse\n";
		cout<<"8. Exit\n";
		cout<<"enter the choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"1. Insert at beginning\n";
				cout<<"2. Insert at last\n";
				cout<<"3. Insert at given position\n";
				cout<<"4. Insert before a given position\n";
				cout<<"5. Insert after a given position\n";
				cout<<"6. Go back\n";
				cout<<"enter the choice1 : ";
				cin>>choice1;
				switch(choice1){
					case 1:
						cout<<"enter the value to be added : ";
				        cin>>value;
				        obj.Insert_at_beg(value);
				        break;
				    case 2:
				       	cout<<"enter the value to be added : ";
				       	cin>>value;
				       	obj.Insert_at_last(value);
				       	break;
					case 3:
						cout<<"enter the value to be added : ";
				       	cin>>value;
				       	cout<<"enter the position on which value is adding : ";
				       	cin>>position;
				       	obj.Insert_at_position(value,position);
				       	break;
					case 4:
						cout<<"enter the value to be added : ";
				       	cin>>value;
				       	cout<<"enter the position on which value is adding : ";
				       	cin>>position;
				       	obj.Insert_before_position(value,position);
				       	break;
					case 5:
						cout<<"enter the value to be added : ";
				       	cin>>value;
				       	cout<<"enter the position on which value is adding : ";
				       	cin>>position;
				       	obj.Insert_after_position(value,position);
				       	break;
					case 6:	
					    obj.go_back();
					    break;
				}
				break;
			case 2:
				obj.display();
				break;
			case 3:
				cout<<"1. Delete at beginning\n";
				cout<<"2. Delete at last\n";
				cout<<"3. Delete at given position\n";
				cout<<"4. Delete before a given position\n";
				cout<<"5. Delete after a given position\n";
				cout<<"6. Go back\n";
				cout<<"enter the choice2 : ";
				cin>>choice2;
				switch(choice2){
					case 1:
				        obj.Delete_at_beg();
				        break;
				    case 2:
				       	obj.Delete_at_last();
				       	break;
					case 3:
				       	cout<<"enter the position on which value is deleting : ";
				       	cin>>position;
				       	obj.Delete_at_position(position);
				       	break;
					case 4:
				       	cout<<"enter the position on which value is deleting : ";
				       	cin>>position;
				       	obj.Delete_before_position(position);
				       	break;
					case 5:
				       	cout<<"enter the position on which value is deleting : ";
				       	cin>>position;
				       	obj.Delete_after_position(position);
				       	break;
					case 6:	
					    obj.go_back();
					    break;
				}
				break;
			case 4:
				cout<<"enter the value to be edited : ";
				cin>>n;
				cout<<"enter the new value";
				cin>>newValue;
				obj.Edit(n,newValue);
				break;
			case 5:
				obj.count();
				break;
			case 6:
				obj.sort();
				break;
			case 7:
				obj.reverse();
				break;
			case 8:
				obj.Exit();
				break;
		}
	}while(choice!=9);
	return 0;
}