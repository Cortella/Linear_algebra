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


    // Construtores
    //padrao
    Matrix();
    //cria matrizes de Hilbert, Vandermond, Cauchy e Toeplitz de tamanho variável
    Matrix(int rows, int cols, char mat = 'm');

    //cria matriz quadrada de zeros
    Matrix(const int& size);
    
    

    //setters
    //Altera o tamanho da matriz e atribui 0.0 a novo espaço alocado
    void setSize(int rows, int cols);

    //altera elemento especifico da matriz
    void setElement(int l, int c, int element) { this->m[l][c] = element; }

    //altera o numero de colunas
    void setCols(int c) { this->nCols = c; }

    //altera o numero de linhas
    void setRows(int r) { this->nRows = r; }


    //getters
    //retorna poteiro para matriz
    double** getMatrix() { return this->m; }

    //retorna o numero de linhas da matriz
    int getRows() const { return this->nRows; }

    //retorna o numero de colunas da matriz
    int getCols() const { return this->nCols; };

    //retorna um elemento especifico
    double getElement(int row, int col) const { return this->m[row][col]; }


    vector<double> getB();
    vector<double> getG(vector<double>& b);
    vector<double> getX(vector<double>& x, vector<double>& g);
    vector<int> getP();
    //retorna elemento especifico
    

    void id();
    
    // transforma *this em sua transposta
    void transpose();

    //imprime matriz na tela
    void print() const;

    //Decomposição LU
    vector<double> decomposicaoLU(vector<double>& x);

    //cria a matriz aumentada
    void aumentada(vector<double> &v);

    //APlica o método de eliminação de gauss e retorna vetor b
    vector<double> resolveGauss(vector<double> &x);

    //Abertos
    //jacobi

   //Metodos


    
    vector<double> jacobi(vector<double> &x);

    //Aplica metodo de Gauss-Seidel
    vector<double> gaussSeidel(vector<double>& b);
    //aplica metodo de eliminacao de gauss jordam
    vector<double> gaussJordan(vector<double>& x);

    //destrutor
   ~Matrix();

};

#endif //MATRIX_H


