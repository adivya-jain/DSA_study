#include <stdio.h>

int main(void)
{
    int inum1 = 5;
    int sum;
    sum = ++inum1 + ++inum1;
    printf("The sum1=++inum1 + ++inum1 is %d\n", sum);
    sum = ++inum1 + --inum1;
    printf("The sum2=++inum1 + --inum1 is %d\n", sum);
    sum = ++inum1 + inum1;
    printf("The sum3=++inum1 + inum1 is %d\n", sum);
    sum = ++inum1 + inum1++;
    printf("The sum4=++inum1 + inum1++ is %d\n", sum);

    return 0;
}
/*
1.	Write a C program to add two numbers and display its sum.
2.	Write a C program to input two number from the user and display the multiplication of these numbers.
3.	Write a Program to calculate and display the volume of a cylinder for height and radius parameters to be input from the user.
4.	Write C program to realize the following expressions:
a.	V = u + at
b.	S = ut+1/2a
c.	T=2*a+√b+9c
5.	Write a program to take input of name, rollno and marks obtained by a student in 5 subjects of 100 mar
5.	Write a program to take input of name, rollno and marks obtained by a student in 5 subjects of 100 marks each and display the name, rollno with percentage score secured.
6.	Write a program to swap values of two variables with and without using third variable.
7.	Write a program to illustrate the use of unary prefix and postfix increment and decrement operators.
8.	Write a program to find the largest of three numbers using ternary operators.
9.	Write a program to find the roots of quadratic equation.
10.	Write a Program to Check Whether a Number is Prime or not.
11.	Write a program to compute grade of students using if else ladder as per MITS norms.
12.	Write a program to check whether the entered year is leap year or not (a year is leap if it is divisible by 4 and divisible by 100 or 400.)
Write a program to print the sum of digits of a number using for loop.
14.	Write a program to check whether a number is Palindrome or not.
15.	Write a program to generate Fibonacci series.
16.	Write a program to find GCD (greatest common divisor or HCF) and LCM (least common multiple) of two numbers.*\
*/
