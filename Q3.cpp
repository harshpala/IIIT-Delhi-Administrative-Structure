#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

const int MAX_EMPLOYEES = 100;
const int MAX_DEPARTMENTS = 6;

class Officer {
protected:
    string name;
    string phone_number;
    string email;
    string room_number;
    string position;

public:
    Officer(const string& name, const string& phone_number, const string& email, const string& room_number, const string& position)
        : name(name), phone_number(phone_number), email(email), room_number(room_number), position(position) {}


    const string& getName() const { return name; }
    const string& getPhoneNumber() const { return phone_number; }
    const string& getEmail() const { return email; }
    const string& getRoomNumber() const { return room_number; }
    const string& getPosition() const { return position; }

    virtual void printInfo() const {
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phone_number << endl;
        cout << "Email: " << email << endl;
        cout << "Room Number: " << room_number << endl;
        cout << "Position: " << position << endl;
    }
};

class Dean : public Officer {
protected:
    string department;

public:
    Dean(const string& name, const string& phone_number, const string& email, const string& room_number, const string& position, const string& department)
        : Officer(name, phone_number, email, room_number, position), department(department) {}

    virtual ~Dean() {}

    const string& getDepartment() const { return department; }

    void printInfo() const override {
        Officer::printInfo();
        cout << "Department: " << department << endl;
    }
};

class AssociateDean : public Dean {
public:
    AssociateDean(const string& name, const string& phone_number, const string& email, const string& room_number, const string& position, const string& department)
        : Dean(name, phone_number, email, room_number, position, department) {}

};

class Registrar : public Officer {
public:
    Registrar(const string& name, const string& phone_number, const string& email, const string& room_number, const string& position)
        : Officer(name, phone_number, email, room_number, position) {}

};

class Director : public Officer {
public:
    Director(const string& name, const string& phone_number, const string& email, const string& room_number, const string& position)
        : Officer(name, phone_number, email, room_number, position) {}

    virtual ~Director() {}
};

class AdministrativeDepartment {
private:
    string departmentName;
    Dean* dean;
    AssociateDean* associateDean;
    Officer* staff[MAX_EMPLOYEES];
    int staffCount;

public:
    AdministrativeDepartment(const string& name)
        : departmentName(name), dean(nullptr), associateDean(nullptr), staffCount(0) {}



    const string& getDepartmentName() const { return departmentName; }

    void assignDean(Dean* d) { dean = d; }
    void assignAssociateDean(AssociateDean* ad) { associateDean = ad; }
    void addStaff(Officer* p) { 
        if (staffCount < MAX_EMPLOYEES) {
            staff[staffCount++] = p; 
        }
    }

    Officer* findOfficer(const string& name) const {
        for (int i = 0; i < staffCount; ++i) {
            if (refactor(staff[i]->getName(), name)) {
                return staff[i];
            }
        }
        if (associateDean && refactor(associateDean->getName(), name)) {
            return associateDean;
        }
        if (dean && refactor(dean->getName(), name)) {
            return dean;
        }
        return nullptr;
    }

    Officer* getNextSeniorOfficer(const Officer* currentOfficer) const {
        if (dynamic_cast<const Dean*>(currentOfficer)) {
            return nullptr; // Dean is the highest level in the department
        }
        if (dynamic_cast<const AssociateDean*>(currentOfficer)) {
            return dean;
        }
        if (associateDean) {
            return associateDean;
        }
        if (dean) {
            return dean;
        }
        return nullptr; // If no higher level found in the department
    }

    static bool refactor(const string& str, const string& substr) {
        string lowerStr = toLower(str);
        string lowerSubstr = toLower(substr);
        return findSubstring(lowerStr, lowerSubstr);
    }

    static string toLower(const string& str) {
        string lowerStr = str;
        for (size_t i = 0; i < lowerStr.length(); ++i) {
            lowerStr[i] = tolower(lowerStr[i]);
        }
        return lowerStr;
    }

    static bool findSubstring(const string& str, const string& substr) {
        size_t strLen = str.length();
        size_t substrLen = substr.length();

        if (substrLen > strLen) {
            return false;
        }

        for (size_t i = 0; i <= strLen - substrLen; ++i) {
            size_t j;
            for (j = 0; j < substrLen; ++j) {
                if (str[i + j] != substr[j]) {
                    break;
                }
            }
            if (j == substrLen) {
                return true;
            }
        }
        return false;
    }
};

string trim(const string& str) {
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        if (first == string::npos || last == string::npos)
            return "";
        return str.substr(first, (last - first + 1));
    }
string toLower(const string& str) {
    string result = str;
    for (char& c : result) {
        c = tolower(c);
    }
    return result;
}

class ComplaintSystem {
private:
    AdministrativeDepartment* departments[MAX_DEPARTMENTS];
    int departmentCount;
    Registrar* registrar;

public:
    ComplaintSystem() : departmentCount(0), registrar(nullptr) {}

    void addDepartment(AdministrativeDepartment* dept) {
        if (departmentCount < MAX_DEPARTMENTS) {
            departments[departmentCount++] = dept;
        }
    }

    void setRegistrar(Registrar* reg) {
        registrar = reg;
    }

    AdministrativeDepartment** getDepartments() {
        return departments;
    }

    int getDepartmentCount() const {
        return departmentCount;
    }

    Registrar* getRegistrar() const {
        return registrar;
    }

