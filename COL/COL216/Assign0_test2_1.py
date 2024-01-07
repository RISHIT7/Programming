def booths_multiplication(multiplier, multiplicand):
    # Initialize variables
    n = 16
    result = 0 # 32 bit integer -> Ac | Q
    Q = multiplier
    counter = 0
    
    result = (result) | multiplier
    
    # Perform Booth's algorithm
    for i in range(n):
        # Check the least significant two bits of the multiplier
        two_bits = (Q & 0b11)
        
        # Based on the two bits, perform the corresponding operation
        if two_bits == 0b01:
            result += multiplicand << n
            counter += 1
            
        elif two_bits == 0b10:
            result -= multiplicand << n
            counter += 1

        print(result)
        # Arithmetic right shift the multiplier and the accumulator
        Q >>= 1
        result >>= 1
    result <<= 1
    
    if (multiplier & 0b1 == 1):
        result -= multiplicand
    
    print(f"hehe lol {multiplicand << n}")
    return result

def main():
            
    # Example with binary input
    # binary_multiplier = 0b0000000011111111 #"00110011.01000100"
    # binary_multiplicand = 0b0000011101001111 #"00100010.00010001"
    # binary_multiplier = 0b1011010100101011 #"00110011.01000100"
    # binary_multiplicand = 0b1000010111011000 #"00100010.00010001"
    binary_multiplier = 0b1001001000101110 #"00110011.01000100"
    binary_multiplicand = 0b1001001000101110 #"00100010.00010001"

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

if __name__ == "__main__":
    main()