#include "poly.h"
#include "stdlib.h"
#include "stdio.h"

int main()
{
    // Create first polynomial: 2 + 3x + 4x^2
    double coeffs1[] = {2.0, 3.0, 4.0};
    PolyArr *poly1 = AssignPolysArr(2, coeffs1);

    // Create second polynomial: 1 + 0x + 5x^2 + 6x^3
    double coeffs2[] = {1.0, 0.0, 5.0, 6.0};
    PolyArr *poly2 = AssignPolysArr(3, coeffs2);

    // Add the two polynomials
    PolyArr *sumPoly = AddPolyArr(poly1, poly2);
    printf("Sum of Polynomials:\n");
    PrintPolyArr(sumPoly);

    // Multiply the two polynomials
    PolyArr *prodPoly = MultPolyArr(poly1, poly2);
    printf("Product of Polynomials:\n");
    PrintPolyArr(prodPoly);

    // Clean up
    DestroyPolyArr(poly1);
    DestroyPolyArr(poly2);
    DestroyPolyArr(sumPoly);
    DestroyPolyArr(prodPoly);

    return 0;
}