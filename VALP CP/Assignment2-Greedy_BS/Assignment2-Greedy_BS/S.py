a, b = map(int, input().split())

s = a + b
x = 0

while (x + 1) * (x + 2) // 2 <= s:
    x+=1

d1 = []
d2 = []

for i in range(x, 0, -1):
    if i <= a:
        d1.append(i)
        a-=i
    else:
        d2.append(i)

print(len(d1))
print(*d1)
print(len(d2))
print(*d2)