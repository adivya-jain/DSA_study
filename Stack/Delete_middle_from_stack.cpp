//  Delete middle element from stack   || Code Studio
// https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM


// You are having a stack "ARR" of size 'N+1', your task is to delete the middlemost element so that the size of resulting stack is 'N'.
// A stack is a linear data structure where both insertion and deletion of elements take place at the top. It follows FILO (First In Last Out) or LIFO (Last In First Out) approaches. Books piled on top of each other is an example of a stack, where you can only remove a single book at a time, which is at the top of the stack. Likewise, you can only add a single book at a time, on the top of the stack only.
#include<iostream>
#include<stack>

void solve(stack<int> &inputStack, int count, int size) {
  // BASE CASE
  if (count == size / 2) {
    inputStack.pop();
    return;
  }

  // RECURSION
  int num = inputStack.top();
  inputStack.pop();
  solve(inputStack, count + 1, size);

  inputStack.push(num);
}
void deleteMiddle(stack<int> &inputStack, int N) {

  // Write your code here
  int count = 0;
  solve(inputStack, count, N);
}