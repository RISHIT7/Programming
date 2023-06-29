def kidWithMaxCandies(candies, extraCandy):
    result = []
    i = 0
    while i < len(candies):
        candies[i] += extraCandy
        if candies[i] == max(candies):
            result.append('true')
        else :
            result.append('false')
        candies[i] -= extraCandy
        i += 1
    return result

def main():
    candies = [2, 3, 5, 1, 3]
    extraCandies = 3
    print(f"Output: {kidWithMaxCandies(candies, extraCandies)}")

if __name__ == "__main__":
    main()