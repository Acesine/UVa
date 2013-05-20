#include <stdio.h>

int main(int argc, char **argv)
{
	char *binord[6] = {"BCG","BGC","CBG","CGB","GBC","GCB"};
	int bin[3][3];
	int ord = 0;
	int min;
	int temp = 0;
	while(scanf("%d %d %d %d %d %d %d %d %d",&bin[0][0],&bin[0][1],&bin[0][2],&bin[1][0],&bin[1][1],&bin[1][2],&bin[2][0],&bin[2][1],&bin[2][2]) == 9)
	{
		// 0: B, 1: G, 2: C
		min = 2147483647;
		ord = 0;
		for(int i=0;i<6;i++)
		{
			temp = 0;
			switch (binord[i][0])
			{
			case 'B':
				temp += bin[0][1] + bin[0][2];
				break;
			case 'G':
				temp += bin[0][0] + bin[0][2];
				break;
			case 'C':
				temp += bin[0][0] + bin[0][1];
				break;
			}
			switch (binord[i][1])
			{
			case 'B':
				temp += bin[1][1] + bin[1][2];
				break;
			case 'G':
				temp += bin[1][0] + bin[1][2];
				break;
			case 'C':
				temp += bin[1][0] + bin[1][1];
				break;
			}
			switch (binord[i][2])
			{
			case 'B':
				temp += bin[2][1] + bin[2][2];
				break;
			case 'G':
				temp += bin[2][0] + bin[2][2];
				break;
			case 'C':
				temp += bin[2][0] + bin[2][1];
				break;
			}
			if(temp < min)
			{
				min = temp;
				ord = i;
			}
		}
		printf("%s %d\n",binord[ord],min);
	}
	return 0;
}
