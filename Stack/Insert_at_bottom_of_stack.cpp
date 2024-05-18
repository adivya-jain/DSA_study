bool isValidParenthesis(string s) {
  // Write your code here.

  stack<char> st;

  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];

    // if opening bracket push krdo
    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    }
    // if closing bracket check top elemtn if reverse of top then pop else
    // return false
    else {
      if (!st.empty()) {
        char top = st.top();
        if ((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
            (ch == ']' && top == '[')) {
          st.pop();
        } else {
          return false;
        }
      }
      else{
          return false;
      }
    }
  }

  if (st.empty()) {
    return true;
  }

  return false;
}