#include "students.h"

Students::Students(){
	num = 0;
	students = new Student[2];
}

void Students::add(Student newStudent){

	Student* temp = new Student[num + 2];

	for(int i = 0; i < num + 1; ++i){
		temp[i] = students[i];
	}
	delete [] students;

	students = new Student[num + 2];
	
	temp[num] = newStudent;

	for(int i = 0; i < num + 1; ++i){
		students[i] = temp[i];
	}

	delete[] temp;

	++num;

	return;

}

void Students::print(){

	for (int i = 0; i < num; ++i){
		students[i].printInfo();
	}

	return;
	
}

int Students::searchIndex(int searchID){

	bool found = false;
	int i;

	for(i = 0; i < num; ++i){

		if(students[i].printID() == searchID){
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

bool Students::search(int searchID){

	bool found = false;

	for(int i = 0; i < num; ++i){

		if(students[i].printID() == searchID){
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

bool Students::courseSearch(int studentID, int courseID){

	bool found = false;

	for(int i = 0; i < num; ++i){

		if(students[i].printID() == studentID){
			found = students[i].searchCourse(courseID);
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

void Students::updateCourses(int studentIndex, int courseID){

	students[studentIndex].updateCourses(courseID);

	return;

}

int Students::getStudentIndex(int studentID){

	int i;
	bool found = false;

	for(i = 0; i < num; ++i){

		if(students[i].printID() == studentID){
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

int Students::indexCourseCount(int index){
	return students[index].printCourseCount();
}

int Students::idCourseCount(int studentID){

	int i;

	for(i = 0; i < num; ++i){
		if(students[i].printID() == studentID){
			break;
		}
	}
	return students[i].printCourseCount();
}

int Students::getCourseID(int studentIndex, int courseIndex){
	return students[studentIndex].getCourseID(courseIndex);
}

string Students::getLastName(int studentID){

	int i;

	for(i = 0; i < num; ++i){
		if(students[i].printID() == studentID){
			break;
		}
	}

	return students[i].printLast();

}

string Students::getFirstName(int studentID){

	int i;

	for(i = 0; i < num; ++i){
		if(students[i].printID() == studentID){
			break;
		}
	}

	return students[i].printFirst();

}

string Students::getType(int studentID){

	int i;

	for(i = 0; i < num; ++i){
		if(students[i].printID() == studentID){
			break;
		}
	}

	if(students[i].printType() == 'F'){
		return "Freshman";
	}
	else if(students[i].printType() == 'S'){
		return "Sophomore";
	}
	else if(students[i].printType() == 'J'){
		return "Junior";
	}
	else if(students[i].printType() == 'N'){
		return "Senior";
	}
	else{
		return "Error";
	}
}

void Students::getStudentName(int studentIndex){
	cout << students[studentIndex].printFirst() << " " << students[studentIndex].printLast();
	return;
}

void Students::save(ofstream& ofs){

	for(int i = 0; i < num; ++i){
		students[i].save(ofs);
	}

}