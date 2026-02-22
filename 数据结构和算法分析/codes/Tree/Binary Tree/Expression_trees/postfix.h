#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

double postfix_cal(char *expression);
void infix_to_postfix(char *infix, char *postfix);