#include "School.h"

School::School() {
    name = "";
    studentAmount = 0;
    studentAmountNextYear = studentAmount;
}

School::School(const School& scl) {
    name = scl.name;
    studentAmount = scl.studentAmount;
    studentAmountNextYear = scl.studentAmountNextYear;
}

School::School(string Name, float amount) {
    name = Name;
    studentAmount = amount;
    studentAmountNextYear = studentAmount;
}

School::~School() {
    
}

void School::admissions(float amount) {
    if(amount > 0) studentAmount += amount;
}

void School::dropouts(float amount) {
    if(amount >= 0 && amount <= studentAmount) studentAmount -= amount;
}

void School::transfer(float amount, School& toSchool) {
    if(amount >= 0 && amount <= studentAmount) {
        this->dropouts(amount);
        toSchool.admissions(amount);
    }
}

ostream& operator<< (ostream& otp, const School& scl) {
    otp << scl.name << "\t" << scl.studentAmount << "\t" << scl.studentAmountNextYear;
    return otp;
}

PrivateSchool::PrivateSchool() {
    dropoutCount = 0;
}

PrivateSchool::PrivateSchool(const PrivateSchool& pvscl) {
    name = pvscl.name;
    studentAmount = pvscl.studentAmount;
    studentAmountNextYear = pvscl.studentAmountNextYear;
    dropoutCount = pvscl.dropoutCount;
}

PrivateSchool::PrivateSchool(string Name, float amount) {
    name = Name;
    studentAmount = amount;
    studentAmountNextYear = studentAmount;
    dropoutCount = 0;
}

PrivateSchool::~PrivateSchool() {
    
}

void PrivateSchool::dropouts(float amount) {
    if(amount >= 0 && amount <= studentAmount) {
        dropoutCount++;
        studentAmount -= amount;
        if(dropoutCount >= 2) studentAmountNextYear -= 100;
    }
}

PublicSchool::PublicSchool() {
    growing_rate = 0.05;
}

PublicSchool::PublicSchool(const PublicSchool& pbscl) {
    name = pbscl.name;
    studentAmount = pbscl.studentAmount;
    studentAmountNextYear = pbscl.studentAmountNextYear;
    growing_rate = pbscl.growing_rate;
}

PublicSchool::PublicSchool(string Name, float amount) {
    name = Name;
    studentAmount = amount;
    studentAmountNextYear = studentAmount;
    growing_rate = 0.05;
}

PublicSchool::~PublicSchool() {
    
}

void PublicSchool::apply_growth() {
    studentAmountNextYear += growing_rate * studentAmountNextYear;
}

void PublicSchool::dropouts(float amount) {
    if(amount >= 0 && amount <= studentAmount) {
        studentAmount -= amount;
        if(amount > 100) {
            studentAmountNextYear *= 0.95;
            int tmp = studentAmountNextYear;
            studentAmountNextYear = tmp;
        }
    }
}
