#include <stdio.h>

int main(int argc, char **argv)
{
	int loopnum,length;
	scanf("%d",&loopnum);
	for(int i=0;i<loopnum;i++)
	{
		int count = 0;
		scanf("%d",&length);
		int *train = new int[length];
		for(int j=0;j<length;j++)
		{
			scanf("%d",&train[j]);
		}
		for(int m=0;m<length;m++)
		{
			for(int n=0;n<length-1;n++)
			{
				if(train[n]>train[n+1])
				{
					int temp = train[n];
					train[n] = train[n+1];
					train[n+1] = temp;
					count++;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n",count);
	}
	return 0;
}
