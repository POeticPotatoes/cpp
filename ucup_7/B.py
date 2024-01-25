n, k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

l=0
r=1e18

while (l<r):
    m = (l+r)//2
    res = sum(min(m, x) for x in A)
    if (res < m*k): r=m
    else: l=m+1

print(int(l-1))
