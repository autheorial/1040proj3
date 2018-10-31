#include "course.h"

class Courses{
	public:
		Courses();
		int printCount(){ return num;};
		int getID(int index);
		string getName(int courseID);
		void add(Course newCourse);
		void print();
		void printInfo(int index);
		void printName(int courseID);
		void printStudentInfo(Enrollments enrollments, Students students, int courseID);
		int printStudentID(int courseID, int index);
		int searchIndex(int searchID);
		int idStudentCount(int courseID);
		int indexStudentCount(int index){ return courses[index].printStudentCount();};
		bool search(int searchID);
		void updateStudents(int courseIndex, int studentID);
		void save (ofstream& ofs);
	private:
		int num;
		Course* courses;

};