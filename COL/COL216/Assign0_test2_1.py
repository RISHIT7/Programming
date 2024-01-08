def booths_multiplication(multiplier, multiplicand):
    # Initialize variables
    n = 16
    result = 0 # 32 bit integer -> Ac | Q
    counter = 0
    clock_num = 0

    # Perform Booth's algorithm
    while counter < 17:
        if counter == 0:
            result = (result) | multiplicand
            s = 0
            counter += 1

        elif result%2 == 0 and s == 1:
            result += multiplier << n
            s = result%2
            result >>= 1
            counter += 1
            
        elif result%2 == 1 and s == 0:
            result -= multiplier << n
            s = result%2
            result >>= 1
            counter += 1

        else:
            while result%2 == s:
                s = result%2
                result >>= 1
                counter += 1

        print(result)
        # Arithmetic right shift the multiplier and the accumulator
        clock_num += 1    
    print(f"hehe lol {clock_num}")
    return result

def run(binary_multiplicand, binary_multiplier):
            
    # Example with binary input
    # binary_multiplier = 0b0000000011111111 #"00110011.01000100"
    # binary_multiplicand = 0b0000011101001111 #"00100010.00010001"
    # binary_multiplier = 0b1011010100101011 #"00110011.01000100"
    # binary_multiplicand = 0b1000010111011000 #"00100010.00010001"

    # Remove the dot and get the total number of bits

    # Adjust the input for the fixed-point representation
    multiplier = binary_multiplier
    multiplicand = binary_multiplicand

    result = booths_multiplication(multiplier, multiplicand) # num of the multiplicand

    # Convert result back to binary fixed-point representation
    result_binary = bin(result)[2:].zfill(32)

    print(f"Binary Multiplier: {(bin(binary_multiplier)[2:].zfill(16))[:8]}{(bin(binary_multiplier)[2:].zfill(16))[8:]} (Decimal : {binary_multiplier})")
    print(f"Binary Multiplicand: {(bin(binary_multiplicand)[2:].zfill(16))[:8]}{(bin(binary_multiplicand)[2:].zfill(16))[8:]} (Decimal : {binary_multiplicand})")
    print(f"Result (Binary) {result_binary[:16]}{result_binary[16:]} (Decimal : {result})")

def main():
    with open(r"C:\Users\rishi\Desktop\Programming\COL\COL216\a_and_b.txt", "w") as file:
        pass

if __name__ == "__main__":
    main()