Algoritmo "DecomposicaoLu"
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


SubstituicoesSucessivas(L : matriz , b : vetor , int: tamanho) : vetor
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
          y[i] <- (b[i] - soma) / L[i][i]
          i <- i + 1
    até i >= n
    retorna(y)
Fimalgoritmo SubstituiçõesSucessivas


SubstituicoesRetroativas(U : matriz , y : vetor , int: tamanho) : vetor
Inicio SubstituicõesRetroativas
    n ,i , j : inteiro
    n <- tamanho
    x : vetor[tamanho] <- 0
    soma : real
    i <- n -1
    repita
          j <- i +1
          soma <- 0
          repita
                soma <- soma + U[i,j] * x[j]
                j <- j +1
          até j >= n
          x[i] <- (y[i] - soma) / U[i][i]
          i <- i - 1
    até i < 0
    retorna(x)
Fimalgoritmo SubstituiçõesRetroativas


Lu(M : matriz , b :vetor , tamanho: int) : vetor
Inicio Lu
    i,j,k,n :inteiro
    fator , elemento : real
    L : matriz[tamanho, tamanho] de real <- identidade
    n <- tamanho

    k <- 0
    repita
          i <- k + 1
          repita
                fator <- -M[i,j] / M[k,k]
                //copiar para matriz L
                elemento <- -fator
                L[i,k] <- elemento
                j <- k + 1
                repita
                      M[i,j] <- fator * M[k,j] + M[i,j]
                      j <- j +1
                até j >= n
                M[i,k] = 0
                i < i + 1
          até i >= n
          k <- k + 1
    até k >= n - 1
    U : matriz[tamanho, tamanho] <- M
    
    //resolve sistema Ly = b
    y : vetor[tamanho]
    y <- SubstituicoesSucessivas(L, b, tamanho )
    
    //resolve Ux = y
    x : vetor[tamanho]
    x <- SubstituicoesSucessivas(U, y, tamanho )
    retorna(x)
Fimalgoritmo Lu

Fimalgoritmo









































Fimalgoritmo