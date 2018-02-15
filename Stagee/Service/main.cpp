#include <iostream>
#include <RestServer.h>
#include <Decimal.h>


using namespace std;

int main() {
    //double aaa = 2.0;
    //double bbb = 3.0;
    //double ccc = aaa / bbb;

    Decimal a(2.32);
    Decimal b(3.23);
    a.print("a = ");
    b.print("b = ");

    Decimal c1 = a + b;
    c1.print("a+b");

    a.print("a = ");
    b.print("b = ");

    Decimal c2 = b + a;
    c2.print("b+a");

    a.print("a = ");
    b.print("b = ");


    Decimal d1 = a - b;
    d1.print("a-b");

    a.print("a = ");
    b.print("b = ");

    Decimal d2 = b - a;
    d2.print("b-a");

    a.print("a = ");
    b.print("b = ");


    return 0;
    RestServer server;
    return 0;
}
