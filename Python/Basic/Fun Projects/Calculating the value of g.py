from geopy import Nominatim
import math

Place = input("Enter City Here: ")
address='Place'
geolocator = Nominatim(user_agent="Your_Name")
location = geolocator.geocode(address)

Arg1 = location.latitude
Arg2 = int(Arg1) * math.pi / 180

R = 6357000
g = 9.83220
w = 0.000072921159
x = math.cos(Arg2)

G = g - ((R * w * w) * x)
print(G)