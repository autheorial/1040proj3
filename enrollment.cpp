#include "enrollment.h"

Enrollment::Enrollment(){
	ID = 000000;
	studentID = 000000;
	courseID = 000000;
	numGrades = 0;
	e = 'e';
}

void Enrollment::setInfo(int count, int studentID, int courseID, int numGrades){

	ID = 1 + count;
	this->studentID = studentID;
	this->courseID = courseID;
	this->numGrades = numGrades;
	grades = new int[numGrades];

	for(int i = 0; i < numGrades; ++i){
		cout << "Grade #" << i + 1 << ": ";
		cin >> grades[i];
	}
	
}

void Enrollment::addGrades(int numAdding){

	int* temp = new int[numGrades + numAdding];

	for(int i = 0; i < numGrades; ++i){
		temp[i] = grades[i];
	}

	delete[] grades;

	numGrades += numAdding;

	for(int i = numGrades - numAdding; i < numGrades; ++i){
		cout << "Grade #" << i + 1 << ": ";
		cin >> temp[i];
	}

	grades = new int[numGrades];

	for(int i = 0; i < numGrades; ++i){
		grades[i] = temp[i];
	}

	delete[] temp;

}

int Enrollment::printOverall(){

	char letter;
	int overall = 0;

	for(int i = 0; i < numGrades; ++i){
		overall += grades[i];
	}

	return overall / numGrades;

}

char Enrollment::printLetterGrade(){

	int overall = Enrollment::printOverall();

	if(overall >= 90){
		return 'A';
		}
		else if(overall >= 80){
		return 'B';
		}
		else if(overall >= 70){
		return 'C';
		}
		else if(overall >= 60){
		return 'D';
		}
		else{
		return 'F';
		}

}

void Enrollment::printGrades(){

	char letter, grade;
	int overall = 0;

	for(int i = 0; i < numGrades; ++i){

		cout.width(37); cout << grades[i];

		if(grades[i] >= 90){
		letter = 'A';
		}
		else if(grades[i] >= 80){
			letter = 'B';
		}
		else if(grades[i] >= 70){
			letter = 'C';
		}
		else if(grades[i] >= 60){
			letter = 'D';
		}
		else{
			letter = 'F';
		}
		cout.width(35); cout << letter << endl;

		overall += grades[i];

	}

	overall = overall / numGrades;

	if(overall >= 90){
		letter = 'A';
		}
		else if(overall >= 80){
			letter = 'B';
		}
		else if(overall >= 70){
			letter = 'C';
		}
		else if(overall >= 60){
			letter = 'D';
		}
		else{
			letter = 'F';
		}


	for (int i = 0; i < 72; ++i){
						cout << "-";
					}
	cout << endl;
	cout.width(35); cout << left << "OVERALL";
	cout.width(16); cout << overall;
	cout.width(21); cout << right << letter << endl;
	
	return;
}

void Enrollment::save(ofstream& ofs){

	ofs.width(1); ofs << e;
	ofs.width(10); ofs << ID;
	ofs.width(30); ofs << studentID;
	ofs.width(20); ofs << courseID;
	ofs.width(20); ofs << numGrades;
	for(int i = 0; i < numGrades; ++i){
		ofs.width(4); ofs << grades[i];
	}
	ofs << endl;

	return;

}

void Enrollment::load(ifstream& ifs){
	ifs >> ID >> studentID >> courseID >> numGrades;
	grades = new int[numGrades];

	for(int i = 0; i < numGrades; ++i){
		ifs >> grades[i];
	}
	return;
}