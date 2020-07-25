#include<iostream>
using namespace std;
class node
{
 public:
 int data;
 node *next;
 node *create(node *head);
 node *insert(node *head);
 node *delet(node *head);
 node *merge(node *,node *);
 node *mergeSortedlist(node *,node *);
 node *removeDuplicateFromSortedList(node *);
 void removeDuplicates(node *);
 void reverseList(node *);
 int compareLists(node *,node*);
 void display(node *head);
};

node *node::create(node *head)
{
    node *temp;
    temp=new node;
    temp->next=NULL;
    cout<<"Enter Data: ";
    cin>>temp->data;

    temp->next=head;
    head=temp;

    return head;
}

node *node::insert(node *head)
{
    char ch;
    node *p;
    node *temp;
    temp=new node;
    temp->next=NULL;

    int c;
        cout<<"INSERTION: \n1.Begining\n2.Middle\n3.Last\n4.Position\n";
        cin>>c;
        switch(c)
        {
            case 1:
             {
               cout<<"Enter Data: ";
               cin>>temp->data;
               temp->next=head;
               head=temp;
             }
            break;

            case 2:
            {
                cout<<"Enter Data: ";
                cin>>temp->data;

                p=head;
                while(p->next->next!=NULL)
                {
                    p=p->next;
                }
                temp->next=p->next;
                p->next=temp;
            }
            break;

            case 3:
            {
                cout<<"Enter Data: ";
                cin>>temp->data;
                 p=head;
                 while(p->next !=NULL)
                 {
                     p=p->next;
                 }
                 p->next=temp;
                 temp->next=NULL;
            }
            break;

            case 4:
            {
                int position;
                p=head;
                cout<<"Enter The Position where U want to add element: ";
                cin>>position;
                cout<<"Enter Data: ";
                cin>>temp->data;
                for(int i=0;i<(position-2);i++)
                {
                    p=p->next;
                }
                temp->next=p->next;
                p->next=temp;
            }
            break;
        }

    return head;
}

node *node::delet(node *head)
{
    int c;
    node *temp,*p;
    cout<<"\nDELETION: \n1.Begining\n2.Second Last\n3.Last\n4.Position\n";
    cin>>c;
    switch(c)
    {
        case 1:
        {
         temp=head;
         if(temp!=NULL)
         {
         head=temp->next;
         temp=NULL;
         delete temp;
         }else
            {
                cout<<"Empty List";
            }
        }
        break;

        case 2:
        {
            temp=head;
            while(temp->next->next->next!=NULL)
            {
                temp=temp->next;
            }
            node *t;
            t=temp->next;
            temp->next=t->next;
            t=NULL;
            delete t;
        }
        break;

        case 3:
        {
            temp=head;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            p=temp->next;
            temp->next=NULL;
            p=NULL;
            delete p;
        }
        break;

        case 4:
        {
            int position;
            cout<<"\nEnter Position: ";
            cin>>position;
            temp=head;
            if(position>1)
            {
            for(int i=0;i<position-2;i++)
            {
                temp=temp->next;
            }
            node *t;
            t=temp->next;
            temp->next=t->next;
            t=NULL;
            delete t;
            cout<<"Element Deleted";
            }else
            {
                cout<<"for deleting 1st element please use Deletion option 1.Begining";
            }
        }
        break;
    }
    return head;
}

//work for only sorted list
node *node::removeDuplicateFromSortedList(node *head)
{
    node *res = head;
    while (head->next !=NULL) {
        if (head->next->data == head->data) {
            node *toDelete = head->next;
            head->next = head->next->next;
            delete toDelete;
        }
        else {
            head = head->next;
        }
    }
    return res;
}

//work for both sorted and unsorted linked lists
void node::removeDuplicates(node *head) {
int x;
node *p;

while(head != NULL)
{
    x=head->data;
    p=head;
    while(p->next != NULL)
    {
        if(p->next->data==x)//delete
           p->next=p->next->next;
        else
         p=p->next;
    }

    head=head->next;
}
}


node *node::merge(node *head,node *head1)
{
    node *temp=head;
    if(temp!=NULL)
    {
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head1;
    }
    else
    {
        cout<<"Both List must contain elements to merge";
        return 0;
    }
    return head;
}


