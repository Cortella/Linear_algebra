#include "Matrix.h"
#include <stdlib.h>
#include <conio.h>


#define HILBERT 'h'
#define VANDERMOND 'v'
#define CAUCHY 'c'
#define TOEPLITZ 't'

using std::iterator;

void printVector(vector<double> m) {
    cout << "--inicio do vetor--" << endl;
    vector<double>::iterator i;
    cout << std::fixed << std::setprecision(7);
    for (i = m.begin(); i != m.end(); i++) {
        cout << *i << endl;
    }
    cout << "--fim do vetor--" << endl;
}

double EQM(vector<double> ones, vector<double> obtidos) {
    double eqm = 0.0;
    for (int i = 0; i < obtidos.size(); i++) {
        eqm += fabs(pow((ones[i] - obtidos[i]), 2));
    }
    return eqm;
}

void analisar(Matrix* m) {
    
    vector<double> x(m->getRows(), 1.0);

    vector<double> b = m->getB();
    cout << "--------------------------------------------------" << endl;
    cout << "PARA METODO DE GAUSS" << endl;
    vector<double> gauss = m->gauss(b);
    printVector(gauss);
    cout << "EQM PARA GAUSS = " << EQM(x, gauss);
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "PARA METODO DE GAUSS-JORDAN" << endl;
    vector<double> gaussJordan = m->gaussJordan(b);
    printVector(gaussJordan);
    cout << "EQM PARA GAUSS-JORDAN = " << EQM(x, gaussJordan);
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "PARA METODO DE DECOMPOSICAO LU" << endl;
    vector<double> lu = m->lu(b);
    printVector(lu);
    cout << "EQM PARA LU = " << EQM(x, lu);
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    //iterativos
    cout << "PARA METODO DE JACOBI" << endl;
    vector<double> jacobi = m->jacobi(b);
    printVector(jacobi);
    cout << "EQM PARA JACOBI = " << EQM(x, jacobi);
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "PARA METODO DE GAUSS-SEIDEL" << endl;
    vector<double> seidel = m->seidel(b);
    printVector(seidel);
    cout << "EQM PARA SEIDEL = " << EQM(x, seidel);
    cout << "--------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}



int main()
{
   
    cout << "----------------------------------------" << endl;
    cout << "ANALIZANDO MATRIZES DE HILBERT" << endl;
    cout << endl;

    cout << "HILBERT 5X5 :" << endl;
    Matrix* hilbertP = new Matrix(5, 5, HILBERT);
    cout << "\n\n";
    analisar(hilbertP);

    cout << "HILBERT 10 X 10: " << endl;
    Matrix* hilbertM = new Matrix(10, 10, HILBERT);
    cout << "\n\n";
    analisar(hilbertM);

    cout << "HILBERT 15 X 15: " << endl;
    Matrix* hilbertG = new Matrix(15, 15, HILBERT);
    cout << "\n\n";
    analisar(hilbertG);



    cout << "----------------------------------------" << endl;
    cout << "ANALIZANDO MATRIZES DE VANDERMOND" << endl;
    cout << endl;


    cout << "VANDERMOND 5X5 :" << endl;
    Matrix* vandermondP = new Matrix(5, 5, VANDERMOND);
    cout << "\n\n";
    analisar(vandermondP);

    cout << "VANDERMONDT 10 X 10: " << endl;
    Matrix* vandermondM = new Matrix(10, 10, VANDERMOND);
    cout << "\n\n";
    analisar(vandermondM);

    cout << "VANDERMOND 15 X 15: " << endl;
    Matrix* vandermondG = new Matrix(15, 15, VANDERMOND);
    cout << "\n\n";
    analisar(vandermondG);

    

    cout << "----------------------------------------" << endl;
    cout << "ANALIZANDO MATRIZES DE CAUCHY" << endl;
    cout << endl;


    cout << "CAUCHY 5X5 :" << endl;
    Matrix* cauchyP = new Matrix(5, 5, CAUCHY);
    cout << "\n\n";
    analisar(cauchyP);

    cout << "CAUCHY 10 X 10: " << endl;
    Matrix* cauchyM = new Matrix(10, 10, CAUCHY);
    cout << "\n\n";
    analisar(cauchyM);

    cout << "CAUCHY 15 X 15: " << endl;
    Matrix* cauchyG = new Matrix(15, 15, CAUCHY);
    cout << "\n\n";
    analisar(cauchyG);

    cout << "----------------------------------------" << endl;
    cout << "ANALIZANDO MATRIZES DE TOEPLITZ" << endl;
    cout << endl;

    cout << "TOEPLITZ 5X5 :" << endl;
    Matrix* toeplitzP = new Matrix(10, 10, TOEPLITZ);
    cout << "\n\n";
    analisar(toeplitzP);

    cout << "TOEPLITZ 10 X 10: " << endl;
    Matrix* toeplitzM = new Matrix(10, 10, TOEPLITZ);
    cout << "\n\n";
    analisar(toeplitzM);

    cout << "TOEPLITZ 15 X 15: " << endl;
    Matrix* toeplitzG = new Matrix(15, 15, TOEPLITZ);
    cout << "\n\n";
    analisar(toeplitzG);


    system("pause");

}
