
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

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 El problema se resuelve utilizando una cola de prioridad para almacenar los usuarios, 
 ordenados por el próximo envío y, en caso de empate, por el id del usuario. 
 El coste sería O(N log N + K log N), donde N es el número de usuarios y K (despuúes de meter el usuario id y preiodo
 en la ocla  de prioridad) es el número de envíos a realizar.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


struct Usuario{
    int id;
    int periodo;
    int proximoEnvio;

     bool operator<(Usuario const& otro) const {
        if (proximoEnvio != otro.proximoEnvio)
         return proximoEnvio > otro.proximoEnvio;
        else{
            return id > otro.id;
        }
    }
};

bool resuelveCaso() {

   // leer los datos de la entrada
   int N;
   cin >> N;

   if (N == 0)
      return false;

   priority_queue<Usuario> colaUsuarios;

   for (int i = 0; i < N; ++i) {
      int id;
      int periodo;
      cin >> id >> periodo;
   
      Usuario u = {id, periodo, periodo};
      colaUsuarios.push(u);
   }
   // K envios
   int K;
   cin >> K;
   for (int i = 0; i < K; ++i) {
      Usuario u = colaUsuarios.top();
      colaUsuarios.pop();
      cout << u.id << '\n';
      u.proximoEnvio += u.periodo;
      colaUsuarios.push(u);
   }

   cout << "---" << '\n';

   // resolver el caso posiblemente llamando a otras funciones

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
