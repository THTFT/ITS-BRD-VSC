/**
 ******************************************************************************
 * @file    main.c
 * @author  Coco
 * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
 ******************************************************************************
 */

 #include "angle.h"
 #include "lcd.h"
#include <complex.h>
 #include <stdio.h>

 /*
Winkel                : XX.X     Grad
Winkelgeschwindigkeit : XX.X     Grad/s
*/
#define CHANGING_SYMBOLS 6
#define Y_OFFSET_ANGEL 5
#define Y_OFFSET_ANGEL_VELOCITY 10
#define X_OFFSET 24
#define TWO_DIGIT 10
#define TEXT_ANGEL "Winkel                : VXXX.X     Grad"
#define TEXT_ANGEL_VELOCITY "Winkelgeschwindigkeit : VXXX.X     Grad/s"
char string_new[CHANGING_SYMBOLS + 1] = "VXXX.X";
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

void array_shift_left() {
    for (int i = 0; i < CHANGING_SYMBOLS; ++i) {
        string_new[i] = string_new[i+1];
    }
}

void array_shift_right() {
    for (int i = CHANGING_SYMBOLS-1; i > 0; --i) {
        string_new[i] = string_new[i-1];
    }
}

char align_sign() {
    char sign = ' ';
    if (string_new[0] == '-') {
        sign = '-';
        string_new[0] = '0';
        array_shift_left();
    }
    return sign;
}

int count_shifts() {
    int counter = 0;
    for (int i = (CHANGING_SYMBOLS-1); i >= 0; --i) {
        if (string_new[i] == '.') {
            break;
        }
        counter++;
    }
    return counter-1;
}

void array_align() {
    char sign = ' ';
    int shift_counter = 0;

    // align sign
    sign = align_sign();

    // count shifts
    shift_counter = count_shifts();

    // shift array
    while (shift_counter > 0) {
        array_shift_right();
        --shift_counter;
    }

    string_new[0] = sign;
}

void update_display() {
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

void init_string_new() {
    for (int i = 0; i < CHANGING_SYMBOLS; ++i) {
        string_new[i] = 0;
    }
}

void update_display_fsm() {
    array_copy();
    double angle = get_angle();
    init_string_new();
    snprintf(string_new, CHANGING_SYMBOLS, "%.1f", angle);
    array_align();
    update_display();
}
