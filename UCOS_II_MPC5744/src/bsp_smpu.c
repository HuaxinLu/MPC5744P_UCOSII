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
* Filename : bsp_smpu.c
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include "MPC5744P.h"


/*
*********************************************************************************************************
*                                                EXTERNS
*********************************************************************************************************
*/
                                                                /* Normal SRAM.                                         */
extern  int  __SRAM_BASE_ADDR;
extern  int  __SRAM_SIZE;

                                                                /* Caching inhibited SRAM.                              */
extern  int  __MPU_NOCACHE_BASE_ADDR;
extern  int  __MPU_NOCACHE_SIZE;


/*
*********************************************************************************************************
*                                            BSP_SMPU_Init()
*
* Description : Set up memory regions for the application.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Note(s)     : None.
*********************************************************************************************************
*/

void  BSP_SMPU_Init (void)
{
    int  start_addr;
    int  end_addr;

    start_addr = (int)&__SRAM_BASE_ADDR;
    end_addr   = (int)&__SRAM_BASE_ADDR + (int)&__SRAM_SIZE - (int)&__MPU_NOCACHE_SIZE - 1u;

    SMPU_0.RGD[0u].WORD0.R      = start_addr;                    /* Start Address.                                       */
    SMPU_0.RGD[0u].WORD1.R      = end_addr;                      /* End Address.                                         */
    SMPU_0.RGD[0u].WORD3.R  = 0u;                            /* Use FMT 0 for the access permissions.                */
    SMPU_0.RGD[0u].WORD2.R = 0xFFFFFFFFu;                   /* R/W access for all bus masters.                      */
    SMPU_0.RGD[0u].WORD3.B.CI   = 0u;                            /* Enable caching for this region.                      */
    SMPU_0.RGD[0u].WORD3.B.VLD  = 1u;                            /* The region descriptor is valid.                      */

    start_addr = (int)&__MPU_NOCACHE_BASE_ADDR;
    end_addr   = (int)&__MPU_NOCACHE_BASE_ADDR + (int)&__MPU_NOCACHE_SIZE - 1u;

    SMPU_0.RGD[1u].WORD0.R      = start_addr;                    /* Start Address.                                       */
    SMPU_0.RGD[1u].WORD1.R      = end_addr;                      /* End Address.                                         */
    SMPU_0.RGD[1u].WORD3.R  = 0u;                            /* Use FMT 0 for the access permissions.                */
    SMPU_0.RGD[1u].WORD2.R = 0xFFFFFFFFu;                   /* R/W access for all bus masters.                      */
    SMPU_0.RGD[1u].WORD3.B.CI   = 1u;                            /* Disable caching for this region.                     */
    SMPU_0.RGD[1u].WORD3.B.VLD  = 1u;                            /* The region descriptor is valid.                      */

    SMPU_0.CESR0.B.GVLD = 1u;                                     /* Enable the MPU.                                      */
}

