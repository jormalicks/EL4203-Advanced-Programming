import math

class CaminosPCB:
    def __init__(self,N,M):
        self.N = N
        self.M = M
        self.dic = {}
        
    def Recursivo(self,x=0,y=0):
        if x == self.N-1 and y == self.M-1:
            return 1

        if x >= self.N or y >= self.M:
            return 0 
        if (x,y) in self.dic:
            return self.dic[(x,y)]
    
        caminos =  self.Recursivo(x+1,y) + self.Recursivo(x,y+1)
        self.dic[(x,y)] = caminos

        return caminos
    
    def Iterativo(self):
        matriz = [[0 for i in range(self.M)] for j in range(self.N)]

        for i in range(self.N):
            matriz[i][0] = 1
        for j in range(self.M):
            matriz[0][j] = 1

        for i in range(1,self.N):
            for j in range(1,self.M):
                matriz[i][j] = matriz[i-1][j] + matriz[i][j-1]

        return matriz[self.N-1][self.M-1]
    
    def Combinatorial(self):
        return math.comb(self.N+self.M-2,self.N-1)