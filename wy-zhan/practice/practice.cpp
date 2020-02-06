//please enter english parenthesis

#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
	char member;
	struct no *next;
}node;

node *createstack(int *n)
{
	node *p,*h;

	h=p=(node *)malloc(sizeof(node));
	h->next=NULL;

	do
	{
		p=(node *)malloc(sizeof(node));
		scanf("%c",&p->member);
		p->next=h;
		h=p;
		(*n)++;
	}while(p->member!='\n');

	h=p->next;
	free(p);

	return h;
}

void check(node *h,int number)
{
	node *p;
	int step=0,i=0;
	int surplus[20];
	char parenthesis[20];
	
	p=h;

	while(h->next!=NULL)
	{
		if(h->member==')'||h->member=='(')
		{
			surplus[step]=number;
			parenthesis[step]=h->member;
		}
		if(step>0)
		{
			if(parenthesis[step]=='('&&parenthesis[step]!=parenthesis[step-1])
			{
				printf("%d and %d is a couple\n",surplus[step],surplus[step-1]);
				step-=2;
			}
		}
		step++;
		number--;
		p=h->next;
		free(h);
		h=p;
	}
	
	printf("have no wife:");
	for(i=0;i<step;i++)
	{
		printf("%6d",surplus[i]);
	}	
}

int main()
{
	node *h;
	int number=0;
	int *n;

	n=&number;

	h=createstack(n);

	check(h,number-1);

	return 0;
}