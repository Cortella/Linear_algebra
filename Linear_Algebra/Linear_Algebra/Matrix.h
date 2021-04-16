#ifndef MATRIX_H
#define MATRIX_H
// matrix.h (header file)

#include <iostream>
#include <iomanip>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

class Matrix {
private:

    double** m; // m é um array 2D a ser implementado como um pointer de pointers
    int nRows;  // numero de linhas
    int nCols;  //  numero de colunas

    
public:

    //cria matriz de hilbert de  tamanho variavel
    void hilbert(int size);

    //Cria matriz de toepliz de tamanho variavel
    void toepliz(int size);
    

    //cria matriz de cauch de tamanho variavel
    void vandermond(int size);

    //Cria matriz de cauchy com tamanho variavel 
    void cauchy(int size);

    //cria matriz de cauchy
    // Construtores
    Matrix();
    // cria matriz B de jacobi
    Matrix(Matrix *x);
    Matrix(int rows, int cols, char mat = 'm');
    Matrix(const int& size);
    Matrix(int rows, int cols, const double& value);
    
    

    //setters
    void setSize(int rows, int cols);
    void setElement(int l, int c, int element) { this->m[l][c] = element; }
    void setCols(int c) { this->nCols = c; }
    void setRows(int r) { this->nRows = r; }
    //getters
    double** getMatrix() { return this->m; }
    int getRows() const { return this->nRows; }
    int getCols() const { return this->nCols; };
    vector<double> getB();
    //retorna elemento especifico
    double get(int row, int col) const { return this->m[row][col]; }

    void id();

  
    vector<int> getP();
    // transforma *this em sua transposta
    void transpose();

    //imprime matriz na tela
    void print() const;

    //Decomposição LU
    vector<double> decomposicaoLU(vector<double>& x);

    // faz com que a matriz torne-se uma matriz identidade
    void unit();

    //faz com o que matriz se torne nula
    void zeros();

    // faz com que a matriz torne-se uma matriz cujos elementos sao iguaia a 1
    void ones();

    //cria a matriz aumentada
    void aumentada(vector<double> &v);

    //APlica o método de eliminação de gauss e retorna vetor b
    vector<double> resolveGauss(vector<double> &x);

    //Abertos
    //jacobi

   
    vector<double> getG(vector<double>& b);

    vector<double> getX(vector<double>& x,vector<double> &g);
    vector<double> jacobi(vector<double> &x);
    //aplica metodo de eliminacao de gauss jordam
    vector<double> gaussJordan(vector<double>& x);

    //destrutor
   ~Matrix();

};

#endif //MATRIX_H


