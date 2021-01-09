
#include <math.h>
#include <stdio.h>
#include "cmsis_os.h"
#include "arm_math.h"
#include "stdbool.h"

void timeoutDataCheck(void);

bool flag = false;

/* 
Those parameters can be generated with the python library scikit-learn.
*/
arm_gaussian_naive_bayes_instance_f32 S;

#define NB_OF_CLASSES 3
#define VECTOR_DIMENSION 2

const float32_t theta[NB_OF_CLASSES*VECTOR_DIMENSION] = {
  1.4539529436590528f, 0.8722776016801852f, 
  -1.5267934452462473f, 0.903204577814203f, 
  -0.15338006360932258f, -2.9997913665803964f
}; /**< Mean values for the Gaussians */

const float32_t sigma[NB_OF_CLASSES*VECTOR_DIMENSION] = {
  1.0063470889514925f, 0.9038018246524426f, 
  1.0224479953244736f, 0.7768764290432544f, 
  1.1217662403241206f, 1.2303890106020325f
}; /**< Variances for the Gaussians */

const float32_t classPriors[NB_OF_CLASSES] = {
  0.3333333333333333f, 0.3333333333333333f, 0.3333333333333333f
}; /**< Class prior probabilities */


void Task2(void *argument)
{
	
	  /* Array of input data */
  float32_t in[2];

  /* Result of the classifier */
  float32_t result[NB_OF_CLASSES];
  float32_t maxProba;
  uint32_t index;
  
  S.vectorDimension = VECTOR_DIMENSION; 
  S.numberOfClasses = NB_OF_CLASSES; 
  S.theta = theta;          
  S.sigma = sigma;         
  S.classPriors = classPriors;    
  S.epsilon=4.328939296523643e-09f; 

  in[0] = 1.5f;
  in[1] = 1.0f;



	for(;;)
	{
			if(true){
	arm_gaussian_naive_bayes_predict_f32(&S, in, result);

	arm_max_f32(result, NB_OF_CLASSES, &maxProba, &index);
				flag = false;
			}
		
	//printf("%d", index);	
		osDelay(1);
	}
}



void timeoutDataCheck(){
		flag = true;
}
