def binary_fixed_point_multiply(a, b):
    result = 0
    num_bits = 16

    for i in range(num_bits):
        # Check if the least significant bit of multiplier is 1
        if (b & 1) == 1:
            result += a

        # Right shift multiplier
        a <<= 1
        b >>= 1


    return result


def main():
            
    # Example with binary input
    binary_multiplier = 0b0101110110111101 #"00110011.01000100"
    binary_multiplicand = 0b0100110101101001 #"00100010.00010001"

    # Remove the dot and get the total number of bits

    # Adjust the input for the fixed-point representation
    multiplier = binary_multiplier
    multiplicand = binary_multiplicand

    result = binary_fixed_point_multiply(multiplier, multiplicand) # num of the multiplicand

    # Convert result back to binary fixed-point representation
    result_binary = bin(result)[2:].zfill(32)

    print(f"Binary Multiplier: {(bin(binary_multiplier)[2:].zfill(16))[:8]}{(bin(binary_multiplier)[2:].zfill(16))[8:]} (Decimal : {binary_multiplier})")
    print(f"Binary Multiplicand: {(bin(binary_multiplicand)[2:].zfill(16))[:8]}{(bin(binary_multiplicand)[2:].zfill(16))[8:]} (Decimal : {binary_multiplicand})")
    print(f"Result (Binary) {result_binary[:16]}{result_binary[16:]} (Decimal : {result})")

if __name__ == "__main__":
    main()