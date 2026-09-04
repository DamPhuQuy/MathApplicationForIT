//#include <stdio.h>
//#include <math.h>
//
//
//void xoahang(int i, int k, float C[][50])
//{
//    for (int a = 0; a < i - 1; a++)
//    {
//        for (int b = 0; b < i; b++)
//        {
//            if (a >= k)
//            {
//                C[a][b] = C[a + 1][b];
//            }
//        }
//    }
//}
//
//
//
//void xoacot(int i, int k, float C[][50])
//{
//    for (int a = 0; a < i; a++)
//    {
//        for (int b = 0; b < i - 1; b++)
//        {
//            if (b >= k)
//            {
//                C[a][b] = C[a][b + 1];
//            }
//        }
//    }
//}
//
//void xuat(int i, float A[][50])
//{
//    for (int k = 0; k < i; k++)
//    {
//        for (int l = 0; l < i; l++)
//        {
//            printf("%.2f\t", A[k][l]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//}
//
//void nhap(int i, float A[][50])
//{
//    for (int k = 0; k < i; k++)
//    {
//        for (int l = 0; l < i; l++)
//        {
//            printf("A[%d][%d] = ", k, l);
//            scanf_s("%f", &A[k][l]);
//        }
//    }
//    printf("\n");
//}
//
//float det(int i, float A[][50])
//{
//    if (i < 1)
//    {
//        printf("Khong co dinh thuc\n");
//        return 0;
//    }
//    if (i == 1)
//    {
//        return A[0][0];
//    }
//    else if (i == 2)
//    {
//        return ((A[0][0]) * (A[1][1]) - (A[0][1]) * (A[1][0]));
//    }
//    else if (i == 3)
//    {
//        return ((A[0][0]) * (A[1][1]) * (A[2][2]) + (A[0][2]) * (A[1][0]) * (A[2][1]) + (A[0][1]) * (A[1][2]) * (A[2][0])) - ((A[0][2]) * (A[1][1]) * (A[2][0]) + (A[0][1]) * (A[1][0]) * (A[2][2]) + (A[0][0]) * (A[1][2]) * (A[2][1]));
//    }
//    else
//    {
//        float D = 0;
//        for (int k = 0; k < i; k++)
//        {
//            float C[50][50];
//            for (int a = 0; a < i; a++)
//            {
//                for (int b = 0; b < i; b++)
//                {
//                    C[a][b] = A[a][b];
//                }
//            }
//            xoahang(i, 0, C);
//            xoacot(i, k, C);
//            D += pow(-1, k) * A[0][k] * det(i - 1, C);
//        }
//        return D;
//    }
//
//}
//
//void phuhop(int i, float A[][50], float N[][50])
//{
//    float D = det(i, A);
//    if (D == 0)
//    {
//        printf("Ma tran khong kha nghich\n");
//        return;
//    }
//    if (i > 1)
//    {
//        for (int k = 0; k < i; k++)
//        {
//            for (int l = 0; l < i; l++)
//            {
//
//                float C[50][50];
//                for (int q = 0; q < i; q++)
//                {
//                    for (int w = 0; w < i; w++)
//                    {
//                        C[q][w] = A[q][w];
//                    }
//                }
//                xoacot(i, l, C); xoahang(i, k, C);
//                N[l][k] = pow(-1, k + l) * det(i - 1, C);
//            }
//        }
//    }
//    else if (i == 1)
//    {
//        N[0][0] = 1;
//    }
//    else
//    {
//        printf("Loi du lieu\n");
//        return;
//    }
//}
//
//int main(void)
//{
//    int n = 0;
//    printf("Kich thuoc ma tran: ");
//    scanf_s("%d", &n);
//    float A[50][50];
//    nhap(n, A);
//    printf("\n Ma tran da nhap: \n");
//    xuat(n, A);
//    float D = det(n, A);
//    printf("Det = %.2f\n", D);
//
//    float C[50][50];
//    phuhop(n, A, C);
//    for (int i = 0; i < n; i++)
//    {
//        for (int k = 0; k < n; k++)
//        {
//            C[i][k] = (1 / D) * C[i][k];
//        }
//    }
//    printf("\nMa tran nghich dao:\n");
//
//    xuat(n, C);
//}


