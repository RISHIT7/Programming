def fractional_knapack(n, values, weights, capacity):
    items = list(range(n))
    ratio = [v//w for v, w in zip(values, weights)]
    items.sort(key=lambda i: ratio[i], reverse=True)
    value =  i = 0
    fractions = []
    while i < len(values):
        if weights[items[i]] <= capacity:
            value += values[items[i]]
            capacity -= weights[items[i]]
            fractions.append(1)
        else:
            fractions.append(capacity//weights[items[i]])
            value += values[items[i]] * capacity//weights[items[i]]
        i += 1
    print(f"The fractions are {fractions}")
    return value

def main():
    n = int(input("Enter the number of objects: "))
    values = [0] * n
    weights = [0] * n
    i = 0
    print()
    while i < n:
        values[i] = int(input("Enter value here: "))
        i += 1
    j = 0
    while j < n:
        weights[j] = int(input("Enter weight here: "))
        j += 1
    capacity = int(input("\n\nwhat is the capacity of the bag? "))
    print(f"\n\nMaximum profit is:- {fractional_knapack(n, values, weights, capacity)}")
if __name__ == "__main__":
    main()