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
	
int main(void) {
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }

    
  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
  }
}



