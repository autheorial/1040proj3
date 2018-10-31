#include "students.h"
#include "courses.h"
#include "enrollments.h"

void studentMenu(Students students){
	cout << "You are viewing all " << students.printCount() << " students." << endl << endl;
	cout.width(10); cout << "ID";
	cout.width(21); cout << "LAST NAME";
	cout.width(21); cout << "FIRST NAME";
	cout.width(20); cout << "CLASS";
	cout << endl;
		for (int i = 0; i < 72; ++i){
			cout << "-";
		}
		cout << endl;
	return;
}

void courseMenu(Courses courses){
	cout << "You are viewing all " << courses.printCount() << " courses." << endl << endl;
	cout.width(10); cout << "ID#";
		cout.width(30); cout << "NAME";
		cout.width(20); cout << "LOCATION";
		cout.width(12); cout << "TIME"<< endl;
		for (int i = 0; i < 72; ++i){
			cout << "-";
		}
	cout << endl;
	return;
}

string changeCase(string& text){

	text[0] = toupper(text[0]);

	for (int i = 1; i < text.length(); ++i){
	   			
	   	if(text[i - 1] != ' '){
	   		text[i] = tolower(text[i]);
	   	}

	   	else{
	   		text[i] = toupper(text[i]);
	   	}
	}
	return text;

}

void viewCourses(Courses courses){

	if (courses.printCount() == 0){
		cout << "No courses available." << endl;
	}

	else{

		courseMenu(courses);
		courses.print();
		cout << endl;

	}
	return;

}

void viewStudents(Students students){

	if (students.printCount() == 0){
		cout << "No students available." << endl;
	}

	else{

		studentMenu(students);
		students.print();
		cout << endl;

	}
	return;

}

void addStudent(Students& students){

	cout << endl << " [                           ADD A STUDENT                             ]" << endl << endl;

	Student temp_student;
	string last, first;
	char type, selection;
	bool validClass;

	cout << "Last name: ";
		cin.ignore();
		getline(cin, last);
		last = changeCase(last);

	cout << "First name: ";
		getline(cin, first);
		first = changeCase(first);

	do{

	cout << "Classification (F = freshman, S = sophomore, J = junior, N = senior): ";
		cin >> type;
	type = toupper(type);

		if(type != 'F' && type != 'S' && type != 'J' && type != 'N'){
			cout << "Invalid classification." << endl;
			validClass = false;
		}

		else{
			temp_student.setInfo(students.printCount(), last, first, type);
			students.add(temp_student);
			validClass = true;
		}

	}while(validClass == false);

	return;

}

void addCourse(Courses& courses){

		cout << endl << " [                            ADD A COURSE                             ]" << endl << endl;

	Course temp_course;
	string name, location;
	Time time;
	bool validTime;

	cout << "Course Name: ";
		cin.ignore();
		getline(cin, name);
		name = changeCase(name);

	cout << "Location: ";
		getline(cin, location);
		location = changeCase(location);

	do{

	cout << "Time (12 hr):" << endl << "\thr: ";
		cin >> time.hr;

	if(time.hr < 0 || time.hr > 12){
		cout << "Invalid time hour." << endl;
		validTime = false;
	}

	else{
		cout << "\tmin: ";
			cin >> time.min;

		if(time.min < 0 || time.min > 59){
			cout << "Invalid time minutes." << endl;
			validTime = false;
		}

		else{

			cout << "\tAM or PM: ";
				cin >> time.period;

			for(int i = 0; i < time.period.length(); ++i){
			time.period[i] = toupper(time.period[i]);
			}

			if(time.period != "AM" && time.period != "PM"){
				cout << "Invalid time period." << endl;
				validTime = false;
			}
			else{
				validTime = true;
			}

		}

	}

	}while(validTime == false);

	temp_course.setInfo(courses.printCount(), name, location, time);
	courses.add(temp_course);

	return;

}

