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
    
    
    //vetores B
    vector<double> xP = { 1.0, 1.0, 1.0, 1.0, 1.0 };
    vector<double> xM = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
    vector<double> xG = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

    //Matrizes de Hilbert
    cout << "MATRIZES DE HILBERT" << endl;
    cout << "--------------------------------------------------" << endl;
    //declara matrizes de hilbert
    Matrix* hilbertP = new Matrix(5, 5, HILBERT);
    Matrix* hilbertM = new Matrix(10, 10, HILBERT);
    Matrix* hilbertG = new Matrix(15, 15, HILBERT);

    //gets b's hilbert
    vector<double> bHilbertP= hilbertP->getB();
    vector<double> bHilbertM = hilbertM->getB();
    vector<double> bHilbertG = hilbertG->getB();

    //metodos de resolucao de sistemas lineares para hilbert P
    vector<double> hilbertGaussP = hilbertP->gauss(bHilbertP);
    printVector(hilbertGaussP);
    vector<double> hilbertGaussJordanP = hilbertP->gaussJordan(bHilbertP);
    printVector(hilbertGaussJordanP);
    vector<double> hilbertLuP = hilbertP->decomposicaoLU(bHilbertP);
    printVector(hilbertLuP);
    vector<double> hilbertJacobiP = hilbertP->jacobi(bHilbertP);
    printVector(hilbertJacobiP);
    vector<double> hilbertGaussSeidelP = hilbertP->gaussSeidel(bHilbertP);
    printVector(hilbertGaussSeidelP);

    vector<double> hilbertGaussM = hilbertM->gauss(bHilbertM);
    printVector(hilbertGaussM);
    vector<double> hilbertGaussJordanM = hilbertM->gaussJordan(bHilbertM);
    printVector(hilbertGaussJordanM);
    vector<double> hilbertLuM = hilbertM->decomposicaoLU(bHilbertM);
    printVector(hilbertLuM);
    vector<double> hilbertJacobiM = hilbertM->jacobi(bHilbertM);
    printVector(hilbertJacobiM);
    vector<double> hilbertGaussSeidelM = hilbertM->gaussSeidel(bHilbertM);
    printVector(hilbertGaussSeidelM);

    vector<double> hilbertGaussG = hilbertG->gauss(bHilbertG);
    printVector(hilbertGaussG);
    vector<double> hilbertGaussJordanG = hilbertG->gaussJordan(bHilbertG);
    printVector(hilbertGaussJordanG);
    vector<double> hilbertLuG = hilbertG->decomposicaoLU(bHilbertG);
    printVector(hilbertLuG);
    vector<double> hilbertJacobiG = hilbertG->jacobi(bHilbertG);
    printVector(hilbertJacobiG);
    vector<double> hilbertGaussSeidelG = hilbertG->gaussSeidel(bHilbertG);
    printVector(hilbertGaussSeidelG);
    

    //Matrizes de Vandermond
    cout << "MATRIZES DE VANDERMOND" << endl;
    cout << "--------------------------------------------------" << endl;

    //Matrizes de Vandermond
    Matrix* vandermondP = new Matrix(5, 5, VANDERMOND);
    Matrix* vandermondM = new Matrix(10, 10, VANDERMOND);
    Matrix* vandermondG = new Matrix(15, 15, VANDERMOND);

    //gets b vandermond
    vector<double> bVandermondP = vandermondP->getB();
    vector<double> bVandermondM = vandermondM->getB();
    vector<double> bVandermondG = vandermondG->getB();

    //metodos de resolucao de sistemas lineares para vandermond
    vector<double> vandermondGaussP = vandermondP->gauss(bVandermondP);
    printVector(vandermondGaussP);
    vector<double> vandermondGaussJordanP = vandermondP->gaussJordan(bVandermondP);
    printVector(vandermondGaussJordanP);
    vector<double> vandermondLuP = vandermondP->decomposicaoLU(bVandermondP);
    printVector(vandermondLuP);
    vector<double> vandermondJacobiP = vandermondP->jacobi(bVandermondP);
    printVector(vandermondJacobiP);
    vector<double> vandermondGaussSeidelP = vandermondP->gaussSeidel(bVandermondP);
    printVector(vandermondGaussSeidelP);

    vector<double> vandermondGaussM = vandermondM->gauss(bVandermondM);
    printVector(vandermondGaussM);
    vector<double> vandermondGaussJordanM = vandermondM->gaussJordan(bVandermondM);
    printVector(vandermondGaussJordanM);
    vector<double> vandermondLuM = vandermondM->decomposicaoLU(bVandermondM);
    printVector(vandermondLuM);
    vector<double> vandermondJacobiM = vandermondM->jacobi(bVandermondM);
    printVector(vandermondJacobiM);
    vector<double> vandermondGaussSeidelM = vandermondM->gaussSeidel(bVandermondM);
    printVector(vandermondGaussSeidelM);

    vector<double> vandermondGaussG = vandermondG->gauss(bVandermondG);
    printVector(vandermondGaussG);
    vector<double> vandermondGaussJordanG = vandermondG->gaussJordan(bVandermondG);
    printVector(vandermondGaussJordanG);
    vector<double> vandermondLuG = vandermondG->decomposicaoLU(bVandermondG);
    printVector(vandermondLuG);
    vector<double> vandermondJacobiG = vandermondG->jacobi(bVandermondG);
    printVector(vandermondJacobiG);
    vector<double> vandermondGaussSeidelG = vandermondG->gaussSeidel(bVandermondG);
    printVector(vandermondGaussSeidelG);


    cout << "MATRIZES DE CAUCHY" << endl;
    cout << "--------------------------------------------------" << endl;

    //Matrizes de Cauchy
    Matrix* cauchyP = new Matrix(5, 5, CAUCHY);
    Matrix* cauchyM = new Matrix(10, 10, CAUCHY);
    Matrix* cauchyG = new Matrix(15, 15, CAUCHY);

    //gets cauchy
    vector<double> bCauchyP = cauchyP->getB();
    vector<double> bCauchyM = cauchyM->getB();
    vector<double> bCauchyG = cauchyG->getB();

    vector<double> cauchyGaussP = cauchyP->gauss(bCauchyP);
    printVector(cauchyGaussP);
    vector<double> cauchyGaussJordanP = cauchyP->gaussJordan(bCauchyP);
    printVector(cauchyGaussJordanP);
    vector<double> cauchyLuP = cauchyP->decomposicaoLU(bCauchyP);
    printVector(cauchyLuP);
    vector<double> cauchyJacobiP = cauchyP->jacobi(bCauchyP);
    printVector(cauchyJacobiP);
    vector<double> cauchyGaussSeidelP = cauchyP->gaussSeidel(bCauchyP);
    printVector(cauchyGaussSeidelP);

    vector<double> cauchyGaussM = cauchyM->gauss(bCauchyM);
    printVector(cauchyGaussM);
    vector<double> cauchyGaussJordanM = cauchyM->gaussJordan(bCauchyM);
    printVector(cauchyGaussJordanM);
    vector<double> cauchyLuM = cauchyM->decomposicaoLU(bCauchyM);
    printVector(cauchyLuM);
    vector<double> cauchyJacobiM = cauchyM->jacobi(bCauchyM);
    printVector(cauchyJacobiM);
    vector<double> cauchyGaussSeidelM = cauchyM->gaussSeidel(bCauchyM);
    printVector(cauchyGaussSeidelM);

    vector<double> cauchyGaussG = cauchyG->gauss(bCauchyG);
    printVector(cauchyGaussG);
    vector<double> cauchyGaussJordanG = cauchyG->gaussJordan(bCauchyG);
    printVector(cauchyGaussJordanG);
    vector<double> cauchyLuG = cauchyG->decomposicaoLU(bCauchyG);
    printVector(cauchyLuG);
    vector<double> cauchyJacobiG = cauchyG->jacobi(bCauchyG);
    printVector(cauchyJacobiG);
    vector<double> cauchyGaussSeidelG = cauchyG->gaussSeidel(bCauchyG);
    printVector(cauchyGaussSeidelG);


    cout << "MATRIZES DE TOEPLITZ" << endl;
    cout << "--------------------------------------------------" << endl;

    //Matrizes de Toeplitz
    Matrix* toeplitzP = new Matrix(5, 5, TOEPLITZ);
    Matrix* toeplitzM = new Matrix(10, 10, TOEPLITZ);
    Matrix* toeplitzG = new Matrix(15, 15, TOEPLITZ);

    //gets b Toeplitz
    vector<double> bToeplitzP = cauchyP->getB();
    vector<double> bToeplitzM = cauchyM->getB();
    vector<double> bToeplitzG = cauchyG->getB();

    //metodos de resolucao de sistemas lineares para vandermond
    vector<double> toeplitzGaussP = toeplitzP->gauss(bToeplitzP);
    printVector(toeplitzGaussP);
    vector<double> toeplitzGaussJordanP = toeplitzP->gaussJordan(bToeplitzP);
    printVector(toeplitzGaussJordanP);
    vector<double> toeplitzLuP = toeplitzP->decomposicaoLU(bToeplitzP);
    printVector(toeplitzLuP);
    vector<double> toeplitzJacobiP = toeplitzP->jacobi(bToeplitzP);
    printVector(toeplitzJacobiP);
    vector<double> toeplitzGaussSeidelP = toeplitzP->gaussSeidel(bToeplitzP);
    printVector(toeplitzGaussSeidelP);

    vector<double> toeplitzGaussM = toeplitzM->gauss(bToeplitzM);
    printVector(toeplitzGaussM);
    vector<double> toeplitzGaussJordanM = toeplitzM->gaussJordan(bToeplitzM);
    printVector(toeplitzGaussJordanM);
    vector<double> toeplitzLuM = toeplitzM->decomposicaoLU(bToeplitzM);
    printVector(toeplitzLuM);
    vector<double> toeplitzJacobiM = toeplitzM->jacobi(bToeplitzM);
    printVector(toeplitzJacobiM);
    vector<double> toeplitzGaussSeidelM = toeplitzM->gaussSeidel(bToeplitzM);
    printVector(toeplitzGaussSeidelM);

    vector<double> toeplitzGaussG = toeplitzG->gauss(bToeplitzG);
    printVector(toeplitzGaussG);
    vector<double> toeplitzGaussJordanG = toeplitzG->gaussJordan(bToeplitzG);
    printVector(toeplitzGaussJordanG);
    vector<double> toeplitzLuG = toeplitzG->decomposicaoLU(bToeplitzG);
    printVector(toeplitzLuG);
    vector<double> toeplitzJacobiG = toeplitzG->jacobi(bToeplitzG);
    printVector(toeplitzJacobiG);
    vector<double> toeplitzGaussSeidelG = toeplitzG->gaussSeidel(bToeplitzG);
    printVector(toeplitzGaussSeidelG);

 
    system("pause");

}
