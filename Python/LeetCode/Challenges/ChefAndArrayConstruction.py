for _ in range(int(input())):
    N, M = [int(v) for v in input().split()]
    if M == 1:
        print('1')
    elif M==2:
        print('3')
    elif M==3:
        print(6*N)
    elif N==1:
        print(M*(M+1)/2)
    else:
        pass