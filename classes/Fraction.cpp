#include "Fraction.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

Fraction::Fraction() : whole(0), fractional(0) {}

Fraction::Fraction(long wholePart, unsigned short fractionalPart) {
    setWhole(wholePart);
    setFractional(fractionalPart);
}

Fraction::Fraction(const Fraction& other) {
    *this = other;
}

bool Fraction::setWhole(long value) {
    whole = value;
    return true;
}

bool Fraction::setFractional(unsigned short value) {
    if (value < 0) {
        cout << "Error: Fractional part cannot be negative.\n";
        return false;
    }
    fractional = value;
    return true;
}

Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        whole = other.whole;
        fractional = other.fractional;
    }
    return *this;
}

Fraction::operator std::string() const {
    stringstream ss;
    ss << whole << "." << setw(5) << setfill('0') << fractional;
    return ss.str();
}

Fraction& Fraction::operator++() {
    whole++;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    whole++;
    return temp;
}

Fraction& Fraction::operator--() {
    if (whole > 0)
        whole--;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    if (whole > 0)
        whole--;
    return temp;
}

Fraction Fraction::toFraction(double x) {
    Fraction result;
    result.whole = static_cast<long>(x);
    result.fractional = static_cast<unsigned short>((x - result.whole) * 100000);
    return result;
}

Fraction operator+(const Fraction& f1, const Fraction& f2) {
    double val1 = static_cast<double>(f1);
    double val2 = static_cast<double>(f2);
    double result = val1 + val2;

    Fraction resultFraction;
    resultFraction.whole = static_cast<long>(result);
    resultFraction.fractional = static_cast<unsigned short>((result - resultFraction.whole) * 100000);

    return resultFraction;
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    double val1 = static_cast<double>(f1);
    double val2 = static_cast<double>(f2);
    double result = val1 * val2;

    Fraction resultFraction;
    resultFraction.whole = static_cast<long>(result);
    resultFraction.fractional = static_cast<unsigned short>((result - resultFraction.whole) * 100000);

    return resultFraction;
}

ostream& operator<<(ostream& out, const Fraction& fraction) {
    out << string(fraction);
    return out;
}

istream& operator>>(istream& in, Fraction& fraction) {
    long wholePart;
    unsigned int tempFractional;

    cout << "Enter whole part: ";
    in >> wholePart;

    cout << "Enter fractional part: ";
    in >> tempFractional;

    fraction.setWhole(wholePart);
    fraction.setFractional(static_cast<unsigned short>(tempFractional));

    return in;
}

Fraction makeFraction(long wholePart, unsigned short fractionalPart) {
    return Fraction(wholePart, fractionalPart);
}
