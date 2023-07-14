
#include "Questions.h"



int Q1_for(){
	int sum=0;
	
	// calculate your sum below..this has to use for loop
	
	int i;
	for (i=30;i<=1000;i++){

		if(i%4==0){
			sum += i;
		}
	 }
	// here, we return the calcualted sum:
	return sum;
}
int Q1_while(){
	int sum=0;

	// calculate your sum below..this has to use while loop
	int i = 30;
	while(i<=1000){
		if(i%4 ==0){
		    sum += i;
		}
		i++;
	}
	// here, we return the calcualted sum:
	return sum;
}
int Q1_do(){
	int sum=0;
	
	// calculate your sum below..this has to use do-while loop
	int i = 30;
	do{
		if (i%4==0){
			sum += i;
		}
		i++;

	}
	while(i<=1000);
// here, we return the calcualted sum:
	return sum;
}
//===============================================================================================
int Q2(int Q2_input){
	
	// this is the flag that is holding whether the input number is 5-digit or not
	int IsFiveDigit;
	
	// Do your coding below to check
	if(Q2_input<0){
		Q2_input = (-1)*Q2_input;
	}
	if(Q2_input<=99999 && Q2_input>=10000){
		IsFiveDigit=1;
	}
	else{
		IsFiveDigit=0;
	}


	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and returns:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program shouldreturn -1
*/	
	// this is the varaible that holds the out value to return
	float GPA;
	
	
	// Do your coding below to calculate the GPA variable value
	GPA=0;
	if(Q3_input<=100 && Q3_input>=90){
		GPA = 4;
	}
	else if(Q3_input<=89 && Q3_input>=80){
		GPA = 3;
	}
	else if(Q3_input<=79 && Q3_input>=70){
		GPA = 2;
	}
	else if(Q3_input<=69 && Q3_input>=60){
		GPA = 1;
	}
	else if(Q3_input<=59 && Q3_input>=0){
		GPA = 0;
	}
	else{
		GPA = -1;
	}
	 
	// finally, we return the GPA
	return GPA;	
}
//===============================================================================================
double Q4(int Q4_input){
	
	// this is the varaible that holds the pi value to return
	double pi=0;
	
	
	// Do your coding below to calculate the pi value
	double k = 1;
	int i = 0;

	//for loop
	for(int i = 0; i<Q4_input; i++){

		if(i%2==0){
			pi = pi + 4/k;
		}
		else{
			pi = pi - 4/k;

		}

		k = k+2;
	}
	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){
	
	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles=0;
	
	
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		and update the total number of triples if needed
	*/int x = 1, y = 0, hyp = 0;
	  float side1 = 0, side2 = 0;

	  for(x=0;x<283;x++){
		  side1 = side1+1;

			for(y=0;y<566-side1;y++){
				side2 = side2+1;

				for(hyp=1;hyp<=400;hyp++){
					if((side1*side1+side2*side2==hyp*hyp) && side1<=side2){
						totNumTribles += 1;
					}
				}
			}
	  side2=0;}
	

	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
	
	
	
		//counts is teh variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0;


		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/
	    int i,j,sum;
	      for(i=2;i<=Q6_input;i++){ //loop runs from 2 to Q6_input times

	      	sum=0;     //for every i value sum initializes to zero
	      	for(j=1;j<i;j++){  //loop runs for i-1 times
	      		 if(i%j==0)
	      		 sum=sum+j;   //adds j to sum only when i is divisible by j
	    	}
	    	if(sum==i){     //checking for sum==i
	    		perfect[counts]=i;    //if yes then adding to array
	    		counts++;             //and incrementing the count

	    	}
	    }

	   return counts;

	
}
//===============================================================================================
int Q7a(int Q7_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer
	int i = 0,divider = 1000000,multiplier = 1,digit = 0;

		for(i=0;i<7;i++){
			digit = (Q7_input-(Q7_input%divider))/divider;
			reversedInt += digit*multiplier;
			Q7_input-=(Q7_input-(Q7_input%divider));
			divider = divider/10;
			multiplier = multiplier*10;
			}
	
	return reversedInt;
	
}
int Q7b(int Q7b_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt = 0;
	
	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
	 while (Q7b_input > 0){
		reversedInt = reversedInt * 10 + Q7b_input % 10;
		Q7b_input = Q7b_input / 10;
	 }
	
	
	return reversedInt;

	
	
	
}
