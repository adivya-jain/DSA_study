#include<stdio.h>
 #include<string.h>
 main()
 {
  struct student{
         char name[10];
         int Roll_no;
         float marks;
};
 struct student stu1,stu2,stu3;
 printf("Enter the name, Roll number and Marks of the student\t");
 scanf("%s%d%f",&stu1.name,&stu1.Roll_no,&stu1.marks);
 printf("Student 1 detail: %s\t%d\t%f",stu1.name,stu1.Roll_no,stu1.marks);
 scanf("%s%d%f",&stu2.name,&stu2.Roll_no,&stu2.marks);
 printf("Student 1 detail: %s\t%d\t%f",stu2.name,stu2.Roll_no,stu2.marks);
 scanf("%s%d%f",&stu3.name,&stu3.Roll_no,&stu3.marks);
 printf("Student 1 detail: %s\t%d\t%f",stu3.name,stu3.Roll_no,stu3.marks);

 }