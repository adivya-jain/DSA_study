#include <stdio.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int p;
        scanf("%d",&p);
        char str1[15];
        // gets(str1);//it is formed so that for use nahi krna o
       for ( int i = 0; i < 14 ; i++)
       {
           scanf("%d" , &str1[i]);
           /* code */
       }
       
        
        
        //correct ha codechef ko mere se dikkat ha usko
        int c1=0;
        int n1=0;
        int d1=0;
        for(int i=0;i<strlen(str1);i++)
        {
            if(str1[i]=='c' || str1[i]=='C')
            {
                c1++;
            }
            if(str1[i]=='n' || str1[i]=='N')
            {
                n1++;
            }
            if(str1[i]=='d' || str1[i]=='D')
            {
                d1++;
            }
        }
       if(c1==n1)
        {
    
            printf("%d \n",(55)*(p));
            
        }
         else if(c1<n1)
        {
            printf("%d \n",(60)*(p));
            
        }
        else
        {
            printf("%d \n",(40)*(p));
        }
    
    }
    
    
    
    
    
    
}