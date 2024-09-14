# Preguntas Teóricas

**¿Qué es un paradigma de programación?**

Un paradigma de programación es un enfoque o estilo particular para resolver problemas mediante la escritura de programas de computadora. Estos paradigmas definen la forma en que los programadores organizan y estructuran su código. Algunos de los paradigmas más conocidos son el imperativo, orientado a objetos, funcional y lógico. El paradigma imperativo, por ejemplo, se basa en la idea de ejecutar instrucciones secuenciales para modificar el estado de un programa, mientras que el paradigma funcional enfatiza la inmutabilidad y el uso de funciones puras. La elección de un paradigma influye en cómo se resuelven los problemas y cómo se estructura el código, teniendo un impacto significativo en la eficiencia, legibilidad y mantenibilidad del software.

**¿En qué se basa la programación orientada a objetos?**

La programación orientada a objetos (POO) se basa en la organización del código en torno a "objetos", que son instancias de clases que encapsulan tanto datos como comportamientos (métodos). Los principios fundamentales de la POO son la encapsulación, que protege los datos dentro de un objeto; la herencia, que permite a las clases derivadas heredar atributos y métodos de una clase base; el polimorfismo, que permite tratar objetos de diferentes clases de manera uniforme; y la abstracción, que facilita la simplificación de los detalles complejos del sistema. Este paradigma es útil para modelar sistemas complejos al dividirlos en objetos interactivos que pueden reflejar entidades del mundo real o abstracciones lógicas.

**¿Cuál es la diferencia entre recursividad e iteración, y cómo se relaciona esto con la notación big 𝑂?**

Recursividad e iteración son dos enfoques diferentes para repetir una secuencia de operaciones. En la recursividad, una función se llama a sí misma para resolver un problema más pequeño del mismo tipo, mientras que en la iteración, se usa una estructura repetitiva (como un bucle for o while) para repetir el código hasta cumplir una condición. En términos de complejidad algorítmica, ambos enfoques pueden tener distintos rendimientos según el problema. La notación Big O se utiliza para expresar el tiempo de ejecución o el espacio utilizado por un algoritmo en función del tamaño de la entrada. Por ejemplo, un algoritmo recursivo que se llama a sí mismo n veces puede tener una complejidad de O(n), similar a un bucle iterativo. Sin embargo, algunos problemas, como la búsqueda en estructuras arborescentes, son más adecuados para soluciones recursivas que iterativas, ya que la recursividad puede simplificar la lógica.

**Explicar la diferencia de rendimiento entre 𝑂(1) y 𝑂(𝑛)**

La notación O(1) indica que un algoritmo tiene una complejidad constante, es decir, su tiempo de ejecución no depende del tamaño de la entrada. Un ejemplo típico es acceder a un elemento en una lista utilizando un índice, ya que este acceso tiene el mismo costo independientemente del tamaño de la lista. Por otro lado, O(n) representa una complejidad lineal, lo que significa que el tiempo de ejecución del algoritmo aumenta proporcionalmente con el tamaño de la entrada. Un ejemplo de esto sería recorrer una lista de n elementos, ya que cada elemento debe ser visitado una vez. Claramente, O(1) es más eficiente que O(n), ya que en escenarios con grandes entradas, el algoritmo con complejidad O(n) consumirá más tiempo y recursos.

**¿Cómo se calcula el orden en un programa que funciona por etapas?**

En un programa que funciona por etapas, el orden o complejidad temporal total puede calcularse sumando o multiplicando las complejidades de cada etapa, dependiendo de cómo interactúen. Si las etapas son secuenciales y cada una tiene una complejidad O(f(n)), O(g(n)), etc., entonces la complejidad total será el máximo de estas complejidades (por ejemplo, O(max(f(n), g(n)))). Si una etapa anida otra, entonces las complejidades se multiplican. Por ejemplo, si un bucle tiene complejidad O(n) y dentro de este hay una operación que tiene complejidad O(n^2), la complejidad total será O(n * n^2) = O(n^3).

**¿Cómo se puede determinar la complejidad temporal de un algoritmo recursivo?**

Para determinar la complejidad temporal de un algoritmo recursivo, se suele usar el método de las ecuaciones de recurrencia. Este método implica definir una ecuación que describa cómo el tamaño del problema disminuye en cada llamada recursiva y cuántas operaciones adicionales se realizan. Por ejemplo, en el caso de la búsqueda binaria, que divide el problema a la mitad en cada paso, la ecuación de recurrencia sería T(n) = T(n/2) + O(1), lo que indica que el problema se reduce a la mitad en cada paso, con un costo constante adicional. Al resolver la ecuación de recurrencia, se puede determinar que la complejidad temporal es O(log n). Para algoritmos recursivos más complejos, se pueden usar métodos como el Teorema Maestro, que facilita la solución de ecuaciones de recurrencia de forma sistemática.


