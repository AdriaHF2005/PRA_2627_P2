#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Devuelve el beneficio maximo.
// s[i] = 1 si el objeto i entra en la mochila, 0 si no.
int mochila(const vector<int>& p, const vector<int>& b, int m, vector<int>& s) {
    int n = p.size();
    vector<vector<int>> g(n + 1, vector<int>(m + 1, 0));

    // Rellenar la tabla
    for (int i = 1; i <= n; i++) {
        for (int C = 0; C <= m; C++) {
            if (p[i - 1] > C)
                g[i][C] = g[i - 1][C];
            else
                g[i][C] = max(g[i - 1][C], b[i - 1] + g[i - 1][C - p[i - 1]]);
        }
    }

    // Recuperar la solucion
    s.assign(n, 0);
    int C = m;
    for (int i = n; i > 0; i--) {
        if (g[i][C] != g[i - 1][C]) {
            s[i - 1] = 1;
            C -= p[i - 1];
        }
    }

    return g[n][m];
}

int main() {
    vector<int> p = {9, 6, 5};
    vector<int> b = {38, 40, 24};
    int m = 15;
    vector<int> s;

    int beneficio_max = mochila(p, b, m, s);

    cout << "--- PROBLEMA DE LA MOCHILA ---" << endl;
    cout << "Beneficio maximo: " << beneficio_max << endl;
    for (size_t i = 0; i < p.size(); i++)
        cout << "  Objeto " << i << " (peso " << p[i] << ", beneficio " << b[i]
            << "): " << s[i] << endl;

    return 0;
}
