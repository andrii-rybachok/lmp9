#include "backsubst.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {

				/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */
				if(mat->c!=x->r || mat->c!=b->r){
					return 2;
				}
				x->data[x->r-1][0] =b->data[b->r-1][0]/ mat->data[mat->r-1][mat->c-1];
				for (int j = mat->r-2; j >= 0; j--)
				{
					double rowSum = 0;

					for (int i = j+1; i < mat->r; i++)
					{
						rowSum += mat->data[j][i]*x->data[i][0];
					}

					if(mat->data[j][j]==0){
						return 1;
					}
					x->data[j][0] = (b->data[j][0]-rowSum)/mat->data[j][j]; 
				}
				return 0;
}


