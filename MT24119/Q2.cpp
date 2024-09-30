#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const string CSV_PATH = "C:/Users/harsh/Documents/MTech/OOPD/Assignment/Assignment 2/Assignment-2A/MT24119/data/data2.csv";
const int MAX_DEPARTMENTS = 5;

class Person {
protected:
    string name;
    string address;
    string phone;
    string email;

public:
    Person(string name, string address, string phone, string email)
        : name(name), address(address), phone(phone), email(email) {}

    Person() {}  // Default constructor

    string getName() { return name; }
    string getRoomNumber() { return address; }
    string getPhoneNumber() { return phone; }
    string getEmail() { return email; }

    void display() {
        cout << endl
             << " * Name: " << name << endl
             << " * Room: " << address << endl
             << " * Phone number: " << phone << endl
             << " * Email: " << email << endl;
    }
};

class Faculty : public Person {
protected:
    string position;
public:
    Faculty(string name, string position, string address, string phone, string email)
        : Person(name, address, phone, email), position(position) {}

    Faculty() : Person() {}  // Default constructor

    void display() {
        cout << " * Position: " << position;  // Display the specific position
        Person::display();
    }
};

class HeadOfDepartment : public Faculty {
public:
    HeadOfDepartment(string name, string address, string phone, string email)
        : Faculty(name, "Head Of Department", address, phone, email) {}

    // Default constructor initializing with empty strings
    HeadOfDepartment() : Faculty("", "Head Of Department", "", "", "") {} 

    void display() {
        cout << "Position: " << position << ", ";  // Position will always be "Head Of Department"
        Person::display();
    }
};

    // Utility function to trim spaces from a string
    string trim(const string& str) {
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        if (first == string::npos || last == string::npos)
            return "";
        return str.substr(first, (last - first + 1));
    }

    // Utility function to convert string to lowercase for case-insensitive comparison
    string toLower(const string& str) {
        string result = str;
        for (char& c : result) {
            c = tolower(c);
        }
        return result;
    }

class Department {
private:
    HeadOfDepartment hod;
    Faculty faculty[4];

public:
    Department() {}  // Default constructor

    void setHOD(HeadOfDepartment head) {
        hod = head;
    }

    void setFaculty(int index, Faculty member) {
        if (index >= 0 && index < 4) {
            faculty[index] = member;
        }
    }



    bool getPersonDetails(string name) {
        name = trim(name);  
        // cout << "Searching for: [" << name << "]" << endl;
        if (toLower(hod.getName()) == toLower(name)) {
            hod.display();
            return true;
        }

        for (int i = 0; i < 4; i++) {
            if (toLower(faculty[i].getName()) == toLower(name)) {
                faculty[i].display();
                return true;
            }
        }

        return false;  
    }
};

// Function to load data from CSV file into departments
void loadDataFromCSV(Department departments[], const string &fileName) {
    const int MAX_DEPARTMENTS = 5;  // Max number of departments
    const int MAX_FACULTY = 4;       // Max number of faculty per department
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Unable to open file" << endl;
        return;
    }

    string line;
    getline(file, line);  // Skip header

    int facultyCount[MAX_DEPARTMENTS] = {0};  // Track number of faculty in each department

    while (getline(file, line)) {
        stringstream ss(line);
        string name, position, address, phoneNumber, email, department;
        
        getline(ss, name, ',');
        getline(ss, position, ',');
        getline(ss, address, ',');
        getline(ss, phoneNumber, ',');
        getline(ss, email, ',');
        getline(ss, department, ',');

        // cout << "Loaded: [" << name << "]";

        // Create a faculty member object
        if (position == "Head Of Department") {
            HeadOfDepartment hod(name, address, phoneNumber, email);
            int deptIndex = (department == "Computer Science") ? 0 :
                            (department == "Electronics and Communication") ? 1 :
                            (department == "Computational Biology") ? 2 :
                            (department == "Human-Centered Design") ? 3 :
                            (department == "Mathematics") ? 4 : -1;
            if (deptIndex != -1) {
                departments[deptIndex].setHOD(hod);
            }
        } else {
            Faculty facultyMember(name, position, address, phoneNumber, email);
            int deptIndex = (department == "Computer Science") ? 0 :
                            (department == "Electronics and Communication") ? 1 :
                            (department == "Computational Biology") ? 2 :
                            (department == "Human-Centered Design") ? 3 :
                            (department == "Mathematics") ? 4 : -1;
            if (deptIndex != -1 && facultyCount[deptIndex] < MAX_FACULTY) {
                departments[deptIndex].setFaculty(facultyCount[deptIndex], facultyMember);
                facultyCount[deptIndex]++;  // Increment the count for that department
            }
        }
    }

    file.close();  // Close the file after loading
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
      // Max number of departments
    Department departments[MAX_DEPARTMENTS];  // Array of departments    

    // Load data from CSV into departments
    loadDataFromCSV(departments, CSV_PATH);

    // Example of searching for a person's details
    string nameToSearch;
    cout << "Please enter a name of the person to search: ";
    getline(cin, nameToSearch);

    if (isValidName(nameToSearch)) {

            // Search across departments
        bool personFound = false;
        for (int i = 0; i < MAX_DEPARTMENTS && !personFound; i++) {
            personFound = departments[i].getPersonDetails(nameToSearch);
        }

        if (!personFound) {
            cout << "Person not found in any department" << endl;
        }
            
        } else {
            cerr << "Invalid name entered. Please enter a valid name (letters and spaces only)." << endl;
        }


    

    return 0;
}
