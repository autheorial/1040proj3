#include "courses.h"

Courses::Courses(){
	num = 0;
	courses = new Course[2];
}

int Courses::getID(int index){
	return courses[index].printID();
}

string Courses::getName(int courseID){

	int i;

	for(i = 0; i < num; ++i){
		if(courses[i].printID() == courseID){
			break;
		}
	}

	return courses[i].getName();
}

void Courses::add(Course newCourse){

	Course* temp = new Course[num + 2];
	for(int i = 0; i < num + 1; ++i){
		temp[i] = courses[i];
	}
	delete [] courses;

	courses = new Course[num + 2];
	
	temp[num] = newCourse;

	for(int i = 0; i < num + 1; ++i){
		courses[i] = temp[i];
	}

	delete[] temp;

	++num;

	return;

}

void Courses::print(){

	for (int i = 0; i < num; ++i){
		courses[i].printInfo();
	}

	return;
	
}

void Courses::printInfo(int index){

	courses[index].printInfo();
	return;

}

void Courses::printName(int courseID){

	int i;

	for(i = 0; i < num; ++i){
		if(courses[i].printID() == courseID){
			break;
		}
	}

	courses[i].printName();
}

int Courses::printStudentID(int courseID, int index){

	int i;

	for(i = 0; i < num; ++i){

		if(courses[i].printID() == courseID){
			break;
		}
	}

	return courses[i].printStudentID(index);

}

int Courses::searchIndex(int searchID){

	bool found = false;
	int i;

	for(i = 0; i < num; ++i){

		if(courses[i].printID() == searchID){
			found = true;
			break;
		}

	}

	if(found == true){
		return i;
	}
	else{
		return -1;
	}

}

bool Courses::search(int searchID){

	bool found = false;

	for(int i = 0; i < num; ++i){

		if(courses[i].printID() == searchID){
			found = true;
			break;
		}

	}

	if(found == true){
		return true;
	}
	else{
		return false;
	}

}

int Courses::idStudentCount(int courseID){

	int i;

	for(i = 0; i < num; ++i){
		if(courses[i].printID() == courseID){
			break;
		}
	}
	return courses[i].printStudentCount();
}

void Courses::updateStudents(int courseIndex, int studentID){

	courses[courseIndex].updateStudents(studentID);

	return;

}

void Courses::save(ofstream& ofs){

	for(int i = 0; i < num; ++i){
		courses[i].save(ofs);
	}

}