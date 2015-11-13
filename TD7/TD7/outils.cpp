#include "outils.h"

// pour section "Fonctions utiles"
#include <string>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


using namespace std;


/*****************************************************************************/
/*                           Fonctions ultiles                               */
/*****************************************************************************/

bool is_integer(string const & s)
{
	if( s.empty() )
		return false;
	string::const_iterator i = s.begin();
	if ( *i == '-' )
		i++;
	while( (i != s.end()) && (isdigit(*i)) )
		i++;
	return (i == s.end());
}

string integer2string(long i)
{
	stringstream tmp;
	tmp << i;
	return tmp.str();
}

long string2integer(string const & s)
{
	return atol(s.c_str());
}



bool is_real(string const & s)
{
	
	if( s.empty() )
	{
		return false;
	}
	string::const_iterator i = s.begin();
	bool coma = false;
	bool hasDigits = false;
	if( *i == '-' )
		i++;
	while( i != s.end() )
	{
		if( isdigit(*i) )
		{
			i++;
			hasDigits = true;
		}
		else
		{
			if( *i == '.' )
			{
				i++;
				coma = true;
			}
			break;
		}
	}
	while( (i != s.end()) && (isdigit(*i)) )
	{
		i++;
		hasDigits = true;
	}
	// avec une vigule, il faut au moins un chiffre (avant ou après)
	if( coma && (! hasDigits) )
		return false;
	return (i == s.end());
}

std::string real2string(double d)
{
	stringstream tmp;
	tmp << d;
	return tmp.str();
}

int string2real(std::string const & s)
{
	return atof(s.c_str());
}





// variable globale permettant d'assurer une seule utilisation de la fonction srand() de <stdlib.h>  dans tout le programme !
bool is_srand_used = false;

long random_between(long start, long end)
{
	assert( start < end );
	
	if( ! is_srand_used )
	{
		srand( (unsigned int)time(NULL) );
		is_srand_used = true;
	}
	long r = rand() % (end+1 - start); // nombre aléatoire entre 0 et (end - start) inclus
	return r + start;
}

