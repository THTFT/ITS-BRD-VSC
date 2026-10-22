/**
 * @file main.c
 * @author Cord Harms, Timo Hinrichs
 * @date Oct 2026
 * @brief ???
 */


#include "lcd.h"
#include "display.h"
#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "tokenhandler.h"
#include "scanner.h"
#include "stack.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>

int main(void)
{
   // Initialisierungen
   initITSboard();                         // Initialisierung des ITS Boards
   GUI_init(DEFAULT_BRIGHTNESS);    // Initialisierung des LCD Boards mit Touch
   TP_Init(false);                        // Initialisierung des LCD Boards mit Touch
   init_display();                        // Initialisierung des Displays
   init_stack();
   const int POLL_DELAY = 10000;

   // Hauptschleife
   while (1)
   {
      // testwerk();
      T_token token = next_token();
      process_token(token);
      HAL_Delay(POLL_DELAY);
   }
}

// EOF
