#include <iostream>
using namespace std;
int main() {
    double a[3][3]= {
        {2,1,2},
        {4,3,1},
        {6,1,5}
    };
    double b[3]= {6,11,13};
    int n=2;
    for(int k=0; k <= n; k++) {
        if(a[k][k]==0) {
            cout << "停机" << endl;
        }
        for(int i=k+1; i <= n; i++) {
            a[i][k] = a[i][k]/a[k][k];
            b[i] = b[i] - a[i][k]*b[k];
            for(int j=k+1; j <= n; j++) {
                a[i][j] = a[i][j] - a[i][k]*a[k][j];
            }
        }

        if(k==n-1) {
            if(a[n][n]==0) {
                cout << "停机" << endl;
            }
            b[n] = b[n]/a[n][n];
            for(int k=n-1; k >=0; k--) {
                double sum = 0;
                for(int l=k+1; l <=n; l++){
                    sum += a[k][l] * b[l];
                }
                b[k] = (b[k] -sum) / a[k][k];
            }
        }
    }
    cout << "答案为：";
    for(int i = 0 ; i <= n; i++){
        cout << b[i] << " ";
    }
    cout << endl;

}
