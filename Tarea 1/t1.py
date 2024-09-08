import math
import time
from time import perf_counter

# Implementar decorador para medir tiempo
def medir_tiempo(func):
    def wrapper(*args, **kwargs):
        inicio = time.perf_counter()
        resultado = func(*args, **kwargs)
        fin = time.perf_counter()
        tiempo_ejecucion = fin - inicio
        wrapper.tiempo_ejecucion = tiempo_ejecucion  # Guardar tiempo de ejecución en wrapper
        print(f"Tiempo de ejecución de {func.__name__}: {tiempo_ejecucion:.6f} segundos")
        return resultado
    wrapper.tiempo_ejecucion = 0  # Inicializamos el tiempo de ejecución
    wrapper.func = func  # Guardamos la referencia a la función original
    return wrapper

# Implementar clase
class CaminosPCB:
    def __init__(self,N,M):
        self.N = N # Número de filas
        self.M = M # Número de columnas
        self.matrix = [[0 for i in range(M)] for j in range(N)] # Grilla para Iterativo
        self.dic = {} # Diccionario para Recursivo

    def Recursivo(self,i=0,j=0): 
        # Caso base 1: Ya estamos en la celda B
        if i == self.N-1 and j == self.M-1:
            return 1
        # Caso base 2: Nos salimos de la grilla
        if i >= self.N or j >= self.M:
            return 0
        # Si ya se ha calculado el número de caminos para esta celda, retornar el valor
        if (i,j) in self.dic:
            return self.dic[(i,j)]
        
        # Llamado recursivo: Sumar los caminos de la celda a la derecha y de la celda de abajo
        caminos = self.Recursivo(i+1,j) + self.Recursivo(i,j+1)
        self.dic[(i,j)] = caminos # Almacenar el número de caminos en el diccionario

        # Finalmente, retorno el número de caminos para llegar a la celda B
        return caminos
    
    def Iterativo(self):
        # Inicializar la primera fila y la primera columna con 1s. Puesto que solo hay un camino 
        # para llegar a estas celdas dadas las restricciones de movilidad del problema
        for i in range(self.N):
            self.matrix[i][0] = 1
        for j in range(self.M):
            self.matrix[0][j] = 1
        
        # El resto de la matriz se llena sumando el número de caminos de la celda de arriba 
        # y de la celda de la izquierda
        for i in range(1,self.N):
            for j in range(1,self.M):
                self.matrix[i][j] = self.matrix[i-1][j] + self.matrix[i][j-1]
        
        # Retorno el número de caminos para llegar a la celda B
        return self.matrix[self.N-1][self.M-1]
    
    def Combinatorial(self):
        # Para llegar a B necesito N-1 movimientos hacia abajo y M-1 movimientos hacia la derecha
        # Por lo tanto, el número total de movimientos es N+M-2
        # Luego, el número de caminos posibles es el número de combinaciones de N+M-2 tomados de a N-1
        return math.comb(self.N+self.M-2,self.N-1)
    
    @medir_tiempo
    # Método para seleccionar alguna de las 3 soluciones planteadas
    def solve(self, solver="Combinatorial"): # Por defecto, uso la solución Combinatorial por ser la más eficiente
        if solver == "Recursivo":
            return self.Recursivo()
        elif solver == "Iterativo":
            return self.Iterativo()
        elif solver == "Combinatorial":
            return self.Combinatorial()
        else:
            raise ValueError("Solución no reconocida. Usa 'Recursivo', 'Iterativo' o 'Combinatorial'")