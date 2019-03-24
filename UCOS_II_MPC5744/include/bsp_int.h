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
* Filename : bsp_int.h
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                                 MODULE
*
* Note(s) : (1) This header file is protected from multiple pre-processor inclusion through use of the
*               BSP present pre-processor macro definition.
*********************************************************************************************************
*/

#ifndef  BSP_INT_PRESENT
#define  BSP_INT_PRESENT


/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/

#include  <cpu.h>
#include  <lib_def.h>
#include  <os.h>


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   BSP_INT_MODULE
#define  BSP_INT_EXT
#else
#define  BSP_INT_EXT  extern
#endif


/*
*********************************************************************************************************
*                                              DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                              STRUCTURES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                         INTERRUPT SERVICES
*********************************************************************************************************
*/

void  BSP_IntInit       (void);

void  BSP_IntEn         (CPU_INT16U     int_id);
void  BSP_IntDis        (CPU_INT16U     int_id);
void  BSP_IntClr        (CPU_INT16U     int_id);

void  BSP_IntVectSet    (CPU_INT16U     int_id,
                         CPU_FNCT_VOID  isr,
                         CPU_BOOLEAN    isKA);

void  BSP_IntPrioSet    (CPU_INT16U     int_id,
                         CPU_INT08U     prio);

void  BSP_IntPrioMaskSet(CPU_INT08U     prio);


/*
*********************************************************************************************************
*                                           MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of module include.                               */

