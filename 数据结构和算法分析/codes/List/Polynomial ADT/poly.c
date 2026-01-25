#include "poly.h"

PolyArr *CreatePolyArr(int MaxDegree)
{
    PolyArr *poly = (PolyArr *)malloc(sizeof(PolyArr));
    poly->MaxDegree = MaxDegree;
    poly->coefficients = (double *)calloc(MaxDegree + 1, sizeof(double));
    return poly;
}

PolyArr *AssignPolysArr(int degree, double coeffs[])
{
    PolyArr *poly = CreatePolyArr(degree);
    for (int i = 0; i <= degree; i++)
    {
        poly->coefficients[i] = coeffs[i];
    }
    return poly;
}

void DestroyPolyArr(PolyArr *poly)
{
    if (poly)
    {
        free(poly->coefficients);
        free(poly);
    }
}

PolyArr *AddPolyArr(const PolyArr *poly1, const PolyArr *poly2)
{
    int maxDegree = (poly1->MaxDegree > poly2->MaxDegree) ? poly1->MaxDegree : poly2->MaxDegree;
    PolyArr *result = CreatePolyArr(maxDegree);

    for (int i = 0; i <= maxDegree; i++)
    {
        double coeff1 = (i <= poly1->MaxDegree) ? poly1->coefficients[i] : 0.0;
        double coeff2 = (i <= poly2->MaxDegree) ? poly2->coefficients[i] : 0.0;
        result->coefficients[i] = coeff1 + coeff2;
    }

    return result;
}

PolyArr *MultPolyArr(const PolyArr *poly1, const PolyArr *poly2)
{
    int maxDegree = poly1->MaxDegree + poly2->MaxDegree;
    PolyArr *result = CreatePolyArr(maxDegree);

    for (int i = 0; i <= poly1->MaxDegree; i++)
    {
        for (int j = 0; j <= poly2->MaxDegree; j++)
        {
            result->coefficients[i + j] += poly1->coefficients[i] * poly2->coefficients[j];
        }
    }

    return result;
}

void PrintPolyArr(const PolyArr *poly)
{
    for (int i = poly->MaxDegree; i >= 0; i--)
    {
        if (poly->coefficients[i] != 0)
        {
            if (i != poly->MaxDegree && poly->coefficients[i] > 0)
            {
                printf("+");
            }
            printf("%.2fx^%d ", poly->coefficients[i], i);
        }
    }
    printf("\n");
}