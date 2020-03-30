#include <bits/stdc++.h>
#define clr(ar) memset(ar, 0, sizeof ar)
using namespace std;
typedef long long ll;
int const sz = 50;

ll MOD;

struct Matrix
{
    int arr[5][5];
    int row,col;

    Matrix(int _r,int _c){
        row = _r;
        col = _c;
    }
    Matrix()
    {
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
                arr[i][j] = 0;
        }
    }

    Matrix operator * (const Matrix &other) const
    {
        Matrix res = Matrix(row,other.col);

        for(int i=0;i<row;i++){
            for(int j=0;j<other.col;j++){
                int result  = 0;
                for(int k=0;k<col;k++){
                    result += (arr[i][k] * other.arr[k][j]);
                }
                res.arr[i][j] = result;
            }
        }

        return res;
    }

    Matrix operator + (const Matrix &other) const
    {
        Matrix res = Matrix(row,col);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                res.arr[i][j] = (arr[i][j] + other.arr[i][j]);
            }
        }

        return res;
    }

    Matrix operator - (const Matrix &other) const
    {
        Matrix res = Matrix(row,col);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                res.arr[i][j] = (arr[i][j] - other.arr[i][j]);
            }
        }

        return res;
    }

    Matrix operator ^ (const int n) const
    {
        Matrix res = Matrix(row,col);
        res = *this;
        Matrix A = Matrix(row,col);
        A = *this;
        for(int i=1;i<n;i++){
            res = res * A;
        }

        return res;
    }

    Matrix clear()
    {
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                arr[i][j] = 0;
            }
        }
    }

    Matrix create_identity()
    {
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==j) arr[i][j] = 1;
                else arr[i][j] = 0;
            }
        }
    }

    Matrix bigmod(Matrix A,int b){
        if(b==0){
            Matrix res = Matrix(row,col);
            res.create_identity();
            return res;
        }
        if(b%2==0){
            Matrix res = Matrix(row,col);
            res = bigmod(A,b/2);
            res = res * res;
            return res;
        }
        else {
             Matrix res = Matrix(row,col);
             res = (A * bigmod(A,b-1));
             return res;
        }
    }
};
int main()
{
    Matrix A,B,C;
    cin >> A.row >> A.col;
    for(int i=0;i<A.row;i++){
        for(int j=0;j<A.col;j++)
            cin >> A.arr[i][j];
    }



    /*cin >> B.row >> B.col;
    for(int i=0;i<B.row;i++){
        for(int j=0;j<B.col;j++)
            cin >> B.arr[i][j];
    }

    C = A * B;

    cout << C.row << " " << C.col << endl;
    for(int i=0;i<C.row;i++){
        for(int j=0;j<C.col;j++){
            cout << C.arr[i][j] << " ";
        }
        cout << endl;
    }

    C.clear();

    C = A + B;

    cout << C.row << " " << C.col << endl;
    for(int i=0;i<C.row;i++){
        for(int j=0;j<C.col;j++){
            cout << C.arr[i][j] << " ";
        }
        cout << endl;
    }

    C.clear();

    C = A - B;

    cout << C.row << " " << C.col << endl;
    for(int i=0;i<C.row;i++){
        for(int j=0;j<C.col;j++){
            cout << C.arr[i][j] << " ";
        }
        cout << endl;
    }

    C.clear();*/

    C.row = A.row;
    C.col = A.col;

    C = C.bigmod(A,2);

    cout << C.row << " " << C.col << endl;
    for(int i=0;i<C.row;i++){
        for(int j=0;j<C.col;j++){
            cout << C.arr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
