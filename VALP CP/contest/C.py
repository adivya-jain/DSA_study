from collections import Counter

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    count = 0
    pos_diff = []
    neg_diff = []
    pairs = Counter()
    for i in range(n):
            pos_diff.append(a[i] - b[i])
            neg_diff.append(a[i] + b[i])
            pairs[(a[i], b[i])] += 1
    
    pos_counts = Counter(pos_diff)
    neg_counts = Counter(neg_diff)

    for diff in pos_counts.values():
        if diff >= 2:
            count += int((diff)*(diff - 1)/2)
    for diff in neg_counts.values():
        if diff >= 2:
            count += int((diff)*(diff - 1)/2)
    for diff in pairs.values():
        if diff >= 2:
            count -= int((diff)*(diff - 1)/2)
    print(count)