#********************************************************************************************************
#*                                                uC/CPU
#*                                    CPU CONFIGURATION & PORT LAYER
#*
#*                          (c) Copyright 2004-2017; Micrium, Inc.; Weston, FL
#*
#*               All rights reserved.  Protected by international copyright laws.
#*
#*               uC/CPU is provided in source form to registered licensees ONLY.  It is 
#*               illegal to distribute this source code to any third party unless you receive 
#*               written permission by an authorized Micrium representative.  Knowledge of 
#*               the source code may NOT be used to develop a similar product.
#*
#*               Please help us continue to provide the Embedded community with the finest 
#*               software available.  Your honesty is greatly appreciated.
#*
#*               You can find our product's user manual, API reference, release notes and
#*               more information at https://doc.micrium.com.
#*               You can contact us at www.micrium.com.
#********************************************************************************************************

#********************************************************************************************************
#*
#*                                            CPU PORT FILE
#*
#*                                           NXP MPC57xx-VLE
#*
#* Filename      : cpu_a.s
#* Version       : V1.31.02
#* Programmer(s) : FGK
#*                 ITJ
#*                 SB
#********************************************************************************************************


#********************************************************************************************************
#*                                             ASM HEADER
#********************************************************************************************************

    .text

#********************************************************************************************************
#                                          PUBLIC DECLARATIONS
#********************************************************************************************************

    .global  CPU_SR_Save
    .global  CPU_SR_Restore
    .global  CPU_SR_Rd
    .global  CPU_IntDis
    .global  CPU_IntEn


#********************************************************************************************************
#*                                     CRITICAL SECTION FUNCTIONS
#*
#* Description : These functions are used to enter and exit critical sections using Critical Method #3.
#*
#*                   CPU_SR  CPU_SR_Save (void)
#*                          Get current global interrupt mask bit value from MSR
#*                          Disable interrupts
#*                          Return global interrupt mask bit
#*
#*                   void  CPU_SR_Restore (CPU_SR  cpu_sr)
#*                          Set global interrupt mask bit on MSR according to parameter cpu_sr
#*                          Return
#*
#* Argument(s) : cpu_sr      global interrupt mask status.
#********************************************************************************************************

CPU_SR_Save:
    mfmsr   r3
    wrteei  0
    se_blr

CPU_SR_Restore:
    wrtee   r3
    se_blr


#********************************************************************************************************
#*                                    READ STATUS REGISTER FUNCTION
#*
#* Description : This function is used to retrieve the status register value.
#*
#*                   CPU_SR  CPU_SR_Rd (void)
#*                          Get current MSR value
#*                          Return
#********************************************************************************************************

CPU_SR_Rd:
    mfmsr   r3
    se_blr


#********************************************************************************************************
#*                                      DISABLE/ENABLE INTERRUPTS
#*
#* Description : Disable/Enable interrupts by setting or clearing the global interrupt mask in the cpu
#*               status register.
#*
#*                    void  CPU_IntDis (void)
#*                           Set global interrupt mask bit on MSR
#*                           Return
#*
#*                    void  CPU_IntEn (void)
#*                           Clear global interrupt mask bit on MSR
#*                           Return
#********************************************************************************************************

CPU_IntDis:
    wrteei  0
    se_blr


CPU_IntEn:
    wrteei  1
    se_blr


#********************************************************************************************************
#*                                     CPU ASSEMBLY PORT FILE END
#********************************************************************************************************
    .end
