
/*
 * File: gas_cylinder.c
 * Desc: this program prints the contents of a cylinder based on the first letter of its color
 * Author: Rishap kumar and mitchell sibal
 */
#include <stdio.h>

int main()
{
	char c;
	scanf( "%c", &c );
/* Input phase */
	switch ( c )
 {
/* Computation phase */
	case 'Y':
		printf( "Hydrogen\n");
	break;
	case 'y':
		printf( "Hydrogen\n");
	break;
	case 'o':
		printf( "Ammonia\n");
	break;
	case 'O':
		printf( "Ammonia\n");
	break;
	case 'b':   
		printf( "Carbon monoxide\n");
	break;
	case 'B':   
		printf( "Carbon monoxide\n");
	break;
	case 'G':
		printf( "Oxygen\n");
	break;
	case 'g':
		printf( "Oxygen\n");
	break;
	default:
		printf( "Contents unknown\n");
	break;
}
/* Exit with no error */
	return 0;
}
