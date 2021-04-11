// Linear_Algebra.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "Matrix.h"
#include <stdlib.h>

void printVector(vector<double> m) {
    vector<double>::iterator i;
    for (i = m.begin(); i != m.end(); i++) {
        cout << *i << endl;
    }
}

int main()
{
    

    Matrix *m = new Matrix(3,3);
    m->setElement(0, 0, 3.0);
    m->setElement(0, 1, 2.0);
    m->setElement(0, 2, 4.0);
   // m->setElement(0, 3, 1.7);
    m->setElement(1, 0, 1.0);
    m->setElement(1, 1, 1.0);
    m->setElement(1, 2, 2.0);
  //  m->setElement(1, 3, 3.5);
    m->setElement(2, 0, 4.0);
    m->setElement(2, 1, 3.0);
    m->setElement(2, 2, -2.0);
  //  m->setElement(2, 3, 5.0);
  //  m->setElement(3, 0, 4.5);
  //  m->setElement(3, 1, -4.0);
  //  m->setElement(3, 2, 2.5);
  //  m->setElement(3, 3, 1.5);
    


    vector<double> b = { 1.0, 2.0, 3.0 };
    vector<double> res = m->resolveGauss(b);
    printVector(res);
    
    
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
