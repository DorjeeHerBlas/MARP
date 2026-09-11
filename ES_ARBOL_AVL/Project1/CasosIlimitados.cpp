/*@ <authors>
 *
 * MARP86 Nombre Apellidos
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
//#include <...>
using namespace std;

#include "bintree.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

template <typename T>
int altura(BinTree<T> const& arbol) { // mirar la altura del arbol
    if (arbol.empty()) {
        return 0; // si el arbol esta vacio devuelvo 0 
    }
    int altIzq = altura(arbol.left()); // devuelvo la altura del arbol recorriendo todo el subarbol izquierdo
    int altDer = altura(arbol.right()); // devuelvo la altura del arbol recorriendo todo el subarbol derecho 

    return 1 + max(altIzq, altDer); // devolver la altura del nodo actual
}


template <typename T>
bool equilibrado(BinTree<T> const& arbol) { // está equilibrado o no, se puede hacer un pair<bool,int>  en una función, pero mejor así que lo desgloso
    if (arbol.empty()) {
        return true;
    }

    int altIzq = altura(arbol.left());
    int altDer = altura(arbol.right());

    return abs(altIzq - altDer) <= 1
        && equilibrado(arbol.left())
        && equilibrado(arbol.right());
}

template <typename T>
T minimo(BinTree<T> const& arbol) {
    if (arbol.left().empty()) {
        return arbol.root();
    }
    else {
        return minimo(arbol.left());
    }
}

template <typename T>
T maximo(BinTree<T> const& arbol) {
    if (arbol.right().empty()) {
        return arbol.root();
    }
    else {
        return maximo(arbol.right());
    }
}

template <typename T>
bool esABB(BinTree<T> const& arbol) {
    if (arbol.empty()) {
        return true;
    }
    if (!arbol.left().empty()) {
        if (maximo(arbol.left()) >= arbol.root()) {
            return false;
        }
    }
    if (!arbol.right().empty()) {
        if (minimo(arbol.right()) <= arbol.root()) {
            return false;
        }
    }
    return esABB(arbol.left()) && esABB(arbol.right());
}


bool resuelveCaso() {

    // leer los datos de la entrada
    char tipo;
    cin >> tipo;
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    if (tipo == 'N') {
        BinTree<int> arbol = read_tree<int>(cin);

        if (equilibrado(arbol) && esABB(arbol)) {
            cout << "SI\n";
        }
        else {
            cout << "NO\n";
        }
    }
    else {
        BinTree<string> arbol = read_tree<string>(cin);

        if (equilibrado(arbol) && esABB(arbol)) {
            cout << "SI\n";
        }
        else {
            cout << "NO\n";
        }
    }
    // escribir la solución
  
    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    if (!in.is_open())
        cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}