    void handleComplaint(const string& officerName) {
        Officer* officer = nullptr;
        AdministrativeDepartment* officerDept = nullptr;

        // Check if the complaint is against the registrar
        if (registrar && AdministrativeDepartment::refactor(registrar->getName(), officerName)) {
            cout << "The complaint can't be escalated as it's against the Registrar." << endl;
            return;
        }

        // Find the officer and their department
        for (int i = 0; i < departmentCount; ++i) {
            officer = departments[i]->findOfficer(officerName);
            if (officer) {
                officerDept = departments[i];
                break;
            }
        }

        if (!officer) {
            cout << "Officer not found." << endl;
            return;
        }

        cout << "Department: " << officerDept->getDepartmentName() << endl;
        cout << "Position: " << officer->getPosition() << endl;

        string resolved;
        cout << "Has complaint been resolved? (Yes/No): ";
        cin >> resolved;

        if (toLower(resolved) == "yes") {
            cout << "Complaint has been closed." << endl;
        } else {
            string threeDaysPassed;
            cout << "Have 3 days passed? (Yes/No): ";
            cin >> threeDaysPassed;

            if (toLower(threeDaysPassed) == "yes") {
                Officer* nextOfficer = officerDept->getNextSeniorOfficer(officer);
                if (nextOfficer) {
                    cout << "Complaint escalated to " << nextOfficer->getName() << " (" << nextOfficer->getPosition() << ")" << endl;
                } else if (registrar) {
                    cout << "Complaint escalated to Registrar: " << registrar->getName() << endl;
                } else {
                    cout << "No higher authority available for escalation." << endl;
                }
            } else {
                cout << "Please wait for 3 days before escalation." << endl;
            }
        }
    }
};

string getDepartment(const string& position) {
    if (position.find("IRD") != string::npos) {
        return "IRD";
    } else if (position.find("Academic") != string::npos) {
        return "Academics";
    } else if (position.find("Student Affairs") != string::npos) {
        return "Student Affairs";
    } else if (position.find("Store & Purchase") != string::npos) {
        return "Store & Purchase";
    } else if (position.find("Library") != string::npos) {
        return "Library";
    } else {
        return "Other";
    }
}


bool isAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == '.');
}

bool isSpace(char c) {
    return c == ' ';
}



bool isValidName(const string& name) {
    if (name.empty() || trim(name).length() == 0) {
        return false; // Empty or whitespace only
    }
    
    for (char c : name) {
        if (!isAlpha(c) && !isSpace(c)) {
            return false; // Invalid character found
        }
    }
    return true; // Valid name
}

int main() {
    ComplaintSystem complaintSystem;

    // Create departments
    AdministrativeDepartment* ird = new AdministrativeDepartment("IRD");
    AdministrativeDepartment* academics = new AdministrativeDepartment("Academics");
    AdministrativeDepartment* studentAffairs = new AdministrativeDepartment("Student Affairs");
    AdministrativeDepartment* storePurchase = new AdministrativeDepartment("Store & Purchase");
    AdministrativeDepartment* library = new AdministrativeDepartment("Library");

    complaintSystem.addDepartment(ird);
    complaintSystem.addDepartment(academics);
    complaintSystem.addDepartment(studentAffairs);
    complaintSystem.addDepartment(storePurchase);
    complaintSystem.addDepartment(library);

    // Read data from CSV and populate departments
    ifstream file("C:/Users/harsh/Documents/MTech/OOPD/Assignment/Assignment 2/Assignment-2A/MT24119/data/data.csv");
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    string line;
    getline(file, line); // Skip header

    while (getline(file, line)) {
        string level, position, name, degree, phone_number, fax_number, email, secondary_email, address;
        stringstream ss(line);
        getline(ss, level, ',');
        getline(ss, position, ',');
        getline(ss, name, ',');
        getline(ss, degree, ',');
        getline(ss, phone_number, ',');
        getline(ss, fax_number, ',');
        getline(ss, email, ',');
        getline(ss, secondary_email, ',');
        getline(ss, address, ',');

        Officer* newOfficer = nullptr;
        string departmentName = getDepartment(position);
        AdministrativeDepartment* dept = nullptr;
        AdministrativeDepartment** departments = complaintSystem.getDepartments();

        for (int i = 0; i < complaintSystem.getDepartmentCount(); ++i) {
            if (departments[i]->getDepartmentName() == departmentName) {
                dept = departments[i];
                break;
            }
        }

        if (position.find("Registrar") != string::npos) {
            Registrar* newRegistrar = new Registrar(name, phone_number, email, address, position);
            complaintSystem.setRegistrar(newRegistrar);
        } else if (position.find("Director") != string::npos) {
            newOfficer = new Director(name, phone_number, email, address, position);
        } else if (position.find("Dean") != string::npos) {
            if (position.find("Associate Dean") != string::npos) {
                newOfficer = new AssociateDean(name, phone_number, email, address, position, departmentName);
                if (dept) dept->assignAssociateDean(static_cast<AssociateDean*>(newOfficer));
            } else {
                newOfficer = new Dean(name, phone_number, email, address, position, departmentName);
                if (dept) dept->assignDean(static_cast<Dean*>(newOfficer));
            }
        } else {
            newOfficer = new Officer(name, phone_number, email, address, position);
        }

        if (newOfficer && dept) {
            dept->addStaff(newOfficer);
        }
    }

    file.close();

    

    // Handle complaints
    string officerName;
    string continueInput;
    do{
    cout << "Enter the name of the officer to which complaint is filed: ";
    cin.ignore(); // Clear any leftover newline characters
    getline(cin, officerName);
    if (isValidName(officerName)) {
        
    complaintSystem.handleComplaint(officerName);
    cout << "Do you want to continue? (Yes/No): ";
    cin >> continueInput;
            
        } else {
            cerr << "Invalid name entered. Please enter a valid name (letters and spaces only)." << endl;
        }
    } while (toLower(continueInput) == "yes");

    return 0;
}