# dy/dx = x, at x += dx, y += x*dx

dx = 10**-7
x = 10
i = 0
y = 0
while i < x:
    y += x*dx
    
    i += dx
print(y)