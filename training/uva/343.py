def val(c):
    if c.isnumeric():
        return int(c)
    return ord(c)-55

def convert(s, b):
    ans, p = 0, 1
    for c in s[::-1]:
        ans += val(c)*p
        p *= b
    return ans

def base(i): return "(base "+str(i)+")"

try:
    while True:
        s = input()
        if len(s)<3: break
        a, b = s.split()
        m = {}
        for i in range(max([val(c)+1 for c in b] + [2]),37):
            v = convert(b,i)
            if not v in m: m[v] = i
        for i in range(max([val(c)+1 for c in a] + [2]),37):
            v = convert(a,i)
            if v in m:
                print(a, base(i), "=", b, base(m[v]))
                break
        else:
            print(a, "is not equal to", b, "in any base 2..36")
except:
    pass
