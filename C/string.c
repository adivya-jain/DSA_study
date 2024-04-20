#include<stdio.h>
int main()
{ int i=0,j=0;
char name[30];
printf("enter name");
scanf("%s",&name);
gets(name);
puts(name);
while(name[i]!='0')
{
    for(j=i++;j!='0';j++)
    {
        if(name[i]=name[j])
        {
            break;
        }
            
        
    }
    
}
return 0;
}