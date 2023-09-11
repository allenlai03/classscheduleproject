
#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <set>

class Course
{
public:
    // Constructors
    Course() : courseNumber(0), courseName("N/A"), courseUnits(0) {};
    //Course();
    
    Course(int theCourseNumber, const std::string& theCourseName, int theCourseUnits,const std::set<int>& thePrereqs);
    
    // Accessor functions
    const std::string& getCourseName() const;
    
    int getCourseNumber() const;
    
    int getCourseUnits() const;
    
    const std::set<int>& getCoursePrereqs() const;
    
    const Course& getCourse() const;
    
    static std::string getPrefix();
    
    // Mutator functions
    void setCourseName(const std::string& theCourseName);
    
    void setCourseNumber(int theCourseNumber);
    
    void setCourseUnits(int theCourseUnits);
    
    void setPrereqs(const int prereqsArr[], int arrLength);
    
    // Destructor
    ~Course() {};
    
private:
    int courseNumber;
    std::string courseName;
    int courseUnits;
    std::set<int> prereqs;
    static const std::string PREFIX;
};
#endif
