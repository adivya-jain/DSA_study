import sys
input = sys.stdin.readline

s, n = map(int, input().split())

dragon = []

for _ in range(n):
    strength, bonus = map(int, input().split())
    dragon.append((strength, bonus))

dragon = sorted(dragon)


for strength, bonus in dragon:
    if s <= strength:
        print("NO")
        break
    s+=bonus
else:
    print("YES")