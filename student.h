#include "header.h"

class Student{
	public:
		Student();
		Student(int ID, string last, string first, char type);
		void setInfo(int count, string last, string first, char type);
		void printInfo();
		int printID(){ return ID;};
		int printCourseCount(){ return courseCount;};
		char printType(){ return type;};
		int getCourseID(int courseIndex){ return courses[courseIndex];};
		string printLast(){ return last;};
		string printFirst(){ return first;};
		bool searchCourse(int courseID);
		void updateCourses(int courseID);
		void save(ofstream& ofs);
		void load(ifstream& ifs);
	private:
		char s;
		int ID;
		string last;
		string first;
		char type;
		int courseCount;
		int* courses;
};