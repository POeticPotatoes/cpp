ft = {0:{}, 1:{}, 2:{}}
m = 2

def cv(i): return (i & (-i))

def modify(t, x, v):
    global m, ft
    while m<t:
        ft[m<<1] = ft[m].copy()
        m<<=1
    while t<=m:
        if not t in ft: ft[t]={}
        if not x in ft[t]: ft[t][x] = 0
        ft[t][x]+=v
        t+=cv(t)

def query(t, x):
    global m, ft
    if t>m: t=m
    ans = 0
    while t:
        if t in ft and x in ft[t]: ans += ft[t][x]
        t-=cv(t)
    print(ans)

def solve():
    a, t, x = [int(i) for i in input().split()]
    
    if a==1: return modify(t,x,1)
    if a==2: return modify(t,x,-1)
    return query(t,x)


n = int(input())

for _ in range(n): solve()
