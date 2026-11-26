import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        if a[i]>b[i]:
            a[i], b[i] = b[i], a[i]
        if i > 0:
            ans += abs(a[i]-a[i-1])
            ans += abs(b[i]-b[i-1])
    print(ans)