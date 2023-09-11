
#include "CourseList.h"

// Definition function insertInOrder
// Assume there are no duplicates.
void CourseList::insertInOrder(Node* otherCourse)
{
    int otherCourseNumber = (otherCourse->getCourse()).getCourseNumber();

    if(first == nullptr)
    {
        last = otherCourse;
        first = last;
    }

    else
    {
        if ((first->getCourse()).getCourseNumber() > otherCourseNumber)
        {
            otherCourse->setNext(first);
            first = otherCourse;
        }
        
        else if((last->getCourse()).getCourseNumber() < otherCourseNumber)
        {
            last->setNext(otherCourse);
            last = otherCourse;
        }
        
        else
        {
            Node* current = first->getNext();
            Node* trailCurrent = first;
            while(current != nullptr &&
                  ((current->getCourse()).getCourseNumber() < otherCourseNumber))
            {
                current = current->getNext();
                trailCurrent = trailCurrent->getNext();
            }
            trailCurrent->setNext(otherCourse);
            otherCourse->setNext(current);
        }
    }
    count++;
}
