vis = 0
mem = {}
n = int(input())
grid = [[int(x) for x in input().split()] for i in range(n)]

def g(i): 
    global n
    return i%n

def visited(x, y):
    global vis, n
    return vis & 1<<(g(y)*n+g(x))

def dfs(x, y, cur):
    global vis, mem, n, grid
    cur += grid[x][y]
    if x==n-1 and y==n-1: return cur
    vis= vis | 1<<(n*y+x)
    if vis in mem: return mem[vis]
    ans = 0
    if not visited(x+1, y): ans = dfs(g(x+1), y, cur)
    if not visited(x, y+1): ans = max(ans, dfs(x, g(y+1), cur))
    mem[vis] = ans
    vis -= 1<<(n*y+x)
    return ans

print(dfs(0,0,0))
