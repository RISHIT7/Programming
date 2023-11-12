#ifndef STAPLE_BYTECODE_H
#define STAPLE_BYTECODE_H

enum _Opcode {
    NOP = 0x00,
    PUSH_CONST = 0x01,
    ADD_STACK = 0x02,
    // SUB_STACK = 0x03,
    // MUL_STACK = 0X04,
    HLT_OP = 0xFF
};

#endif // STAPLE_BYTECODE_H