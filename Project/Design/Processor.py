# This is the over arching implementaiton of the Processor

# We want to implement basic ALU operations only at first, we may expand upon the "architecture + code" later :)

# We want out processor to have, pipelining, optimised addition and multiplication logics, Memory, Data, 16 registers (including x0)
# cache implementation and a TLB implementation are thoughts for the future updates

# for operation -> code[14:16]
# for choosing between I, R, mv type
# func2 -> code[0:2]

# R-type instructions func2 = 01
# rd -> code[10:14]
# rs2 -> code[2:6]
# rs1 -> code[6:10]

# move instruction func2 = 10
# rd -> code[10:14]
# imm -> code[2:10]

# I-type instruction func2 = 11
# rd -> code[10:14]
# rs1 -> code[6:10]
# imm -> code[2:6]

# instruction code 
# value -> code[2:8]

import sys
exit = "0000000000000000"
register_data = [0]*16

def control_panel(instr) -> bool:
    if (instr[0:2] == "10"):
        return True
    return False

def registers(instr, regW, data = 0):
    # in: data
    # out: data
    
    if (regW):
        if (instr[0:2] == "10"):
            # this is a mv instruction
            register_data[int(instr[10:14], 2)] = int(instr[2:10], 2)
        elif (instr[0:2] == "11"):
            # this is an I-type instruction
            pass
        elif (instr[0:2] == "01"):
            # this is a R-type instruction
            register_data[int(instr[10:14], 2)] = data
        else:
            raise SystemError("invalid instruction")        

            # handling x0 register
        if (instr[10:14] == "0000"):
            register_data[int(instr[10:14], 2)] = 0


        print(f"{instr} -> {register_data}")

    else:
        # return rs1, rs2
        print(f"{instr} -> {register_data}")
        return register_data[int(instr[6:10], 2)], register_data[int(instr[2:6], 2)]
    

def data_and_memory():
    # in: write-read, data
    # out: data
    pass

def instruction_fetch(pc: int, machine_code):
    # in: pc_count
    # out: instruction

    return machine_code[int(pc/4)]

def pc_counter(pc: int) -> int:
    # in: new_pc count
    # out: old_pc count
    return ALU.add(pc, 4)

class ALU:
    def aluOP(instr, a: int, b: int) -> int:
        # in: instruction
        # out: final answer, Zero bit

        if (instr[0:2] == "01" or instr[0:2] == "11"):
            if (instr[14:16] == "00"):
                # add
                return ALU.add(a, b)

            elif (instr[14:16] == "01"):
                # sub
                return ALU.sub(a, b)
                
            elif (instr[14:16] == "10"):
                # mul
                return ALU.mul(a, b)

            elif (instr[14:16] == "11"):
                # div
                return ALU.div(a, b)
        
        return 0        


    def add(a: int, b: int) -> int:
        # in: two registers
        # out: one register
        
        # prototype
        return a + b

    def mul(a: int, b: int) -> int:
        # in: two registers
        # out: one register

        # prototype
        return a * b

    def sub(a: int, b: int) -> int:
        # in: two registers
        # out: one register

        # prototype
        return a - b

    def div(a: int, b: int) -> int:
        # in: two registers
        # out: one register

        # prototype
        return a / b

def main():
    # overlooking the process
       
    machine_code = sys.argv[1]
    # opening the machine code
    with open(machine_code, "r") as f:
        machine_code = f.read()
    # parsing the machine code
    machine_code = machine_code.split("\n")
       
    # running the processor
    pc = 0
    instr = machine_code[int(pc/4)]
    while (instr != exit):
        try:
            control_signals = control_panel(instr)
            # for now
            regW = control_signals
            registersData = registers(instr, regW)
            # Execution: Ex
            if (instr[0:2] != "10"):
                output = ALU.aluOP(instr, registersData[0], registersData[1])
                # Memory Access: Mem
                # Write Back: Wb
                registers(instr, True, output)

            # Instruction Fetch: IF
            pc = pc_counter(pc)
            # Instruction Decode: ID
            instr = instruction_fetch(pc, machine_code)
        except:
            raise SystemError("EOF Error")
    

if __name__ == "__main__":
    main()
