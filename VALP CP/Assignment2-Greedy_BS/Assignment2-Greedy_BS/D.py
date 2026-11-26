import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    # total = sum(arr)

    # if any( 2*x - total == k for x in arr):
    #     print("YES")
    # else:
    #     print("NO")

    s = set(arr)

    ans = any(x+k in s for x in arr)
    print("YES" if ans else "NO")