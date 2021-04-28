Algoritmo "gauss"

Var
// Seção de Declarações das variáveis
//considere em uma matriz de tamanho x, o indice de acesso como x-1
// Ex: matriz[5,5] , para acessar a primeira linha e primeira coluna
// use matriz[0,0]
tamanho: inteiro //especifica tamanho do vetores e da matriz quadrada
vetB: vetor[tamanho] de real
m : matriz[tamanho, tamanho] de real
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...


SubstituicoesSucessivas(M : matriz , tamanho: inteiro) : vetor
Inicio SubstituicõesSucessivas
    n ,i , j : inteiro
    n <- tamanho
    y : vetor[tamanho] <- 0
    soma : real
    i <- 0
    repita
          j <- 0
          soma <- 0
          repita
                soma <- soma + L[i,j] * y[j]
                j <- j +1
          até j >= i
          y[i] <- (M[k][n] - soma) / L[i][i]
          i <- i + 1
    até i >= n
    retorna(y)
Fimalgoritmo SubstituiçõesSucessivas

Gauss(L :matriz, b: vetor ): vetor
Inicio Gauss
//faz aumentada
L <- L + b
k , i , j: inteiro
  multiplicador : real
  k <- 0 ,i <- 0 ,j <- 0
  //eliminação
  repita
        i <- k+1
        repita
              //m[k,k] -> refere-se aos termos da diagonal (pivôs)
              multiplicador <- m[i,k] / m[k,k]
              repita
                    //m[i,j] posicao atual
                    m[i,j] <- m[i,j] - multiplicador * m[i,j]
                    j <- j + 1
              até j >= tamanho
              //atualiza valor do vetB que compõe
              //a parte aumentada da matriz original
              vetB[i] = vetB[i] - multiplicador * M[k][n]
              i <- i + 1
        até i >= tamanho
        k <- k + 1
  até k >= tamanho
Fimalgoritmo Gauss









































Fimalgoritmo














































