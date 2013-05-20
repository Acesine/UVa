#include <stdio.h>

struct datastrct{
	char* strAddr;
	int swaps;
};

int checkSwaps(char *string_orig,int length)
{
	char *string = new char[length];
	for(int m=0;m<length;m++)
		string[m] = string_orig[m];
	int swap=0;
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length-1;j++)
		{
			if(string[j]>string[j+1])
			{
				char temp = string[j];
				string[j] = string[j+1];
				string[j+1] = temp;
				swap ++;
			}
		}
	}
	return swap;
}

int main(int argc, char **argv)
{
	int datasetnum,stringlen,stringnum;
	scanf("%d",&datasetnum);
	for(int i=0;i<datasetnum;i++)
	{
		scanf("%d %d",&stringlen,&stringnum);
		struct datastrct * data = new struct datastrct[stringnum];
		char** strings = new char*[stringnum];
		for(int j=0;j<stringnum;j++)
		{
			strings[j] = new char[stringlen];
			scanf("%s",strings[j]);
			
			data[j].strAddr = strings[j];
			data[j].swaps = checkSwaps(strings[j],stringlen);
		}
		//sort:
		struct datastrct temp;
		for(int k=1;k<stringnum;k++)
		{
			temp.strAddr = data[k].strAddr;
			temp.swaps = data[k].swaps;
			int count = k;
			while(count-1>=0 && temp.swaps < data[count-1].swaps)
			{
				data[count].strAddr = data[count-1].strAddr;
				data[count].swaps = data[count-1].swaps;
				count -- ;
			}
			data[count].strAddr = temp.strAddr;
			data[count].swaps = temp.swaps;
		}
		
		for(int m=0;m<stringnum;m++)
		{
			printf("%s\n",data[m].strAddr);
		}
		
		for(int t=0;t<stringnum;t++)
		{
			delete[] strings[t];
		}
		delete[] strings;
		delete[] data;
	}
	return 0;
}
