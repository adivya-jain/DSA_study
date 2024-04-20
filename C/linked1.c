#include<stdio.h>
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");

}
int insertElement(int arr[],int element,int index,int size,int capacity)
{
    if(size>=capacity)
    {
        return -1;
    }
    for(int i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}

int main()
{
int size,element,index;
//printf("enter capacity:");
//scanf("%d",&ca[]
int arr[50];
printf("enter size");
scanf("%d",&size);//5
for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("\nenter element to be insert:");
    scanf("%d",&element);
    printf("\nenter index value:");
    scanf("%d",&index);
    printArray(arr,size);
    //


  
int temp= insertElement(arr,element,index,size,50);
   
    if(temp!=-1)
    {
        size+=1;

         printArray(arr,size);
    }
}