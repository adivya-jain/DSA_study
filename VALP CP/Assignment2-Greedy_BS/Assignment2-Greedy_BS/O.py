t = int(input().strip())

for _ in range(t):
    s = input().strip()
    cnt_b = s.count("B")
    if cnt_b == 0:
        print(0)
        continue

    blocks = []
    cur = 0
    for ch in s:
        if ch == "A":
            cur += 1
        else:
            if cur > 0:
                blocks.append(cur)
                cur = 0
    if cur > 0:
        blocks.append(cur)

    blocks.sort(reverse=True)
    print(sum(blocks[:cnt_b]))


# for _ in range(t):
#     s = input().strip()
#     cnt_a = s.count("A")
#     cnt_b = len(s) - cnt_a

#     if cnt_a == 0 or cnt_b == 0:
#         print(0)
#     elif s[0] != "B" and s[-1] != "B" and "BB" not in s:
#         print(cnt_a - 1)
#     else:
#         print(cnt_a)