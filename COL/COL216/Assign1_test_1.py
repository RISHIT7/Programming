def binary_fixed_point_multiply(a, b, num_frac_bits, num_int_bits):
    result = 0

    for i in range(num_frac_bits + num_int_bits):
        # Check if the least significant bit of multiplier is 1
        result <<= 1
        if (b & 1) == 1:
            result += a

        # Right shift multiplier
        print(bin(b))
        b >>= 1

    # Adjust the result for the fractional bits
    result = result >> num_frac_bits

    return result

# Example with binary input
binary_multiplier = 0b00110100 #"0011.0100"
binary_multiplicand = 0b00100001 #"0010.0001"

# Remove the dot and get the total number of bits

# Adjust the input for the fixed-point representation
multiplier = binary_multiplier
multiplicand = binary_multiplicand

result = binary_fixed_point_multiply(multiplier, multiplicand, 4, 4)

# Convert result back to binary fixed-point representation
result_binary = bin(result)[2:].zfill(16)

print("Binary Multiplier:", bin(binary_multiplier)[2:].zfill(8))
print("Binary Multiplicand:", bin(binary_multiplicand)[2:].zfill(8))
print(f"Result (Binary):", result_binary)
