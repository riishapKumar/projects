/*ss_bearing.c*
 * File: compass_bearing.c 
 * Desc: this program converts a true bearing into a direction bearing
 * Author: Rishap kumar and mitchell sibal
 */
#include <stdio.h>

int main(void)
{
 /* Input phase */
	float tru_bearing_degree, conventional_degree ;
	
	scanf("%f", &tru_bearing_degree);
/* Computation phase */
	if (0 <=  tru_bearing_degree && tru_bearing_degree < 90) {
		printf("North %.1f East\n",tru_bearing_degree);
	}	
	else if (90 <= tru_bearing_degree && tru_bearing_degree < 180){
		conventional_degree = 180 - tru_bearing_degree;
		printf("South %.1f East\n",  conventional_degree);
	}	
	else if (180 <= tru_bearing_degree && tru_bearing_degree < 270) {
		conventional_degree = (180 - tru_bearing_degree) * -1;
		printf("South %.1f West\n", conventional_degree);
	}	
	else if (270 <= tru_bearing_degree  && tru_bearing_degree < 360) {
		conventional_degree = (180 -  tru_bearing_degree) * -1;
		printf("North %.1f West\n", conventional_degree);
	}	
	else {
		printf("Invalid compass heading\n");
	}
/* Exit with no error */
	return 0;
}
	 