//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//void xoahang(int i, int k, float C[][50]) {
//    for (int a = 0; a < i - 1; a++) {
//        for (int b = 0; b < i; b++) {
//            if (a >= k) {
//                C[a][b] = C[a + 1][b];
//            }
//        }
//    }
//}
//
//void xoacot(int i, int k, float C[][50]) {
//    for (int a = 0; a < i; a++) {
//        for (int b = 0; b < i - 1; b++) {
//            if (b >= k) {
//                C[a][b] = C[a][b + 1];
//            }
//        }
//    }
//}
//
//void xuat(int i, float A[][50]) {
//    for (int k = 0; k < i; k++) {
//        for (int l = 0; l < i; l++) {
//            cout << fixed << setprecision(2) << A[k][l] << "\t";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
//
//void nhap(int i, float A[][50]) {
//    for (int k = 0; k < i; k++) {
//        for (int l = 0; l < i; l++) {
//            cout << "A[" << k << "][" << l << "] = ";
//            cin >> A[k][l];
//        }
//    }
//    cout << endl;
//}
//
//float det(int i, float A[][50]) {
//    if (i < 1) {
//        cout << "Khong co dinh thuc\n";
//        return 0;
//    }
//    if (i == 1) {
//        return A[0][0];
//    }
//    else if (i == 2) {
//        return ((A[0][0]) * (A[1][1]) - (A[0][1]) * (A[1][0]));
//    }
//    else if (i == 3) {
//        return ((A[0][0]) * (A[1][1]) * (A[2][2]) + (A[0][2]) * (A[1][0]) * (A[2][1]) + (A[0][1]) * (A[1][2]) * (A[2][0])) - ((A[0][2]) * (A[1][1]) * (A[2][0]) + (A[0][1]) * (A[1][0]) * (A[2][2]) + (A[0][0]) * (A[1][2]) * (A[2][1]));
//    }
//    else {
//        float D = 0;
//        for (int k = 0; k < i; k++) {
//            float C[50][50];
//            for (int a = 0; a < i; a++) {
//                for (int b = 0; b < i; b++) {
//                    C[a][b] = A[a][b];
//                }
//            }
//            xoahang(i, 0, C);
//            xoacot(i, k, C);
//            D += pow(-1, k) * A[0][k] * det(i - 1, C);
//        }
//        return D;
//    }
//}
//
//void phuhop(int i, float A[][50], float N[][50]) {
//    float D = det(i, A);
//    if (D == 0) {
//        cout << "Ma tran khong kha nghich\n";
//        return;
//    }
//    if (i > 1) {
//        for (int k = 0; k < i; k++) {
//            for (int l = 0; l < i; l++) {
//
//                float C[50][50];
//                for (int q = 0; q < i; q++) {
//                    for (int w = 0; w < i; w++) {
//                        C[q][w] = A[q][w];
//                    }
//                }
//                xoacot(i, l, C);
//                xoahang(i, k, C);
//                N[l][k] = pow(-1, k + l) * det(i - 1, C);
//            }
//        }
//    }
//    else if (i == 1) {
//        N[0][0] = 1;
//    }
//    else {
//        cout << "Loi du lieu\n";
//        return;
//    }
//}
//
//int main() {
//    int n = 0;
//    cout << "Kich thuoc ma tran: ";
//    cin >> n;
//    float A[50][50];
//    nhap(n, A);
//    cout << "\n Ma tran da nhap: \n";
//    xuat(n, A);
//    float D = det(n, A);
//    cout << "Det = " << fixed << setprecision(2) << D << endl;
//
//    float C[50][50];
//    phuhop(n, A, C);
//    for (int i = 0; i < n; i++) {
//        for (int k = 0; k < n; k++) {
//            C[i][k] = (1 / D) * C[i][k];
//        }
//    }
//    cout << "\nMa tran nghich dao:\n";
//
//    xuat(n, C);
//    return 0;
//}
