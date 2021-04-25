#include "Matrix.h"
#include <stdlib.h>


#define HILBERT 'h'
#define VANDERMOND 'v'
#define CAUCHY 'c'
#define TOEPLITZ 't'

using std::iterator;

void printVector(vector<double> m) {
    vector<double>::iterator i;
    cout << std::fixed << std::setprecision(7);
    for (i = m.begin(); i != m.end(); i++) {
        cout << *i << endl;
    }
}

double EQM(vector<double> ones, vector<double> obtidos) {
    double eqm = 0.0;
    for (int i = 0; i < obtidos.size(); i++) {
        eqm += fabs(pow(ones[i], 2) + pow(ones[i], 2));
    }
    return eqm;
}

void printMap(map<string, double> m) {

    map<string, double>::iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr) {
        cout << '\t' << itr->first
            << '\t' << itr->second << '\n';
    }
}

int main()
{
    map<string, double> map;
    
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
    vector<double> bHilbertP = hilbertP->getB();

    vector<double> bHilbertM = hilbertM->getB();

    vector<double> bHilbertG = hilbertG->getB();

    cout << "NOVA LU " << endl;
    vector<double> teste = hilbertP->lu(bHilbertP);
    printVector(teste);
    /*
    vector<double> hilbertGaussJordanP = hilbertP->gaussJordan(bHilbertP);
    printVector(hilbertGaussJordanP);
    map["HILBERT->P - GAUSS-JORDAN"] = EQM(xG, hilbertGaussJordanP);
    vector<double> hilbertGaussJordanM = hilbertM->gaussJordan(bHilbertM);
    printVector(hilbertGaussJordanM);
    map["HIBERT->M - GAUSS-JORDAN"] = EQM(xG, hilbertGaussJordanM);
    vector<double> hilbertGaussJordanG = hilbertG->gaussJordan(bHilbertG);
    printVector(hilbertGaussJordanG);
    map["HIBERT->G - GAUSS-JORDAN"] = EQM(xG, hilbertGaussJordanG);
    vector<double> hilbertLuP = hilbertP->decomposicaoLU(bHilbertP);
    printVector(hilbertLuP);
    vector<double> hilbertLuM = hilbertM->decomposicaoLU(bHilbertM);
    printVector(hilbertLuM);
    vector<double> hilbertLuG = hilbertG->decomposicaoLU(bHilbertG);
    printVector(hilbertLuG);
    */
    //metodos de resolucao de sistemas lineares
    /*
    vector<double> hilbertGaussP = hilbertP->gauss(bHilbertP);
    map["HILBERT->P - GAUSS"] = EQM(xG, hilbertGaussP);
    vector<double> hilbertGaussJordanP = hilbertP->gaussJordan(bHilbertP);
    map["HILBERT->P - GAUSS-JORDAN"] = EQM(xG, hilbertGaussJordanP);
    vector<double> hilbertLuP = hilbertP->gaussJordan(bHilbertP);
    map["HILBERT->P - Lu"] = EQM(xG, hilbertLuP);
    vector<double> hilbertJacobiP = hilbertP->decomposicaoLU(bHilbertP);
    map["HILBERT->P - JACOBI"] = EQM(xG, hilbertJacobiP);
    vector<double> hilbertGaussSeidelP = hilbertP->gaussSeidel(bHilbertP);
    map["HILBERT->P - SEIDEL"] = EQM(xG, hilbertGaussSeidelP);

    vector<double> hilbertGaussM = hilbertM->gauss(bHilbertM);
    map["HILBERT->M - GAUSS"] = EQM(xG, hilbertGaussM);
    vector<double> hilbertGaussJordanM = hilbertM->gaussJordan(bHilbertM);
    map["HIBERT->M - GAUSS-JORDAN"] = EQM(xG, hilbertGaussJordanM);
    vector<double> hilbertLuM = hilbertM->decomposicaoLU(bHilbertM);
    map["HILBERT->M - LU"] = EQM(xG, hilbertLuM);
    vector<double> hilbertJacobiM = hilbertM->jacobi(bHilbertM);
    map["HILBERT->M - JACOBI"] = EQM(xG, hilbertJacobiM);
    vector<double> hilbertGaussSeidelM = hilbertM->gaussSeidel(bHilbertM);
    map["HILBERT->M - SEIDEL"] = EQM(xG, hilbertGaussSeidelM);

    vector<double> hilbertGaussG = hilbertG->gauss(bHilbertG);
    map["HILBERT->G - GAUSS"] = EQM(xG, hilbertGaussG);
    vector<double> hilbertGaussJordanG = hilbertG->gaussJordan(bHilbertG);
    map["HIBERT->G - GAUSS-JORDAN"] = EQM(xG, hilbertGaussJordanG);
    vector<double> hilbertLuG = hilbertG->decomposicaoLU(bHilbertG);
    map["HILBERT->G - LU"] = EQM(xG, hilbertLuG);
    vector<double> hilbertJacobiG = hilbertG->jacobi(bHilbertG);
    map["HILBERT->G - JACOBI"] = EQM(xG, hilbertJacobiG);
    vector<double> hilbertGaussSeidelG = hilbertG->gaussSeidel(bHilbertG);
    map["HILBERT->G - SEIDEL"] = EQM(xG, hilbertGaussSeidelG);
    

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
    map["VANDERMOND->P - GAUSS"] = EQM(xG, vandermondGaussP);
    vector<double> vandermondGaussJordanP = vandermondP->gaussJordan(bVandermondP);
    map["VANDERMOND->P - GAUSS-JORDAN"] = EQM(xG, vandermondGaussJordanP);
    vector<double> vandermondLuP = vandermondP->decomposicaoLU(bVandermondP);
    map["VANDERMOND->P - LU"] = EQM(xG, vandermondLuP);
    vector<double> vandermondJacobiP = vandermondP->jacobi(bVandermondP);
    map["VANDERMOND->P - JACOBI"] = EQM(xG, vandermondJacobiP);
    vector<double> vandermondGaussSeidelP = vandermondP->gaussSeidel(bVandermondP);
    map["VANDERMOND->P - SEIDEL"] = EQM(xG, vandermondGaussSeidelP);

    vector<double> vandermondGaussM = vandermondM->gauss(bVandermondM);
    map["VANDERMOND->M - GAUSS"] = EQM(xG, vandermondGaussM);
    vector<double> vandermondGaussJordanM = vandermondM->gaussJordan(bVandermondM);
    map["VANDERMOND->M - GAUSS-JORDAN"] = EQM(xG, vandermondGaussJordanM);
    vector<double> vandermondLuM = vandermondM->decomposicaoLU(bVandermondM);
    map["VANDERMOND->M - LU"] = EQM(xG, vandermondLuM);
    vector<double> vandermondJacobiM = vandermondM->jacobi(bVandermondM);
    map["VANDERMOND->M - JACOBI"] = EQM(xG, vandermondJacobiM);
    vector<double> vandermondGaussSeidelM = vandermondM->gaussSeidel(bVandermondM);
    map["VANDERMOND->M - SEIDEL"] = EQM(xG, vandermondGaussSeidelM);

    vector<double> vandermondGaussG = vandermondG->gauss(bVandermondG);
    map["VANDERMOND->G - GAUSS"] = EQM(xG, vandermondGaussG);
    vector<double> vandermondGaussJordanG = vandermondG->gaussJordan(bVandermondG);
    map["VANDERMOND->G - GAUSS-JORDAN"] = EQM(xG, vandermondGaussJordanG);
    vector<double> vandermondLuG = vandermondG->decomposicaoLU(bVandermondG);
    map["VANDERMOND->G - LU"] = EQM(xG, vandermondLuG);
    vector<double> vandermondJacobiG = vandermondG->jacobi(bVandermondG);
    map["VANDERMOND->G - JACOBI"] = EQM(xG, vandermondJacobiG);
    vector<double> vandermondGaussSeidelG = vandermondG->gaussSeidel(bVandermondG);
    map["VANDERMOND->G - SEIDEL"] = EQM(xG, vandermondGaussSeidelG);


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
    map["CAUCHY->P - GAUSS-JORDAN"] = EQM(xG, cauchyGaussP);
    vector<double> cauchyGaussJordanP = cauchyP->gaussJordan(bCauchyP);
    map["CAUCHY->P - GAUSS-JORDAN"] = EQM(xG, cauchyGaussJordanP);
    vector<double> cauchyLuP = cauchyP->decomposicaoLU(bCauchyP);
    map["CAUCHY->P - LU"] = EQM(xG, cauchyLuP);
    vector<double> cauchyJacobiP = cauchyP->jacobi(bCauchyP);
    map["CAUCHY->P - JACOBI"] = EQM(xG, cauchyJacobiP);
    vector<double> cauchyGaussSeidelP = cauchyP->gaussSeidel(bCauchyP);
    map["CAUCHY->P - SEIDEL"] = EQM(xG, cauchyGaussSeidelP);

    vector<double> cauchyGaussM = cauchyM->gauss(bCauchyM);
    map["CAUCHY->M - GAUSS"] = EQM(xG, cauchyGaussM);
    vector<double> cauchyGaussJordanM = cauchyM->gaussJordan(bCauchyM);
    map["CAUCHY->M - GAUSS-JORDAN"] = EQM(xG, cauchyGaussJordanM);
    vector<double> cauchyLuM = cauchyM->decomposicaoLU(bCauchyM);
    map["CAUCHY->M - LU"] = EQM(xG, cauchyLuM);
    vector<double> cauchyJacobiM = cauchyM->jacobi(bCauchyM);
    map["CAUCHY->M - JACOBI"] = EQM(xG, cauchyJacobiM);
    vector<double> cauchyGaussSeidelM = cauchyM->gaussSeidel(bCauchyM);
    map["CAUCHY->M - SEIDEL"] = EQM(xG, cauchyGaussSeidelM);

    vector<double> cauchyGaussG = cauchyG->gauss(bCauchyG);
    map["CAUCHY->G - GAUSS"] = EQM(xG, cauchyGaussG);
    vector<double> cauchyGaussJordanG = cauchyG->gaussJordan(bCauchyG);
    map["CAUCHY->G - GAUSS-JORDAN"] = EQM(xG, cauchyGaussJordanG);
    vector<double> cauchyLuG = cauchyG->decomposicaoLU(bCauchyG);
    map["CAUCHY->G - LU"] = EQM(xG, cauchyLuG);
    vector<double> cauchyJacobiG = cauchyG->jacobi(bCauchyG);
    map["CAUCHY->G - JACOBI"] = EQM(xG, cauchyJacobiG);
    vector<double> cauchyGaussSeidelG = cauchyG->gaussSeidel(bCauchyG);
    map["CAUCHY->G - SEIDEL"] = EQM(xG, cauchyGaussSeidelG);


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
    map["TOEPLIZ->P - GAUSS"] = EQM(xG, toeplitzGaussP);
    vector<double> toeplitzGaussJordanP = toeplitzP->gaussJordan(bToeplitzP);
    map["TOEPLIZ->P - GAUSS-JORDAN"] = EQM(xG, toeplitzGaussJordanP);
    vector<double> toeplitzLuP = toeplitzP->decomposicaoLU(bToeplitzP);
    map["TOEPLIZ->P - LU"] = EQM(xG, toeplitzLuP);
    vector<double> toeplitzJacobiP = toeplitzP->jacobi(bToeplitzP);
    map["TOEPLIZ->P - JACOBI"] = EQM(xG, toeplitzJacobiP);
    vector<double> toeplitzGaussSeidelP = toeplitzP->gaussSeidel(bToeplitzP);
    map["TOEPLIZ->P - SEIDEL"] = EQM(xG, toeplitzGaussSeidelP);

    vector<double> toeplitzGaussM = toeplitzM->gauss(bToeplitzM);
    map["TOEPLIZ->m - GAUSS"] = EQM(xG, toeplitzGaussM);
    vector<double> toeplitzGaussJordanM = toeplitzM->gaussJordan(bToeplitzM);
    map["TOEPLIZ->M - GAUSS-JORDAN"] = EQM(xG, toeplitzGaussJordanM);
    vector<double> toeplitzLuM = toeplitzM->decomposicaoLU(bToeplitzM);
    map["TOEPLIZ->M - LU"] = EQM(xG, toeplitzLuM);
    vector<double> toeplitzJacobiM = toeplitzM->jacobi(bToeplitzM);
    map["TOEPLIZ->M - JACOBI"] = EQM(xG, toeplitzJacobiM);
    vector<double> toeplitzGaussSeidelM = toeplitzM->gaussSeidel(bToeplitzM);
    map["TOEPLIZ->M - SEIDEL"] = EQM(xG, toeplitzGaussSeidelM);

    vector<double> toeplitzGaussG = toeplitzG->gauss(bToeplitzG);
    map["TOEPLIZ->G - GAUSS"] = EQM(xG, toeplitzGaussG);
    vector<double> toeplitzGaussJordanG = toeplitzG->gaussJordan(bToeplitzG);
    map["TOEPLIZ->G - GAUSS-JORDAN"] = EQM(xG, toeplitzGaussJordanG);
    vector<double> toeplitzLuG = toeplitzG->decomposicaoLU(bToeplitzG);
    map["TOEPLIZ->G - LU"] = EQM(xG, toeplitzLuG);
    vector<double> toeplitzJacobiG = toeplitzG->jacobi(bToeplitzG);
    map["TOEPLIZ->G - JACOBI"] = EQM(xG, toeplitzJacobiG);
    vector<double> toeplitzGaussSeidelG = toeplitzG->gaussSeidel(bToeplitzG);
    map["TOEPLIZ->G - SEIDEL"] = EQM(xG,toeplitzGaussSeidelG);

    printMap(map);
    */
    
    system("pause");

}
