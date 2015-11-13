#pragma once

#include <string>

/*****************************************************************************/
/*                           Fonctions ultiles                               */
/*****************************************************************************/

bool is_integer(std::string const & s);
std::string integer2string(long i);
long string2integer(std::string const & s);


bool is_real(std::string const & s);
std::string real2string(double d);
double string2real(std::string const & s);




/// retour un nombre entier, généré pseudo-aléatoirement, dans l'intervalle [start, end] (bornes incluses)
long random_between(long start, long end);
