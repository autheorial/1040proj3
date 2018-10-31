#include "main.h"
using namespace std;

int main(){

	Students students;
	Courses courses;
	Enrollments enrollments;
	char selection;

	cout 
		   << endl
		   << "   +-----------------------------------------------------------------+  " << endl
		   << "   |                Computer Science and Engineering                 |  " << endl
		   << "   |                CSCE 1040 - Computer Science II                  |  " << endl
		   << "   |            Alice Zhu  az0144  alicezhu@my.unt.edu               |  " << endl
		   << "   +-----------------------------------------------------------------+  " << endl
		   << endl
		   << "                           G R A D E B O O K                          " << endl
		   << endl
	;

	do{

 		cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl
	  	   << endl
	  	   << " [                               M E N U                               ]" << endl
	  	   << endl
		   << "Welcome to your gradebook! Begin entering data to create a new gradebook," << endl
		   << "or press 'L' to load an existing one. Remember to save (k) before you quit!" << endl
		   << endl
		   		<<"\ta) Add student" << endl
		   		<<"\tb) Add course" << endl
		   		<<"\tc) Enroll a student" << endl
		   		<<"\td) Add a student's grades in a course" << endl
		   		<<"\te) View all of a student's grades in a course" << endl
		   		<<"\tf) View all students in a course" << endl
		   		<<"\tg) View all course averages of a student" << endl
		   		<<"\th) View all courses" << endl
		   		<<"\ti) View all students" << endl
		   		<<"\tj) View overall average of all courses" << endl
		   		<<"\tk) Save a gradebook" << endl
		   		<<"\tl) Load a gradebook" << endl 
	   		<< endl
	   		<< "Enter selection ('q' to quit): ";

		cin >> selection;
		selection = tolower(selection);
		cout << endl;

		switch(selection){

		case 'a':
			addStudent(students);
			break;

		case 'b':
			addCourse(courses);
			break;

		case 'c':
			enroll(enrollments, students, courses);
			break;

		case 'd':
			addGrades(enrollments, students, courses);
			break;

		
		case 'e':
			viewGrades(enrollments, students, courses);
			break;

		case 'f':
			viewCourseStudents(enrollments, students, courses);
			break;

		case 'g':
			viewStudentGrades(enrollments, students, courses);
			break;

		case 'h':
			viewCourses(courses);
			break;
		
		case 'i':
			viewStudents(students);
			break;

		case 'j':
			viewCourseAverages(enrollments, students, courses);
			break;

		case 'k':
			save(enrollments, courses, students);
			break;

		case 'l':
			load(enrollments, courses, students);

		default:
			;

		}

		if(selection != 'q'){

		cout << endl << "Press any key to return to the main menu." << endl;
			cin >> selection;
		cout << endl;

		}

	}while (selection != 'q');

	return 0;

}