void enroll(Enrollments& enrollments, Students& students, Courses& courses){

	Enrollment temp_enroll;
	int ID, studentID, courseID, numGrades;

	if(students.printCount() == 0){
		cout << "No students are available at this time." << endl;
	}

	else if(courses.printCount() == 0){
		cout << "No courses are available at this time." << endl;
	}

	else{

		cout << endl << " [                               ENROLL                                ]" << endl << endl;


		viewStudents(students);

		cout << "Student ID#: ";
			cin >> studentID;

		if(students.search(studentID) == false){
			cout << "Student does not exist." << endl;
		}

		else if(students.idCourseCount(studentID) >= 5){
			cout << "Student is already enrolled in 5 courses. (Maximum amount.)" << endl;
		}

		else{

			cout << endl;

			viewCourses(courses);

			cout << "Course ID#: ";
				cin >> courseID;

				if(courses.search(courseID) == false){
					cout << "Course does not exist." << endl;
				}

				else if(students.courseSearch(studentID, courseID) == true){
					cout << "Student is already enrolled in this course." << endl;
				}

				else if(courses.idStudentCount(courseID) >= 48){
					cout << "Course already has 48 students enrolled. (Maximum amount.)" << endl;
				}

				else{

					cout << endl << "How many grades would you like to add?: ";
						cin >> numGrades;

					if(numGrades > 10){ cout << "No more than 10 grades may be entered." << endl; }
					
					else{
						temp_enroll.setInfo(enrollments.getNum(), studentID, courseID, numGrades);
						enrollments.add(temp_enroll);
						courses.updateStudents(courses.searchIndex(courseID), studentID);
						students.updateCourses(students.searchIndex(studentID), courseID);
					}

				}

		}	

	}

	return;

}

void addGrades(Enrollments& enrollments, Students& students, Courses& courses){

	Enrollment updatedEnroll;
	int numAdding = 0, studentID, courseID, index, courseCount;

	if(students.printCount() == 0){
		cout << "No students are available at this time." << endl;
	}

	else if(courses.printCount() == 0){
		cout << "No courses are available at this time." << endl;
	}

	else{

		viewStudents(students);

		cout << "Student ID#: ";
			cin >> studentID;

		if(students.search(studentID) == false){
			cout << "Student does not exist." << endl;
		}

		else if(students.idCourseCount(studentID) == 0){
			cout << "Student is not enrolled in any courses." << endl;
		}

		else{

			cout << endl;

			index = students.getStudentIndex(studentID);
			courseCount = students.indexCourseCount(index);
			
			students.getStudentName(index); cout << " is enrolled in " << courseCount << " courses." << endl;
			cout << endl;
			cout.width(10); cout << "ID#";
			cout.width(30); cout << "NAME";
			cout.width(20); cout << "LOCATION";
			cout.width(12); cout << "TIME"<< endl;
			for (int i = 0; i < 72; ++i){
				cout << "-";
			}
		cout << endl;

			for (int i = 0; i < courseCount; ++i){

				for (int j = 0; j < courses.printCount(); ++j){

					if(students.getCourseID(index, i) == courses.getID(j)){
						courses.printInfo(j);

					}

				}

			}

			cout << endl << "Course ID#: ";
				cin >> courseID;

				if(courses.search(courseID) == false){
					cout << "Course does not exist." << endl;
				}

				else if(students.courseSearch(studentID, courseID) == false){
					cout << "Student is not enrolled in this course." << endl;
				}

				else{

					cout << "How many grades would you like to add?: ";
						cin >> numAdding;

					if(enrollments.studentGradesAmount(courseID, studentID) + numAdding > 10){
						cout << "Number of grades exceeds limit. Max is 10." << endl;
					}

					else{
						enrollments.moreGrades(courseID, studentID, numAdding);
					}
				}

			}
		}

	return;
}

