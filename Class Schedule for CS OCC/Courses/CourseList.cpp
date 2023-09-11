

#include "CourseList.h"

#include <iostream>
using namespace std;

// Definition function addCourse
void CourseList::addCourse(const Course& newCourse)
{
    insertInOrder(new Node(newCourse, nullptr));
}
// Definition function addCourse
void CourseList::addCourse(int otherCourseNumber, const string& otherCourseName, int otherCourseUnits, const set<int>& otherPrereqs)
{
    insertInOrder(new Node(Course(otherCourseNumber, otherCourseName, otherCourseUnits, otherPrereqs), nullptr));
}
// Definition function getPrefix
string CourseList::getPrefix() const
{
    return Course::getPrefix();
}

// Definition function getNumberOfCourses
int CourseList::getNumberOfCourses() const
{
    return count;
}
// Definition function isEmpty
bool CourseList::isEmpty() const
{
    return count == 0;
}
// Definition function searchCourse (courseNumber)
// Assume list is non-empty.
bool CourseList::searchCourse(int otherCourseNumber) const
{
    return getCourseLocation(otherCourseNumber) != nullptr;
}

// Definition function searchCourse (courseNumber, courseName)
// Assume list is non-empty.
bool CourseList::searchCourse(int otherCourseNumber, string& otherCourseName) const
{
    Node* otherCourse = getCourseLocation(otherCourseNumber);
    if (otherCourse != nullptr)
    {
        otherCourseName = (otherCourse->getCourse()).getCourseName();
        return true;
    }
    return false;
}
// Definition function searchCourse(courseNumber, course)
// Assume list is non-empty.
bool CourseList::searchCourse(int otherCourseNumber, Course& paramCourse) const
{
    Node* otherCourse = getCourseLocation(otherCourseNumber);
    if (otherCourse != nullptr)
    {
        paramCourse = otherCourse->getCourse();
        return true;
    }
    return false;
}
// Definitiion deleteCourse
// Assume list is non-empty.
// Assume course is in the list.
void CourseList::deleteCourse(int theCourseNumber)
{
    if(first == nullptr)
    {
        cerr << "Cannot delete an empty list." << endl;
    }
    else if(count == 1)
    {
        delete first;
        first = nullptr;
        last = nullptr;
    }
    else
    {
        Node* current = first->getNext();
        Node* trailCurrent = first;
        
        if((trailCurrent->getCourse()).getCourseNumber() == theCourseNumber)
        {
            delete trailCurrent;
            first = current;
            current = nullptr;
            trailCurrent = nullptr;
        }
        
        else
        {
            while(current != nullptr)
            {
                
                if((current->getCourse()).getCourseNumber() == theCourseNumber)
                {
                    trailCurrent->setNext(current->getNext());
                    delete current;
                    current = nullptr;
                    trailCurrent = nullptr;
                }
                else
                {
                    current = current->getNext();
                    trailCurrent = trailCurrent->getNext();
                }
            }
        }
    }
    count--;
}

// Definition retrieveAllCourses
// Assume list is non-empty.
void CourseList::retrieveAllCourses(string& allCoursesList) const
{
    if(first != nullptr)
    {
        Node* current = first;
        Course currentCourse = current->getCourse();
        while(current != nullptr)
        {
            allCoursesList += currentCourse.getPrefix() + to_string(currentCourse.getCourseNumber()) + " - "
            + currentCourse.getCourseName() + "\n";
            
            current = current->getNext();
            if(current != nullptr)
            {
                currentCourse = current->getCourse();
            }
        }
    }
}

// Definition clearList
void CourseList::clearList()
{
    if(first == nullptr)
    {
        first = nullptr;
        last = nullptr;
    }
    else
    {
        Node* current = first->getNext();
        while(first != nullptr)
        {
            delete first;
            first = current;
            if (current != nullptr)
            {
                current = current->getNext();
            }
        }
        last = nullptr;
    }
    count = 0;
}
// Definition function getCourseLocation
Node* CourseList::getCourseLocation(int courseNumber) const
{
    Node* current = first;
    while(current != nullptr)
    {
        if ((current->getCourse()).getCourseNumber() == courseNumber)
        {
            return current;
        }
        current = current ->getNext();
    }
    return nullptr;
}
