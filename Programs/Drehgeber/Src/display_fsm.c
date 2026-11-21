/**
 ******************************************************************************
 * @file    main.c
 * @author  Coco
 * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
 ******************************************************************************
 */

 #include "angle.h"
 #include "lcd.h"
 #include <stdio.h>

 /*
Winkel                : XX.X     Grad
Winkelgeschwindigkeit : XX.X     Grad/s
*/
#define CHANGING_SYMBOLS 5
#define Y_OFFSET_ANGEL 5
#define Y_OFFSET_ANGEL_VELOCITY 10
#define X_OFFSET 24
#define TWO_DIGIT 10
#define TEXT_ANGEL "Winkel                : XXX.X     Grad"
#define TEXT_ANGEL_VELOCITY "Winkelgeschwindigkeit : XXX.X     Grad/s"
char string_new[CHANGING_SYMBOLS + 1] = "XXX.X";
char string_old[CHANGING_SYMBOLS + 1];


void init_display_fsm() {
    lcdGotoXY(0,Y_OFFSET_ANGEL);
    lcdPrintS(TEXT_ANGEL);
    lcdGotoXY(0,Y_OFFSET_ANGEL_VELOCITY);
    lcdPrintS(TEXT_ANGEL_VELOCITY);
}

void array_copy() {
    for(int i = 0; i < CHANGING_SYMBOLS; ++i) {
        string_old[i] = string_new[i];
    }
}

void array_align() {
    for(int i = (CHANGING_SYMBOLS - 1); i > 0; --i) {
        string_new[i] = string_new[i-1];
    }
}

void update_display_fsm() {
    array_copy();
    double angle = get_angle();
    snprintf(string_new, CHANGING_SYMBOLS, "%.1f", angle);
    if (angle < TWO_DIGIT) {
        array_align();
    }
    for (int i = 0; i < CHANGING_SYMBOLS; ++i) {
        if(string_new[i] != string_old[i])
        {
           lcdGotoXY(X_OFFSET + i, Y_OFFSET_ANGEL);
           lcdPrintC(string_new[i]);
        }
    }
    for (int i = 0; i < CHANGING_SYMBOLS; ++i) {
        if(string_new[i] != string_old[i])
        {
           lcdGotoXY(X_OFFSET + i, Y_OFFSET_ANGEL_VELOCITY);
           lcdPrintC(string_new[i]);
        }
    }
}




