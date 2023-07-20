n = int(input())

count = 0

while n > 0:
    x = n%10
    n //= 10
    if x%2 != 0:
        count += 1
print(count)