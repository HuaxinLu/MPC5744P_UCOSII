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
* Filename : bsp_clk.c
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include  <lib_def.h>
#include  "bsp_clk.h"
#include  "MPC5744P.h"

#ifdef  CLK_MODULE_PRESENT
#include  <Source/clk.h>
#include  <clk_cfg.h>
#endif


/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/

#define  BSP_MCTL_DRUN                            (   0x3u << 28u)
#define  BSP_MCTL_KEY                             (0x5AF0u <<  0u)
#define  BSP_MCTL_INV_KEY                         (0xA50Fu <<  0u)


/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                          GLOBAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            BSP_ClkInit()
*
* Description : Initializes the system clock for the kernel.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Note(s)     : (1) Should be called before OSStart() in main.
*********************************************************************************************************
*/

void  BSP_ClkInit (void)
{
//                                                                /* ----------------- CONFIGURE MC_CGM ----------------- */
//    MC_CGM.AC5_SC.B.SELCTL = 1u;                                /* Select OSC as input to the PLL.                      */
//
//                                                                /* ------------------ CONFIGURE PLL ------------------- */
//                                                                /* VCO = 40 MHz / PREDIV * (MFD + (MFN / (MFDEN + 1)))  */
//                                                                /*     = 40 MHz /      2 * (16  + (  0 / (    1 + 1)))  */
//                                                                /*     = 320 MHz                                        */
//    PLLDIG.PLLDV.B.PREDIV  =  2u;
//    PLLDIG.PLLDV.B.MFD     = 16u;
//    PLLDIG.PLLFD.B.MFN     =  0u;
//    PLLDIG.PLLCAL3.B.MFDEN =  1u;
//
//    PLLDIG.PLLDV.B.RFDPHI  =  0u;                               /* PHI  = VC0 / 2 = 160 MHz                             */
//    PLLDIG.PLLDV.B.RFDPHI1 =  1u;                               /* PHI1 = VC0 / 4 =  80 MHz                             */
//
//                                                                /* --------------- CONFIGURE DRUN MODE ---------------- */
//    MC_ME.DRUN_MC.B.PLLON   = 1u;                               /* Enable the PLL.                                      */
//    MC_ME.DRUN_MC.B.FXOSCON = 1u;                               /* Enable the OSC.                                      */
//    MC_ME.DRUN_MC.B.SYSCLK  = 2u;                               /* Use PLL PHI_0 for the system clock.                  */
//
//
//    MC_ME.RUN_PC[0].R = 0xF8u;                                  /* PC0: Affected peripherals enabled for all RUN modes. */
//    MC_ME.RUN_PC[1].R = 0x00u;                                  /* PC1: Affected peripherals disabled for all RUN modes.*/
//
//    BSP_ClkModeTransition_DRUN();                               /* Apply the new configuration.                         */

    MC_CGM.AC3_SC.B.SELCTL = 0x01;		    //connect XOSC to the PLL0 input
    MC_CGM.AC4_SC.B.SELCTL = 0x01;		    //connect XOSC to the PLL1 input

    // Set PLL0 to 50 MHz with 40MHz XOSC reference
    PLLDIG.PLL0DV.R = 0x3008100A;	     // PREDIV =  1, MFD = 10, RFDPHI = 8, RFDPHI1 = 6

    MC_ME.RUN0_MC.R = 0x00130070;		    // RUN0 cfg: IRCON,OSC0ON,PLL0ON,syclk=IRC

    // Mode Transition to enter RUN0 mode:
    MC_ME.MCTL.R = 0x40005AF0;		    // Enter RUN0 Mode & Key
    MC_ME.MCTL.R = 0x4000A50F;		    // Enter RUN0 Mode & Inverted Key
    while (MC_ME.GS.B.S_MTRANS) {};		    // Wait for mode transition to complete
    while(MC_ME.GS.B.S_CURRENT_MODE != 4) {};	    // Verify RUN0 is the current mode

    // Set PLL1 to 200 MHz with 40MHz XOSC reference
    PLLDIG.PLL1DV.R = 0x00020014;	     // MFD = 20, RFDPHI = 2

    MC_ME.RUN_PC[0].R = 0x000000FE;		    // enable peripherals run in all modes
    MC_ME.RUN0_MC.R = 0x001300F4;		    // RUN0 cfg: IRCON, OSC0ON, PLL1ON, syclk=PLL1

    MC_CGM.SC_DC0.R = 0x80030000;    // PBRIDGE0/PBRIDGE1_CLK at syst clk div by 4 ... (50 MHz)

    // Mode Transition to enter RUN0 mode:
    MC_ME.MCTL.R = 0x40005AF0;		    // Enter RUN0 Mode & Key
    MC_ME.MCTL.R = 0x4000A50F;		    // Enter RUN0 Mode & Inverted Key
    while (MC_ME.GS.B.S_MTRANS) {};		    // Wait for mode transition to complete
    while(MC_ME.GS.B.S_CURRENT_MODE != 4) {};	    // Verify RUN0 is the current mode



    //初始化外设时钟
    // MC_CGM.SC_DC0.R = 0x80030000;    // PBRIDGE0/PBRIDGE1_CLK at syst clk div by 4 ... (50 MHz)
    MC_CGM.AC0_SC.R = 0x02000000;    // Select PLL0 for auxiliary clock 0
    MC_CGM.AC0_DC0.R = 0x80010000;    // MOTC_CLK : Enable aux clk 0 div by 2 锟� (25 MHz)
    MC_CGM.AC0_DC1.R = 0x80070000;    // SGEN_CLK : Enable aux clk 0 div by 8 锟� (6.25 MHz)
    MC_CGM.AC0_DC2.R = 0x80010000;    // ADC_CLK : Enable aux clk 0 div by 2 锟� (25 MHz)
    MC_CGM.AC6_SC.R = 0x04000000;    // Select PLL1 for auxiliary clock 6
    MC_CGM.AC6_DC0.R = 0x80010000;    // CLKOUT0 : Enable aux clk 6 div by 2 锟� (100 MHz)
    MC_CGM.AC10_SC.R = 0x04000000;    // Select PLL1 for auxiliary clock 10
    MC_CGM.AC10_DC0.R = 0x80030000;    // ENET_CLK : Enable aux clk 10 div by 4 锟� (50 MHz)
    MC_CGM.AC11_SC.R = 0x04000000;    // Select PLL1 for auxiliary clock 11
    MC_CGM.AC11_DC0.R = 0x80030000;    // ENET_TIME_CLK : Enable aux clk 11 div by 4 锟� (50 MHz)
    MC_CGM.AC5_SC.R = 0x02000000;    // Select PLL0 for auxiliary clock 5
    MC_CGM.AC5_DC0.R = 0x80000000;    // LFAST_CLK : Enable aux clk 5 div by 1 锟� (50 MHz)
    MC_CGM.AC2_DC0.R = 0x80010000;    // CAN_PLL_CLK : Enable aux clk 2 (PLL0) div by 2 锟� (25 MHz)
    MC_CGM.AC1_DC0.R = 0x80010000;    // FRAY_PLL_CLK : Enable aux clk 1 (PLL0) div by 2 锟� (25 MHz)
    MC_CGM.AC1_DC1.R = 0x80010000;    // SENT_CLK : Enable aux clk 1 (PLL0) div by 2 锟� (25 MHz)

}


