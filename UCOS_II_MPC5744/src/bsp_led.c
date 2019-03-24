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
* Filename : bsp_led.c
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include  "bsp_led.h"
#include  "MPC5744P.h"


/*
*********************************************************************************************************
*                                              DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
**                                         GLOBAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                           BSP_LED_Init()
*
* Description : Initializes the required pins that control the LEDs.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_Init (void)
{
    BSP_LED_Off(0u);

    SIUL2.MSCR[ 98u].B.SSS = 0u;                                /* PG2 source select: GPIO                              */
    SIUL2.MSCR[ 98u].B.OBE = 1u;                                /* PG2 GPIO Output Buffer: Enabled                      */

    SIUL2.MSCR[ 99u].B.SSS = 0u;                                /* PG3 source select: GPIO                              */
    SIUL2.MSCR[ 99u].B.OBE = 1u;                                /* PG3 GPIO Output Buffer: Enabled                      */

    SIUL2.MSCR[100u].B.SSS = 0u;                                /* PG4 source select: GPIO                              */
    SIUL2.MSCR[100u].B.OBE = 1u;                                /* PG4 GPIO Output Buffer: Enabled                      */

    SIUL2.MSCR[101u].B.SSS = 0u;                                /* PG5 source select: GPIO                              */
    SIUL2.MSCR[101u].B.OBE = 1u;                                /* PG5 GPIO Output Buffer: Enabled                      */
}


/*
*********************************************************************************************************
*                                            BSP_LED_On()
*
* Description : Turn ON a specific LED.
*
* Argument(s) : led    The ID of the LED to control.
*
* Return(s)   : none.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_On (BSP_LED  led)
{
    switch (led) {
        case USR_LED_ALL:
             SIUL2.PGPDO[6u].R &= ~(1u << 13u);
             SIUL2.PGPDO[6u].R &= ~(1u << 12u);
             SIUL2.PGPDO[6u].R &= ~(1u << 11u);
             SIUL2.PGPDO[6u].R &= ~(1u << 10u);
             break;


        case USR_LED1:
             SIUL2.PGPDO[6u].R &= ~(1u << 13u);
             break;


        case USR_LED2:
             SIUL2.PGPDO[6u].R &= ~(1u << 12u);
             break;


        case USR_LED3:
             SIUL2.PGPDO[6u].R &= ~(1u << 11u);
             break;


        case USR_LED4:
             SIUL2.PGPDO[6u].R &= ~(1u << 10u);
             break;


        default:
             break;
    }
}


/*
*********************************************************************************************************
*                                            BSP_LED_Off()
*
* Description : Turn OFF a specific LED.
*
* Argument(s) : led    The ID of the LED to control.
*
* Return(s)   : none.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_Off (BSP_LED  led)
{
    switch (led) {
        case USR_LED_ALL:
             SIUL2.PGPDO[6u].R |= 1u << 13u;
             SIUL2.PGPDO[6u].R |= 1u << 12u;
             SIUL2.PGPDO[6u].R |= 1u << 11u;
             SIUL2.PGPDO[6u].R |= 1u << 10u;
             break;


        case USR_LED1:
             SIUL2.PGPDO[6u].R |= 1u << 13u;
             break;


        case USR_LED2:
             SIUL2.PGPDO[6u].R |= 1u << 12u;
             break;


        case USR_LED3:
             SIUL2.PGPDO[6u].R |= 1u << 11u;
             break;


        case USR_LED4:
             SIUL2.PGPDO[6u].R |= 1u << 10u;
             break;


        default:
             break;
    }
}

/*
*********************************************************************************************************
*                                          BSP_LED_Toggle()
*
* Description : Toggles a specific LED.
*
* Argument(s) : led    The ID of the LED to control.
*
* Return(s)   : none.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_Toggle (BSP_LED  led)
{
    switch (led) {
        case USR_LED_ALL:
             SIUL2.PGPDO[6u].R ^= 1u << 13u;
             SIUL2.PGPDO[6u].R ^= 1u << 12u;
             SIUL2.PGPDO[6u].R ^= 1u << 11u;
             SIUL2.PGPDO[6u].R ^= 1u << 10u;
             break;


        case USR_LED1:
             SIUL2.PGPDO[6u].R ^= 1u << 13u;
             break;


        case USR_LED2:
             SIUL2.PGPDO[6u].R ^= 1u << 12u;
             break;


        case USR_LED3:
             SIUL2.PGPDO[6u].R ^= 1u << 11u;
             break;


        case USR_LED4:
             SIUL2.PGPDO[6u].R ^= 1u << 10u;
             break;


        default:
             break;
    }
}

