
#include "CourseList.h"

#include <iostream>
using namespace std;

// Copy constructor
CourseList::CourseList(const CourseList& otherCourseList)
{
    if(otherCourseList.first == nullptr)
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else
    {
        Node* callingCurrent = new Node(otherCourseList.first->getCourse(), nullptr);
        first = callingCurrent;
        Node* paramCurrent = otherCourseList.first->getNext();
        
        while(paramCurrent != nullptr)
        {
            callingCurrent->setNext(new Node(paramCurrent->getCourse(), nullptr));
            callingCurrent = callingCurrent->getNext();
            paramCurrent = paramCurrent->getNext();
        }
        last = callingCurrent;
        count = otherCourseList.count;
    }
}
// Definition overloaded assignment operator
CourseList& CourseList::operator=(const CourseList& otherCourseList)
{
    if (&otherCourseList == this)
    {
        cerr << "Attemped assignment to itself.";
    }
    else if (otherCourseList.count == 0)
    {
        this->clearList();
    }
    else if (count == 0)
    {
        copyCallingObjIsEmpty(*this);
    }
    else if (count == otherCourseList.count)
    {
        this->copyObjectsSameLength(otherCourseList);
    }
    else if(count < otherCourseList.count)
    {
        this->copyCallingObjShorter(otherCourseList);
    }
    else
    {
        this->copyCallingObjLonger(otherCourseList);
    }
    return *this;
}
// Definition function copyCallingObjIsEmpty
void CourseList::copyCallingObjIsEmpty(const CourseList& otherCourseList)
{
    if(otherCourseList.first == nullptr)
    {
        first = nullptr;
        last = nullptr;
    }
    else
    {
        Node* callingCurrent = new Node(otherCourseList.first->getCourse(), nullptr);
        first = callingCurrent;
        Node* paramCurrent = otherCourseList.first->getNext();
        
        while(paramCurrent != nullptr)
        {
            callingCurrent->setNext(new Node(paramCurrent->getCourse(), nullptr));
            callingCurrent = callingCurrent->getNext();
            paramCurrent = paramCurrent->getNext();
        }
        last = callingCurrent;
    }
    count = otherCourseList.count;
}
// Definition function copyObjectsSameLength
void CourseList::copyObjectsSameLength(const CourseList& otherCourseList)
{
    Node* callingCurrent = first;
    Node* paramCurrent = otherCourseList.first;
    
    while(paramCurrent != nullptr)
    {
        callingCurrent->setCourse(paramCurrent->getCourse());
        callingCurrent = callingCurrent->getNext();
        paramCurrent = paramCurrent->getNext();
    }
}
// Definition function copyCallingObjLonger
void CourseList::copyCallingObjLonger(const CourseList& otherCourseList)
{
    Node* callingCurrent = first;
    Node* paramCurrent = otherCourseList.first;
    while(paramCurrent != nullptr)
    {
        callingCurrent->setCourse(paramCurrent->getCourse());
        paramCurrent = paramCurrent->getNext();
        if(paramCurrent == nullptr)
        {
            last = callingCurrent;
        }
        callingCurrent = callingCurrent->getNext();
    }
    
    Node* trailCallingCurrent = callingCurrent;
    last->setNext(nullptr);
    callingCurrent = trailCallingCurrent -> getNext();
        
    while(trailCallingCurrent != nullptr)
    {
        delete trailCallingCurrent;
        trailCallingCurrent = callingCurrent;
        if (callingCurrent != nullptr)
        {
            callingCurrent = callingCurrent ->getNext();
        }
    }
    count = otherCourseList.count;
}
// Definition function copyCallingObjShorter
void CourseList::copyCallingObjShorter(const CourseList& otherCourseList)
{
    Node* callingCurrent = first;
    Node* paramCurrent = otherCourseList.first;
    
    while(callingCurrent != nullptr)
    {
        callingCurrent->setCourse(paramCurrent->getCourse());
        if (callingCurrent->getNext() == nullptr)
        {
            last = callingCurrent;
        }
        callingCurrent = callingCurrent->getNext();
        paramCurrent = paramCurrent->getNext();
    }
    callingCurrent = last;
    while(paramCurrent != nullptr)
    {
        callingCurrent->setNext(new Node(paramCurrent->getCourse(), nullptr));
        callingCurrent = callingCurrent->getNext();
        paramCurrent = paramCurrent->getNext();
    }
    last = callingCurrent;
    count = otherCourseList.count;
}
// Destructor
CourseList::~CourseList()
{
    if (count != 0)
    {
        this->clearList();

    }
}
