/**
 * @file main.c
 * @author Cord Harms, Timo Hinrichs
 * @date Oct 2026
 * @brief Der Superloop des Taschenrechner
 */

#include "display.h"
#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "tokenhandler.h"
#include "scanner.h"
#include "stack.h"
#include "stm32f4xx_hal.h"

int main(void)
{
   // Initialisierungen
   initITSboard();
   GUI_init(DEFAULT_BRIGHTNESS);
   TP_Init(false);
   init_display();
   init_stack();
   const int POLL_DELAY = 67;

   // Hauptschleife
   while (1)
   {
      T_token token = next_token();
      process_token(token);
      HAL_Delay(POLL_DELAY);
   }
}

// EOF
