#include "Matrix.h"

//Construtores
Matrix::Matrix() {
    int rows = 0, cols = 0;
    double** aux = new double* [rows];
    nRows = rows;
    nCols = cols;
    m = aux;
}

Matrix::Matrix(int rows, int cols, char mat) {
    double** aux;
    aux = new double* [cols];
    vector<double> base;
    double value;
    for (int i = 0; i < rows; i++) {
        base.push_back(1.0 + i);
    }

    for (int i = 0; i < rows; i++)
    {
        aux[i] = new double[cols];
        switch (mat) {
        case 'h':
            for (int j = 0; j < cols; j++)
            {
                double result = 1.0 / (1.0 * i + j + 1.0);
                aux[i][j] = result;
            }
            break;

        case 'c':
            for (int j = 0; j < cols; j++)
            {
                double result = 1.0 / (1.0 * i + j + 2.0);
                aux[i][j] = result;
            }
            break;
        case 'v':

            for (int j = 0; j < cols; j++)
            {
                if (i == 0) {
                    aux[i][j] = 1.0;
                }
                else if (i == 1) {
                    aux[i][j] = base[j];
                }
                else {
                    aux[i][j] = 0.0;
                    aux[i][j] = pow(base[j], i);
                }

            }
            break;
        case 't':
            for (int j = 0; j < cols; j++)
            {
                if (i == j) {
                    aux[i][j] = 1.0;
                }
                else if (j < i) {
                    aux[i][j] = base.back() + j + 1.0;
                }
                else {
                    aux[i][j] = j + 1.0 - i;
                }
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


//Setters
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


//Geters

void Matrix::print() const {
    
    for (int i = 0; i < this->nRows; i++) {
        for (int j = 0; j < this->nCols; j++) {
            std::cout << m[i][j] << "|";
        }
        std::cout << endl;
    }
}


Matrix& Matrix::operator=(Matrix& m) {

    this->setSize(m.getRows(), m.getCols());
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            this->m[i][j] = m.getElement(i, j);
        }
    }

    return *this;
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


vector<double> Matrix::getB() {
    vector<double> b(this->getRows());
    for (int i = 0; i < this->getRows(); i++) {
        double sum = 0.0;
        for (int j = 0; j < this->getCols(); j++) {
            sum += this->m[i][j];
        }
        b[i] = sum;
    }
    return b;
}

void Matrix::aumentada(vector<double>& v) {
    this->setSize(this->getRows(), this->getCols() + 1 );
    for (int i = 0; i < getRows(); i++) {
        this->setElement(i, (getCols() - 1), v[i]);
    }
}


vector<double> Matrix::gauss(vector<double>& b) {
    Matrix *aux = new Matrix();
    *aux = *this;
    vector<double> x(b.size());
    int n = b.size();
    auto begin = std::chrono::high_resolution_clock::now();
    //eliminacao
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double multiplicador = this->m[i][k] / this->m[k][k];
            for (int j = 0; j < this->getCols(); j++) {
                this->m[i][j] = this->m[i][j] - multiplicador * this->m[k][j];

            }
            b[i] = b[i] - multiplicador * b[k];
        }

    }

    //substituicoes sucessivas
    n = n - 1;
    x[n] = b[n] / this->m[n][n];
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j <= n; j++) {
            sum += this->m[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / this->m[i][i];
    }
    auto end = std::chrono::high_resolution_clock::now() - begin;
    long long miliSeconds = std::chrono::duration_cast<std::chrono::microseconds>(end).count();
    cout << "Tempo de execucao do metodo de Gauss matriz " << this->getRows() << " X " << this->getCols() << " " << miliSeconds << "ms" << endl;;
    *this = *aux;
    return x;
}


vector<double> Matrix::gaussJordan(vector<double>& x) {

    vector<double> res(this->getRows());
    this->aumentada(x);
    int i, j, k, n =2; // declare variables and matrixes as
    double element;
    for (j = 0; j <= n; j++) {
        for (i = 0; i <= n; i++) {
            if (i != j) {
                element = this->m[i][j] / this->m[j][j];
                for (k = 0; k <= n + 1; k++) {
                    this->m[i][k] = this->m[i][k] - element * this->m[j][k];
                }
            }
        }
    }
    cout << "\nThe solution is:\n";
    for (i = 0; i <= n; i++) {
        res[i] = this->m[i][n + 1] / this->m[i][i];
        cout << "x" << i << "=" << res[i] << " ";
    }
    return res;
}

void Matrix::id() {
    for (int i = 0; i < this->getRows(); i++) {
        this->m[i][i] = 1.0;
    }
}


vector<double> Matrix::decomposicaoLU(vector<double>& b) {
    Matrix* aux = new Matrix();
    *aux = *this;
    vector<double> y(this->getRows(), 1.0);
    vector<double> x(this->getRows(), 1.0);
    
    Matrix* L = new Matrix(this->getRows(), this->getCols());
    L->id();
    Matrix* U = new Matrix(this->getRows(), this->getCols());

    int n = b.size();
    auto begin = std::chrono::high_resolution_clock::now();
    //get LU
    for (int k = 0; k < n - 1; k++) {
        double pivo = this->m[k][k];
        for (int i = k + 1; i < n; i++) {
            double multiplicador = this->m[i][k] / pivo;
            L->m[i][k] = multiplicador;
            for (int j = 0; j < this->getCols(); j++) {
                this->m[i][j] = this->m[i][j] - multiplicador * this->m[k][j];
            }
        }
    }
   *U = *this;
    //resolve Ly = b
    for (int i = 0; i < L->getRows(); i++) {
        double result =0.0;
        for (int j = 0; j < L->getCols(); j++) {
            if (i != j) {
                result += L->m[i][j] * y[j];
            } 
        }
        y[i] = b[i] - result;    
    }

    //resolve ux = y
    n = n - 1;
    x[n] = y[n] / U->getElement(n,n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j <= n; j++) {
            sum += U->getElement(i,j) * x[j];
        }
        x[i] = (y[i] - sum) / U->getElement(i,i);
    }
    auto end = std::chrono::high_resolution_clock::now() - begin;
    long long miliSeconds = std::chrono::duration_cast<std::chrono::microseconds>(end).count();
    cout << "Tempo de execucao decomposicao LU matriz " << this->getRows() << " X " << this->getCols() << " " << miliSeconds << "ms" << endl;
    *this = *aux;
    return b;
}

