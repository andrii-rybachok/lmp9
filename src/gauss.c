#include "gauss.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>
int eliminate(Matrix *mat, Matrix *b) {
    if (mat->r != mat->c || mat->r != b->r) {
        return 2; // Błąd nieprawidłowych rozmiarów macierzy
    }
    double mainEl = mat->data[0][0];
    int indexForChange=0;
    for (int i = 0; i < mat->r; i++)
    {
        double absCurr=fabs(mat->data[i][0]);

        if(mainEl<absCurr){
            mainEl = absCurr;
            indexForChange=i;

        }
        
    }
    if(indexForChange!=0){
        
        double tmp = b->data[0][0];
        b->data[0][0] =  b->data[indexForChange][0];
        b->data[indexForChange][0] = tmp;

        for (int j = 0; j < mat->r; j++)
        {
            for (int i = 0; i < mat->c; i++)
            {
                double tmp = mat->data[j][i];
                mat->data[j][i] =  mat->data[indexForChange][i];
                mat->data[indexForChange][i] = tmp;
            }
            
        }
        
    }
    
    for (int k = 0; k < mat->r - 1; k++) {
        for (int i = k + 1; i < mat->r; i++) {
            if (mat->data[k][k] == 0) {
                return 1; // Błąd dzielenia przez 0 (element na diagonali = 0)
            }

            double factor = mat->data[i][k] / mat->data[k][k];

            for (int j = k; j < mat->r; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }

            b->data[i][0] -= factor * b->data[k][0];
        }
    }

    return 0; // Eliminacja zakończona sukcesem
}

