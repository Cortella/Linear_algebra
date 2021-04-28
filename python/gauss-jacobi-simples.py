# -*- coding: utf-8 -*-
"""
Created on Sun Apr 25 01:20:28 2021

@author: bnmac
"""

def norma(v,x):
    '''calcula norma entre dois vetores'''
    n = len(v)
    maxNum = 0
    maxDen = 0
    for i in range(0, n):
            num = abs(v[i] - x[i])
            if num >maxNum:
                maxNum = num
            den = abs(v[i])
            if den > maxDen:
                maxDen = den
    return maxNum /maxDen


#transformando sistem Ax =b em x = Cx +g

def geraHilbert(n_linhas, n_colunas):
    V=n_linhas
    matriz =  [[i  for i in range(V)] for j in range(V) ] 
    for l in range(n_linhas):
        for c in range(n_colunas):
            matriz[l][c] = 1.0/ (1.0 * l + c + 1.0)
    return matriz

def getVandermond(n_linhas, n_colunas):
    base = [];
    for i in range(0,n_linhas):
        base.append(i+1)
    
    V=n_linhas
    matriz =  [[i  for i in range(V)] for j in range(V) ] 
    for i in range(n_linhas):
        for j in range(n_colunas):
            if (i == 0):
                matriz[i][j] = 1.0
            elif (i == 1):
                matriz[i][j] = base[j]
            else:
                matriz[i][j] = 0.0
                matriz[i][j] = pow(base[j], i)     
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

def getB(m):
    b = []
    l = len(m)
    c = len(m[0])
    for i in range(l):
        soma = 0.0
        for j in range(c):
            soma = soma + m[i][j]
        b.append(soma)
    return b

def jacobi(A,b, epsilon = 0, interMax =3):
    '''Resolve sistema linear Ax =b usando gauss -Jacobi '''
    n = len(A)
    x = n * [0]
    v = n * [0]
    
    for i in range(0, n):
        for j in range(0,n):
            if i != j:
                #supondo que todos os elementos da diag principal deve ser diferentes de 0
                A[i][j] = A[i][j] / A[i][i]
        b[i] = b[i] / A[i][i]
        #inicializar vetor x  com aproximacao inicial bi / Aii
    #slicing x = b
    x = b[:]
    
    #iteracoes
    #somatorio de Aij * xj
    #atual bi - somatorio
    for k in range(0, interMax):
        for i in range(0 ,n):
            soma = 0
            for j in range(0,n):
                if( i != j):
                    soma = soma + A[i][j] * x[j]
            v[i] = b[i] - soma
        d = norma(v, x)
        print("iteracao = ", k)
        print(v)
        if((d <= epsilon) or (k == 9)):
            return v
        
        x = v[:]
        
        
        


HILBERT = geraHilbert(5,5)


print("V: \n%s" % formata_matriz(HILBERT))
b = getB(HILBERT)
print(b)
res = jacobi(HILBERT, b,0.05)
print(res)
    