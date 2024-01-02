def booths_multiplier(multiplier, multiplicand, num_int_bits, num_frac_bits):
    # Initialize variables
    n = num_int_bits + num_frac_bits  
    result = 0
    accumulator = 0

    # Perform Booth's algorithm
    for i in range(n):
        # Check the least significant two bits of the multiplier
        two_bits = (multiplier & 0b11)
        
        # Based on the two bits, perform the corresponding operation
        if two_bits == 0b01:
            accumulator -= multiplicand
        elif two_bits == 0b10:
            accumulator += multiplicand
        
        # Arithmetic right shift the multiplier and the accumulator
        multiplier >>= 1
        accumulator >>= 1

    # Combine the final result from the accumulator and the multiplier
    result = (accumulator << n) | multiplier

    return result

def main():
            
    # Example with binary input
    binary_multiplier = 0b0011001101000100 #"00110011.01000100"
    binary_multiplicand = 0b0010001000010001 #"00100010.00010001"

    # Remove the dot and get the total number of bits

    # Adjust the input for the fixed-point representation
    multiplier = binary_multiplier
    multiplicand = binary_multiplicand

    result = booths_multiplier(multiplier, multiplicand, 8, 8)

    # Convert result back to binary fixed-point representation
    result_binary = bin(result)[2:].zfill(32)
    print(bin(result))

    print(f"Binary Multiplier: {(bin(binary_multiplier)[2:].zfill(16))[:8]}.{(bin(binary_multiplier)[2:].zfill(16))[8:]}")
    print(f"Binary Multiplicand: {(bin(binary_multiplicand)[2:].zfill(16))[:8]}.{(bin(binary_multiplicand)[2:].zfill(16))[8:]}")
    print(f"Result (Binary) {result_binary[:16]}.{result_binary[16:]}")

if __name__ == "__main__":
    main()