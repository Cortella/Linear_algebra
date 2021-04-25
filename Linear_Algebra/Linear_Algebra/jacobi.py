# -*- coding: utf-8 -*-
"""
Created on Tue Apr 20 01:26:23 2021

@author: bnmac
"""  
import numpy as np  
from numpy import linalg  


def gaussJacobi(A,b,vetorSolucao,iteracoes):
    iteracao = 0
    vetorAuxiliar = []
    for k in range(len(vetorSolucao)):
        vetorAuxiliar.append(0)
    
    while(iteracao < iteracoes):
        for i in range(len(A)):
            x = b[i]
            for j in range(len(A)):
                if i != j:
                    x -= A[i][j]*vetorSolucao[j]
            x /= A[i][i]
            vetorAuxiliar[i] = x
            iteracao += 1
            
        for p in range(len(vetorAuxiliar)):
            vetorSolucao[p] = vetorAuxiliar[p]
                
    print(vetorSolucao)

l1 = 1+1/2+1/3+1/4+1/5
l2 = 1/2+1/3+1/4+1/5+1/6
l3 = 1/3+1/4+1/5+1/6+1/7
l4 = 1/4+1/5+1/6+1/7+1/8
l5 = 1/5+1/6+1/7+1/8+1/9
print(l1,l2,l3,l4,l5)


gaussJacobi([[1.0,1/2,1/3,1/4,1/5],
             [0.5,1/3,1/4,1/5, 1/6],
             [1/3,1/4,1/5, 1/6,1/7],
             [1/4,1/5, 1/6,1/7,1/8],
             [1/5, 1/6,1/7,1/8,1/9]],
             [l1,l2,l3,l4,l5], [0.0,0.0,0.0,0.0,0.0], 50)

