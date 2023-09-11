

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

#include <string>
#include <set>

class Node
{
public:
    Node() : course(), next(nullptr) {};
    Node(const Course& newCourse, Node* newNext)
    : course(newCourse), next(newNext) {};
    Course getCourse() const { return course; };
    Node* getNext() const { return next; };
    void setCourse(const Course& newCourse) { course = newCourse; };
    void setNext(Node* newNext) { next = newNext; };
    ~Node() {};
private:
    Course course;
    Node* next;
};

class CourseList
{
public:
    // Default constructor
    CourseList() : first(nullptr), last (nullptr), count(0) {}
    
    // Functions addCourse
    void addCourse(const Course& newCourse);
    
    void addCourse(int otherCourseNumber, const std::string& otherCourseName, int otherCourseUnits,
                   const std::set<int>& otherPrereqs);
    
    // Accessor functions
    Node* getFirst() const {return first;};
    
    Node* getLast() const {return last;};
    
    std::string getPrefix() const;
    
    int getNumberOfCourses() const;
    
    // Boolean functions
    bool isEmpty() const;
    
    bool searchCourse(int otherCourseNumber) const;
    
    bool searchCourse(int otherCourseNumber, std::string& otherCourseName) const;
    
    bool searchCourse(int otherCourseNumber, Course& paramCourse) const;
    
    // Function deleteCourse
    void deleteCourse(int theCourseNumber);
    
    // Function retrieveAllCourses
    void retrieveAllCourses(std::string& allCoursesList) const;
    
    // Function clearList
    void clearList();
    
    /********************* THE BIG THREE *********************/
    // Copy constructor
    CourseList(const CourseList& otherCourseList);
    
    // Overloaded assignment operator
    CourseList& operator=(const CourseList& otherCourseList);
    
    // Destructor
    ~CourseList();
    
private:
    // Function getCourseLocation
    Node* getCourseLocation(int courseNumber) const;
    
    // Function addInOrder
    void insertInOrder(Node* otherCourse);
    
    // Helper functions for overloaded assignment operator
    void copyCallingObjIsEmpty(const CourseList& otherCourseList);
    
    void copyObjectsSameLength(const CourseList& otherCourseList);
    
    void copyCallingObjLonger(const CourseList& otherCourseList);
    
    void copyCallingObjShorter(const CourseList& otherCourseList);
    
    Node* first;
    Node* last;
    int count;
};
#endif
