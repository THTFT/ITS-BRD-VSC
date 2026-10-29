/**
 * @file stack.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oct 2026
 * @brief Header file of display module. */

#ifndef STACK_H
#define STACK_H
#include "stdbool.h"

/*
 ****************************************************************************************
 *  @brief    Diese Funktion initialisiert den Stack.
 *
 *  @source   https://www.delftstack.com/howto/c/how-to-convert-an-integer-to-a-string-in-c/
 
 *  @return   void
 ****************************************************************************************/
void init_stack();

/*
 ****************************************************************************************
 *  @brief     Diese Funktion legt eine Zahl auf dem Stack ab, falls genügend
 * Platz auf dem Stack vorhanden ist.
 *
 *  @return    Ein Fehlercode, falls es zu einem Fehler gekommen ist.
 ****************************************************************************************/
int push(int number);

/*
 ****************************************************************************************
 *  @brief     Diese Funktion liefert in einer angegebenen Variable den obersten
 * Wert des Stacks.
 *
 *  @return    Ein Fehlercode, falls es zu einem Fehler gekommen ist.
 ****************************************************************************************/
int pop(int *result);

/*
 ****************************************************************************************
 *  @brief     Diese Funktion liefert in zwei angegebenen Variable die beiden
 * obersten Werte des Stacks.
 *
 *  @return    Ein Fehlercode, falls es zu einem Fehler gekommen ist.
 ****************************************************************************************/
int pop_twice(int *result1, int *result2);

/*
 ****************************************************************************************
 *  @brief     Diese Funktion gibt zurück, ob der Stack leer ist.
 *
 *  @return    false: Es können noch Elemente auf dem Stack abgelegt werden.
 *             true: Der Stack ist leer.
 ****************************************************************************************/
bool is_empty();

/*
 ****************************************************************************************
 *  @brief     Diese Funktion gibt zurück, ob der Stack voll ist.
 *
 *  @return    false: Es können noch Elemente auf dem Stack abgelegt werden.
 *             true: Der Stack ist voll.
 ****************************************************************************************/
bool is_full();

/*
 ****************************************************************************************
 *  @brief     Diese Funktion gibt das oberste Element aus.
 *
 *  @return    Ein Fehlercode, falls es zu einem Fehler gekommen ist.
 ****************************************************************************************/
int print_top();

/*
 ****************************************************************************************
 *  @brief     Diese Funktion tauscht die obersten zwei Elemente vom Stack.
 *
 *  @return    Ein Fehlercode, falls es zu einem Fehler gekommen ist.
 ****************************************************************************************/
int swap();

/*
 ****************************************************************************************
 *  @brief     Diese Funktion gibt die obersten drei Elemente vom Stack aus.
 *
 *  @return    Ein Fehlercode, falls es zu einem Fehler gekommen ist.
 ****************************************************************************************/
int print_all();

/*
 ****************************************************************************************
 *  @brief     Diese Funktion leert den Stack.
 *
 *  @return    void
 ****************************************************************************************/
void clear();

/*
 ****************************************************************************************
 *  @brief     Dupliziert den obersten Wert des Stacks.
 *
 *  @return    Ein Fehlercode, falls es zu einem Fehler gekommen ist.
 ****************************************************************************************/
int dup();

#endif /* STACK_H */
       // EOF