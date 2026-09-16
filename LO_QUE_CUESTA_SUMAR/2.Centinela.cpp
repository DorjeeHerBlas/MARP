
/*@ <authors>
 *
 * MARP86 Nombre Apellidos
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

   // leer los datos de la entrada
   int N;
   cin >> N;
  
   
   if (N == 0)
      return false;
   
   priority_queue<long long, vector<long long>, greater<long long>> colaMin; // cola de prioridad mínima  

   for(int i = 0; i < N; ++i) {
      long long numero;
      cin >> numero;
      colaMin.push(numero);
   }
   // resolver el caso posiblemente llamando a otras funciones
   long long esfuerzoTotal = 0;

   while (colaMin.size() >= 2) {  // pq necesito 2, el primero y segundo, si es empty me da igual 
      long long primero = colaMin.top(); // primer minimo
      colaMin.pop();
      long long segundo = colaMin.top(); // segundo minimo
      colaMin.pop();

      long long suma = primero + segundo;
      esfuerzoTotal += suma;
      colaMin.push(suma);
   }
   // escribir la solución
   cout << esfuerzoTotal << endl;
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
