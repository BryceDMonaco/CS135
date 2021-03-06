/*
	Bryce Monaco
	CS135-1002, CS135-1201
	
	The challenge was accepted.
	Compile with "gcc grade.c -o grade -std=c99"
*/

#include <stdio.h>

int main (void) {
	//Amt means "Amount", Avg means "Average"
	int projectsAmt = 0, midtermsAmt = 0, quizAmt = 0, validGrade = 1;
	int maxProjectsAmt, maxMidtermsAmt, maxQuizAmt;
	float projectsAvg = 0.0, midtermsAvg = 0.0, quizAvg = 0.0, finalProjectGrade, finalExamGrade, totalExamAvg, finalClassGrade, gradeCache;
	
	printf("(-1 Can be input to fill in a grade for ungraded assignments)\n");
	
	//Begin Project Input Sequence
	printf("\nInput Number of Projects (Excluding Final Project): ");
	scanf("%d", &maxProjectsAmt);
	
	//Projects Input Loop
	for (int i = 0; i < maxProjectsAmt; i++) {
		projectsAmt = i + 1;
		
		gradeCache = 0.0;
		
		validGrade = 0; //A boolean to check if the grade is valid or not
		
		printf("Please enter your grade for project number %d: ", projectsAmt);
		scanf("%f", &gradeCache);
		
		if (gradeCache == -1.0) {
			gradeCache = 100.0;
			validGrade = 1;
			
		} else if ((gradeCache < 0) && (gradeCache != -1)) { //If the input grade is some number less than zero that isn't -1
			while (validGrade == 0) {
				printf("***INVALID INPUT, PLEASE ENTER A NUMBER GREATER THAN 0 OR -1 IF NO GRADE EXISTS***\n");
				printf("Please re-enter your grade for project number %d: ", projectsAmt);
				scanf("%f", &gradeCache);
				
				if ((gradeCache < 0) && (gradeCache != -1)) {
					validGrade = 0;
				} else {
					validGrade = 1;
				}
			}
		} else {
			validGrade = 1;
		}
		
		projectsAvg += gradeCache;
		
		if (projectsAmt == maxProjectsAmt) {
			projectsAvg = projectsAvg / maxProjectsAmt;
		}
	}
	
	//Begin Midterm Input Sequence
	printf("\nInput Number of Midterms: ");
	scanf("%d", &maxMidtermsAmt);
	
	//Midterm Input Loop
	for (int i = 0; i < maxMidtermsAmt; i++) {
		
		midtermsAmt = i +1;
		
		gradeCache = 0.0;
		
		validGrade = 0; //A boolean to check if the grade is valid or not
		
		printf("Please enter your grade for midterm number %d: ", midtermsAmt);
		scanf("%f", &gradeCache);
		
		if (gradeCache == -1.0) {
			gradeCache = 100.0;
			validGrade = 1;
			
		} else if ((gradeCache < 0) && (gradeCache != -1)) { //If the input grade is some number less than zero that isn't -1
			while (validGrade == 0) {
				printf("***INVALID INPUT, PLEASE ENTER A NUMBER GREATER THAN 0 OR -1 IF NO GRADE EXISTS***\n");
				printf("Please re-enter your grade for midterm number %d: ", midtermsAmt);
				scanf("%f", &gradeCache);
				
				if ((gradeCache < 0) && (gradeCache != -1)) {
					validGrade = 0;
				} else {
					validGrade = 1;
				}
			}
		} else {
			validGrade = 1;
		}
		
		
		midtermsAvg += gradeCache;
		
		if (midtermsAmt == maxMidtermsAmt) {
			midtermsAvg = midtermsAvg / maxMidtermsAmt;
		}
	}
	
	//Begin Quiz Input Sequence
	printf("\nInput Number of Quizes: ");
	scanf("%d", &maxQuizAmt);
	
	//Quiz Input Loop
	for (int i = 0; i < maxQuizAmt; i++) {
		
		quizAmt = i + 1;
		
		gradeCache = 0.0;

		validGrade = 0; //A boolean to check if the grade is valid or not
		
		printf("Please enter your grade for quiz number %d: ", quizAmt);
		scanf("%f", &gradeCache);
		
		if (gradeCache == -1.0) {
			gradeCache = 100.0;
			validGrade = 1;
			
		} else if ((gradeCache < 0) && (gradeCache != -1)) { //If the input grade is some number less than zero that isn't -1
			while (validGrade == 0) {
				printf("***INVALID INPUT, PLEASE ENTER A NUMBER GREATER THAN 0 OR -1 IF NO GRADE EXISTS***\n");
				printf("Please re-enter your grade for quiz number %d: ", quizAmt);
				scanf("%f", &gradeCache);
				
				if ((gradeCache < 0) && (gradeCache != -1)) {
					validGrade = 0;
				} else {
					validGrade = 1;
				}
			}
		} else {
			validGrade = 1;
		}
		
		
		quizAvg += gradeCache;
		
		if (quizAmt == maxQuizAmt) {
			quizAvg = quizAvg / maxQuizAmt;
		}
	}
	
	printf("\nPlease Input the Final Project Grade: ");
	scanf("%f", &finalProjectGrade);
	
	if (finalProjectGrade == -1.0) {
		finalProjectGrade = 100.0;
	}
	
	printf("\nPlease Input the Final Exam Grade: ");
	scanf("%f", &finalExamGrade);
	
	if (finalExamGrade == -1.0) {
		finalExamGrade = 100.0;
	}
	
	//Begin Final Computations
	totalExamAvg = (finalExamGrade + midtermsAvg) / 2.0;
	
	finalClassGrade = ((projectsAvg * 0.4) + (finalProjectGrade * 0.1) + (midtermsAvg * 0.2) + (quizAvg * 0.1) + (finalExamGrade * 0.2));
	
	printf("\nAverage Projects Grade: \t%.3f\nAverage Exam Grade: \t\t%.3f\nFinal Grade: \t\t\t%.3f\n", projectsAvg, totalExamAvg, finalClassGrade);
	
	if (finalClassGrade >= 60.0) {
		printf("You can take CS202!\n");
	} else {
		printf("You cannot take CS202.\n");
	}
	
	return 0;
}
