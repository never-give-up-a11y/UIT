#include<stdio.h>

void Quicksort(float base[],int left,int n)
{
	if(left<n)
	{
		float key;
		int right=n;
		key=base[left];

		while(left<right)
		{
			while(left<right && base[right]>key)
			right--;
			if(left<right)
			base[left++]=base[right];
			while(left<right && base[left]<key)
				left++;
			if(left<right)
			base[right--]=base[left];
		}
		base[left]=key;
		Quicksort(base,0,left-1);
		Quicksort(base,left+1,n);
	}
}


int main()
{
	int n=0,left=0,right=0;

	float base[28]={0};

	scanf("%d",&right);

	for(n=0;n<right;n++)
		scanf("%f",&base[n]);

	right--;

	Quicksort(base,left,right);

	for(n=0;n<right+1;n++)
		printf("%5.2f",base[n]);

	return 0;
}