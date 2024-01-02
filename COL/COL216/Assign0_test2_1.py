def booths_multiplication(multiplier, multiplicand):
    # Initialize variables
    n = 16  # Assuming 16-bit multiplication
    result = 0
    Q = multiplier
    accumulator = 0

    # Perform Booth's algorithm
    for i in range(n):
        # Check the least significant two bits of the multiplier
        two_bits = (Q & 0b11)
        
        # Based on the two bits, perform the corresponding operation
        if two_bits == 0b01:
            accumulator += multiplicand
        elif two_bits == 0b10:
            accumulator -= multiplicand
        
        # Arithmetic right shift the multiplier and the accumulator
        Q >>= 1
        accumulator >>= 1

    # Combine the final result from the accumulator and the multiplier
    result = (accumulator << n) | Q
    return result

# Example usage:
multiplier = 0b0011001101000100  
multiplicand = 0b0010001000010001  

result = booths_multiplication(multiplier, multiplicand)

print(f"Result of {bin(multiplier)} (Decimal: {multiplier}) * {bin(multiplicand)} (Decimal: {multiplicand}) is {bin(result)} (Decimal: {result})")
