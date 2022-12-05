if __name__ == "__main__":
    n = int(input())
    if n == 1:
        print(4)
        exit()
    zbx = []
    zby = []
    zb = []
    for i in range(n):
        x, y = map(int, input().split())
        zb.append((x, y))
        zbx.append(x)
        zby.append(y)
    lx, rx = min(zbx) - 1, max(zbx) + 1
    ly, ry = min(zby) - 1, max(zby) + 1
    xza = xzb = xzc = xzd = min(rx - lx + 1, ry - ly + 1)
    for xx in zb:
        xza = min(xza, xx[0] - lx + xx[1] - ly)
        xzb = min(xzb, xx[0] - lx + ry - xx[1])
        xzc = min(xzc, rx - xx[0] + xx[1] - ly)
        xzd = min(xzd, rx - xx[0] + ry - xx[1])
    # print(lx, rx, ly, ry, xza, xzb, xzc, xzd)
    ans = (ry - ly + rx - lx + 2) * 2 - xza - xzb - xzc - xzd
    if ry - ly == rx - lx and ans == (ry - ly) * 2:
        ans += 1
    print(ans)
