#include "student.h"

Student::Student(){
	ID = 000000;
	last = "NONE";
	first = "NONE";
	type = 'X';
	courseCount = 0;
	courses = new int[2];
	s = 's';
}

Student::Student(int ID, string last, string first, char type){
	this->ID = ID;
	this->last = last;
	this->first = first;
	this->type = type;
	courseCount = 0;
	courses = new int[2];
	s = 's';
}

void Student::setInfo(int count, string last, string first, char type){
	ID = 100001 + count;
	this->last = last;
	this->first = first;
	this->type = type;
}

void Student::printInfo(){

	cout.width(10); cout << ID;
	cout.width(21); cout << last;
	cout.width(21); cout << first;
	cout.width(20); 

		if(type == 'F'){
			cout << "Freshman";
		}
		else if(type == 'S'){
			cout << "Sophomore";
		}
		else if(type == 'J'){
			cout << "Junior";
		}
		else if(type == 'N'){
			cout << "Senior";
		}

	cout << endl;

}

bool Student::searchCourse(int courseID){

	bool found = false;

	for(int i = 0; i < courseCount; ++i){
		if (courses[i] == courseID){
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

void Student::updateCourses(int courseID){

	int* temp = new int[courseCount + 2];

	for(int i = 0; i < courseCount; ++i){
		temp[i] = courses[i];
	}

	temp[courseCount] = courseID;

	delete[] courses;

	++courseCount;

	courses = new int[courseCount + 2];

	for(int i = 0; i < courseCount; ++i){
		courses[i] = temp[i];
	}

	delete[] temp;

	return;

}

void Student::save(ofstream& ofs){

	ofs.width(1); ofs << s;
	ofs.width(10); ofs << ID;
	ofs.width(30); ofs << last;
	ofs.width(20); ofs << first;
	ofs.width(20); ofs << type << endl;

	return;

}