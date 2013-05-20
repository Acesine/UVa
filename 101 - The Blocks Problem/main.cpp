#include <stdio.h>
#include <string.h>

#define POSITION 0
#define COUNT 1

int main(int argc, char **argv)
{
	int i;
	int posMatrix[25][3];
	int posLength[25];
	int Matrix[25][25];
	int numOfBlocks = 0;
	char cmd1[5];
	int oprd1;
	char cmd2[5];
	int oprd2;
	int cp0,cp1,cp2,cp3,cp4;
	int temp;
	while (numOfBlocks <= 0 || numOfBlocks >= 25)
	{
		scanf("%d",&numOfBlocks);
	}

	for(i = 0;i<numOfBlocks;i++)
	{
		posMatrix[i][POSITION] = i;
		posMatrix[i][COUNT] = 0;
		posLength[i] = 1;
	}
	while(1)
	{
		scanf("%s",cmd1);
		cp0 = strncmp(cmd1,"quit",4);
		if(!cp0)
		{
			break;
		}
		scanf("%d %s %d",&oprd1,cmd2,&oprd2);
		cp1 = strncmp(cmd1,"move",4);
		cp2 = strncmp(cmd1,"pile",4);
		cp3 = strncmp(cmd2,"onto",4);
		cp4 = strncmp(cmd2,"over",4);

		if(oprd1 == oprd2 || oprd1 >= numOfBlocks || oprd2 >= numOfBlocks ||posMatrix[oprd1][POSITION] == posMatrix[oprd2][POSITION])
		{
			continue;
		}
		if(!cp1)
		{
			if(!cp3)
			{
				for(i=0;i<numOfBlocks;i++)
				{
					if(posMatrix[i][POSITION] == posMatrix[oprd2][POSITION] && posMatrix[i][COUNT] > posMatrix[oprd2][COUNT])
					{
						posMatrix[i][COUNT] = 0;
						posMatrix[i][POSITION] = i;
						posLength[i] = 1;
					}
					if(posMatrix[i][POSITION] == posMatrix[oprd1][POSITION] && posMatrix[i][COUNT] > posMatrix[oprd1][COUNT])
					{
						posMatrix[i][COUNT] = 0;
						posMatrix[i][POSITION] = i;
						posLength[i] = 1;
					}
				}
				posLength[posMatrix[oprd1][POSITION] ] = posMatrix[oprd1][COUNT];
				posLength[posMatrix[oprd2][POSITION] ] = posMatrix[oprd2][COUNT]+2;

				posMatrix[oprd1][POSITION] = posMatrix[oprd2][POSITION];
				posMatrix[oprd1][COUNT] = posMatrix[oprd2][COUNT]+1;
			}
			else
			{
				if(!cp4)
				{
					for(i=0;i<numOfBlocks;i++)
					{
						if(posMatrix[i][POSITION] == posMatrix[oprd1][POSITION] && posMatrix[i][COUNT] > posMatrix[oprd1][COUNT])
						{
							posMatrix[i][COUNT] = 0;
							posMatrix[i][POSITION] = i;
							posLength[i] = 1;
						}
					}
					posLength[posMatrix[oprd1][POSITION] ]  = posMatrix[oprd1][COUNT];
					posMatrix[oprd1][POSITION] = posMatrix[oprd2][POSITION];
					posMatrix[oprd1][COUNT] = posLength[posMatrix[oprd2][POSITION]];
					posLength[posMatrix[oprd2][POSITION] ] ++;
				}
			}
		}
		if(!cp2)
		{
			if(!cp3)
			{
				int temp_count = posMatrix[oprd1][COUNT];
				int temp_pos = posMatrix[oprd1][POSITION];
				temp = posLength[posMatrix[oprd1][POSITION]] - posMatrix[oprd1][COUNT];

				posLength[posMatrix[oprd1][POSITION] ] -= temp;
				posLength[posMatrix[oprd2][POSITION] ] = posMatrix[oprd2][COUNT]+1+temp;
				for(i=0;i<numOfBlocks;i++)
				{
					if(posMatrix[i][POSITION] == posMatrix[oprd2][POSITION] && posMatrix[i][COUNT] > posMatrix[oprd2][COUNT])
					{
						posMatrix[i][COUNT] = 0;
						posMatrix[i][POSITION] = i;
						posLength[i] = 1;
					}
					if(posMatrix[i][POSITION] == temp_pos && posMatrix[i][COUNT] >= temp_count)
					{
						posMatrix[i][COUNT] = (posMatrix[oprd2][COUNT] + 1 + posMatrix[i][COUNT] - temp_count);
						posMatrix[i][POSITION] = posMatrix[oprd2][POSITION];
					}
				}
			}
			else
			{
				if(!cp4)
				{
					int temp_count = posMatrix[oprd1][COUNT];
					int temp_pos = posMatrix[oprd1][POSITION];
					temp = posLength[posMatrix[oprd1][POSITION]] - posMatrix[oprd1][COUNT];
					posLength[posMatrix[oprd1][POSITION] ] -= temp;
					for(i=0;i<numOfBlocks;i++)
					{
						if(posMatrix[i][POSITION] == temp_pos && posMatrix[i][COUNT] >= temp_count)
						{
							posMatrix[i][COUNT] = (posLength[posMatrix[oprd2][POSITION]] + posMatrix[i][COUNT] - temp_count);
							posMatrix[i][POSITION] = posMatrix[oprd2][POSITION];
						}
					}
					posLength[posMatrix[oprd2][POSITION] ] += temp;
				}
			}
		}

	}

	for(i=0;i<numOfBlocks;i++)
	{
		Matrix[posMatrix[i][POSITION]][posMatrix[i][COUNT]] = i;
		/*printf("%d, ", posLength[i]);*/
	}
/*	printf("\n");*/
	int j;
	for(i=0;i<numOfBlocks;i++)
	{
		printf("%d:",i);
		for(j=0;j<posLength[i];j++)
		{
			printf(" ");
			printf("%d",Matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
