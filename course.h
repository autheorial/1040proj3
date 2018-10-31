#include "header.h"
#include "time.h"

class Course{
	public:
		Course();
		Course(int ID, char* name, char* location, Time time);
		void setInfo(int count, string name, string location, Time time);
		void printInfo();
		void printName();
		string getName(){ return name;};
		void updateStudents(int studentID);
		int printID(){ return ID;}
		int printStudentCount(){ return studentCount;};
		int printStudentID(int index);
		void save(ofstream& ofs);
		void load(ifstream& ifs);
	private:
		char c;
		int ID;
		string name;
		string location;
		Time time;
		int studentCount;
		int* students;
};