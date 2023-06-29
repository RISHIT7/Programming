def dostuff(st):
    lst = [0]*(len(st)+1)
    lst[-1] = 1
    lst[-2] = 1
    for k in range ( len(st)-2 , -1 ,-1 ):
        if( st[k] == st[k+1] ):
            lst[k] = lst[k+1]
        else:
            lst[k] = (lst[k+1] + lst[k+2])%998244353
    return lst[0]%998244353

def main():
    for _ in range(int(input())):
        s = input()
        print(dostuff(s))

if __name__ == "__main__":
    main()