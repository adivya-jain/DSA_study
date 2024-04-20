#include <stdio.h>
int main()
{
    int submark[5];
    char name[30];
    printf("enter name of student\n");

    
    scanf("%s",&name);

    printf("enter marks of 5 subjects\n");
    for (int i = 0;i<5;i++)
    {
        scanf("%d", &submark[i]);
    }
    
    
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum = sum + submark[i];
    }
    float avg = 0.0;
    avg = sum / 5.0;
    printf("average is %f ", avg);
    printf("%d",4*4);

    return 0;
}
/*

#include<stdio.h>
#define FREQUENCY 4
#define RESPONSES 20
int main(){
int answer ,rating , frequency[FREQUENCY]={0};
int responses[RESPONSES]={0,1,0,0,3,
                          3,0,1,2,2,
                          0,0,1,2,3,
                          3,1,1,1,1};

for (answer=0; answer<=RESPONSES-1;answer++)
    ++frequency[responses[answer]];

printf("%s%17s\n","Rating","Frequency");

for (rating=0;rating<=FREQUENCY-1 ;rating++)
    printf("%6d%17d\n",rating,frequency[rating]);


return 0;
}
*/