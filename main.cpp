// Rafael A. Arce Nazario
//
// Cliente con pruebas para la clase Racional

#define CATCH_CONFIG_MAIN
#include <iostream>
#include "/home/rarce/Dropbox/ccom3034-b92/catch.hpp"
#include "Racional.h"
using namespace std;


TEST_CASE("Rational tests", "[rational]") {
    Racional r01;
    Racional r02(10,8);
    
    REQUIRE(r01.getP() == 0);
    REQUIRE(r01.getQ() == 1);

    REQUIRE(r02.getP() == 10);
    REQUIRE(r02.getQ() == 8);

    //    r02.simplificar();
    ~r02;
    REQUIRE(r02.getP() == 5);
    REQUIRE(r02.getQ() == 4);

    Racional r03;
    //    r03 = r02.suma(r01);
    REQUIRE(r02.suma(r01).getP() == 5);
    REQUIRE(r02.suma(r01).getQ() == 4);

    r03 = r01 + r02;

    Racional r04(1000,10000);
    Racional r05(1,2);

    REQUIRE((r04 > r05) == false);
    REQUIRE((r05 > r04) == true);

    r05.display();

    Racional r06(1,2);
    Racional r07(3,5);
    Racional r08;
    r08 = suma(r06,r07);

    REQUIRE((r06 + 5).getP() == 11);
    REQUIRE((r06 + 5).getQ() == 2);

    REQUIRE((5 + r06).getP() == 11);
    REQUIRE((5 + r06).getQ() == 2);

    REQUIRE( (r06++) == Racional(1,2));

    REQUIRE( r06 == Racional(3,2));

}