/*
*********************************************************************************************************
*                                           BSP_ClkEnable()
*
* Description : Enables a specific peripheral clock.
*
* Argument(s) : clk_id    Clock identifier
*
* Return(s)   : none
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_ClkEnable (BSP_CLK_ID  clk_id)
{
//    MC_ME.PCTL[clk_id].B.RUN_CFG = 0u;
//    MC_ME.PCTL99.B
//    BSP_ClkModeTransition_DRUN();                               /* Apply the new configuration.                         */
}


/*
*********************************************************************************************************
*                                          BSP_ClkDisable()
*
* Description : Disables a specific peripheral clock.
*
* Argument(s) : clk_id    Clock identifier
*
* Return(s)   : none
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_ClkDisable (BSP_CLK_ID  clk_id)
{
//    MC_ME.PCTL[clk_id].B.RUN_CFG = 1u;
//
//    BSP_ClkModeTransition_DRUN();                               /* Apply the new configuration.                         */
}


/*
*********************************************************************************************************
*********************************************************************************************************
*                                            EXTENDED API
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                     BSP_ClkModeTransition_DRUN()
*
* Description : Perform a mode transition to DRUN.
*               This applies the latest DRUN configuration to the peripherals.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Note(s)     : None.
*********************************************************************************************************
*/

