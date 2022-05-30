#ifndef School_h
#define School_h

#include <string>
#include <iostream>
using namespace std;

class School {
protected:
    string name;
    float studentAmount;
    float studentAmountNextYear;
    
public:
    School();
    School(const School& scl);
    School(string Name, float amount);
    ~School();
    void admissions(float amount);
    virtual void dropouts(float amount);
    void transfer(float amount, School& toSchool);
    friend ostream& operator<< (ostream& otp, const School& scl);
    
};

class PrivateSchool : public School{
private:
    float dropoutCount;
    
public:
    PrivateSchool();
    PrivateSchool(const PrivateSchool& pvscl);
    PrivateSchool(string Name, float amount);
    ~PrivateSchool();
    void dropouts(float amount) override;
};

class PublicSchool : public School{
private:
    float growing_rate;
    
public:
    PublicSchool();
    PublicSchool(const PublicSchool& pbscl);
    PublicSchool(string Name, float amount);
    ~PublicSchool();
    void apply_growth();
    void dropouts(float amount) override;
};

#endif /* School_h */
