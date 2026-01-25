#ifndef _POLY_H_
#define _POLY_H_

#include "stdio.h"
#include "stdlib.h"

struct poly_arr
{
    int MaxDegree;
    double *coefficients;
};

struct poly_list
{
    int coefficient;
    int exponent;
    struct poly_list *next;
};

typedef struct poly_arr PolyArr;
typedef struct poly_list *PolyList;

PolyArr *CreatePolyArr(int MaxDegree);
PolyArr *AssignPolysArr(int degree, double coeffs[]);
void DestroyPolyArr(PolyArr *poly);
PolyArr *AddPolyArr(const PolyArr *poly1, const PolyArr *poly2);
PolyArr *MultPolyArr(const PolyArr *poly1, const PolyArr *poly2);
void PrintPolyArr(const PolyArr *poly);

#endif /* _POLY_H_ */