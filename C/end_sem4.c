///Question 4 
#include<stdio.h>
#include <string.h>
 
int main()
{
    char st[1000],c;  
    int i,count=0;
 
    printf("Enter  the string : ");
    gets(st);
    printf("Enter character to be searched: ");
    c=getchar();
    
    for(i=0;st[i];i++)  
    {
    	if(st[i]==c)
    	{
          count++;
		}
 	}
     
	printf("character '%c' occurs %d times \n ",c,count);
 
 	 
     
    return 0;
}