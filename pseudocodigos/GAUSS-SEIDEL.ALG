Algoritmo "Gauss-Seidel"
Var
// Se��o de Declara��es das vari�veis
//considere em uma matriz de tamanho x, o indice de acesso como x-1
// Ex: matriz[5,5] , para acessar a primeira linha e primeira coluna
// use matriz[0,0]
tamanho: inteiro //especifica tamanho do vetores e da matriz quadrada
vetB: vetor[tamanho] de real
m : matriz[tamanho, tamanho] de real
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...
getNorma( v : vetor , x : vetor)
inicio getNorma
n , i
n <- tamanho
maxNum, maxDen , num : real
maxNum <- 0, maxDen <- 0
i <- 0
repita
      num <- abs(v[i] - x[i])
      se num > maxNum
         maxNum <- num
      fim se
      den <- abs(v[i]) : real
      se den == 0
         continue
      senao
           se den > maxDen
              maxDen = den
           fim se
      fim senao
      i <- i + 1
at� i>=n
retorna (maxNum / maxDen)
Fimalgoritmo getNorma

jacobi( M: matriz ,b: vetor ,epsilon:real , iterMax: inteiro) : vetor
Inicio Jacobi
    n , i , j , k :inteiro
    n <- tamanho
    x[0 .. tamanho] :vetor <- 0
    v[0 .. tamanho] :vetor <- 0
    i <- 0
    repita
          j <- 0
          repita
                se i != j
                   M[i,j] = M[i,j] / M[i,i]
                fim se
                j <- j + 1
          at� j >= n
          b[i] <- b[i] / M[i,i]
          i <- i + 1
    at� i >= n
    k <- 1 ,i <- 0 , j <- 0
    repita
          repita
                s :real <- 0
                repita
                      se(i != j)
                           s <- s + M[i,j] * x[j]
                      fim se
                      j <- j+1
                at� j >= n
                x[i] <- b[i] - s
                i <- i + 1
          at� i >= n
          d : real <- getNorma(x , v)
          se d <= epsilon
             return x
          fim se
          v[0 .. tamanho] = x[0 .. tamanho ]
          k <- k +1
    at� k >= iterMax
    retorna x
Fimalgoritmo Jacobi


Fimalgoritmo