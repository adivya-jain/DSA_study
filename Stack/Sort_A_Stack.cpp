// Code Studio Problem Link: https://www.naukri.com/code360/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h>
void arrangeElement(stack<int> &stack, int element) {

  if (stack.empty() || (!stack.empty() && stack.top() <= element)) {
    stack.push(element);
    return;
  }
  int top = stack.top();
  stack.pop();
  arrangeElement(stack, element);
  stack.push(top);
}
void sortStack(stack<int> &stack) {
  // Write your code here

  if (stack.empty()) {
    return;
  }

  int topelement = stack.top();
  stack.pop();
  sortStack(stack);
  arrangeElement(stack, topelement);
}