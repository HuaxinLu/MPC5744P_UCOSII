/*
*********************************************************************************************************
*                                            EXAMPLE CODE
*
*               This file is provided as an example on how to use Micrium products.
*
*               Please feel free to use any application code labeled as 'EXAMPLE CODE' in
*               your application products.  Example code may be used as is, in whole or in
*               part, or may be used as a reference only. This file can be modified as
*               required to meet the end-product requirements.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*
*               You can find our product's user manual, API reference, release notes and
*               more information at https://doc.micrium.com.
*               You can contact us at www.micrium.com.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                    MICRIUM BOARD SUPPORT PACKAGE
*                                            MPC574xG-324DS
*
* Filename : bsp_int.c
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#define  BSP_INT_MODULE
#include  "MPC5744P.h"
#include  "bsp_int.h"
#include  "bsp_os.h"


/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/

#define  BSP_INT_VECT_TBL_SIZE          754u
#define  BSP_INT_MAX_PRIO               0xFu


/*
*********************************************************************************************************
*                                           LOCAL CONSTANTS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                          LOCAL DATA TYPES
*********************************************************************************************************
*/

typedef  struct  bsp_int_isr {
    CPU_FNCT_VOID  FnctPtr;
    CPU_BOOLEAN    isKA;
} BSP_INT_ISR;


/*
*********************************************************************************************************
*                                            LOCAL TABLES
*********************************************************************************************************
*/

static  BSP_INT_ISR  BSP_IntVectTbl[BSP_INT_VECT_TBL_SIZE];


/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  BSP_IntHandlerDummy(void);


/*
*********************************************************************************************************
*                                     LOCAL CONFIGURATION ERRORS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                              BSP_IntInit()
*
* Description : Initialize interrupts.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_IntInit (void)
{
    CPU_INT16U  i;
    CPU_SR_ALLOC();


    CPU_CRITICAL_ENTER();

    INTC_0.BCR.B.HVEN0 = 0u;                                      /* Use software vector mode for Z4a.                    */

    for (i = 0; i < BSP_INT_VECT_TBL_SIZE; i++) {               /* Initialize the vector table.                         */
        BSP_IntVectTbl[i].FnctPtr = BSP_IntHandlerDummy;
        BSP_IntVectTbl[i].isKA    = DEF_NO;
    }

    INTC_0.CPR0.B.PRI = 0x0u;                                  /* Don't mask any interrupts.                           */
    CPU_CRITICAL_EXIT();
}


/*
*********************************************************************************************************
*                                            BSP_IntVectSet()
*
* Description : Place an ISR handler into the vector table.
*
* Argument(s) : int_id      Interrupt for which vector will be set.
*
*               isr         Handler to assign.
*
*               isKA
*
* Return(s)   : none.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_IntVectSet (CPU_INT16U     int_id,
                      CPU_FNCT_VOID  isr,
                      CPU_BOOLEAN    isKA)
{
    CPU_SR_ALLOC();


    if (int_id >= BSP_INT_VECT_TBL_SIZE) {
        return;
    }

    CPU_CRITICAL_ENTER();

    BSP_IntVectTbl[int_id].FnctPtr = isr;
    BSP_IntVectTbl[int_id].isKA    = isKA;

    CPU_CRITICAL_EXIT();
}


/*
*********************************************************************************************************
*                                            BSP_IntVectClr()
*
* Description : Remove an ISR handler from the vector table and mask it.
*
* Argument(s) : int_id      Interrupt for which vector will be set.
*
*               isr         Handler to assign.
*
* Return(s)   : none.
*
* Note(s)     : (1) The peripheral interrupt should be disabled before calling this function.
*********************************************************************************************************
*/

