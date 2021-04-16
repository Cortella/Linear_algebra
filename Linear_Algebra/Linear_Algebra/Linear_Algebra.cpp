// Linear_Algebra.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "Matrix.h"
#include <stdlib.h>

#define HILBERT 'h'
#define VANDERMOND 'v'
#define CAUCHY 'c'
#define TOEPLITZ 't'

void printVector(vector<double> m) {
    vector<double>::iterator i;
    for (i = m.begin(); i != m.end(); i++) {
        cout << *i << endl;
    }
}

int main()
{
    
    
    Matrix *m = new Matrix(3,3);
   
 
    m->setElement(0, 0, 10.0);
    m->setElement(0, 1, 2.0);
    m->setElement(0, 2, 1.0);


    m->setElement(1, 0, 1.0);
    m->setElement(1, 1, 5.0);
    m->setElement(1, 2, 1.0);


    m->setElement(2, 0, 2.0);
    m->setElement(2, 1, 3.0);
    m->setElement(2, 2, 10.0);

 
    
    


    vector<double> b = {7.0, -8.0, 6.0};
    vector<double> res = m->gaussSeidel(b);
    //printVector(res);
    //m->print();

    
   // m->print();
    
    
    
    
    // m->aumentada(x);
    // m->print();
   
    system("pause");

}

    
    
 

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
