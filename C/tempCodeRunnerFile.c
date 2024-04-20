/* Aim: Write a C program to accept n integers as command line arguments and find average */
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])//argument ki
{
	int avg=0,i;
	if(argc<=1)
	{
	printf("\n Enter appropriate number of arguments to calculate average. \n \n");
	exit(0);//ye seede exit pr ja raha value kaha li
	}
	else
	{
		for(i=1;i<argc;i++)
		{
			avg+=atoi(argv[i]);
		}
	}
avg/=argc-1;
	printf("\n Average of all command line arguments is %d \n \n",avg); 