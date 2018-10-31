#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Enrollment{

	public:
		Enrollment();
		int printStudentID(){ return studentID;};
		int printCourseID(){ return courseID;};
		int printNumGrades(){ return numGrades;};
		int printOverall();
		char printLetterGrade();
		void setInfo(int count, int studentID, int courseID, int numGrades);
		void addGrades(int numGrades);
		void printInfo();
		void printGrades();
		int getAvg();
		void save(ofstream& ofs);
		void load(ifstream& ifs);

	private:
		char e;
		int ID;
		int studentID;
		int courseID;
		int numGrades;
		int* grades;
};