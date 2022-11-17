
#include <iostream>
#include <string>
#include <sstream>
#include "Profile.h"

using namespace std;

int main() {

    //SOLO DE PRUEBA
    Profile *perfil = new Profile("sarahqc2003", "password123", "password123");
    perfil->setPurpose(true, false, "necesito un ingeniero en sistemas");

    return 0;
}