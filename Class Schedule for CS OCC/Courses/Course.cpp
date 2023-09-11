
#include "Course.h"

#include <iostream>
#include <iomanip>
using namespace std;

const string Course::PREFIX = "CS A";

// Definition overloaded constructor
Course::Course(int theCourseNumber, const string& theCourseName, int theCourseUnits, const set<int>& thePrereqs)
{
    courseNumber = theCourseNumber;
    courseName = theCourseName;
    courseUnits = theCourseUnits;
    prereqs = thePrereqs;
}

// Definition function getCourseNumber
int Course::getCourseNumber() const
{
    return courseNumber;
}

// Definition function getCourseName
const string& Course::getCourseName() const
{
    return courseName;
}

// Definition function getCourseUnits
int Course::getCourseUnits() const
{
    return courseUnits;
}

// Definition function getPrereqs
const set<int>& Course::getCoursePrereqs() const
{
    return prereqs;
}

// Definition function getCourse
const Course& Course::getCourse() const
{
    return *this;
}

// Definition function getPrefix
string Course::getPrefix()
{
    return PREFIX;
}

// Definition function setCourseName
void Course::setCourseName(const std::string& theCourseName)
{
    courseName = theCourseName;
}

// Definition function setCourseNumber
void Course::setCourseNumber(int theCourseNumber)
{
    courseNumber = theCourseNumber;
}

// Definition function setCourseUnits
void Course::setCourseUnits(int theCourseUnits)
{
    courseUnits = theCourseUnits;
}

// Definition function setPrereqs
void Course::setPrereqs(const int prereqsArr[], int arrLength)
{
    for(int i = 0; i < arrLength; ++i)
    {
        prereqs.insert(prereqsArr[i]);
    }
}
