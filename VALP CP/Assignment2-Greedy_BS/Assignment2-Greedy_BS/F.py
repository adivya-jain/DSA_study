
import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    s = input().strip()
    stack = []

    for ch in s:
        if stack and ch == 'B':
            stack.pop()
        else:
            stack.append(ch)

    print(len(stack))
