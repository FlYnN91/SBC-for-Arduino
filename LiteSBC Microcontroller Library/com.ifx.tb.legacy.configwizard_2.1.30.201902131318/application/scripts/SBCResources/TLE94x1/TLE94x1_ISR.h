/*********************************************************************************************************************
 * Copyright (c) 2019, Infineon Technologies AG
 *
 * 
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * 
 *********************************************************************************************************************/


/****************************************************************************************************//**
 * @file        TLE94x1_ISR.h
 *
 * @brief       Declaration file for ISR-Vectors and ISR related functions
 * 
 * @version     V1.0.0
 * @date        15. April 2019
 * @author      Markus Noll / markus.noll@infineon.com
 * @author      Yannek Micha Rixen / Yannek.Rixen@infineon.com
 *******************************************************************************************************/




#ifndef TLE94x1_ISR_H
#define TLE94x1_ISR_H







/* ================================================================================ */
/* ============================   HEADER FILES   ================================== */
/* ================================================================================ */ 

#include "TLE94x1_DEFINES.h"








/* ================================================================================ */
/* ================================   MACROS   ==================================== */
/* ================================================================================ */ 


/**
 * @def     SBC_ISR_VECTOR
 *
 * @brief   Vector defining the handling of interrupts.
 * 
 *          Vectors of this type have to be registered by the SBC_Register_Callback method.
 */
#define SBC_ISR_VECTOR(REG,MASK,POS,COMPARE)    ((((uint32_t)REG) << 24) | (((uint32_t)MASK) << 16) | (((uint32_t)POS) << 8) | ((uint32_t)COMPARE))






/* ================================================================================ */
/* =======================   General Interrupt Defines   ========================== */
/* ================================================================================ */ 



/* Interrupts based on WK_STAT_0 and WK_STAT_1 register are always available */
#define SBC_ISR_CAN_WU                          SBC_ISR_VECTOR(SBC_WK_STAT_0,       SBC_WK_STAT_0_CAN_WU_Msk,       SBC_WK_STAT_0_CAN_WU_Pos,       SBC_CAN_WU_EVENT)
#define SBC_ISR_TIMER_WU                        SBC_ISR_VECTOR(SBC_WK_STAT_0,       SBC_WK_STAT_0_TIMER_WU_Msk,     SBC_WK_STAT_0_TIMER_WU_Pos,     SBC_TIMER_WU_EVENT)
#define SBC_ISR_WK_WU                           SBC_ISR_VECTOR(SBC_WK_STAT_0,       SBC_WK_STAT_0_WK_WU_Msk,        SBC_WK_STAT_0_WK_WU_Pos,        SBC_WK_WU_EVENT)
#define SBC_ISR_GPIO_WK_WU                      SBC_ISR_VECTOR(SBC_WK_STAT_1,       SBC_WK_STAT_1_GPIO_WK_WU_Msk,   SBC_WK_STAT_1_GPIO_WK_WU_Pos,   SBC_GPIO_WK_WU_EVENT)


