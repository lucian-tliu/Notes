#pragma once

// Only for arithmetic calculation
#include "Stack.h"
#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"

double postfix_cal(char *expression);
void infix_to_postfix(char *infix, char *postfix);