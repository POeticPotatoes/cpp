if __name__ == '__main__':
    import numpy as np
    inp=input()
    aaa=inp.split(' ')
    n = int(aaa[0])
    p = int(aaa[1])
    k = int(aaa[2])
 
    lis=[0]
    fi=np.zeros((1,n))
    li=np.zeros((n,n))
    go=np.zeros((n,1))
    for i in range(1,n+1):
        lis.append(lis[i-1]+1/i)
        fi[0][i-1]=i
    go[p-1][0]=1
    for i in range(1,n+1):
        for j in range(1,n+1):
            li[i-1][j-1]=(lis[n]-lis[max(i,j)-1])/n
            if i == j:
                li[i-1][j-1] = li[i-1][j-1]+(i-1)/n
    for i in range(k):
        go = np.dot(li,go)
    ans = np.dot(fi,go)
    print(ans[0][0])