void viewGrades(Enrollments enrollments, Students students, Courses courses){

	int numAdding = 0, studentID, courseID, index, courseCount, enrollIndex;

	if(students.printCount() == 0){
		cout << "No students are available at this time." << endl;
	}

	else if(courses.printCount() == 0){
		cout << "No courses are available at this time." << endl;
	}

	else{

		cout << endl << " [                         VIEW COURSE GRADES                          ]" << endl << endl;

		viewStudents(students);

		cout << "Student ID#: ";
			cin >> studentID;

		if(students.search(studentID) == false){
			cout << "Student does not exist." << endl;
		}

		else if(students.idCourseCount(studentID) == 0){
			cout << "Student is not enrolled in any courses." << endl;
		}

		else{

			cout << endl;

			index = students.getStudentIndex(studentID);
			courseCount = students.indexCourseCount(index);
			
			students.getStudentName(index); cout << " is enrolled in " << courseCount << " courses: " << endl;
			cout << endl;
			cout.width(10); cout << "ID#";
			cout.width(30); cout << "NAME";
			cout.width(20); cout << "LOCATION";
			cout.width(12); cout << "TIME"<< endl;
			for (int i = 0; i < 72; ++i){
				cout << "-";
			}
		cout << endl;

			for (int i = 0; i < courseCount; ++i){

				for (int j = 0; j < courses.printCount(); ++j){

					if(students.getCourseID(index, i) == courses.getID(j)){
						courses.printInfo(j);

					}

				}

			}

			cout << endl << "Course ID#: ";
				cin >> courseID;

				if(courses.search(courseID) == false){
					cout << "Course does not exist." << endl;
				}

				else if(students.courseSearch(studentID, courseID) == false){
					cout << "Student is not enrolled in this course." << endl;
				}

				else{

					for(int i = 0; i < enrollments.getNum(); ++i){

						if(enrollments.matchingCourseIndex(i, courseID, studentID) == true){
							enrollIndex = i;
							break;
						}
					}

					cout << endl;

					students.getStudentName(index); cout << " has " << enrollments.studentGradesAmount(courseID, studentID) << " grades in ";
					courses.printName(courseID); cout << ": " << endl << endl;

					cout.width(37); cout << "SCORE";
					cout.width(35); cout << "GRADE" << endl;
					for (int i = 0; i < 72; ++i){
						cout << "-";
					}

					enrollments.printStudentGrades(enrollIndex);

				}

			}

		}

}

void viewCourseStudents(Enrollments enrollments, Students students, Courses courses){

	int courseID;

	cout << endl << " [                        VIEW COURSE STUDENTS                         ]" << endl << endl;

	if(students.printCount() == 0){
		cout << "No students are available at this time." << endl;
	}

	else if(courses.printCount() == 0){
		cout << "No courses are available at this time." << endl;
	}

	else{

		viewCourses(courses);

		cout << "Course ID#: ";
			cin >> courseID;

		if(courses.search(courseID) == false){
			cout << "Course does not exist." << endl;
		}

		else if(courses.idStudentCount(courseID) == 0){
			cout << "No students have enrolled in this course." << endl;
		}

		else{

			cout << endl;
			courses.printName(courseID);
				cout << " has " << courses.idStudentCount(courseID) << " students: " << endl << endl;

			cout.width(10); cout << "ID#";
			cout.width(16); cout << "LAST NAME";
			cout.width(16); cout << "FIRST NAME";
			cout.width(20); cout << "CLASSIFICATION";
			cout.width(10); cout << "GRADE" << endl;
			for (int i = 0; i < 72; ++i){
				cout << "-";
			}

			cout << endl;

			for(int i = 0; i < courses.idStudentCount(courseID); ++i){
				int studentID = courses.printStudentID(courseID, i);
				cout.width(10); cout << studentID;
				cout.width(16); cout << students.getLastName(studentID);
				cout.width(16); cout << students.getFirstName(studentID);
				cout.width(20); cout << students.getType(studentID);
				cout.width(10); cout << enrollments.printLetterGrade(courseID, studentID) << endl;
			}

			cout << endl;

		}

	}

}

void viewStudentGrades(Enrollments enrollments, Students students, Courses courses){

	int studentID;

	if(students.printCount() == 0){
		cout << "No students are available at this time." << endl;
	}

	else if(courses.printCount() == 0){
		cout << "No courses are available at this time." << endl;
	}

	else{

		cout << endl << " [                         VIEW STUDENT GRADES                         ]" << endl << endl;

		viewStudents(students);

		cout << "Student ID#: ";
			cin >> studentID;

		if(students.search(studentID) == false){
			cout << "Student does not exist." << endl;
		}

		else if(students.idCourseCount(studentID) == 0){
			cout << "Student is not enrolled in any courses." << endl;
		}

		else{

			int studentIndex = students.getStudentIndex(studentID);
			int courseIndex;

			cout << endl << "You are viewing ";
			students.getStudentName(studentIndex);
			cout << "'s course grade averages: " << endl << endl;

			cout.width(10); cout << "ID";
				cout.width(29); cout << right << "COURSE NAME";
				cout.width(16); cout << "AVG";
				cout.width(17); cout << "GRADE"<< endl;
				for (int i = 0; i < 72; ++i){
					cout << "-";
				}
				cout << endl;

			
			for(int i = 0; i < students.idCourseCount(studentID); ++i){
				for(int j = 0; j < courses.printCount(); ++j){
					if(courses.getID(j) == students.getCourseID(studentIndex, i)){
						cout.width(10); cout << courses.getID(j);
						cout.width(29); cout << right << courses.getName(courses.getID(j));
					}
				}
				for(int k = 0; k < enrollments.getNum(); ++k){
					if(enrollments.printCourseID(k) == students.getCourseID(studentIndex, i) && enrollments.printStudentID(k) == studentID){

						cout.width(16); cout << enrollments.printOverall(k);
						cout.width(17); cout << enrollments.printLetterGrade(enrollments.printCourseID(k), studentID);

					}
				}

			cout << endl;

			}
		}

	}

	return;

}

