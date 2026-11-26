
import sys
from bisect import bisect_right

input = sys.stdin.readline

n = int(input())
a = sorted(map(int, input().split()))

q = int(input())

for _ in range(q):
    m = int(input())
    print(bisect_right(a, m))
