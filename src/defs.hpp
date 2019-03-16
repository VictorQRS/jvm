#pragma once

#define W(x)         std::cerr << "\033[35m" << #x << "=" << (x) << "\033[0m" << "\n";
#define MAGIC_NUMBER 0xCAFEBABE
#define BYTESIZE     8
#define HALFSIZE     16
#define WORDSIZE     32

#define T_ARRAY      1 // TODO: verify this
#define T_OBJ        2 // TODO: verify this
#define T_REF        3 // TODO: verify this
#define T_BOOL       4
#define T_CHAR       5
#define T_FLOAT      6
#define T_DOUBLE     7
#define T_BYTE       8
#define T_SHORT      9
#define T_INT       10
#define T_LONG      11
#define T_RET       12
#define T_METHOD    13 // TODO: verify this
#define T_INTERFACE 14 // TODO: verify this
#define T_STRING    69 // TODO: verify this