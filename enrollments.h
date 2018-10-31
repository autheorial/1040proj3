#include "enrollment.h"

class Enrollments{

	public:
		Enrollments();
		void add(Enrollment newEnrollment);
		int getNum(){ return num;}
		int printStudentID(int index) {return enrollments[index].printStudentID();};
		int printCourseID(int index) {return enrollments[index].printCourseID();};
		int printOverall(int index){return enrollments[index].printOverall();};
		char printLetterGrade(int courseID, int studentID);
		int studentGradesAmount(int courseID, int studentID);
		int calcAverage(int courseID);
		void moreGrades(int courseID, int studentID, int numAdding);
		void save(ofstream& ofs);
		bool matchingCourseIndex(int index, int courseID, int studentID);
		void printStudentGrades(int index);

	private:
		int num;
		Enrollment* enrollments;

};