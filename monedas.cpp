#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Devuelve el minimo de monedas para d (INF si no hay solucion).
// s[i] = cantidad de monedas de valor m[i].
int cambio_monedas(const vector<int>& m, int d, vector<int>& s) {
    int n = m.size();
    vector<vector<int>> T(n, vector<int>(d + 1, INF));

    // Para devolver 0 hacen falta 0 monedas
    for (int i = 0; i < n; i++) T[i][0] = 0;

    // Primera fila: solo la moneda m[0]
    for (int j = 1; j <= d; j++) {
        if (j >= m[0] && T[0][j - m[0]] != INF)
            T[0][j] = 1 + T[0][j - m[0]];
    }

    // Resto de filas
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= d; j++) {
            if (j < m[i] || T[i][j - m[i]] == INF)
                T[i][j] = T[i - 1][j];
            else if (T[i - 1][j] != INF)
                T[i][j] = min(T[i - 1][j], 1 + T[i][j - m[i]]);
            else
                T[i][j] = 1 + T[i][j - m[i]];
        }
    }

    // Recuperar la solucion
    s.assign(n, 0);
    int i = n - 1, j = d;
    while (i >= 0 && j > 0) {
        if (i == 0) {
            if (T[i][j] != INF) s[i] = j / m[i];
            break;
        }
        if (T[i][j] == T[i - 1][j]) {
            i--;            // moneda no usada
        } else {
            s[i]++;         // moneda usada
            j -= m[i];
        }
    }

    return T[n - 1][d];
}

int main() {
    vector<int> m = {1, 4, 6};
    int d = 8;
    vector<int> s;

    int min_monedas = cambio_monedas(m, d, s);

    cout << "--- CAMBIO DE MONEDAS ---" << endl;

    if (min_monedas == INF) {
        cout << "No es posible devolver esa cantidad" << endl;
        return 0;
    }

    cout << "Minimo de monedas: " << min_monedas << endl;
    for (size_t i = 0; i < m.size(); i++)
        cout << "  Moneda de " << m[i] << ": " << s[i] << endl;

    return 0;
} 
