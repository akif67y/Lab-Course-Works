#include<iostream>
#include<string>
using namespace std;
int totalStudents = 0;

class Course {
    private :
    string name;
    float creditHour;
    public :
    Course(){
        name = "Not set";
        creditHour = 0;
    }
    Course(string name, float creditHour){
        this->name = name;
        this->creditHour = creditHour;
    }
    string getName(){return name;}
    float getCreditHour() {return creditHour;}
    void setName(string name)  {this->name = name;}
    void  setCreditHour(float  creditHour) {this->creditHour = creditHour;} 
    void display() {
        cout << "Course Name: "<< name <<" ,";
        cout <<"Credit hour: " << creditHour<<' ';
    }


};

class Student{
    private :
    string name;
    int id ;
    Course *courses;
    int totalCourse;
    int maxCourses;
    float *gradePoints;
    public :
    Student(){
        name = "not set";
        id = 0;
        totalCourse = 0;
        maxCourses = 0;
        courses = new Course[6];
        gradePoints = new float[6];
    }
    Student(string  name,  int  id,  int maxCourses){
        this->name = name;
        this->id = id;
        this->maxCourses = maxCourses;
        this->totalCourse = 0;
        courses = new Course[maxCourses];
        gradePoints = new float[maxCourses];
    }
    Student(const Student& temp){
        name = temp.name;
        id = temp.id;
        totalCourse = temp.totalCourse;
        maxCourses = temp.maxCourses;
        courses = new Course[maxCourses];
        gradePoints = new float[maxCourses];
        for(int i = 0; i < totalCourse; i++){
            courses[i] = temp.courses[i];
            gradePoints[i] = temp.gradePoints[i];
        }
    }
    ~Student(){
       delete [] courses;
       delete [] gradePoints;
    }
void setName(string name)  {this->name = name;}
 void setId(int id) {this->id = id;}  
 void  setInfo(string  name,  int  id)  {this->name = name;this->id = id;}
  void  addCourse(Course  c){
    if(totalCourse < maxCourses){
    courses[totalCourse] = c;
    gradePoints[totalCourse] =  0;
    totalCourse++;
    }
    else{
        cout <<"Cannot Add any more course to " << name <<'\n';
    }
    
  }
void  addCourse(Course  course,  float  gradePoint) {
    if(totalCourse < maxCourses){
        courses[totalCourse] = course;
        gradePoints[totalCourse] =  gradePoint;
        totalCourse++;
        }
        else{
            cout <<"Cannot Add any more course to " << name <<'\n';
        }
}
  void  setgradePoint(Course  c,  float  gradePoint){
        for(int i = 0; i < totalCourse; i++){
            if(courses[i].getName() == c.getName() ){
                gradePoints[i] = gradePoint;
            }
        }
  }   
 void  setgradePoint(float*  gradePoints,  int  n){
    for(int i = 0; i < n && i < totalCourse; i++){
        this->gradePoints[i] = gradePoints[i];
    }
 }
  string getName(){return name;}
  float  getTotalCreditHours(){
 
    float ans = 0;
    for(int i = 0; i < totalCourse; i++){
        ans += courses[i].getCreditHour();
    }
    return ans;
  }  
  float  getCGPA() {
    float upore= 0;
    float niche = getTotalCreditHours();
    for(int i = 0; i < totalCourse; i++){
        upore += courses[i].getCreditHour() * gradePoints[i];
    }
    if(niche == 0){
        cout <<"Error: Zero total credit\n";
        return -1;
    }
    float ans = upore/niche;
    return ans;
  }
 float  getgradePoint(Course  c) {
    for(int i = 0; i < totalCourse; i++){
        if(courses[i].getName() == c.getName() ){
            return gradePoints[i];
        }
    }
    return 0; // jodi na thake
 }  
  int  getTotalCourses(){
    return totalCourse;
  }  

Course getMostFavoriteCourse(){
    int indx = 0;
    int highestgrade = gradePoints[0];
    for(int i = 1; i < totalCourse; i++){
       if(gradePoints[i] > highestgrade){
        highestgrade = gradePoints[i];
        indx = i;
       }
    }
    return courses[indx];
}
 Course getLeastFavoriteCourse(){
    int indx = 0;
    int highestgrade = gradePoints[0];
    for(int i = 1; i < totalCourse; i++){
       if(gradePoints[i] < highestgrade){
        highestgrade = gradePoints[i];
        indx = i;
       }
    }
    return courses[indx];
  }
Course*  getFailedCourses(int  &count){
    int failed[maxCourses];
    int indx = 0;
    for(int i = 0; i < totalCourse; i++){
        if(gradePoints[i] < 2){
            failed[indx] = i;
            indx++;
        }
    }
    Course *ans = new Course[indx];
    for(int i = 0 ; i < indx; i++){
        ans[i] = courses[failed[i]];
    }
    count = indx;
    return ans;

 }  
 void  display() {
    cout <<"Student Name: "<< name <<" ,";
    cout << "ID: "<< id <<'\n';
    for(int i = 0; i < totalCourse; i++){
        courses[i].display();
        cout <<" ,gained grade : "<< gradePoints[i] <<'\n';
    };
    cout << "CGPA:" << getCGPA()<<'\n';
    cout << "Total credits Earned: "<< getTotalCreditHours() <<'\n';
    cout <<"Favourite Course: " ;
    cout << getMostFavoriteCourse().getName() <<"\n";
    cout <<"\n";
    cout <<"Least favourite Course: " ;
    cout << getLeastFavoriteCourse().getName() <<"\n";
    cout <<"\n";
 }

};



