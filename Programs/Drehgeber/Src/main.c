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
#include "gpio.h"
#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "timer.h"
#include "timer_fsm.h"

static void init() {
   initTimer();
   init_timer_fsm();
   init_display_fsm();
   init_fsm();
   init_angle();

}

int main(void) {

   // Initialisierungen
   initITSboard(); // Initialisierung des ITS Boards
   GUI_init(DEFAULT_BRIGHTNESS); // Initialisierung des LCD Boards mit Touch
   TP_Init(false); // Initialisierung des LCD Boards mit Touch
   init();

   // SUPERLOOP
   // const int POLL_DELAY = 1000;
   while (1) {
      
      if(read_s6()) {
         init();
         clear_leds();
      }
      if (get_event() == STATE_ERROR) {
         set_led_error();
         continue;
      }
      update_timer();
      update_state();
      update();
      update_display_fsm();
      set_leds();
      
   }
}
//29 mikro
// EOF
