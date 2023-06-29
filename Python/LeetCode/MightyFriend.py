for _ in range(int(input())):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    m=l[::2]
    t=l[1::2]
 
    for i in range(k):
        m.sort()
        t.sort()
        temp=m[-1]
        m[-1]=t[0]
        t[0]=temp
    if(sum(t)>sum(m)):
        print("YES")
    else:
        print("NO")