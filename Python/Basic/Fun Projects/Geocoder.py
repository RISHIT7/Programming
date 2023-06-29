from geopy import Nominatim

place = input("Enter Your City Here: ")
address = place
geolocator = Nominatim(user_agent="Rishit")
location = geolocator.geocode(address)
print(location.address)
print((location.latitude, location.longitude))