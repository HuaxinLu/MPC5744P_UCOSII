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
* Filename : bsp_os.c
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include  <cpu.h>
#include  <os.h>
#include  <lib_def.h>

#include  "bsp_os.h"
#include  "bsp_int.h"
#include  "MPC5744P.h"


/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/

#ifndef  OS_CFG_DYN_TICK_EN                                     /* Dynamic tick only available for uCOS-III             */
#define  OS_CFG_DYN_TICK_EN          DEF_DISABLED
#endif


/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static void  BSP_OS_TickISR(void);


/*
*********************************************************************************************************
*********************************************************************************************************
*                                           GLOBAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                          BSP_OS_TickInit()
*
* Description : Initializes the tick interrupt for the OS.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Note(s)     : (1) Must be called prior to OSStart() in main().
*
*               (2) This function ensures that the tick interrupt is disabled until BSP_OS_TickEn() is
*                   called in the startup task.
*********************************************************************************************************
*/

void  BSP_OS_TickInit (void)
{
    BSP_IntVectSet(226u, BSP_OS_TickISR, DEF_YES);              /* Place tick ISR into the vector table.                */
    BSP_IntPrioSet(226u, 0x1u);                                 /* Set tick interrupt to the lowest priority.           */

    PIT_0.MCR.B.MDIS             = 0u;                            /* Enable the PIT section of the module.                */
    PIT_0.MCR.B.FRZ              = 1u;                            /* Stop PIT timers while in debug mode.                 */

#if (OS_VERSION >= 30000u)
    PIT_0.TIMER[0].LDVAL.R     = (          40000000u /         /* PIT is clocked by F40.                               */
                                  OS_CFG_TICK_RATE_HZ);
#else
    PIT_0.TIMER[0].LDVAL.R     = (          25000000u /         /* PIT is clocked by F40.                               */
                                  OS_TICKS_PER_SEC);
#endif

    PIT_0.TIMER[0].TFLG.B.TIF  = 1u;                            /* Clear the interrupt flag for PIT_14.                 */
}


/*
*********************************************************************************************************
*                                         BSP_OS_TickEnable()
*
* Description : Enable the OS tick interrupt.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Note(s)     : none
*********************************************************************************************************
*/

void  BSP_OS_TickEnable (void)
{
	PIT_0.TIMER[0].TCTRL.B.TIE = 1u;                            /* Enable the interrupt.                                */
	PIT_0.TIMER[0].TCTRL.B.TEN = 1u;                            /* Enable the timer.                                    */
}


/*
*********************************************************************************************************
*                                        BSP_OS_TickDisable()
*
* Description : Disable the OS tick interrupt.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Note(s)     : none
*********************************************************************************************************
*/

void  BSP_OS_TickDisable (void)
{
	PIT_0.TIMER[0].TCTRL.B.TEN = 0u;                            /* Disable the timer.                                   */
	PIT_0.TIMER[0].TCTRL.B.TIE = 0u;                            /* Disable the interrupt.                               */
}


/*
*********************************************************************************************************
*                                           BSP_OS_TickISR()
*
* Description : Handles the PIT_14 interrupt.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Note(s)     : None.
*********************************************************************************************************
*/

static void  BSP_OS_TickISR (void)
{
	PIT_0.TIMER[0].TFLG.B.TIF = 1u;                             /* Clear the interrupt flag.                            */
    OSTimeTick();                                               /* Notify the kernel that a tick has occurred.          */
}


/*
*********************************************************************************************************
*********************************************************************************************************
**                                      uC/OS-III DYNAMIC TICK
*********************************************************************************************************
*********************************************************************************************************
*/

#if (OS_CFG_DYN_TICK_EN == DEF_ENABLED)


/*
*********************************************************************************************************
*                                          BSP_OS_TickGet()
*
* Description : Get the OS Tick Counter as if it was running continuously.
*
* Argument(s) : none.
*
* Return(s)   : The effective OS Tick Counter.
*
* Caller(s)   : OS_TaskBlock, OS_TickListInsertDly and OSTimeGet.
*
*               This function is an INTERNAL uC/OS-III function & MUST NOT be called by application
*               function(s).
*
* Note(s)     : none.
*********************************************************************************************************
*/

OS_TICK  BSP_OS_TickGet (void)
{
    OS_TICK  tick;


#error "BSP_OS_TickGet() needs to be implemented."

    return (tick);
}


/*
*********************************************************************************************************
*                                        BSP_OS_TickNextSet()
*
* Description : Set the number of OS Ticks to wait before calling OSTimeTick.
*
* Argument(s) : ticks       number of OS Ticks to wait.
*
* Return(s)   : Number of effective OS Ticks until next OSTimeTick.
*
* Caller(s)   : OS_TickTask and OS_TickListInsert.
*
*               This function is an INTERNAL uC/OS-III function & MUST NOT be called by application
*               function(s).
*
* Note(s)     : none.
*********************************************************************************************************
*/

OS_TICK  BSP_OS_TickNextSet (OS_TICK  ticks)
{
    OS_TICK  tick;


#error "BSP_OS_TickNextSet() needs to be implemented."

    return (tick);
}


/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of uC/OS-III Dynamic Tick module.                */