/* Following interrupts only usable if INT_GLOBAL bit is set to '1' */
#define SBC_ISR_VS_UV                           SBC_ISR_VECTOR(SBC_SUP_STAT_1,      SBC_SUP_STAT_1_VS_UV_Msk,       SBC_SUP_STAT_1_VS_UV_Pos,       SBC_VS_UV_EVENT)
#define SBC_ISR_VS_OV                           SBC_ISR_VECTOR(SBC_SUP_STAT_1,      SBC_SUP_STAT_1_VS_OV_Msk,       SBC_SUP_STAT_1_VS_OV_Pos,       SBC_VS_OV_EVENT)
#define SBC_ISR_VCC1_OV                         SBC_ISR_VECTOR(SBC_SUP_STAT_1,      SBC_SUP_STAT_1_VCC1_OV_Msk,     SBC_SUP_STAT_1_VCC1_OV_Pos,     SBC_VCC1_OV_EVENT)
#define SBC_ISR_VCC1_UV_PREWARN                 SBC_ISR_VECTOR(SBC_SUP_STAT_1,      SBC_SUP_STAT_1_VCC1_WARN_Msk,   SBC_SUP_STAT_1_VCC1_WARN_Pos,   SBC_VCC1_UV_PREWARN_EVENT)
#define SBC_ISR_VCC2_OT                         SBC_ISR_VECTOR(SBC_SUP_STAT_0,      SBC_SUP_STAT_0_VCC2_OT_Msk,     SBC_SUP_STAT_0_VCC2_OT_Pos,     SBC_VCC2_OT_EVENT)
#define SBC_ISR_VCC2_UV                         SBC_ISR_VECTOR(SBC_SUP_STAT_0,      SBC_SUP_STAT_0_VCC2_UV_Msk,     SBC_SUP_STAT_0_VCC2_UV_Pos,     SBC_VCC2_UV_EVENT)
#define SBC_ISR_VCC1_UV                         SBC_ISR_VECTOR(SBC_SUP_STAT_0,      SBC_SUP_STAT_0_VCC1_UV_Msk,     SBC_SUP_STAT_0_VCC1_UV_Pos,     SBC_VCC1_UV_EVENT)
#define SBC_ISR_TSD2_SAFESTATE                  SBC_ISR_VECTOR(SBC_THERM_STAT,      SBC_THERM_STAT_TSD2_SAFE_Msk,   SBC_THERM_STAT_TSD2_SAFE_Pos,   SBC_TSD2_SAFE_SAFESTATE_DETECTED)
#define SBC_ISR_TSD1                            SBC_ISR_VECTOR(SBC_THERM_STAT,      SBC_THERM_STAT_TSD1_Msk,        SBC_THERM_STAT_TSD1_Pos,        SBC_TSD1_EVENT)
#define SBC_ISR_TPW                             SBC_ISR_VECTOR(SBC_THERM_STAT,      SBC_THERM_STAT_TPW_Msk,         SBC_THERM_STAT_TPW_Pos,         SBC_TPW_EVENT)
#define SBC_ISR_RESTART_AFTER_FAIL              SBC_ISR_VECTOR(SBC_DEV_STAT,        SBC_DEV_STAT_DEV_STAT_Msk,      SBC_DEV_STAT_DEV_STAT_Pos,      SBC_DEV_STAT_RESTART_AFTER_FAIL)
#define SBC_ISR_FROM_SLEEPMODE                  SBC_ISR_VECTOR(SBC_DEV_STAT,        SBC_DEV_STAT_DEV_STAT_Msk,      SBC_DEV_STAT_DEV_STAT_Pos,      SBC_DEV_STAT_SLEEP_MODE)
#define SBC_ISR_WD_FAIL_1                       SBC_ISR_VECTOR(SBC_DEV_STAT,        SBC_DEV_STAT_WD_FAIL_Msk,       SBC_DEV_STAT_WD_FAIL_Pos,       SBC_WD_FAIL_1FAIL)
#define SBC_ISR_WD_FAIL_2                       SBC_ISR_VECTOR(SBC_DEV_STAT,        SBC_DEV_STAT_WD_FAIL_Msk,       SBC_DEV_STAT_WD_FAIL_Pos,       SBC_WD_FAIL_2FAIL)
#define SBC_ISR_FAILURE                         SBC_ISR_VECTOR(SBC_DEV_STAT,        SBC_DEV_STAT_FAILURE_Msk,       SBC_DEV_STAT_FAILURE_Pos,       SBC_FAILURE_EVENT)
#define SBC_ISR_CAN_TSD                         SBC_ISR_VECTOR(SBC_BUS_STAT,        SBC_BUS_STAT_CAN_FAIL_Msk,      SBC_BUS_STAT_CAN_FAIL_Pos,      SBC_CAN_FAIL_TSD)
#define SBC_ISR_CAN_TXD_DOM_TO                  SBC_ISR_VECTOR(SBC_BUS_STAT,        SBC_BUS_STAT_CAN_FAIL_Msk,      SBC_BUS_STAT_CAN_FAIL_Pos,      SBC_CAN_FAIL_TXD_DOM_TO)
#define SBC_ISR_CAN_BUS_DOM_TO                  SBC_ISR_VECTOR(SBC_BUS_STAT,        SBC_BUS_STAT_CAN_FAIL_Msk,      SBC_BUS_STAT_CAN_FAIL_Pos,      SBC_CAN_FAIL_BUS_DOM_TO)
#define SBC_ISR_VCAN_UV                         SBC_ISR_VECTOR(SBC_BUS_STAT,        SBC_BUS_STAT_VCAN_UV_Msk,       SBC_BUS_STAT_VCAN_UV_Pos,       SBC_VCAN_UV_EVENT)
#define SBC_ISR_GPIO_OC                         SBC_ISR_VECTOR(SBC_GPIO_OC_STAT,    SBC_GPIO_OC_STAT_GPIO_OC_Msk,   SBC_GPIO_OC_STAT_GPIO_OC_Pos,   SBC_GPIO_OC_EVENT)
#define SBC_ISR_GPIO_OL                         SBC_ISR_VECTOR(SBC_GPIO_OL_STAT,    SBC_GPIO_OL_STAT_GPIO_OL_Msk,   SBC_GPIO_OL_STAT_GPIO_OL_Pos,   SBC_GPIO_OL_EVENT)


#endif  /*TLE94x1_ISR_H*/
