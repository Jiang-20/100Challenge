#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main(void)
{
	int array[5][2];
	float bmi[5];
	int i,j;
	printf("Please input 5 height and weight:\n");
	for(i=0; i<5; i++)
	{
		printf("height and weight %d:",i+1);
		scanf("%d%d",&array[i][0],&array[i][1]);
		bmi[i]=(float)array[i][1]*10000/array[i][0]/array[i][0];

	}
	
	for(i=0;i<5;i++)
	{
		if(bmi[i]<19)
			printf("%d:BMI is %.2f,Emaciaation\n",i+1,bmi[i]);
		else if(bmi[i]<=24)
			printf("%d:BMI is %.2f,Normal\n",i+1,bmi[i]);
		else if(bmi[i]<=28)
			printf("%d:BMI is %.2f,Overweight\n",i+1,bmi[i]);
		else if(bmi[i]>=28)
		{
			printf("%d:BMI is %.2f,Fat\n",i+1,bmi[i]);
		}
	}
	
	 return 0;
	
}