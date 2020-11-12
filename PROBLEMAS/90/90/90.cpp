//Mario Blanco E0

#include <iostream>
#include <iomanip>
#include <fstream>
#include<unordered_map>
#include<vector>

// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n,num;
    std::cin >> n;
    if (! std::cin)
        return false;
    std::unordered_map<int, int> d;
    std::vector<int> order;
    for(int i=0;i<n;++i) {
        std::cin >> num;
        if (!d.count(num)) order.push_back(num);
        d[num]++;
    }
    // escribir sol
    for (auto i : order) {
        std::cout << i << " " << d[i] << "\n";
    }
    std::cout << "---\n";
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}