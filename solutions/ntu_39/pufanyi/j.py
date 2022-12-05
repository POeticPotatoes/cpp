if __name__ == "__main__":
    n = int(input())
    zb = []
    for i in range(n):
        zb.append(int(input().split()[1]))
    zb.append(zb[0])
    for i in range(n):
        if abs(zb[i + 1] - zb[i]) == 180:
            print("yes")
            exit()
    jg = [0] * 720
    md = 720
    for i in range(n + 1):
        zb[i] += 180
        zb[i] *= 2
    for i in range(n):
        if (zb[i + 1] - zb[i]) % md < (zb[i] - zb[i + 1]) % md:
            nowx = zb[i]
            while nowx != zb[i + 1]:
                jg[nowx] = 1
                nowx += 1
                nowx %= md
                # print("nowx ", nowx)
            jg[nowx] = 1
        else:
            nowx = zb[i]
            while nowx != zb[i + 1]:
                jg[nowx] = 1
                nowx -= 1
                nowx %= md
                # print("nowx ", nowx)
            jg[nowx] = 1
    for i in range(md):
        if jg[i] == 0:
            print("no ", end="")
            print("%.1f" % (i / 2 - 180))
            exit()
    print("yes")

"""
6
0 -179
0 0
0 2
0 -180
0 2
0 0
"""