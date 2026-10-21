/**
 * @file speicherwerk.h
 * @author Cord Harms, Timo Hinrichs, Duc Nguyen
 * @date Oktober 2026
 * @brief ???
 */

#ifndef SPEICHERWERK_H
#define SPEICHERWERK_H // ???
#define STACK_SIZE 3

typedef struct {
   int array[STACK_SIZE];
   int top;
} Stack;

// void: nochmal was zu Fehlercodes überlegen
void push(int zahl);
int pop();
void swap();
void print_top();
void print_all();
void clear();
void double_top();




#endif /* SPEICHERWERK_H */
// EOF