// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <vector>
#include <fstream>
#include <iostream>
#include "hashmap_eda.h"

int resolver(const std::vector<int>& cap) {
    unordered_map <int, int> dicc;
    int maximo = 0, inicio=0;
    for (int i = 0;i < cap.size();++i) {
        if (dicc.count(cap[i]) != 0 && dicc[cap[i]]>=inicio) {
            if (i - inicio > maximo)maximo = i - inicio;
            inicio = dicc[cap[i]]+1;
        }
        dicc[cap[i]] = i;
    }
    if (cap.size() - inicio > maximo) return cap.size() - inicio;
    return maximo;
}
void resuelveCaso() {

    int n;
    std::cin >> n;
    std::vector<int> cap(n);
    for (int& i : cap) std::cin >> i;
    std::cout << resolver(cap) << '\n';
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
     int numCasos;
     std::cin >> numCasos;
     for (int i = 0; i < numCasos; ++i)
         resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}