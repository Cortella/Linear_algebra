# -*- coding: utf-8 -*-
"""
Created on Sun Apr 25 09:19:09 2021

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

def saidel(A , b ,epsilon, interMax = 50):
    
    n= len(A)
    x = n* [0]
    v = n* [0]
    for i in range(0,n):
        for j in range(0,n):
            if i != j:
                A[i][j] = A[i][j] / A[i][i]
        b[i] = b[i] / A[i][i]
    for k in range(0, interMax):
        for i in range(0 , n):
            soma = 0
            for j in range(0,n):
                 if i != j:
                     soma = soma + A[i][j] * x[j]
            x[i] = b[i] - soma
        d = norma(x,v)
        if d <= epsilon:

            return x
        v = x[:]
A =[[5,1,1],
    [3,4,1],
    [3,3,6]]
b = [5,6,0]
eps = 0.05
x = saidel(A, b, eps)
print(x)