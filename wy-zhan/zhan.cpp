/*Using the stack*/

#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
	int a;
	struct no *next;
}node;

node *createstack(int min)
{
	node *h,*p;
	int i=0;
	h=p=(node *)malloc(sizeof(node));
	p->next=NULL;

	while(min)
	{
		p=(node *)malloc(sizeof(node));
		scanf("%d",&p->a);
		p->next=h;
		h=p;
		min--;
	}

	return h;
}
int judge(node *h)
{	
	if(h->next==NULL)
	{
		printf("empty!\n");
		return 1;
	}
	else
	{
		printf("not empyt!\n");
		return 0;
	}
}
int main()
{
	int min;
	node *h,*p;

	printf("please enter\n");
	scanf("%d",&min);
again:	
	if(min>30)
	{
		printf("out of stack!\n");
		goto again;
	}

	h=createstack(min);

	min=h->a;

	while(h->next!=NULL)
	{
		if(min>h->a)
		{
			min=h->a;
		}
		p=h->next;
		free(h);
		h=p;
	}
	printf("The min number is %d!\n",min);

	judge(h);

	return 0;
}





		


