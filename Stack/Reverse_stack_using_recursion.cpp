//Code Studio  Reverse Stack Using Recursion

// Reverse a given stack of 'N' integers using recursion. You are required to make changes in the input parameter itself.



// Note: You are not allowed to use any extra space other than the internal stack space used due to recursion.

// Example:
// Input: [1,2,3,4,5] 
// Output: [5,4,3,2,1]
void insertAtBottom(stack<int> &stack,int element)
{
    if(stack.empty())
    {
        stack.push(element);
        return;
    }

    int top = stack.top();
    stack.pop();
    insertAtBottom(stack,element);
    stack.push(top);
}

void reverseStack(stack<int> &stack) {
    // Write your code here


    if(stack.empty())
    {
        return;
    }

    int top = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack,top);
}