void  BSP_ClkModeTransition_DRUN (void)
{
//    MC_ME.MCTL.R = BSP_MCTL_DRUN | BSP_MCTL_KEY;
//    MC_ME.MCTL.R = BSP_MCTL_DRUN | BSP_MCTL_INV_KEY;
//    while (MC_ME.GS.B.S_MTRANS == 1u) {
//        CPU_NOP();
//    }
}


/*
*********************************************************************************************************
*                                      EXTERNAL TIMESTAMP TIMER
*********************************************************************************************************
*/

#ifdef  CLK_MODULE_PRESENT


/*
*********************************************************************************************************
*                                          Clk_ExtTS_Init()
*
* Description : Initialize & start External timestamp timer.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : Clk_Init().
*
*               This function is an INTERNAL Clock module function & MUST be implemented by application/
*               BSP function(s) [see Note #1] but MUST NOT be called by application function(s).
*
* Note(s)     : (1) CLK_ExtTS_Init() is an application/BSP function that MUST be defined by the developer
*                   if External timestamp is enabled.
*
*                   See 'clk_cfg.h  CLK CONFIGURATION  Note #1'.
*
*               (2) (a) External timestamp values MUST be returned via 'CLK_TS_SEC' data type.
*
*                   (b) External timestamp values SHOULD be returned on the epoch of Clock module and
*                       include the time zone offset.
*
*               (3) (a) External timestamp SHOULD be an 'up' counter whose values increase at each second.
*                       It's possible to use a 'down' counter, but a conversion MUST be applied when setting
*                       and getting timestamp.
*
*                   (b) External timestamp COULD come from another application (e.g. by SNTPc).
*********************************************************************************************************
*/

#if (CLK_CFG_EXT_EN == DEF_ENABLED)
void  Clk_ExtTS_Init (void)
{

}
#endif


