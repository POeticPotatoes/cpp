t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    p = 1
    for i in a: p *= i
    if p>0:
        print(1)
        print(1, 0)
    else:
        print(0)
