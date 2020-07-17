#include <string.h>
#define MAX 10                
#define Deque_DEFINE(t)                                                        \
    typedef struct Deque_##t                                                   \
	{                                                                          \
		t data[MAX];                                                           \
		int dq_rear,dq_front;                                                  \
		char type_name[15] = "Deque_"#t;		                                   \
		int len = strlen(type_name);                                            \
		int size(Deque_##t *P);                                                \
		void initialize(Deque_##t *p);                                         \
		int empty(Deque_##t *p);                                               \
		int full(Deque_##t *p);                                                \
		void push_back(Deque_##t *p,t x);                                      \
		void push_front(Deque_##t *p,t x);                                     \
		struct t pop_front(Deque_##t *p);                                      \
		t front(Deque_##t *P);                                                 \
		t back(Deque_##t *P);                                                  \
		struct t pop_back(Deque_##t *p);                                       \
		void print(Deque_##t *p);                                              \
		void Deque_##t##_ctor(Deque_##t *P,bool (*f)(const t &, const t &)); \
	}Deque_##t;                                                                \
	void Deque_##t##_ctor(Deque_##t *P,bool (*f)(const t &, const t &)){   \
		P->dq_rear=-1;                                                         \
		P->dq_front=-1;                                                        \
	}                                                                          \
	int Deque_##t::size(Deque_##t *P)                                          \
	{                                                                          \
		if(empty(P))                                                           \
		{                                                                      \
			return 0;                                                          \
		}                                                                      \
		int i;                                                                 \
		int num_elements = 0;                                                  \
		i=P->dq_front;                                                         \
		while(i!=P->dq_rear)                                                   \
		{                                                                      \
			printf("\n%d - %s",P->data[i], P->data[i].name);                   \
			i=(i+1)%MAX;                                                       \
			num_elements++;                                                    \
		}                                                                      \
		printf("\n%d - %s\n",P->data[P->dq_rear].id, P->data[P->dq_rear].name);      \
		return num_elements;                                                   \
	}                                                                          \
	void Deque_##t::initialize(Deque_##t *P)                                   \
	{                                                                          \
		P->dq_rear=-1;                                                            \
		P->dq_front=-1;                                                           \
	}                                                                          \
	int Deque_##t::empty(Deque_##t *P)                                         \
	{                                                                          \
		if(P->dq_rear==-1)                                                        \
			return(1);                                                         \
		return(0);                                                             \
	}                                                                          \
	int Deque_##t::full(Deque_##t *P)                                          \
	{                                                                          \
		if((P->dq_rear+1)%MAX==P->dq_front)                                          \
			return(1);                                                         \
		return(0);                                                             \
	}                                                                          \
	void Deque_##t::push_back(Deque_##t *P,t x)                                \
	{                                                                          \
		if(empty(P))                                                           \
		{                                                                      \
			P->dq_rear=0;                                                         \
			P->dq_front=0;                                                        \
			P->data[0]=x;                                                      \
		}                                                                      \
		else                                                                   \
		{                                                                      \
			P->dq_rear=(P->dq_rear+1)%MAX;                                           \
			P->data[P->dq_rear]=x;                                                \
		}                                                                      \
	}                                                                          \
	void Deque_##t::push_front(Deque_##t *P,t x)                             \
	{                                                                          \
		if(empty(P))                                                           \
		{                                                                      \
			P->dq_rear=0;                                                         \
			P->dq_front=0;                                                        \
			P->data[0]=x;                                                      \
		}                                                                      \
		else                                                                   \
		{                                                                      \
			P->dq_front=(P->dq_front-1+MAX)%MAX;                                     \
			P->data[P->dq_front]=x;                                               \
		}                                                                      \
	}                                                                          \
	struct t Deque_##t::pop_front(Deque_##t *P)                              \
	{                                                                          \
		t x;                                                             \
		x=P->data[P->dq_front];                                                   \
		if(P->dq_rear==P->dq_front)	/*delete the last element   */                 \
			initialize(P);                                                     \
		else                                                                   \
			P->dq_front=(P->dq_front+1)%MAX;                                         \
		return(x);                                                             \
	}                                                                          \
	t Deque_##t::front(Deque_##t *P)                              \
	{                                                                          \
		t x;                                                             \
		x=P->data[P->dq_front];                                                   \
		return(x);                                                             \
	}                                                                          \
	struct t Deque_##t::pop_back(Deque_##t *P)                               \
	{                                                                          \
		t x;                                                             \
		x=P->data[P->dq_rear];                                                    \
		if(P->dq_rear==P->dq_front)                                                  \
			initialize(P);                                                     \
		else                                                                   \
			P->dq_rear=(P->dq_rear-1+MAX)%MAX;                                       \
		return(x);                                                             \
	}                                                                          \
	t Deque_##t::back(Deque_##t *P)                               \
	{                                                                          \
		t x;                                                             \
		x=P->data[P->dq_rear];                                                    \
		return(x);                                                             \
	}                                                                          \
	void Deque_##t::print(Deque_##t *P)                                            \
	{                                                                          \
		if(empty(P))                                                           \
		{                                                                      \
			printf("\nQueue is empty!!");                                      \
			return;                                                            \
		}                                                                      \
		int i;                                                                 \
		i=P->dq_front;                                                            \
		while(i!=P->dq_rear)                                                      \
		{                                                                      \
			printf("\n%d - %s",P->data[i].id, P->data[i].name);                \
			i=(i+1)%MAX;                                                       \
		}                                                                      \
		printf("\n%d - %s\n",P->data[P->dq_rear].id, P->data[P->dq_rear].name);}
	