/*
*********************************************************************************************************
*                                           Clk_ExtTS_Get()
*
* Description : Get Clock module's timestamp from converted External timestamp.
*
* Argument(s) : none.
*
* Return(s)   : Current Clock timestamp (in seconds, UTC+00).
*
* Caller(s)   : Clk_GetTS().
*
*               This function is an INTERNAL Clock module function & MUST be implemented by application/
*               BSP function(s) [see Note #1] but SHOULD NOT be called by application function(s).
*
* Note(s)     : (1) Clk_ExtTS_Get() is an application/BSP function that MUST be defined by the developer
*                   if External timestamp is enabled.
*
*                   See 'clk_cfg.h  CLK CONFIGURATION  Note #1'
*
*
*               (2) (a) Clock timestamp values MUST be returned via 'CLK_TS_SEC' data type.
*
*                   (b) (1) If the External timestamp has more bits than the 'CLK_TS_SEC' data type,
*                           Clk_ExtTS_Get() MUST truncate the External timestamp's higher order bits
*                           greater than the 'CLK_TS_SEC' data type.
*
*                       (2) If the External timestamp has less bits than the 'CLK_TS_SEC' data type,
*                           Clk_ExtTS_Get() MUST pad the Clock timestamp's higher order bits with
*                           0 bits.
*
*
*               (3) (a) External timestamp values MUST be returned from the reference of the Clock
*                       epoch start date/time.
*
*                   (b) External timestamp SHOULD start on midnight of January 1st of its epoch start
*                       year. Otherwise, the equations to convert between External timestamp & Clock
*                       timestamp MUST also include the External timestamp's epoch Day-of-Year, Hour,
*                       Minute, & Second (see Note #4).
*
*                   (c) Returned Clock timestamp MUST be representable in Clock epoch. Thus equivalent
*                       date of the External timestamp MUST be between :
*
*                       (1) >= CLK_EPOCH_YR_START
*                       (2) <  CLK_EPOCH_YR_END
*
*                   (d) If the External timestamp includes an (optional) external time zone,
*                       Clk_ExtTS_Get() MUST subtract the external time zone offset from the
*                       converted External timestamp.
*
*
*               (4) The Clock timestamp is calculated by one of the following equations (assuming
*                   Note #3b) :
*
*                   (a) When External epoch start year is less than Clock epoch start year
*                       ('CLK_EPOCH_YR_START') :
*
*                       Clock TS = External TS
*                                - [(((Clock start year - External start year) * 365) + leap day count)
*                                    * seconds per day]
*                                - External TZ
*
*                       Examples with a 32-bit External timestamp :
*
*                       (1)   Valid equivalent date to convert is after  Clock epoch start year :
*
*                             2010 Oct 8, 11:11:11 UTC-05:00
*                           External TS (in seconds)                                 = 1286536271
*                           External start year                                      =       1970
*                           Clock    start year                                      =       2000
*                           Leap day count between External & Clock epoch start year =          7
*                           External TZ (in seconds)                                 =     -18000
*                           Clock    TS (in seconds)                                 =  339869471
*                             2010 Oct 8, 16:11:11 UTC
*
*                           This example successfully converts an External timestamp into a
*                           representable Clock timestamp without underflowing.
*
*                       (2) Invalid equivalent date to convert is before Clock epoch start year :
*
*                             1984 Oct 8, 11:11:11 UTC-05:00
*                           External TS (in seconds)                                 =  466081871
*                           External start year                                      =       1970
*                           Clock    start year                                      =       2000
*                           Leap day count between External & Clock epoch start year =          7
*                           External TZ (in seconds)                                 =     -18000
*                           Clock    TS (in seconds)                                 = -480584929
*
*                           This example underflows to a negative Clock timestamp since the
*                           equivalent date to convert is incorrectly less than the Clock epoch
*                           start year ('CLK_EPOCH_YR_START').
*
*
*                   (b) When External epoch start year is greater than Clock epoch start year
*                       ('CLK_EPOCH_YR_START') :
*
*                       Clock TS = External TS
*                                + [(((External start year - Clock start year) * 365) + leap day count)
*                                    * seconds per day]
*                                - External TZ
*
*
*                       Examples with a 32-bit External timestamp :
*
*                       (1)   Valid equivalent date to convert is before Clock epoch end year :
*
*                             2010 Oct 8, 11:11:11 UTC-05:00
*                           External TS (in seconds)                                 =   24232271
*                           External start year                                      =       2010
*                           Clock    end   year                                      =       2136
*                           Leap day count between External & Clock epoch start year =          3
*                           External TZ (in seconds)                                 =     -18000
*                           Clock    TS (in seconds)                                 =  339869471
*                             2010 Oct 8, 16:11:11 UTC-05:00
*
*                           This example successfully converts an External timestamp into a
*                           representable Clock timestamp without overflowing.
*
*                       (2) Invalid equivalent date to convert is after  Clock epoch end year :
*
*                             2140 Oct 8, 11:11:11 UTC-05:00
*                           External TS (in seconds)                                 = 4126677071
*                           External start year                                      =       2010
*                           Clock    end   year                                      =       2136
*                           Leap day count between External & Clock epoch start year =          3
*                           External TZ (in seconds)                                 =     -18000
*                           Clock    TS (in seconds)                                 = 4442314271
*
*                           This example overflows the Clock timestamp (32-bit) 'CLK_TS_SEC' data
*                           type with an equivalent date incorrectly greater than or equal to the
*                           Clock epoch end year ('CLK_EPOCH_YR_END').
*
*
*                   (c) Where
*
*                       (1) Clock    TS             Converted Clock timestamp (in seconds,
*                                                       from UTC+00)
*                       (2) External TS             External timestamp to convert (in seconds)
*                       (3) Clock    start year     Clock epoch start year ('CLK_EPOCH_YR_START')
*                       (4) Clock    end   year     Clock epoch end   year ('CLK_EPOCH_YR_END')
*                       (5) External start year     External timestamp epoch start year
*                       (6) Leap day count          Number of leap days between Clock epoch
*                                                       start year & External epoch start year
*                       (7) Seconds per day         Number of seconds per day (86400)
*                       (8) External TZ             Time zone offset applied to External TS
*                                                       (in seconds, from UTC+00)
*********************************************************************************************************
*/

