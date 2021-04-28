Algoritmo "gaussJordan"
Var
// Seção de Declarações das variáveis
//considere em uma matriz de tamanho x, o indice de acesso como x-1
// Ex: matriz[5,5] , para acessar a primeira linha e primeira coluna
// use matriz[0,0]
tamanho: inteiro //especifica tamanho do vetores e da matriz quadrada
vetB : vetor[tamanho] de real
m : matriz[tamanho,tamanho] de real


Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
metodoDeGaussJordan( m : matriz , vetB: vetor, tamanho : inteiro )
    saida : vetor[tamanho] de real
    i,j,k, n : inteiro
    n <- tamanho
    m <- vetB
    elemento : real
    j <- 0
    repita
          i <- 0
          repita
                se (i diferente de j)
                   elemento <- m[i,j] / m[j,j]
                   k <- 0
                   repita
                         m[i,k] = m[i,k] - elemento * m[j,k]
                         k <- k +1
                   até k > n+1
                fim se
          i <- i + 1
          até i > n
    j <- j +1
    até j > n
    repita
          saida[i] <- m[i, n+1] / m [i, i]
          i <- i +1
    até i > n
    retorna(saida)

Fimalgoritmo


