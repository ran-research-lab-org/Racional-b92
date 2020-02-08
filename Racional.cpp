
// Rafael A. Arce Nazario
//
// Implementación de la clase Racional

#include "Racional.h"
#include <algorithm>
#include <iostream>
using namespace std;
Racional::Racional() : p(0), q(1) {
}

Racional::Racional(int pa, int qa) : p(pa), q(qa) {
}

int Racional::getP() const {
    return p;
}

int Racional::getQ() const {
    return q;
}

void Racional::simplificar() {
    int g = __gcd(p,q);
    p = p / g;
    q = q / g;
}

void Racional::operator~() {
    int g = __gcd(p,q);
    p = p / g;
    q = q / g;
}

Racional Racional::suma(const Racional &r) const {
    return Racional((p * r.q) + (q * r.p) , q * r.q);
}


Racional Racional::operator+(const Racional &r) const {
    return Racional((p * r.q) + (q * r.p) , q * r.q);
}

Racional Racional::operator+(int a) const {
    return Racional((p) + (q * a) , q );
}

Racional operator+(int a, const Racional &r) {
    return Racional((a * r.getQ()) + (r.getP()) ,  r.getQ());
}

Racional suma(const Racional &r1, const Racional &r2) {
    return Racional((r1.getP() * r2.getQ()) + (r1.getQ() * r2.getP()) , r1.getP() * r2.getQ());
}

bool Racional::gt(const Racional &r) const {
    return  p * r.q > q * r.p ;
}

bool Racional::operator>(const Racional &r) const {
    return  p * r.q > q * r.p ;
}

void Racional::display() const {
    cout << p << " / " << q << endl;
}

bool  Racional::operator==(const Racional &r) const {
    return (p * r.q) == (q * r.p);
}

Racional Racional::operator ++(int dummy) {
    int oldP = p;
    p += q;
    return Racional(oldP, q);
}