
#include "Matrix.h"



Matrix::Matrix(const Matrix& that) {
    *this = that;
}

void Matrix::setSize(int rows, int cols) {
    double** aux;
    aux = new double* [rows];
    for (int i = 0; i < rows; i++) {
        aux[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            if ((j < this->nCols) && (i < this->nRows)) {
                aux[i][j] = this->m[i][j];
            }
            else {
                aux[i][j] = 0.0;
            }
            
        }
    }
    this->nCols = cols;
    this->nRows = rows;
    this->m = aux;
    
}
Matrix::Matrix(int rows, int cols) {
    double** aux;
    aux = new double* [rows];
        for (int i = 0; i < rows; i++)
        {
            aux[i] = new double[cols];
            switch (rows) {
                case 5:
                    for (int j = 0; j < cols; j++)
                    {
                        double result = 1.0 / (i + j + 1);
                        aux[i][j] = result;
                    }
                    break;
                default:
                    for (int j = 0; j < cols; j++)
                    {
                        double result = 0.000;
                        aux[i][j] = result;
                    }
                    break;
            }
            
            
        }
       
    nRows = rows;
    nCols = cols;
    m = aux;
}
Matrix::Matrix() {
    int rows, cols;
    cout << "Linhas :" << endl;
    cin >> rows;
    cout << "Colunas :" << endl;
    cin >> cols;

    double** aux = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        aux[i] = new double[cols];
        for (int j = 0; j < cols; j++)
        {
            cout << "Valor de m[" + i;
            cout << "][" + j;
            cout<< "]" << endl;
            cin >> aux[i][j];
        }
    }
    nRows = rows;
    nCols = cols;
    m = aux;
}




Matrix::Matrix(const int& size) {
    double** aux = new double* [size];
    for (int i = 1; i <= size; i++)
    {
        aux[i] = new double[size];
        for (int j = 0; j < size; j++) {
            aux[i][j] = 0;
        }
        
    }
    nRows = size;
    nCols = size;
    m = aux;
}

void Matrix::print() const {
    std::cout << std::fixed << std::setprecision(4);
    for (int i = 0; i < this->nRows; i++) {
        for (int j = 0; j < this->nCols; j++) {
            std::cout << m[i][j] << "|";
        }
        std::cout << endl;
    }
}

void Matrix::transpose() {
    Matrix matriz(*this);
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            matriz.setElement(j, i, this->m[i][j]);
        }
    }
    *this = matriz;
}

void Matrix::zeros() {
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            this->m[i][j] = 0.0;
        }
    }
}

void Matrix::ones() {
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            this->m[i][j] = 1.0;
        }
    }
}

void Matrix::unit() {
    if (this->nCols != this->nRows) {
        cout << "Impossivel fazer matriz identidade , pois nao e quadrada" << endl;
    }
    else {
        for (int i = 0; i <= this->getRows(); i++) {
            for (int j = 0; j <= this->getCols(); j++) {
                if (i == j) {
                    this->m[i][j] = 1.0;
                }
                else {
                    this->m[i][j] = 0.0;
                }

            }
        }
    }

}



void Matrix::aumentada(vector<double>& v) {
    this->setSize(this->getRows(), this->getCols() + 1 );
    for (int i = 0; i < getRows(); i++) {
        this->setElement(i, (getCols() - 1), v[i]);
    }
}

vector<double> Matrix:: resolveGauss(vector<double> &b) {
    vector<double> x(b.size());
    int n = b.size();
    for (int k = 0; k < n - 1; k++ ) {
        for (int i = k + 1; i < n; i++) {
            double multiplicador = this->m[i][k] / this->m[k][k];
            for (int j = 0; j < this->getCols(); j++) {
                this->m[i][j] = this->m[i][j] - multiplicador * this->m[k][j];
                
            }
            b[i] = b[i] - multiplicador * b[k];
        }
        
    }

        
    vector<double>::iterator it;
    for (it = b.begin(); it != b.end(); it++) {
        std::cout << std::fixed << std::setprecision(4);
        cout << "elemento: " << *it << endl;
    }

    n = n - 1;
    x[n] = b[n] / this->m[n][n];
    for (int i = n-1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j <= n; j++) {
            sum += this->m[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / this->m[i][i];
    }
    
    this->print();


    
    return x;
}


Matrix::~Matrix() {
    for (int i = 0; i <= nRows; i++) {
        delete[] m[i];
    }
    delete[] m;
}
