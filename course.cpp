#include "course.h"

Course::Course(){
	ID = 000000;
	name = "NONE";
	location = "NONE";
	studentCount = 0;
	students = new int[2];
	c = 'c';
}

Course::Course(int ID, char* name, char* location, Time time){
	this->ID = ID;
	this->name = name;
	this->location = location;
	this->time = time;
	studentCount = 0;
	students = new int[2];
	c = 'c';
}

void Course::setInfo(int count, string name, string location, Time time){

	ID = 600001 + count;
	this->name = name;
	this->location = location;
	this->time = time;

}

void Course::printInfo(){
	cout.width(10); cout << ID;
		cout.width(30); cout << name;
		cout.width(20); cout << location;
		cout.width(4); cout << " ";
		cout.width(9); cout << setw(2) << setfill('0') << right << time.hr << ":" << setw(2) << time.min << " " << time.period << setfill(' ') << endl;
}

void Course::printName(){

	cout << name.at(0);

	for (int i = 1; i < name.length(); ++i){

		if(name.at(i) == ' '){

			if(name.at(i - 1) != ' '){
				cout << name.at(i);
			}

		}

		else{
			cout << name.at(i);
		}
	}

	return;
}

int Course::printStudentID(int index){
	return students[index];
}

void Course::updateStudents(int studentID){

	int* temp = new int[studentCount + 2];

	for(int i = 0; i < studentCount; ++i){
		temp[i] = students[i];
	}

	temp[studentCount] = studentID;

	++studentCount;

	delete[] students;

	students = new int[studentCount + 2];

	for(int i = 0; i < studentCount; ++i){
		students[i] = temp[i];
	}

	delete[] temp;


}

void Course::save(ofstream& ofs){

	ofs.width(1); ofs << c;
	ofs.width(10); ofs << ID;
	ofs.width(30); ofs << name;
	ofs.width(20); ofs << location;
	ofs.width(20); ofs << time.hr;
	ofs.width(3); ofs << time.min;
	ofs.width(3); ofs << time.period << endl;

}
