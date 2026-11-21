/**
 ******************************************************************************
 * @file    main.c
 * @author  Franz Korf
 * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/

#include "angle.h"
#include "display_fsm.h"
#include "fsm.h"
#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "timer.h"
#include "timer_fsm.h"

int main(void) {

   // Initialisierungen
   initITSboard(); // Initialisierung des ITS Boards
   GUI_init(DEFAULT_BRIGHTNESS); // Initialisierung des LCD Boards mit Touch
   TP_Init(false); // Initialisierung des LCD Boards mit Touch
   initTimer();
   init_display_fsm();
   init_fsm();
   init_angle();

   // SUPERLOOP
   // const int POLL_DELAY = 1000;
   while (1) {
      update_timer();
      update_state();
      update();
      update_display_fsm();

      // HAL_Delay(POLL_DELAY);
   }
}

// EOF
