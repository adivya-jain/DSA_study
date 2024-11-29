import sys
sys.setrecursionlimit(10000)  # Increase recursion limit if needed

def memo_array(s, subs, memo):
    if s in memo:
        return memo[s]
    
    cnt_maxi = 0
    for sub in subs:
        pos = s.find(sub)
        if pos != -1:
            new_str = s[:pos] + s[pos+len(sub):]
            cnt_maxi = max(cnt_maxi, 1 + memo_array(new_str, subs, memo))
    
    memo[s] = cnt_maxi
    return cnt_maxi

def mainfunc():
    n = int(input("Enter the number of substrings: "))
    if n <= 0:
        print("Error: Number of substrings must be greater than 0.")
        return
    
    subs = []
    for i in range(n):
        sub = input(f"Enter substring {i + 1}: ")
        if not sub:
            print("Error: Substring cannot be empty.")
            return
        subs.append(sub)
    
    main_string = input("Enter the main string: ")
    if not main_string:
        print("Error: Main string cannot be empty.")
        return
    
    memo = {}
    try:
        result = memo_array(main_string, subs, memo)
        print(f"Maximum removals: {result}")
    except RecursionError:
        print("Error: Recursion depth exceeded. Input is too complex.")

if __name__ == "__main__":
    mainfunc()
