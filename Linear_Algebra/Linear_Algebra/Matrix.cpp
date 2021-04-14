
#include "Matrix.h"





Matrix::Matrix(Matrix* x) {
    double** aux =  new double* [x->getRows()];;
    for (int i = 0; i < x->getRows(); i++) {
        aux[i] = new double[x->getCols()];
        for (int j = 0; j < this->getCols(); j++) {
            aux[i][j] = x->m[i][j];
        }
    }
    this->nRows = x->getRows();
    this->nCols = x->getCols();
    this->m = aux;
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

void Matrix::hilbert(int size) {

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
                        double result = 1.0 / (1.0*i + j + 1.0);
                        aux[i][j] = result;
                    }
                    break;

                case 'c' :
                    for (int j = 0; j < cols; j++)
                    {
                        double result = 1.0 / (1.0*i + j + 2.0);
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
                            aux[i][j] = j+ 1.0 -i;
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

vector<double> Matrix::resolveGauss(vector<double>& b) {
    vector<double> x(b.size());
    int n = b.size();
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double multiplicador = this->m[i][k] / this->m[k][k];
            cout << "i = " << i << endl;
            cout << "k = " << k << endl;
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
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j <= n; j++) {
            sum += this->m[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / this->m[i][i];
    }
    
    this->print();


    
    return x;
}


vector<double> Matrix::gaussJordan(vector<double>& x) {

    vector<double> res(this->getRows());
    this->aumentada(x);
    int i, j, k, n =2; // declare variables and matrixes as
    //to find the elements of diagonal matrix
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

vector<int> Matrix::getP() {
    vector<int> p(this->getRows());
    for (int i = 0; i < p.size(); i++) {
        p[i] = i + 1;
    }
    return p;
}

void Matrix::id() {
    for (int i = 0; i < this->getRows(); i++) {
        this->m[i][i] = 1.0;
    }
}

vector<double> Matrix::decomposicaoLU(vector<double>& x) {
    vector<double> b(this->getRows());
    vector<int> p = this->getP();
    Matrix* L = new Matrix(this->getRows(), this->getCols());
    L->id();
    Matrix* U = new Matrix(this->getRows(), this->getCols());
    L->print();

    int n = b.size();
    
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
    return b;
}


bool checkJacobi() {
    /*
    if () {
        return false;
    }
    return true;
    */
    return true;
}

void Matrix::createXn(vector<double> &b) {
    vector<double> pivo(this->getCols());
    for (int i = 0; i < pivo.size(); i++) {
        pivo[i] = this->m[i][i];
    }

    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            if (i == j) {
                this->m[i][j] = b[i];    
            }
            else {
                this->m[i][j] = -1 * this->m[i][j] / pivo[i];
            }
        }
    }
}

vector<double> Matrix::jacobi(vector<double>& b) {
    this->createXn(b);
    vector<double> x(this->getRows(), 0.0);
    vector<double> res = x;
    vector<double> error(this->getRows(), 0.0);
    
    int stop = 3;
    int c = 0;
    
    while (c < stop) {
    /*
        for (int i = 0; i < this->getRows(); i++) {
            double result = 0.0;
            for (int j = 0; this->getRows() ; j++) {
                if (i != j) {
                    result = result + 1;//   result += this->m[i][j] * x[j];
                } else {
                    result += this->m[i][j];
                }
            }
           // res[i] = result;
        }
       // x = res;
        */
        c++;
    }
 
    return x;
}


Matrix::~Matrix() {
    for (int i = 0; i <= nRows; i++) {
        delete[] m[i];
    }
    delete[] m;
}

