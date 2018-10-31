#include <string>
#include "student.h"
using namespace std;

class Students{

	public:
		Students();
		int printCount(){return num;};
		void add(Student newStudent);
		void print();
		int searchIndex(int searchID);
		bool search(int searchID);
		bool courseSearch(int studentID, int courseID);
		void updateCourses(int studentIndex, int courseID);
		int getStudentIndex(int studentID);
		int indexCourseCount(int index);
		int idCourseCount(int studentID);
		int getCourseID(int studentIndex, int courseIndex);
		string getLastName(int studentID);
		string getFirstName(int studentID);
		string getType(int studentID);
		void getStudentName(int index);
		void save(ofstream& ofs);

	private:
		int num;
		Student* students;
};