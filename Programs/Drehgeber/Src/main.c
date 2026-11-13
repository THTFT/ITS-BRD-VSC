/**
 ******************************************************************************
 * @file    main.c
 * @author  Franz Korf
 * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/

#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "init.h"
#include "lcd.h"
#include "stm32f429xx.h"
#include "stm32f4xx_hal.h"

int main(void) {

   // Initialisierungen
   initITSboard(); // Initialisierung des ITS Boards
   GUI_init(DEFAULT_BRIGHTNESS); // Initialisierung des LCD Boards mit Touch
   TP_Init(false); // Initialisierung des LCD Boards mit Touch
   init_fsm();

   // SUPERLOOP
   const int POLL_DELAY = 10000;
   while (1) {
      update_state();
      HAL_Delay(POLL_DELAY);
   }
}

// EOF