void  BSP_IntVectClr (CPU_INT16U     int_id,
                      CPU_FNCT_VOID  isr)
{
    CPU_SR_ALLOC();


    if (int_id >= BSP_INT_VECT_TBL_SIZE) {
        return;
    }

    CPU_CRITICAL_ENTER();

    INTC_0.PSR[int_id].B.PRIN = 0u;                               /* Mask the interrupt.                                  */

    BSP_IntVectTbl[int_id].FnctPtr = BSP_IntHandlerDummy;

    CPU_CRITICAL_EXIT();
}


/*
*********************************************************************************************************
*                                            BSP_IntPrioSet()
*
* Description : Assign ISR priority.
*
* Argument(s) : int_id      Interrupt for which vector will be set.
*
*               prio        Priority to assign. Between 0h and Fh inclusive.
*                           0h is equivalent to masking the interrupt.
*
* Return(s)   : none.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_IntPrioSet (CPU_INT16U  int_id,
                      CPU_INT08U  prio)
{
    CPU_SR_ALLOC();


    if ((int_id >= BSP_INT_VECT_TBL_SIZE) ||
        (prio   >       BSP_INT_MAX_PRIO)) {
        return;
    }

    CPU_CRITICAL_ENTER();

    INTC_0.PSR[int_id].B.PRIN = prio;

    CPU_CRITICAL_EXIT();
}


/*
*********************************************************************************************************
*                                         BSP_IntPrioMaskSet()
*
* Description : Masks all interrupts with priorities less than or equal to prio.
*
* Argument(s) : prio        Highest priority to mask between 0h and Fh inclusive.
*                           0h enables all interrupts.
*                           Fh masks all interrupts.
*
* Return(s)   : none.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_IntPrioMaskSet (CPU_INT08U  prio)
{
    CPU_SR_ALLOC();


    if (prio > BSP_INT_MAX_PRIO) {
        return;
    }

    CPU_CRITICAL_ENTER();

    INTC_0.CPR0.B.PRI = prio;//屏蔽掉所有优先级以下的中断

    CPU_CRITICAL_EXIT();
}


/*
*********************************************************************************************************
*********************************************************************************************************
*                                           INTERRUPT HANDLER
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                          OS_CPU_IntHandler()
*
* Description : Central interrupt handler.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  OS_CPU_IntHandler (void)
{
    CPU_INT16U   int_id;
    CPU_BOOLEAN  isKA;

                                                                /* ---- INTERRUPTS ARE DISABLED BEFORE WE GET HERE ---- */
    int_id = INTC_0.IACKR0.B.INTVEC;                           /* Acknowledge the interrupt.  */
     	 	 	 	 	 	 	 	 	 	 	 	 	 	 	/* 获取中断信息*/

    isKA = BSP_IntVectTbl[int_id].isKA;

    if (isKA == DEF_NO) {
        CPU_IntEn();                                            /* Allow interrupt nesting.                             */
        BSP_IntVectTbl[int_id].FnctPtr();                       /* Call the appropriate handler.                        */

        CPU_MB();                                               /* Ensure that the interrupt flag was cleared.          */

        CPU_IntDis();
        INTC_0.EOIR0.R = 0x00000000u;                          /* Signal the end of interrupt.                         */

    } else {
        OSIntEnter();                                           /* Increment the nesting counter.                       */

        CPU_IntEn();                                            /* Allow interrupt nesting.                             */

        BSP_IntVectTbl[int_id].FnctPtr();                       /* Call the appropriate handler.                        */

        CPU_MB();                                               /* Ensure that the interrupt flag was cleared.          */

        CPU_IntDis();
        INTC_0.EOIR0.R = 0x00000000u;                          /* Signal the end of interrupt.                         */

        OSIntExit();                                            /* Decrement nesting counter. Context switch if 0.      */
    }
}


/*
*********************************************************************************************************
*********************************************************************************************************
*                                           LOCAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                        BSP_IntHandlerDummy()
*
* Description : Dummy interrupt handler.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Note(s)     : none.
*********************************************************************************************************
*/

static  void  BSP_IntHandlerDummy (void)
{
    while (1u) {
        CPU_NOP();
    }
}

