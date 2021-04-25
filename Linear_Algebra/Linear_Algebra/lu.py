# -*- coding: utf-8 -*-
"""
Created on Sat Apr 24 19:49:31 2021

@author: bnmac
"""

def substituicoesSucessivas(A, b):
    ''' Resolve o sistema linear triangular inferior Ax = b'''
    
    ##n é a ordem da matriz A
    
    n = len(A)
    
    x = n * [0]
    for i in range(0, n):
        s = 0
        ##i menor que
        for j in range(0 , i):
            s = s +A[i][j] * x[j]
        x[i] = (b[i] - s) / A[i][i]
    return x

def identidade(n): 
    m =[]
    for i in range(0, n):
        linha = [0] * n
        linha[i] = 1
        m.append(linha)
    return m;

def lu(A):
    n = len(A)
    #inicializa matriz L com matriz identidade
    L = identidade(n)
    
    for k in range(0 , n-1):
        for i in range(k+1 , n):
            m = - A[i][k] / A[k][k]
            
            #copiar para matriz L
            L[i][k] = -m
            #calcula fator m
          
            for j in range(k + 1, n):

                A[i][j] = m * A[k][j] + A[i][j]
            
            ##zera Aik
            A[i][k] = 0
    return (L,A)

def substituicoesRetroativas(A,b):
    n = len(A)
    
    x = n *[0]
    
    for i in range(n - 1, -1 , -1):
        s = 0
        for j in range(i+1, n):
            s = s + A[i][j] * x[j]
        x[i] = (b[i] - s) / A[i][i]
    return x

def lux(L , U , b):
    y = substituicoesSucessivas(L, b)
    
    x = substituicoesRetroativas(U, y)
    
    return x

def geraHilbert(n_linhas, n_colunas):
    V=n_linhas
    matriz =  [[i  for i in range(V)] for j in range(V) ] 
    for l in range(n_linhas):
        for c in range(n_colunas):
            matriz[l][c] = 1.0/ (1.0 * l + c + 1.0)
    return matriz

def formata_matriz(M):
    m = len(M) # número de linhas
    n = len(M[0]) # número de colunas
    s = ""
    for i in range(m):
        for j in range(n):
           s += "%9.3f " % M[i][j]
        s += "\n"
    return s

def geraB(m):
    b = []
    l = len(m)
    c = len(m[0])
    for i in range(l):
        soma = 0.0
        for j in range(c):
            soma = soma + m[i][j]
        b.append(soma)
    return b

    
hilbert = geraHilbert(15,15)
b = geraB(hilbert)
print(b)
(L, U) = lu(hilbert)
print("L: \n%s" % formata_matriz(L))
print("U: \n%s" % formata_matriz(U))
x = lux(L, U, b)
print(x)

print("for in range teste")

  
    