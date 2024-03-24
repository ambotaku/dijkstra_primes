#include <vector>
#include <iostream>

using namespace std;

typedef long unsigned int ulong;

//
// Primzahlenberechnung nach einem Algorithmus von  Edsger W. Dijkstra
//
class DijkstraPrimes {
private:
    // speichert das letzt erreichte Vielfache einer zugehörigen Primzahl
    vector<ulong> pool = {4};
public:
    // speichert alle gefundenen Primzahlen
    vector<ulong> primes = {2};

    // Aufruf mit Bereichsende
    DijkstraPrimes(ulong last) {
        // iteriere den gesamten Test-Zahlenbereich
        for (ulong test = 3; test <= last; ++test) {
            bool isPrim = true; // wird zurückgesetzt, wenn Teiler gefunden
            // suche nach bereits erreichten Primzahl - Vielfachen
            for (ulong index = 0; index < pool.size() - 1; ++index) {
                // aktualisiere gefundenen Teiler
                if (pool[index] == test) {
                    pool[index] += primes[index];
                    isPrim = false; // Teiler gefunden
                }
            }
            // eine Primzahl wurde gefunden
            if (isPrim) {
                // trage sie und ihr Quadrat in Pool ein
                primes.push_back(test);
                pool.push_back(test * test);
                //cout << test;
            }
        }
    }
};

int main() {
    auto dijkstra = DijkstraPrimes(10000);
    auto primes = dijkstra.primes;

    cout <<  "primes" << endl;
    for(auto it = primes.begin(); it != primes.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
