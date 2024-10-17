from cpython.mem cimport PyMem_Malloc, PyMem_Free


cdef struct Nodo:
    int valor
    Nodo* izq
    Nodo* der

cdef class ArbolBusquedaBinaria:
    cdef Nodo* raiz

    def __cinit__(self):
        self.raiz = NULL
    
    def __dealloc__(self):
        self._dealloc(self.raiz)

    cdef void _dealloc(self, Nodo* nodo):
        if nodo:
            self._dealloc(nodo.izq)
            self._dealloc(nodo.der)
            PyMem_Free(nodo)

    cdef Nodo* _crear_nodo(self, int valor):
        nuevo_nodo = <Nodo*>PyMem_Malloc(sizeof(Nodo))
        nuevo_nodo.valor = valor
        nuevo_nodo.izq = NULL
        nuevo_nodo.der = NULL
        return nuevo_nodo

    cdef void insertar(self, int valor):
        if not self.raiz:
            self.raiz = self._crear_nodo(valor)
        else:
            self._insertar(self.raiz, valor)

    cdef void _insertar(self, Nodo* nodo, int valor):
        if valor < nodo.valor:
            if not nodo.izq:
                nodo.izq = self._crear_nodo(valor)
            else:
                self._insertar(nodo.izq, valor)
        else:
            if not nodo.der:
                nodo.der = self._crear_nodo(valor)
            else:
                self._insertar(nodo.der, valor)

    cdef bint buscar(self, int valor):
        return self._buscar(self.raiz, valor)

    cdef bint _buscar(self, Nodo* nodo, int valor):
        if not nodo:
            return False # type: ignore

        if valor < nodo.valor:
            return self._buscar(nodo.izq, valor)
        elif valor > nodo.valor:
            return self._buscar(nodo.der, valor)

        return True # type: ignore

    cdef void remover(self, int valor):
        self.raiz = self._remover(self.raiz, valor)

    cdef Nodo* _remover(self, Nodo* nodo, int valor):
        if not nodo:
            return nodo

        cdef Nodo* temp
        if valor < nodo.valor:
            nodo.izq = self._remover(nodo.izq, valor)
        elif valor > nodo.valor:
            nodo.der = self._remover(nodo.der, valor)
        else:
            if not nodo.izq:
                temp = nodo.der
                PyMem_Free(nodo)
                return temp
            elif not nodo.der:
                temp = nodo.izq
                PyMem_Free(nodo)
                return temp

            min_valor = self.minimo_valor(nodo.der)
            nodo.valor = min_valor
            nodo.der = self._remover(nodo.der, min_valor)

        return nodo
    
    cdef int minimo_valor(self, Nodo* nodo):
        while nodo.izq:
            nodo = nodo.izq
        
        return nodo.valor
    
    cdef void recorrido_in_orden(self):
        self._recorrido_in_orden(self.raiz)
        print()

    cdef void _recorrido_in_orden(self, Nodo* nodo):
        if nodo:
            self._recorrido_in_orden(nodo.izq)
            print(f"{nodo.valor}", end=" ")
            self._recorrido_in_orden(nodo.der)
    
    cdef int ancestro_mas_cercano(self, int nodo1, int nodo2):
        cdef Nodo* actual = self.raiz
        
        while actual:
            if nodo1 < actual.valor and nodo2 < actual.valor:
                actual = actual.izq
            elif nodo1 > actual.valor and nodo2 > actual.valor:
                actual = actual.der
            else:
                return actual.valor
        
        return -1


cpdef main():
    cdef ArbolBusquedaBinaria bst = ArbolBusquedaBinaria()
    bst.insertar(61)
    bst.insertar(49)
    bst.insertar(74)
    bst.insertar(33)
    bst.insertar(57)
    bst.insertar(65)
    bst.insertar(82)

    print("¿Está el número 7 en el árbol?:", bst.buscar(7))
    bst.insertar(7)
    print("¿Está el número 7 en el árbol?:", bst.buscar(7))

    bst.insertar(41)
    bst.insertar(50)
    bst.insertar(60)
    bst.insertar(63)
    bst.insertar(71)
    bst.insertar(79)
    bst.insertar(98)
    bst.recorrido_in_orden()

    print(
        "¿Cuál es el ancestro más cercano entre 63 y 79?",
        bst.ancestro_mas_cercano(63, 79)
    )

    bst.remover(82)
    bst.recorrido_in_orden()