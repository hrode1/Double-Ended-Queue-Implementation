#include<stdio.h>
#define MAX 30
 
struct MyClass {
    int id;
    char name[10];
}; 
 
typedef struct dequeue
{
	MyClass data[MAX];
	int rear,front;
}dequeue;
 
void initialize(dequeue *p);
int empty(dequeue *p);
int full(dequeue *p);
void push_back(dequeue *p,MyClass x);
//void push_front(dequeue *p,int x);
//int pop_front(dequeue *p);
struct MyClass pop_back(dequeue *p);
void print(dequeue *p);
 
int main()
{
	int i,op,n;
	MyClass x;
	dequeue q;
	
	initialize(&q);
	
	do
	{
		printf("\n1.Insert(rear)\n2.Delete(rear)");
		printf("\n3.Print\n7.Exit\n\nEnter your choice:");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1: if(full(&q))
					{
						printf("\nQueue is full!!");
						return 0;
					}
					
					push_back(&q,MyClass{10, "Joe"});
					break;
														
			case 2: if(empty(&q))
					{
						printf("\nQueue is empty!!");
						return 0;
					}
							
					x=pop_back(&q);
					printf("\nElement deleted is %d - %s\n",x.id, x.name);
					break;
							
			case 3: print(&q);
					break;
					
			default: break;
		}
	}while(op!=7);
}
 
void initialize(dequeue *P)
{
	P->rear=-1;
	P->front=-1;
}
 
int empty(dequeue *P)
{
	if(P->rear==-1)
		return(1);
	
	return(0);
}
 
int full(dequeue *P)
{
	if((P->rear+1)%MAX==P->front)
		return(1);
	
	return(0);
}
 
void push_back(dequeue *P,MyClass x)
{
	if(empty(P))
	{
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else
	{
		P->rear=(P->rear+1)%MAX;
		P->data[P->rear]=x;
	}
}
 
/*void push_front(dequeue *P,int x)
{
	if(empty(P))
	{
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else
	{
		P->front=(P->front-1+MAX)%MAX;
		P->data[P->front]=x;
	}
}*/
 
/*int pop_front(dequeue *P)
{
	int x;
	
	x=P->data[P->front];
	
	if(P->rear==P->front)	//delete the last element
		initialize(P);
	else
		P->front=(P->front+1)%MAX;
	
	return(x);
}*/
 
struct MyClass pop_back(dequeue *P)
{
	MyClass x;
	
	x=P->data[P->rear];
	
	if(P->rear==P->front)
		initialize(P);
	else
		P->rear=(P->rear-1+MAX)%MAX;
		
	return(x);
}
 
void print(dequeue *P)
{
	if(empty(P))
	{
		printf("\nQueue is empty!!");
		return;
	}
	
	int i;
	i=P->front;
	
	while(i!=P->rear)
	{
		printf("\n%d - %s",P->data[i], P->data[i].name);
		i=(i+1)%MAX;
	}
	
	printf("\n%d - %s\n",P->data[P->rear].id, P->data[P->rear].name);
}