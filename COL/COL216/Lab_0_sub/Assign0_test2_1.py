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

        # Arithmetic right shift the multiplier and the accumulator
        clock_num += 1    
    return result, clock_num

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

    result, clock_num = booths_multiplication(multiplier, multiplicand) # num of the multiplicand

    # Convert result back to binary fixed-point representation
    # result_binary = bin(result)[2:].zfill(32)

    # print(f"Binary Multiplier: {(bin(binary_multiplier)[2:].zfill(16))[:8]}{(bin(binary_multiplier)[2:].zfill(16))[8:]} (Decimal : {binary_multiplier})")
    # print(f"Binary Multiplicand: {(bin(binary_multiplicand)[2:].zfill(16))[:8]}{(bin(binary_multiplicand)[2:].zfill(16))[8:]} (Decimal : {binary_multiplicand})")
    # print(f"Result (Binary) {result_binary[:16]}{result_binary[16:]} (Decimal : {result})")
    
    return clock_num        

def string_bin_to_int(input):
    input = input[1:-1]
    result = 0
    i = 0
    for char in input[::-1]:
        if (char == "1"):
            result += 2**i
        i += 1
    return result

def main():
    result_list = []
    with open(r"C:\Users\rishi\Desktop\Programming\COL\COL216\a_and_b.txt", "r") as file:
        para = file.read()
        lines = para.split("\n")
        lines = lines[:-1]
        for line in lines:
            binary_multiplicand = line.split(", ")[0]
            binary_multiplier = line.split(", ")[1]
            binary_multiplicand = string_bin_to_int(binary_multiplicand)
            binary_multiplier = string_bin_to_int(binary_multiplier)
            clock_num = run(binary_multiplicand, binary_multiplier)
            result_list.append(clock_num)
    file.close()
    
    with open(r"C:\Users\rishi\Desktop\Programming\COL\COL216\out_clock.txt", "w") as file:
        for el in result_list:
            file.write(str(el) + "\n")
    file.close()

if __name__ == "__main__":
    main()