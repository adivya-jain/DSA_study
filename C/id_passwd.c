#include<stdio.h>
int main()
{
    int id,passwd;
    printf("enter your id");
    scanf("%d",&id);
    switch(id)
    {
        case 06:
        printf("enter your passed");
        scanf("%d",&passwd);
        switch (passwd)
        {
           case 7860:
           printf("right passwad");
           break;
           default:
           printf("wrong passwd");
        }
        
    }



return 0;
}