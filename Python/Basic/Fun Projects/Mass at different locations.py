from geopy import Nominatim
import math

Mass = input("Enter Your weight Here: ")
place = input("Enter Your Place Here: ")
address1 = place
geolocator = Nominatim(user_agent="Your_Name")
location = geolocator.geocode(address1)
Arg1 = float(location.latitude) * math.pi / 180

place = input("Enter Desired Place Here: ")
address2 = place
geolocator = Nominatim(user_agent="Your_Name")
location = geolocator.geocode(address2)
Arg2 = float(location.latitude) * math.pi / 180

R = 6357000
g = 9.83220
w = 0.000072921159
x1 = math.cos(Arg1)
x2 = math.cos(Arg2)

G1 = g - ((R * w * w) * x1)
G2 = g - ((R * w * w) * x2)

M = float(Mass) * G2 / G1
print("Your weight at the location will be " + str(M))

D = float(M) - float(Mass)

if D >= 0:
    print("Difference between the weight is " + str(D))
else :
    d = -1 * float(D)
    print("Difference between the weight is " + str(d))