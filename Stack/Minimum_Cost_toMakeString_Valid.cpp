// Minimum Cost To Make String Valid
// https://www.naukri.com/code360/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
int findMinimumCost(string str) {
  // Write your code here
  stack<char> st;
  if (str.length() % 2 == 1) {
    return -1;
  }

  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];

    if (ch == '{') {
      st.push(ch);
    } else {
      if (!st.empty() && st.top() == '{') {
        st.pop();
      } else {
        st.push(ch);
      }
    }
  }
  int a = 0;
  int b = 0;
  while (!st.empty()) {
    char ch = st.top();
    if (ch == '{') {
      a++;
    } else{ b++;}
    st.pop();
     
  }

  int ans = (a + 1) / 2 + (b + 1) / 2;

  return ans;
}