void viewCourseAverages(Enrollments enrollments, Students students, Courses courses){

	if(students.printCount() == 0){
		cout << "No students are available at this time." << endl;
	}

	else if(courses.printCount() == 0){
		cout << "No courses are available at this time." << endl;
	}

	else{

	cout << endl << " [                           COURSE AVERAGES                           ]" << endl << endl;

	cout.width(10); cout << "ID#";
	cout.width(30); cout << "NAME";
	cout.width(16); cout << "# ENROLLED";
	cout.width(8); cout << "AVG";
	cout.width(8); cout << "GRADE" << endl;
	for (int i = 0; i < 72; ++i){
		cout << "-";
	}
	cout << endl;

		
	for(int i = 0; i < courses.printCount(); ++i){

		int average;

		if(courses.indexStudentCount(i) == 0){
			average = 0;
		}
		else{
			average = enrollments.calcAverage(courses.getID(i));
		}

		char letter;

		if(average >= 90){
		letter = 'A';
		}
		else if(average >= 80){
			letter = 'B';
		}
		else if(average >= 70){
			letter = 'C';
		}
		else if(average >= 60){
			letter = 'D';
		}
		else{
			letter = 'F';
		}

		cout.width(10); cout << courses.getID(i);
		cout.width(29); cout << right << courses.getName(courses.getID(i));
		cout.width(16); cout << courses.indexStudentCount(i);
		cout.width(8); cout << average;
		cout.width(8); cout << letter;
		cout << endl;

		}

	}

	return;
}

void save(Enrollments enrollments, Courses courses, Students students){

	cout << endl << " [                           SAVE GRADEBOOK                            ]" << endl << endl;

	string filename;
	ofstream ofs;

	cout << "Save database as: ";
		cin >> filename;

	ofs.open(filename.c_str());
		if(!ofs){
			cout << "Error accessing database." << endl;
		}

		else{
			students.save(ofs);
			courses.save(ofs);
			enrollments.save(ofs);
			cout << "Successfully saved your gradebook!" << endl;
		}

	ofs.close();

	return;

}

void load(Enrollments& enrollments, Courses& courses, Students& students){

	cout << endl << " [                           LOAD GRADEBOOK                            ]" << endl << endl;

	ifstream ifs;
	string filename = "";
	char in;
		int ID;
		string last;
		string first;
		char type;
		Time time;
	Enrollment enr;
	int studentCounter = 0, courseCounter = 0, enrollmentCounter = 0;

	cout << "Enter the filename of your gradebook: ";
		cin >> filename;

	ifs.open(filename.c_str());

	if(!ifs){
		cout << "Error accessing file." << endl;
	}

	else{

		while(ifs >> in){

			if (in == 's'){

				++studentCounter;
					ifs >> ID >> last >> first >> type;
				Student stu(ID, last, first, type);
				students.add(stu);
				}

			if (in == 'c'){

				char* nameStr = new char[30];
				char* locationStr = new char[20];

				++courseCounter;
					ifs >> ID;
					ifs.ignore();
						ifs.getline(nameStr, 30);
				ifs.clear();
						ifs.ignore();
				ifs.getline(locationStr, 20);
						ifs.clear();
				ifs >> time.hr >> time.min >> time.period;

				Course cou(ID, nameStr, locationStr, time);
				courses.add(cou);

				delete[] nameStr;
				delete[] locationStr;

				}

			if (in == 'e'){

				++enrollmentCounter;
				enr.load(ifs);
				enrollments.add(enr);
				courses.updateStudents(courses.searchIndex(enr.printCourseID()), enr.printStudentID());
				students.updateCourses(students.searchIndex(enr.printStudentID()), enr.printCourseID());
				}


			}

			cout << "Successfully loaded your gradebook!" << endl;

		}

		ifs.close();

		return;
}