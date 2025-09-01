#include <bits/stdc++.h>
using namespace std;


long long convertToDecimal(const string &value, int base) {
    long long result = 0;
    for (char c : value) {
        int digit;
        if (isdigit(c)) digit = c - '0';
        else if (isalpha(c)) digit = tolower(c) - 'a' + 10; 
        else digit = 0;
        result = result * base + digit;
    }
    return result;
}

vector<long long> buildPolynomial(const vector<long long> &roots) {
    int degree = roots.size();
    vector<long long> coeffs(degree + 1, 0);
    coeffs[0] = 1; 

    for (long long root : roots) {
        vector<long long> newCoeffs(degree + 1, 0);
        for (int i = 0; i < coeffs.size(); i++) {
            newCoeffs[i] += coeffs[i];
            newCoeffs[i + 1] -= coeffs[i] * root;
        }
        coeffs = newCoeffs;
    }
    return coeffs;
}

int main() {
    int n, k;
    cin>>n>>k;

    vector<long long> roots;

    for (int i = 0; i < n; i++) {
        int base;
        string value;
        cin >> base >> value;
        long long decimal = convertToDecimal(value, base);
        roots.push_back(decimal);
    }

    vector<long long> selected(roots.begin(), roots.begin() + k);

    vector<long long> coeffs = buildPolynomial(selected);

    cout << "Polynomial coefficients:" << endl;
    for (long long c : coeffs) cout << c << " ";
    cout << endl;

    return 0;
}