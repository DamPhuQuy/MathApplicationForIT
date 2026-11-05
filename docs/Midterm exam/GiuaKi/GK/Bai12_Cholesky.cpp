#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

/*
   Augmented Cholesky decomposition theo FA Graybill (1976)

   C^T * C = orig
   chol    = C (ma trận tam giác trên)
   cholaug = C^-T * aug
*/

int cholesky(double **orig, int n,
             double **aug, int mcol,
             double **chol, double **cholaug,
             int ofs)
{
    int retval = 1;

    for (int i = ofs; i < n + ofs; i++) {

        // Tính phần tử đường chéo
        chol[i][i] = orig[i][i];
        for (int k = ofs; k < i; k++)
            chol[i][i] -= chol[k][i] * chol[k][i];

        if (chol[i][i] <= 0) {
            cerr << "\nERROR: non-positive definite matrix!\n";
            cerr << "problem at index " << i
                 << ", value = " << chol[i][i] << endl;
            return 0;
        }

        chol[i][i] = sqrt(chol[i][i]);

        // Nhân ma trận phụ với C^-T
        for (int l = ofs; l < mcol + ofs; l++) {
            cholaug[i][l] = aug[i][l];
            for (int k = ofs; k < i; k++)
                cholaug[i][l] -= cholaug[k][l] * chol[k][i];

            cholaug[i][l] /= chol[i][i];
        }

        // Tính các phần tử phía trên đường chéo
        for (int j = i + 1; j < n + ofs; j++) {
            chol[i][j] = orig[i][j];
            for (int k = ofs; k < i; k++)
                chol[i][j] -= chol[k][i] * chol[k][j];

            chol[i][j] /= chol[i][i];
        }
    }

    return retval;
}
