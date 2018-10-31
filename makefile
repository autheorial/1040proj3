gradebook : main.o students.o student.o courses.o course.o enrollments.o enrollment.o
	g++ main.o students.o student.o courses.o course.o enrollments.o enrollment.o -o gradebook

main.o : main.h students.h courses.h enrollments.h student.h course.h enrollment.h time.h header.h
	g++ -c $*.cpp

students.o : students.h student.h header.h
	g++ -c $*.cpp

student.o : student.h header.h
	g++ -c $*.cpp

courses.o : courses.h course.h header.h time.h
	g++ -c $*.cpp

course.o : course.h header.h time.h
	g++ -c $*.cpp

enrollments.o : enrollments.h enrollment.h
	g++ -c $*.cpp

enrollment.o : enrollment.h
	g++ -c $*.cpp

run : gradebook
	./gradebook

clean :
	rm *.o gradebook