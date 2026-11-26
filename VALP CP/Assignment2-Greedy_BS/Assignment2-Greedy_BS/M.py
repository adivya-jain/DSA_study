
import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    freq = [0] * (n + 1)

    for x in a:
        freq[x] += 1

    mex = 0
    while freq[mex] > 0:
        mex += 1

    ans = []
    i = 0

    while i < n:
        seen = [0] * (mex + 1)
        count = 0
        j = i

        while j < n:
            x = a[j]

            if x < mex and seen[x] == 0:
                seen[x] = 1
                count += 1

            j += 1

            if count == mex:
                break

        ans.append(mex)

        for k in range(i, j):
            freq[a[k]] -= 1

        mex = 0
        while freq[mex] > 0:
            mex += 1

        i = j

    print(len(ans))
    print(*ans)
