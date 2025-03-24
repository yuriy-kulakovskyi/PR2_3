#include "./classes/Fraction.h"
#include <iostream>

using namespace std;

int main() {
    Fraction f1;
    Fraction f2(123, 45678);
    cout << "f1 (без аргументів): " << f1 << endl;
    cout << "f2 (з параметрами): " << f2 << endl;

    Fraction f3 = f2;
    Fraction f4;
    f4 = f2;
    cout << "f3 (копія f2): " << f3 << endl;
    cout << "f4 (присвоєно f2): " << f4 << endl;

    cout << "\nВведіть перше значення:" << endl;
    Fraction a;
    cin >> a;

    cout << "Введіть друге значення:" << endl;
    Fraction b;
    cin >> b;

    cout << "Перше значення: " << a << endl;
    cout << "Друге значення: " << b << endl;

    Fraction sum = a + b;
    cout << "Сума: " << sum << endl;

    Fraction product = a * b;
    cout << "Добуток: " << product << endl;

    cout << "\nДемонстрація інкрементів та декрементів:" << endl;
    cout << "a початкове: " << a << endl;

    Fraction temp;
    temp = ++a;
    cout << "temp = ++a: " << endl;
    cout << "a = " << a << ", temp = " << temp << endl;

    temp = --a;
    cout << "temp = --a: " << endl;
    cout << "a = " << a << ", temp = " << temp << endl;

    temp = a++;
    cout << "temp = a++: " << endl;
    cout << "a = " << a << ", temp = " << temp << endl;

    temp = a--;
    cout << "temp = a--: " << endl;
    cout << "a = " << a << ", temp = " << temp << endl;

#pragma pack(push, 1)
    struct FractionPacked {
        long whole;
        unsigned short fractional;
    };
#pragma pack(pop)

    cout << "\nРозмір класу Fraction:" << endl;
    cout << "Звичайний: " << sizeof(Fraction) << " байт" << endl;
    cout << "З #pragma pack(1): " << sizeof(FractionPacked) << " байт" << endl;

    return 0;
}