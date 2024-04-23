with open('time.txt', 'r') as f:
    lines = f.read()
    
lines = lines.split('\n')[1::2]
times = []
for line in lines:
    times.append((line.split()))

for i, time_line in enumerate(times):
    times[i] = time_line[1::4]

for time_line in times:
    for time in time_line:
        print(time, end=' ,')
    print()