Student * students[180];

Student getTopper(){
    int ans = 0;
    float highestCGPA = students[0]->getCGPA();
    for(int i = 1; i < totalStudents; i++){
        if(students[i]->getCGPA() > highestCGPA){
            highestCGPA = students[i]->getCGPA();
            ans = i;
        }
    }
    return *students[ans];
}
Student getTopper(Course c){
    int ans = 0;
    float highestgrade = 0;
    for(int i = 0; i < totalStudents; i++){
        if(students[i]->getgradePoint(c) > highestgrade){
            ans = i;
            highestgrade = students[i]->getgradePoint(c);
        }
    }
    if(highestgrade > 0){
        return *students[ans];
    }
    else{
        return *students[ans];
    }

}
int main(){
    
        // generate courses 

        const int COURSE_COUNT = 6; 
        Course courses[COURSE_COUNT] = { 
        Course("CSE107", 3), 
        Course("CSE105", 3), 
        Course("CSE108", 1.5), 
        Course("CSE106", 1.5), 
        Course("EEE164", 0.75), 
        Course("ME174", 0.75), 
        }; 
        float gradePoints[COURSE_COUNT] = {4.0, 4.0, 3.5, 3.5, 4.0, 3.25}; 
        // generate students 
        Student s1 = Student("Sheldon", 1, 5); 
        students[totalStudents++] = &s1; 
        // add courses to s1 
        s1.addCourse(courses[0]); 
        s1.addCourse(courses[1]); 
        s1.addCourse(courses[2]); 
        s1.addCourse(courses[3]); 
        s1.addCourse(courses[4]); 
        s1.addCourse(courses[5]); 
        s1.setgradePoint(gradePoints, s1.getTotalCourses()); 
        cout << "==================================" << endl; 
        s1.display(); 
        cout << "==================================" << endl; 
        Student s2 = Student("Penny", 2, 5); 
        students[totalStudents++] = &s2; 
        s2.addCourse(courses[0]); 
        s2.addCourse(courses[2]); 
        s2.addCourse(courses[5]); 
        s2.setgradePoint(gradePoints, s2.getTotalCourses()); 
        s2.setgradePoint(courses[0], 3.25); 
        cout << "==================================" << endl; 
        s2.display(); 
        cout << "==================================" << endl; 
        Student s3 = s2; 
        students[totalStudents++] = &s3; 
        s3.setName("Leonard"); 
        s3.setId(3); 
        s3.setgradePoint(gradePoints, s3.getTotalCourses()); 
        s3.addCourse(courses[1], 3.75);
        cout << "==================================" << endl;  
        s3.display(); 
        cout << "==================================" << endl; 
        Student s4 = s3; 
        students[totalStudents++] = &s4; 
        s4.setInfo("Howard", 4); 
        s4.setgradePoint(gradePoints, s4.getTotalCourses()); 
        s4.addCourse(courses[3], 3.75); 
        cout << "==================================" << endl; 
        s4.display(); 
        cout << "==================================" << endl; 
        Student s5 = s4; 
        students[totalStudents++] = &s5; 
        s5.setInfo("Raj", 5); 
        s5.setgradePoint(gradePoints, s5.getTotalCourses()); 
        s5.setgradePoint(courses[0], 1.5); 
        s5.setgradePoint(courses[2], 2.0); 
        s5.setgradePoint(courses[5], 1.75); 
        s5.setgradePoint(courses[3], 3.75); 
        cout << "==================================" << endl; 
        s5.display(); 
        cout << "==================================" << endl; 
        int failedCount; 
        Course* failedCourses = s5.getFailedCourses(failedCount); 
        cout << "Failed Courses for " << s5.getName() << ":" << endl; 
        for (int i = 0; i < failedCount; ++i) { 
        failedCourses[i].display(); 
        cout << endl; 
        } 
        delete[] failedCourses; 
        cout << "==================================" << endl; 
        Student topper = getTopper(); 
        cout << "Topper: " << topper.getName() << endl; 
        cout << "Topper CGPA: " << topper.getCGPA() << endl; 
        cout << "==================================" << endl; 
        for (int i = 0; i < COURSE_COUNT; ++i) { 
        Course c = courses[i]; 
        Student topperInCourse = getTopper(c); 
        cout << "Topper in " << c.getName() << ": " << 
        topperInCourse.getName() << endl; 
        cout << "Topper in " << c.getName() << " gradePoint: " << 
        topperInCourse.getgradePoint(c) << endl; 
        cout << "==================================" << endl; 
        } 
        return 0; 
        

}