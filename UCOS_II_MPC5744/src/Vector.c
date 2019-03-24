/**************************************************************************/
/*                                                                        */
/* DESCRIPTION:                                                           */
/* This is a generic base template for all core exceptions, excluding     */
/* the IVOR4 exception which has a seperate handler                       */
/*                                                                        */
/* This file starts in memory at the beginning of the                     */
/* .core_exceptions_table_c2" section.                                    */
/**************************************************************************/

#define PPCASM   __asm__
#define PPCASM_STR(x) #x
#define PPCASMF(x) PPCASM (" " PPCASM_STR(x) " ")
#define PPCASMF2(x,x1) PPCASM (" " PPCASM_STR(x) "," PPCASM_STR(x1) " ")

PPCASMF( .globl VTABLE );
PPCASMF( .globl IVOR0_Vector );
PPCASMF( .globl IVOR1_Vector );
PPCASMF( .globl IVOR2_Vector );
PPCASMF( .globl IVOR3_Vector );
PPCASMF( .globl IVOR4_Vector );
PPCASMF( .globl IVOR5_Vector );
PPCASMF( .globl IVOR6_Vector );
PPCASMF( .globl IVOR7_Vector );
PPCASMF( .globl IVOR8_Vector );
PPCASMF( .globl IVOR9_Vector );
PPCASMF( .globl IVOR10_Vector );
PPCASMF( .globl IVOR11_Vector );
PPCASMF( .globl IVOR12_Vector );
PPCASMF( .globl IVOR13_Vector );
PPCASMF( .globl IVOR14_Vector );
PPCASMF( .globl IVOR15_Vector );

PPCASMF( .extern OS_ExceptHandler_CriticalInput );
PPCASMF( .extern OS_ExceptHandler_MachineCheck );
PPCASMF( .extern OS_ExceptHandler_DataStorage );
PPCASMF( .extern OS_ExceptHandler_InstructionStorage );
PPCASMF( .extern OS_ExceptHandler_ExternalInput );
PPCASMF( .extern OS_ExceptHandler_Alignment );
PPCASMF( .extern OS_ExceptHandler_Program );
PPCASMF( .extern OS_ExceptHandler_PerformanceMonitor );
PPCASMF( .extern OS_ExceptHandler_SystemCall );
PPCASMF( .extern OS_ExceptHandler_Debug );
PPCASMF( .extern OS_ExceptHandler_EFPUDataException );
PPCASMF( .extern OS_ExceptHandler_EFPURoundException );
PPCASMF( .extern OS_ExceptHandler_EFPUUnavailable );
PPCASMF( .extern OS_ExceptHandler_IVOR13 );
PPCASMF( .extern OS_ExceptHandler_IVOR14 );
PPCASMF( .extern OS_ExceptHandler_IVOR15 );

PPCASMF2( .section    .core_exceptions_table, "ax" );

PPCASMF(.align 4);
PPCASMF( VTABLE: );
PPCASMF( IVOR0_Vector: );
PPCASMF( e_b   OS_ExceptHandler_CriticalInput );

PPCASMF(.align 4);
PPCASMF( IVOR1_Vector: );
PPCASMF( e_b   OS_ExceptHandler_MachineCheck );

PPCASMF(.align 4);
PPCASMF( IVOR2_Vector: );
PPCASMF( e_b   OS_ExceptHandler_DataStorage );

PPCASMF(.align 4);
PPCASMF( IVOR3_Vector: );
PPCASMF( e_b   OS_ExceptHandler_InstructionStorage );

PPCASMF(.align 4);
PPCASMF( IVOR4_Vector: );
PPCASMF( e_b   OS_ExceptHandler_ExternalInput );

PPCASMF(.align 4);
PPCASMF( IVOR5_Vector: );
PPCASMF( e_b   OS_ExceptHandler_Alignment );

PPCASMF(.align 4);
PPCASMF( IVOR6_Vector: );
PPCASMF( e_b   OS_ExceptHandler_Program );

PPCASMF(.align 4);
PPCASMF( IVOR7_Vector: );
PPCASMF( e_b   OS_ExceptHandler_PerformanceMonitor );

PPCASMF(.align 4);
PPCASMF( IVOR8_Vector: );
PPCASMF( e_b   OS_ExceptHandler_SystemCall );

PPCASMF(.align 4);
PPCASMF( IVOR9_Vector: );
PPCASMF( e_b   OS_ExceptHandler_Debug );

PPCASMF(.align 4);
PPCASMF( IVOR10_Vector: );
PPCASMF( e_b   OS_ExceptHandler_EFPUDataException );

PPCASMF(.align 4);
PPCASMF( IVOR11_Vector: );
PPCASMF( e_b   OS_ExceptHandler_EFPURoundException );

PPCASMF(.align 4);
PPCASMF( IVOR12_Vector: );
PPCASMF( e_b   OS_ExceptHandler_EFPUUnavailable );

PPCASMF(.align 4);
PPCASMF( IVOR13_Vector: );
PPCASMF( e_b   OS_ExceptHandler_IVOR13 );

PPCASMF(.align 4);
PPCASMF( IVOR14_Vector: );
PPCASMF( e_b   OS_ExceptHandler_IVOR14 );

PPCASMF(.align 4);
PPCASMF( IVOR15_Vector: );
PPCASMF( e_b   OS_ExceptHandler_IVOR15 );