vector<double> Matrix::getG(vector<double>& b) {
    vector<double> g;
    for (int i = 0; i < this->getRows(); i++) {
        double pivo = this->m[i][i];
        for (int j = 0; j < this->getCols(); j++) {
            if (i == j) {
                this->m[i][j] = 0.0;
            }
            else {
                this->m[i][j] = -1 * this->m[i][j] / pivo;
            }
        }
        g.push_back(b[i] / pivo);
    }
    return g;
}

vector<double> Matrix::getX(vector<double>& x, vector<double> &g) {
    vector<double> x1;
    for (int i = 0; i < this->getRows(); i++) {
        double result = 0.0;
        for (int j = 0; j < this->getCols(); j++) {
            result += this->m[i][j] * x[j];      
        }
        result += g[i];
        x1.push_back(result);
    }
    
    return x1;
}


vector<double> Matrix::jacobi(vector<double>& b) {
    vector<double> g = this->getG(b);
    vector<double> x(b.size(), 0.0);
    vector<double> x1;

    auto begin = std::chrono::high_resolution_clock::now();
    int stop = 50;
    int  c = 0;
    while (c < stop) {
        x1 = getX(x,g);
        x = x1;
        c++;
    }
    auto end = std::chrono::high_resolution_clock::now() - begin;
    long long miliSeconds = std::chrono::duration_cast<std::chrono::microseconds>(end).count();
    cout << "Tempo de execucao jacobi matriz " << this->getRows() << " X " << this->getCols() << " " << miliSeconds << "ms" << endl;
    return x;
}


vector<double> Matrix::gaussSeidel(vector<double>& b) {
    vector<double> x;
    for (int i = 0; i < this->getRows(); i++) {
        x.push_back(b[i] / this->m[i][i]);
    }

    auto begin = std::chrono::high_resolution_clock::now();
    vector<double> g = this->getG(b);

    int stop = 2;
    int  c = 0;
    while (c < stop) {
        for (int i = 0; i < this->getRows(); i++) {
            double result = 0.0;
            for (int j = 0; j < this->getCols(); j++) {
                result += this->m[i][j] * x[j];
            }
            result += g[i];
            x[i] = result;
        }

        c++;
    }
    auto end = std::chrono::high_resolution_clock::now() - begin;
    long long miliSeconds = std::chrono::duration_cast<std::chrono::microseconds>(end).count();
    cout << "Tempo de execucao Gauss-Seidel matriz " << this->getRows() << " X " << this->getCols() << " " << miliSeconds << "ms" << endl;
    return x;
}

//Destrutor
Matrix::~Matrix() {
    for (int i = 0; i <= nRows; i++) {
        delete[] m[i];
    }
    delete[] m;
}

