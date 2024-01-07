t = int(input())
for _ in range(t):
    s = input()
    n = len(s)
    a = "()"*n
    b = "("*n+")"*n
    if not s in a:
        print("YES")
        print(a)
        continue
    if not s in b:
        print("YES")
        print(b)
        continue
    print("NO")
