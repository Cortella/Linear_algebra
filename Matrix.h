#ifndef MATRIX_H
#define MATRIX_H
// matrix.h (header file)

#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>

#define IDENTIDADE 'i'

using std::cout;
using std::endl;
using std::cin;
using std::vector;



class Matrix {
private:

    double** m; // m é um array 2D a ser implementado como um pointer de pointers
    int nRows;  // numero de linhas
    int nCols;  //  numero de colunas


    //calcula a norma
    double getNorma(vector<double>v, vector<double>x);

    //cria a matriz aumentada
    void aumentada(vector<double> v);

    vector<double>successiveSubstitutions(vector<double> b);

    vector<double>retroactiveSubstitutions(vector<double> b);

public:


    // Construtores
    //padrao
    Matrix();

    //cria matrizes de Hilbert, Vandermond, identidade, Cauchy e Toeplitz de tamanho variável
    Matrix(int rows, int cols, char mat = 'm');

    //setters
    //Altera o tamanho da matriz e atribui 0.0 a novo espaço alocado
    void setSize(int rows, int cols);

    //altera elemento especifico da matriz
    void setElement(int l, int c, double element) { this->m[l][c] = element; }

    //altera o numero de colunas
    void setCols(int c) { this->nCols = c; }

    //altera o numero de linhas
    void setRows(int r) { this->nRows = r; }

    
    //sobrecargas
    //sobrecarrega operador = e permite copia de valores de uma matriz em uma unica passagem
    Matrix& operator=(Matrix& m);

    //getters
    //retorna poteiro para matriz
    double** getMatrix() { return this->m; }

    //retorna o numero de linhas da matriz
    int getRows() const { return this->nRows; }

    //retorna o numero de colunas da matriz
    int getCols() const { return this->nCols; };

    //retorna um elemento especifico
    double getElement(int row, int col) const { return this->m[row][col]; }

    //obtem vetor b a partir da soma da linha da matriz
    vector<double> getB();

    //imprime matriz na tela
    void print() const;

    //Metodos
    //implementa metodo de gauss e retorna vetor solucao X
    vector<double> gauss(vector<double> b);

    //implementa metodo de gauss jordan e retorna vetor solucao X
    vector<double> gaussJordan(vector<double> x);

    //metodo de decomposicao LU
    vector<double>lu(vector<double> b);

    //Metodos iterativos

    vector<double> jacobi(vector<double> b, double epsilon = 0.05, int iterMax = 10);

    vector<double> seidel(vector<double> b, double epsilon = 0.05, int iterMax = 10);
    //destrutor
   ~Matrix();

};

#endif //MATRIX_H