node *node::mergeSortedlist(node *head,node *head1)
{

node *start=NULL,*p;
if(head==NULL)
 return head1;
if(head1==NULL)
 return head;


//coping first element
if(head->data < head1->data)
{
    start=p=head;//storing first element in start
    head=head->next;//incrementing
}
else
{
    start=p=head1;
    head1=head1->next;
}

//appending remaining elements
 while(head!=NULL && head1!=NULL)
 {
     if(head->data < head1->data)
     {
         p->next=head;
         head=head->next;
         p=p->next;
     }else{
         p->next=head1;
         head1=head1->next;
         p=p->next;
     }
 }

 //for remaining elements
  if(head!=NULL)
    {
         p->next=head;
     }else{
         p->next=head1;
     }
return start;
}


void node::reverseList(node *head)
{
    if(head!=NULL)
    {
        reverseList(head->next);
        cout<<head->data<<" ";
    }
}

int node::compareLists(node *head,node *head1)
{
    /* method 1: recurssion
    if(head==NULL && head1==NULL)
     return 1;
    else if(head==NULL || head1==NULL)
     return 0;

    if(head->data==head1->data)
     return compareLists(head->next,head1->next);
    else
      return 0;
      */

    //method 2: traversing
    while(head!=NULL && head1!=NULL)
     {
        if(head->data==head1->data)
         {
             head=head->next;
             head1=head1->next;
         }else
           break;
     }

     if(head==NULL && head1==NULL)
      return 1;


      return 0;
}

void node::display(node *head)
{
    node *temp;
    temp=head;
    if(temp!=NULL)
    {
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    }
    else{
        cout<<"Empty list";
    }
}

int main()
{
    char ch;
    node n;//class object
    node *head,*head1,*head2;//created linked lists
    head=NULL;//initialize the empty list
    head1=NULL;
    head2=NULL;
    do{
        int choose;
        cout<<"1.create list 1\n2.create list 2\n3.Insert(applicable for only List 1)"
               "\n4.Delete(applicable for only List 1)\n5.Display list 1"
               "\n6.Display list 2\n7.Merge list 1 and list 2\n"
               "8.Reverse list( applicable for only list 1)\n9.compareLists\n10.sort and Merge lists\n"
               "11.Removing duplication from sorted linked list\n12.Removing duplication from linked list\n";
  
        cin>>choose;
        switch(choose)
        {
            case 1:
             head=n.create(head);
            break;

            case 2:
             head1=n.create(head1);
            break;

            case 3:
             head=n.insert(head);
            break;

            case 4:
             head=n.delet(head);
            break;

            case 5:
              n.display(head);
            break;

            case 6:
              n.display(head1);
            break;

            case 7:
             head2=n.merge(head,head1);
             if(head2!=NULL){
             cout<<"\nElements After Merging lists: \n";
             n.display(head2);
             }
            break;

            case 8:
             n.reverseList(head);
            break;

            case 9:
            {
             int result=n.compareLists(head,head1);
             if(result==1)
              cout<<"Both list have same elements";
             else
              cout<<"Both List are not same";
            }
            break;

            case 10:
             node *head3=NULL;
             head3=n.mergeSortedlist(head,head1);
             if(head3!=NULL)
              {
             cout<<"\nElements After sorting and Merging lists: \n";
             n.display(head3);
           }
             /*
             The first linked list is: 1 -> 2 -> 3 -> NULL
             The second linked list is: 3 -> 4 -> NULL
             Hence, the merged linked list is: 1 -> 2 -> 3 -> 3 -> 4 -> NULL
             */
            break;

          case 11:
            {
            n.removeDuplicateFromSortedList(head);
            cout<<"List after removing dulplicate elements(sorted list): \n";
            n.display(head);
            }
            break;

            case 12:
            {
            n.removeDuplicates(head);
            cout<<"List after removing dulplicate elements( unsorted or sorted list): \n";
            n.display(head);
            }
            break;

        }
        cout<<"\nWant U to continue: ";
        cin>>ch;
    }while(ch=='y');
}
