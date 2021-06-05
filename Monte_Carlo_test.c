#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float mc_pi(int);

float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

float mc_pi(int n) {
	float circle_points = 0;
	float square_points = 0;
	for(int i = 1; i<= n; i++) {
		float x = frandom();
		float y = frandom();
		if ((pow(x,2)+pow(y,2)) <= 1.0) {
			circle_points += 1;
		}
		else {
			square_points += 1;
		}
	}
	//printf("%f\n", circle_points);
	//printf("%f\n", square_points);
	square_points += circle_points;
	float pi = 4.0*(float)circle_points/square_points;
	return pi;
}
