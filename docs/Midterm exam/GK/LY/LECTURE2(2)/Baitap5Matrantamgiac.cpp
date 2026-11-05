#include <bits/stdc++.h>
using namespace std;
void biendoi(float A[][3], int n)
{
    float m;
    for (int i=0;i<n-1;i++)
    {
        if (A[i][i]==0) {
            for (int j=i+1;j<n;j++)
            {
                if (A[j][i]!=0) for (int k=0;k<n;k++) swap(A[i][k],A[j][k]);
            }
        }
        for (int j=i+1;j<n;j++)
        {
            m = -A[j][i]/A[i][i];
            for (int k=i;k<n;k++) A[j][k]+= A[i][k]*m;
        }
    }

}
int main()
{
    float A[3][3];
    int n=3;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cin >> A[i][j];
        }
    }
    
    biendoi(A,n);
    cout << "Ma tran bien doi : " << endl;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout << A[i][j] << "\t";

        }
        cout << endl;
    }
}
