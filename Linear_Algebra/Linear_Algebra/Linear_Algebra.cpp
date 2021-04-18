#include <iostream>
#include "Matrix.h"
#include <stdlib.h>

#define HILBERT 'h'
#define VANDERMOND 'v'
#define CAUCHY 'c'
#define TOEPLITZ 't'

void printVector(vector<double> m) {
    vector<double>::iterator i;
    cout << std::fixed << std::setprecision(7);
    for (i = m.begin(); i != m.end(); i++) {
        cout << *i << endl;
    }
}

int main()
{
    /*
    
    //vetores B
    vector<double> xP = { 1.0, 1.0, 1.0, 1.0, 1.0 };
    vector<double> xM = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
    vector<double> xG = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

    //Matrizes de Hilbert
    Matrix* hilbertP = new Matrix(5, 5, HILBERT);
    Matrix* hilbertM = new Matrix(10, 10, HILBERT);
    Matrix* hilbertG = new Matrix(15, 15, HILBERT);

    //calula o vetor b inicial
    vector<double> b;
    b = hilbertP->getB();


    //Matrizes de Vandermond
    Matrix* vandemondP = new Matrix(5, 5, VANDERMOND);
    Matrix* vandemondM = new Matrix(10, 10, VANDERMOND);
    Matrix* vandemondG = new Matrix(15, 15, VANDERMOND);

    //Matrizes de Cauchy
    Matrix* cauchyP = new Matrix(5, 5, CAUCHY);
    Matrix* cauchyM = new Matrix(10, 10, CAUCHY);
    Matrix* cauchyG = new Matrix(15, 15, CAUCHY);

    //Matrizes de Toeplitz
    Matrix* toeplizP = new Matrix(5, 5, TOEPLITZ);
    Matrix* toeplizM = new Matrix(10, 10, TOEPLITZ);
    Matrix* toeplizG = new Matrix(15, 15, TOEPLITZ);
    
*/
    
    Matrix* m = new Matrix(3, 3);

    m->setElement(0, 0, 3.0);
    m->setElement(0, 1, 2.0);
    m->setElement(0, 2, 4.0);

    m->setElement(1, 0, 1.0);
    m->setElement(1, 1, 1.0);
    m->setElement(1, 2, 2.0);

    m->setElement(2, 0, 4.0);
    m->setElement(2, 1, 3.0);
    m->setElement(2, 2, -2.0);

   // m->print();
   
    cout <<"TESTE GAUSS" << endl;
    cout << "MATRIZ DE TESTE" << endl;
    m->print();
    cout << "VETOR DE TESTE" << endl;
    vector<double> b = { 1 , 2 , 3 };
    printVector(b);
    vector<double> x = m->gauss(b);
    cout << "X" << endl;
    printVector(x);
   // vector<double> res = hilbert->getB();
   // vector<double> x = hilbert->gauss(res);

   //Matrix* hilbert = new Matrix(10,10, HILBERT);
    //vector<double> res = hilbert->getB();
    
    //printVector(x);
   // m->print();

   // m->print();
 
    // m->aumentada(x);
    // m->print();
    



    system("pause");

}
