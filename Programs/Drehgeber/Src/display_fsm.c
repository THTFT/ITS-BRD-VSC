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
#define CHANGING_SYMBOLS 7
#define Y_OFFSET_ANGEL 5
#define Y_OFFSET_ANGEL_VELOCITY 10
#define X_OFFSET 24
#define TWO_DIGIT 10
#define TEXT_ANGEL "Winkel                :  0000.0     Grad"
#define TEXT_ANGEL_VELOCITY "Winkelgeschwindigkeit :  0000.0     Grad/s"

static char string_new_angle[CHANGING_SYMBOLS + 1] = " 0000.0";
static char string_old_angle[CHANGING_SYMBOLS + 1];
static char string_new_angle_velocity[CHANGING_SYMBOLS + 1] = " 0000.0";
static char string_old_angle_velocity[CHANGING_SYMBOLS + 1];

void init_display_fsm() {
   lcdGotoXY(0, Y_OFFSET_ANGEL);
   lcdPrintS(TEXT_ANGEL);
   lcdGotoXY(0, Y_OFFSET_ANGEL_VELOCITY);
   lcdPrintS(TEXT_ANGEL_VELOCITY);
}

static void array_copy(char *string_old, char *string_new) { // NOLINT
   for (int i = 0; i < CHANGING_SYMBOLS; ++i) {
      string_old[i] = string_new[i];
   }
}

static void array_shift_left(char *string) {
   for (int i = 0; i < CHANGING_SYMBOLS; ++i) {
      string[i] = string[i + 1];
   }
}

static void array_shift_right(char *string) {
   for (int i = CHANGING_SYMBOLS - 1; i > 0; --i) {
      string[i] = string[i - 1];
   }
}

static char align_sign(char *string) {
   char sign = ' ';
   if (string[0] == '-') {
      sign = '-';
      // string[0] = '0';
      array_shift_left(string);
   }
   return sign;
}

// funktioniert nur mit arrays die so lang sind wie CHANING_SYMBOLS.
static int count_shifts(char *string) { // NOLINT
   int counter = 0;
   for (int i = (CHANGING_SYMBOLS - 1); i >= 0; --i) {
      if (string[i] == '.') {
         break;
      }
      counter++;
   }
   return counter - 1;
}

static void array_align(char *string) {
   char sign = ' ';
   int shift_counter = 0;

   // align sign
   sign = align_sign(string);

   // count shifts
   shift_counter = count_shifts(string);

   // shift array
   int count_doku = 0;
   while (shift_counter > 0) {
      array_shift_right(string);
      string[count_doku] = '0';
      --shift_counter;
      ++count_doku;
   }

   string[0] = sign;
}

static int update_display(char *string_old, char *string_new, // NOLINT
                           int y_offset) { // NOLINT
   for (int i = 0; i < CHANGING_SYMBOLS; ++i) {
      if (string_new[i] != string_old[i]) {
         lcdGotoXY(X_OFFSET + i, y_offset);
         lcdPrintC(string_new[i]);
         return 1;
      }
   }
   return 0;
}

static void init_string(char *string) {
   for (int i = 0; i < CHANGING_SYMBOLS; ++i) {
      string[i] = 0;
   }
}

// Die Auswertung ergaben eine Durchlaufzeit von: 30 mikros.
void update_display_fsm() {
//   GPIOE->ODR = 1;
   array_copy(string_old_angle, string_new_angle);
   array_copy(string_old_angle_velocity, string_new_angle_velocity);
   double angle = get_angle();
   double angle_velocity = get_angle_velocity();
   init_string(string_new_angle);
   init_string(string_new_angle_velocity);
   snprintf(string_new_angle, CHANGING_SYMBOLS + 1, "%.1f", angle);
   snprintf(string_new_angle_velocity, CHANGING_SYMBOLS + 1, "%.1f",
            angle_velocity);
   array_align(string_new_angle);
   array_align(string_new_angle_velocity);

   // nur alle 300ms ausführen
   int updated = update_display(string_old_angle, string_new_angle,
                  Y_OFFSET_ANGEL);
   // Wenn es eine Veränderung gegeben hat, hör auf.
   if (updated) {
      return;
   }
   update_display(string_old_angle_velocity, string_new_angle_velocity,
                  Y_OFFSET_ANGEL_VELOCITY);
//   GPIOE->ODR = 0;
}
