#include <iostream>
#include <RestServer.h>
#include <Decimal.h>

using namespace std;

int main() {
    Decimal a(2.0);
    Decimal b(3.5);
    a.print("a = ");
    b.print("b = ");

    Decimal c1 = a * b;
    c1.print("c1 = a * b = ");

    Decimal c2 = c1 * b;
    c2.print("c2 = c1 * b = ");

    Decimal c3 = c2 / c1;
    c3.print("c2 / c1 = ");

    Decimal c4 = c1 / a;
    c4.print("c1 / a = ");

    return 0;
    RestServer server;
    return 0;
}
