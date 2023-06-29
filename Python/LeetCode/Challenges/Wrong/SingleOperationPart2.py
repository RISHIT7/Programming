def dostuff():
    n = int(input())
    s = input()
    value = 0
    for i in range(n):
        if s[len(s)-i-1] == '1':
            value += 2**i
    min = value
    for i in range(1, n+1):
        temp = int(value/(2**i))
        tem = value^temp
        if min >= tem:
            min = tem
            y = i
    print(y)
    return 0

def main():
    for _ in range(int(input())):
        dostuff()
    return 0

if __name__ == "__main__":
    main()