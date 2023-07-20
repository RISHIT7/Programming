sec_in = int(input())

hours_out = sec_in//(3600)
min_out = (sec_in-(hours_out*3600))//60
sec_out = (sec_in-(hours_out*3600)-(min_out*60))

print("Hours: " + str(hours_out))
print("Minutes: " + str(min_out))
print("Seconds: " + str(sec_out))

