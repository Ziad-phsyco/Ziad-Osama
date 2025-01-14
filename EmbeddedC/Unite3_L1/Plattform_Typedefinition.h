#define CPU_TYPE            0 //CPU_TYPE_8, CPU_TYPE_16, CPU_TYPE_32, CPU_TYPE_64
#define CPU_BIT_ORDER       0 //MSB_FIRST, LSB_FIRST
#define CPU_BYTE_ORDER      0 //HIGH_BYTE_FIRST, LOW_BYTE_FIRST
#define TRUE_FALSE          0 //0x00, 0x01

typedef unsigned char       boolean;
typedef signed char         sint8; 
typedef unsigned char       uint8;
typedef signed short        sint16;
typedef unsigned short      uint16;
typedef signed long         sint32;
typedef unsigned long       uint32;
typedef signed long long    sint64;
typedef unsigned long long  uint64;
typedef signed char         sint8_least;
typedef unsigned char       uint8_least;
typedef signed short        sint16_least;
typedef unsigned short      uint16_least;
typedef signed long         sint32_least;
typedef unsigned long       uint32_least;
typedef signed long long    sint64_least;
typedef unsigned long long  uint64_least;