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
#include "angle.h"
#include "display_fsm.h"
#include "fsm.h"
#include "gpio.h"
#include "init.h"
#include "timer.h"
#include "timer_fsm.h"

#define BSRR_MASK_CLEAR_8 (1 << 16)
static void init() {
   initTimer();
   init_timer_fsm();
   init_display_fsm();
   init_fsm();
   init_angle();
}

int main(void) {

   // Initialisierungen
   initITSboard();               // Initialisierung des ITS Boards
   GUI_init(DEFAULT_BRIGHTNESS); // Initialisierung des LCD Boards mit Touch
   TP_Init(false);               // Initialisierung des LCD Boards mit Touch
   init();

   // SUPERLOOP
   // const int POLL_DELAY = 1000;
   while (1) {
      
      uint16_t idr2 = GPIOE->IDR;
      int result= idr2 & 0x1;
      if(result != 1) {
         GPIOE->BSRR = 1;
      }
      else {
         GPIOE->BSRR = BSRR_MASK_CLEAR_8;
      }

      // Eingabe - einlesen der Sensoren
      if (read_s6()) {
         init();
         clear_leds();
      }
      if (get_event() == STATE_ERROR) {
         set_led_error();
         continue;
      }
      read_sensors();

      // Update des Zustandes
      update_timer();
      update_state();

      // Berechnung der neuen Werte fuer die Aktoren
      calc_values();
      update();

      // Ausgabe - treiben der Aktoren
      update_display_fsm();
      set_leds();
      
      // GPIOE->ODR = 0;
   }
}
// 76,5 mikro
//  EOF