#if (CLK_CFG_EXT_EN == DEF_ENABLED)
CLK_TS_SEC  Clk_ExtTS_Get (void)
{
    return (0u);
}
#endif


/*
*********************************************************************************************************
*                                           Clk_ExtTS_Set()
*
* Description : Set External timestamp.
*
* Argument(s) : ts_sec      Timestamp value to set (in seconds, UTC+00).
*
* Return(s)   : DEF_OK,     if External timestamp succesfully set.
*
*               DEF_FAIL,   otherwise.
*
* Caller(s)   : Clk_SetTS().
*
*               This function is an INTERNAL Clock module function & MUST be implemented by application/
*               BSP function(s) [see Note #1] but SHOULD NOT be called by application function(s).
*
* Note(s)     : (1) CLK_ExtTS_Set() is an application/BSP function that MUST be defined by the developer
*                   if External timestamp is enabled.
*
*                       See 'clk_cfg.h  CLK CONFIGURATION  Note #1'.
*
*                   (a) If External timestamp is provided by another application, it's possible that the
*                       External timestamp may NOT be set (e.g. by SNTPc) in which case CLK_ExtTS_Set()
*                       MUST ALWAYS return 'DEF_FAIL'.
*
*
*               (2) (a) External timestamp values are converted from Clock timestamp's 'CLK_TS_SEC'
*                       data type.
*
*                   (b) (1) If the External timestamp has more bits than the 'CLK_TS_SEC' data type,
*                           Clk_ExtTS_Set() MUST pad the External timestamp's higher order bits with
*                           0 bits.
*
*                       (2) If the External timestamp has less bits than the 'CLK_TS_SEC' data type,
*                           Clk_ExtTS_Set() MUST truncate the Clock timestamp's higher order bits
*                           greater than the External timestamp.
*
*
*               (3) (a) External timestamp values MUST be converted from the reference of the Clock
*                       epoch start date/time.
*
*                   (b) External timestamp SHOULD start on midnight of January 1st of its epoch start
*                       year. Otherwise, the equations to convert between External timestamp & Clock
*                       timestamp MUST also include the External timestamp's epoch Day-of-Year, Hour,
*                       Minute, & Second (see Note #4).
*
*                   (c) Converted External timestamp MUST be representable in External epoch. Thus
*                       equivalent date of the External timestamp MUST be between :
*
*                       (1) External epoch start year
*                       (2) External epoch end   year
*
*                   (d) If the External timestamp includes an (optional) external time zone,
*                       Clk_ExtTS_Set() MUST add the external time zone offset to the converted
*                       External timestamp.
*
*
*               (4) The External timestamp is calculated by one of the following equations (assuming
*                   Note #3b) :
*
*                   (a) When External epoch start year is less than Clock epoch start year
*                       ('CLK_EPOCH_YR_START') :
*
*                       External TS = Clock TS
*                                   + [(((Clock start year - External start year) * 365) + leap day count)
*                                       * seconds per day]
*                                   + External TZ
*
*                       Examples with a 32-bit External timestamp :
*
*                       (1)   Valid equivalent date to convert is before External epoch end year :
*
*                             2010 Oct 8, 16:11:11 UTC
*                           Clock    TS (in seconds)                                 =  339869471
*                           External start year                                      =       1970
*                           External end   year                                      =       2106
*                           Leap day count between External & Clock epoch start year =          7
*                           External TZ (in seconds)                                 =     -18000
*                           External TS (in seconds)                                 = 1286536271
*                             2010 Oct 8, 11:11:11 UTC-05:00
*
*                           This example successfully converts an External timestamp into a
*                           representable Clock timestamp without overflowing.
*
*                       (2) Invalid equivalent date to convert is after  External epoch end year :
*
*                             2120 Oct 8, 11:11:11 UTC
*                           Clock    TS (in seconds)                                 = 3811144271
*                           External start year                                      =       1970
*                           External end   year                                      =       2106
*                           Leap day count between External & Clock epoch start year =          7
*                           External TZ (in seconds)                                 =     -18000
*                           External TS (in seconds)                                 = 4757811071
*
*                           This example overflows the External (32-bit) timestamp with an equivalent
*                           date incorrectly greater than or equal to the External epoch end year.
*
*
*                   (b) When External epoch start year is greater than Clock epoch start year
*                       ('CLK_EPOCH_YR_START') :
*
*                       External TS = Clock TS
*                                   - [(((External start year - Clock start year) * 365) + leap day count)
*                                       * seconds per day]
*                                   + External TZ
*
*
*                       Examples with a 32-bit External timestamp :
*
*                       (1)   Valid equivalent date to convert is after  External epoch start year :
*
*                             2010 Oct 8, 16:11:11 UTC
*                           Clock    TS (in seconds)                                 =  339869471
*                           External start year                                      =       2010
*                           Leap day count between External & Clock epoch start year =          3
*                           External TZ (in seconds)                                 =     -18000
*                           External TS (in seconds)                                 =   24232271
*                             2010 Oct 8, 11:11:11 UTC-05:00
*
*                           This example successfully converts an External timestamp into a
*                           representable Clock timestamp without underflowing.
*
*                       (2) Invalid equivalent date to convert is before External epoch start year :
*
*                             2005 Oct 8, 11:11:11 UTC
*                           Clock    TS (in seconds)                                 =  182085071
*                           External start year                                      =       2010
*                           Leap day count between External & Clock epoch start year =          3
*                           External TZ (in seconds)                                 =     -18000
*                           External TS (in seconds)                                 = -133552129
*
*                           This example underflows to a negative External timestamp since the
*                           equivalent date to convert is incorrectly less than the External
*                           epoch start year.
*
*
*                   (c) where
*
*                       (1) Clock    TS             Clock timestamp (in seconds, from UTC+00)
*                       (2) External TS             Converted External timestamp (in seconds)
*                       (3) Clock    start year     Clock epoch start year ('CLK_EPOCH_YR_START')
*                       (4) External start year     External timestamp epoch start year
*                       (5) External end   year     External timestamp epoch end   year
*                       (6) Leap day count          Number of leap days between Clock epoch
*                                                       start year & External epoch start year
*                       (7) Seconds per day         Number of seconds per day (86400)
*                       (8) External TZ             Time zone offset applied to External TS
*                                                       (in seconds, from UTC+00)
*********************************************************************************************************
*/

#if (CLK_CFG_EXT_EN == DEF_ENABLED)
CPU_BOOLEAN  Clk_ExtTS_Set (CLK_TS_SEC  ts_sec)
{
    return (DEF_FAIL);
}
#endif


/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of uC/Clk module include.       */

