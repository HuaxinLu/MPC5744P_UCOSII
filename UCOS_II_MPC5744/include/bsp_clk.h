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
* Filename : bsp_clk.h
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               MODULE
*
* Note(s) : (1) This header file is protected from multiple pre-processor inclusion through use of the
*               BSP present pre-processor macro definition.
*********************************************************************************************************
*/

#ifndef  BSP_CLK_PRESENT
#define  BSP_CLK_PRESENT


/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                     EXTERNAL C LANGUAGE LINKAGE
*
* Note(s) : (1) C++ compilers MUST 'extern'ally declare ALL C function prototypes & variable/object
*               declarations for correct C language linkage.
*********************************************************************************************************
*/

#ifdef __cplusplus
extern  "C" {                                                   /* See Note #1.                        */
#endif


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/
                                                                /* Clock IDs.                          */
typedef  enum  bsp_clk_id {
    CLK_ID_BCTU      =   0u,
    CLK_ID_eMIOS_0   =   1u,
    CLK_ID_eMIOS_1   =   2u,
    CLK_ID_eMIOS_2   =   3u,
    CLK_ID_USB_OTG   =   4u,
    CLK_ID_USB_SPH   =   5u,
    CLK_ID_MLB       =   6u,
    CLK_ID_SDHC      =   7u,
    CLK_ID_SAI0      =  10u,
    CLK_ID_SAI1      =  11u,
    CLK_ID_SAI2      =  12u,
    CLK_ID_ENET      =  15u,
    CLK_ID_CMP_0     =  20u,
    CLK_ID_CMP_1     =  21u,
    CLK_ID_CMP_2     =  22u,
    CLK_ID_ADC_0     =  24u,
    CLK_ID_ADC_1     =  25u,
    CLK_ID_FlexRay   =  28u,
    CLK_ID_IIC_0     =  30u,
    CLK_ID_IIC_1     =  31u,
    CLK_ID_IIC_2     =  32u,
    CLK_ID_IIC_3     =  33u,
    CLK_ID_DSPI_0    =  40u,
    CLK_ID_DSPI_1    =  41u,
    CLK_ID_DSPI_2    =  42u,
    CLK_ID_DSPI_3    =  43u,
    CLK_ID_LIN_0     =  50u,
    CLK_ID_LIN_1     =  51u,
    CLK_ID_LIN_2     =  52u,
    CLK_ID_LIN_3     =  53u,
    CLK_ID_LIN_4     =  54u,
    CLK_ID_LIN_5     =  55u,
    CLK_ID_LIN_6     =  56u,
    CLK_ID_LIN_7     =  57u,
    CLK_ID_LIN_8     =  58u,
    CLK_ID_LIN_9     =  59u,
    CLK_ID_LIN_10    =  60u,
    CLK_ID_LIN_11    =  61u,
    CLK_ID_LIN_12    =  62u,
    CLK_ID_LIN_13    =  63u,
    CLK_ID_LIN_14    =  64u,
    CLK_ID_LIN_15    =  65u,
    CLK_ID_LIN_16    =  66u,
    CLK_ID_LIN_17    =  67u,
    CLK_ID_FLEXCAN_0 =  70u,
    CLK_ID_FLEXCAN_1 =  71u,
    CLK_ID_FLEXCAN_2 =  72u,
    CLK_ID_FLEXCAN_3 =  73u,
    CLK_ID_FLEXCAN_4 =  74u,
    CLK_ID_FLEXCAN_5 =  75u,
    CLK_ID_FLEXCAN_6 =  76u,
    CLK_ID_FLEXCAN_7 =  77u,
    CLK_ID_TDM       =  81u,
    CLK_ID_JDC       =  82u,
    CLK_ID_MEMU_0    =  83u,
    CLK_ID_CRC       =  84u,
    CLK_ID_DMAMUX    =  90u,
    CLK_ID_PIT_RTI_0 =  91u,
    CLK_ID_WKPU      =  93u,
    CLK_ID_SPI0      =  96u,
    CLK_ID_SPI1      =  97u,
    CLK_ID_SPI2      =  98u,
    CLK_ID_SPI3      =  99u,
    CLK_ID_SPI4      = 100u,
    CLK_ID_SPI5      = 101u,
    CLK_ID_RTC_API   = 102u,
    CLK_ID_MEMU_1    = 105u
} BSP_CLK_ID;


/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void  BSP_ClkInit               (void);

void  BSP_ClkEnable             (BSP_CLK_ID  clk_id);

void  BSP_ClkDisable            (BSP_CLK_ID  clk_id);

void  BSP_ClkModeTransition_DRUN(void);


/*
*********************************************************************************************************
*                                   EXTERNAL C LANGUAGE LINKAGE END
*********************************************************************************************************
*/

#ifdef __cplusplus
}                                                               /* End of 'extern'al C lang linkage.   */
#endif


/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of module include.              */

