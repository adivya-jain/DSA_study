s = input().strip()

ans = []
mx = 'a'

for i in range(len(s) - 1, -1, -1):
    if s[i] >= mx:
        ans.append(s[i])
        mx = s[i]

print(''.join(ans[::-1]))
