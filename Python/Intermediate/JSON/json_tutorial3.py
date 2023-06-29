import json

with open(r"C:\Users\rishi\OneDrive\Desktop\Programming\Python\Intermediate\JSON\data.json", "r") as f:
    data = json.load(f)

print(data)

with open(r"C:\Users\rishi\OneDrive\Desktop\Programming\Python\Intermediate\JSON\data.json", "w") as f:
    json.dump(data, f)