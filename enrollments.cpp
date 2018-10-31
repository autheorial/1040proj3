#include "enrollments.h"

Enrollments::Enrollments(){
	num = 0;
	enrollments = new Enrollment[2];
}

void Enrollments::add(Enrollment newEnrollment){

	Enrollment* temp = new Enrollment[num + 2];
	for(int i = 0; i < num + 1; ++i){
		temp[i] = enrollments[i];
	}
	delete [] enrollments;

	enrollments = new Enrollment[num + 2];
	
	temp[num] = newEnrollment;

	for(int i = 0; i < num + 1; ++i){
		enrollments[i] = temp[i];
	}

	delete[] temp;

	++num;

	return;
}

int Enrollments::studentGradesAmount(int courseID, int studentID){

	int i, j, total = 0;

	for(i = 0; i < num; ++i){
		if(enrollments[i].printStudentID() == studentID && enrollments[i].printCourseID() == courseID){
			break;
		}
	}

	return enrollments[i].printNumGrades();

}

void Enrollments::moreGrades(int courseID, int studentID, int numAdding){

	int i;

	for(i = 0; i < num; ++i){
		if(enrollments[i].printStudentID() == studentID && enrollments[i].printCourseID() == courseID){
			break;
		}
	}

	enrollments[i].addGrades(numAdding);

}

char Enrollments::printLetterGrade(int courseID, int studentID){

	int i;

	for(i = 0; i < num; ++i){

		if(enrollments[i].printCourseID() == courseID && enrollments[i].printStudentID() == studentID){
			break;
		}
	
	}

	return enrollments[i].printLetterGrade();

}

int Enrollments::calcAverage(int courseID){

	int sum = 0, counter = 0;;

	for(int i = 0; i < num; ++i){

		if(enrollments[i].printCourseID() == courseID){
			sum += enrollments[i].printOverall();
			++counter;
		}
	
	}

	return sum / counter;

}

void Enrollments::save(ofstream& ofs){

	for(int i = 0; i < num; ++i){
		enrollments[i].save(ofs);
	}

}

bool Enrollments::matchingCourseIndex(int index, int courseID, int studentID){

	if(enrollments[index].printCourseID() == courseID && enrollments[index].printStudentID() == studentID){
		return true;
	}

	else{
		return false;
	}

}

void Enrollments::printStudentGrades(int index){

	cout << endl;
	enrollments[index].printGrades();
	cout << endl;
	return;

}