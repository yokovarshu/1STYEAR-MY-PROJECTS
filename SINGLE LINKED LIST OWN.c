#include<stdio.h>
#include<stdlib.h>
int value,pos,i;
struct node
{
	int data ;
	float data2;
	char data3;
	struct node *next;
}*nn,*head,*temp,*d;
void createlist()
{
	char ch,y='y',n;
	do 
	{
		nn=(struct node *)malloc(sizeof(struct node));
		printf("enter a value");
		scanf("%d",&value);
		nn->data=value;
		nn->next=NULL;
		if(head==NULL)
		{
			head=nn;
			temp=nn;
		}
		else
		{
			temp->next=nn;
			temp=temp->next;
		}
		printf("DO YOU WANT TO ADD ONE MORE NODE TO THE LIST(y|n)");
		fflush(stdin);
		scanf(" %c",&ch);
	}while(ch==y);
}
void insertionatbegin()
{
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter a value to be inserted at begin");
	scanf("%d",&value);
	nn->data=value;
	nn->next=head;
	head=nn;
}
int display()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
void insertionatend()
{
	nn=(struct node *)malloc(sizeof(struct node));
	temp=head;
	printf("enter a value to be inserted at end");
	scanf("%d",&value);
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=nn;
	nn->data=value;
	nn->next=NULL;
	temp=nn;
}
void insertatspecifiedposition()
{
	int pos,i;
	nn=(struct node *)malloc(sizeof(struct node));
	temp=head;
	printf("enter position");
	scanf("%d",&pos);
	printf("enter value to be inserted at specified position");
	scanf("%d",&value);
	for(i=0;i<pos-1;i++)
	{
	temp=temp->next;
 }
	nn->data=value;
	nn->next=temp->next;
	temp->next=nn;
}
void deletionatbegin()
{
	temp=head;
	printf("deleted node is %d",temp->data);
	head=head->next;
	temp->next=NULL;
	free(temp);
}
void deletionatend()
{
	temp=head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	d=temp->next;
	printf("deleted node is %d",d->data);
	temp=temp->next;
	free(d);
}
void deletionatspecifiedposition()
{
	temp=head;
	printf("enter position");
	scanf("%d",&pos);
	for(i=0;i<pos-1;i++)
	{
		temp=temp->next;
	}
	d=temp->next;
	printf("%d",d->data);
	temp->next=d->next;
	d->next=NULL;
	free(d);
}
void numberofnodes()
{
	temp=head;
	int count=0;
	while(temp!=NULL)
	{
		count=count+1;
		temp=temp->next;
	}
	printf("number of nodes is %d",count);
}
void linearsearch()
{
	int key,flag=0,pos=0;
	temp=head;
	printf("enter key element");
	scanf("%d",&key);
	while(temp!=NULL)
	{
		if(key==temp->data)
		{
			flag=1;
			break;
		}
		temp=temp->next;
		pos++;
	}
	if(flag==1)
	{
		printf("key element is present at position %d",pos);
	}
	else
	{
		printf("key element is not present");
	}
}
void bubblesort()
{
	int t;
	struct node *t1,*t2;
	for(t1=head;t1->next!=NULL;t1=t1->next)
	{
		for(t2=head;t2->next!=NULL;t2=t2->next)
		{
		if(t2->data>t2->next->data)
		{
			t=t2->data;
			t2->data=t2->next->data;
			t2->next->data=t;
		}
	}
	}
}
void reverse()
{
	struct node *current,*next;
	struct node *prev=NULL;
	current=head;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
}
int main()
{
	int choice;
	do
	{
	printf("enter wt u wanna do 1.createlist()\n2.insertionatbegin\n3.insertionatending\n4.insertatspecifiedposition\n5.deletionatbegin()\n6.deletionatend()\n7.deletionatspecifiedposition()\n8.numberofnodes()\n9.linearsearch()\n10.bubblesort()\n11.reverse()\n12.display\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			createlist();
			break;
			case 2:
			insertionatbegin();
			break;
			case 3:
			insertionatend();
			break;
			case 4:
			insertatspecifiedposition();
			break;
			case 5:
			deletionatbegin();
			break;
			case 6:
			deletionatend();
			break;
			case 7:
			deletionatspecifiedposition();
			break;
			case 8:
			numberofnodes();
			break;
			case 9:
			linearsearch();
			break;
			case 10:
			bubblesort();
			break;
			case 11:
				reverse();
			case 12:
				display();
				break;
				default :
					printf("EXITING...");
	}
}while(choice!=0);
return 0;
}
