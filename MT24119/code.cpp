// // #include <iostream>
// // #include <string>
// // #include <vector>

// // class Person; // Forward declaration

// // class Complaint {
// // public:
// //     std::string complaint_info;
// //     Person* assigned_to;
// //     bool status;
// //     Person* escalated_to;
// //     int pending_days;

// //     Complaint(std::string info, Person* assigned, int days)
// //         : complaint_info(info), assigned_to(assigned), status(false), escalated_to(nullptr), pending_days(days) {}
// // };

// // class Person {
// // public:
// //     std::string name;
// //     std::string position;
// //     Person* supervisor;

// //     Person(std::string n, std::string pos, Person* sup = nullptr)
// //         : name(n), position(pos), supervisor(sup) {}
// // };

// // class Department {
// // public:
// //     std::string name;
// //     Person* dean;
// //     std::vector<Person*> staff;

// //     Department(std::string n, Person* d) : name(n), dean(d) {}

// //     void addStaff(Person* p) {
// //         staff.push_back(p);
// //     }
// // };

// // class ComplaintManagementSystem {
// // private:
// //     std::vector<Department*> departments;
// //     Person* registrar;

// // public:
// //     ComplaintManagementSystem(Person* reg) : registrar(reg) {}

// //     void addDepartment(Department* dept) {
// //         departments.push_back(dept);
// //     }

// //     Person* escalateComplaint(Complaint& complaint) {
// //         if (complaint.pending_days <= 3) {
// //             return complaint.assigned_to;
// //         }

// //         Person* current = complaint.assigned_to;
// //         while (current->supervisor != nullptr) {
// //             current = current->supervisor;
// //             if (current->position.find("Dean") != std::string::npos) {
// //                 complaint.escalated_to = current;
// //                 return current;
// //             }
// //         }

// //         // If not resolved by Dean, escalate to Registrar
// //         complaint.escalated_to = registrar;
// //         return registrar;
// //     }
// // };

// // int main() {
// //     // Create the organizational structure
// //     Person registrar("Dr. Deepika Bhaskar", "Registrar");
    
// //     Person deanIRD("Vivek Ashok Bohara", "Dean of Innovation- Research & Development (DIRD)");
// //     Person adminOfficerIRD("Kapil Dev Garg", "Administrative Officer (IRD)", &deanIRD);
// //     Person juniorOfficerIRD("Imran Khan", "Junior Administrative Officer (IRD)", &adminOfficerIRD);

// //     Department irdDepartment("IRD", &deanIRD);
// //     irdDepartment.addStaff(&adminOfficerIRD);
// //     irdDepartment.addStaff(&juniorOfficerIRD);

// //     ComplaintManagementSystem cms(&registrar);
// //     cms.addDepartment(&irdDepartment);

// //     // Get complaint information from user
// //     std::string complaint_info;
// //     int pending_days;

// //     std::cout << "Enter complaint information: ";
// //     std::getline(std::cin, complaint_info);

// //     std::cout << "Enter number of pending days: ";
// //     std::cin >> pending_days;

// //     // Create and process the complaint
// //     Complaint complaint(complaint_info, &juniorOfficerIRD, pending_days);
// //     Person* escalated_to = cms.escalateComplaint(complaint);

// //     std::cout << "Complaint escalated to: " << escalated_to->name << " (" << escalated_to->position << ")" << std::endl;

// //     return 0;
// // }
// #include <iostream>
// #include <string>
// #include <sstream>
// #include <fstream>

// class Person {
// public:
//     std::string name;
//     std::string position;
//     std::string level;
//     Person* supervisor;

//     Person(std::string n, std::string pos, std::string lvl, Person* sup = nullptr)
//         : name(n), position(pos), level(lvl), supervisor(sup) {}
// };

// class Complaint {
// public:
//     std::string complaint_info;
//     Person* assigned_to;
//     bool status;
//     Person* escalated_to;
//     int pending_days;

//     Complaint(std::string info, Person* assigned, int days)
//         : complaint_info(info), assigned_to(assigned), status(false), escalated_to(nullptr), pending_days(days) {}
// };

// class ComplaintManagementSystem {
// private:
//     Person* registrar;
//     Person* director;

// public:
//     ComplaintManagementSystem() : registrar(nullptr), director(nullptr) {}

//     void loadOrganizationStructure(const std::string& filename) {
//         std::ifstream file(filename);
//         std::string line;
//         std::getline(file, line); // Skip header

//         while (std::getline(file, line)) {
//             std::istringstream iss(line);
//             std::string level, position, name;

//             if (std::getline(iss, level, ',') &&
//                 std::getline(iss, position, ',') &&
//                 std::getline(iss, name, ',')) {
                
//                 Person* person = new Person(name, position, level);

//                 if (position == "Registrar") {
//                     registrar = person;
//                 } else if (position == "Director (IIIT-Delhi)") {
//                     director = person;
//                 }

//                 // Set up supervisor relationships (simplified for this example)
//                 if (level == "Dean") {
//                     person->supervisor = director;
//                 } else if (level == "Administrative Officers" || level == "Officers") {
//                     person->supervisor = registrar;
//                 }
//             }
//         }
//     }

//     Person* findPersonByPosition(const std::string& position) {
//         if (registrar && registrar->position == position) return registrar;
//         if (director && director->position == position) return director;
//         // Add more checks if needed
//         return nullptr;
//     }

//     Person* escalateComplaint(Complaint& complaint) {
//         if (complaint.pending_days <= 3) {
//             return complaint.assigned_to;
//         }

//         Person* current = complaint.assigned_to;
//         while (current->supervisor != nullptr) {
//             current = current->supervisor;
//             if (current->level == "Dean" || current->level == "Director") {
//                 complaint.escalated_to = current;
//                 return current;
//             }
//         }

//         // If not resolved by Dean or Director, escalate to Registrar
//         complaint.escalated_to = registrar;
//         return registrar;
//     }
// };

// int main() {
//     ComplaintManagementSystem cms;
//     cms.loadOrganizationStructure("organization_structure.csv");

//     // Get complaint information from user
//     std::string complaint_info;
//     int pending_days;
//     std::string assigned_to_position;

//     std::cout << "Enter complaint information: ";
//     std::getline(std::cin, complaint_info);

//     std::cout << "Enter number of pending days: ";
//     std::cin >> pending_days;
//     std::cin.ignore(); // Clear the newline from the buffer

//     std::cout << "Enter the position of the person assigned to (e.g., Junior Administrative Officer (IRD)): ";
//     std::getline(std::cin, assigned_to_position);

//     Person* assigned_to = cms.findPersonByPosition(assigned_to_position);
//     if (!assigned_to) {
//         std::cout << "Error: Assigned person not found." << std::endl;
//         return 1;
//     }

//     // Create and process the complaint
//     Complaint complaint(complaint_info, assigned_to, pending_days);
//     Person* escalated_to = cms.escalateComplaint(complaint);

//     std::cout << "Complaint escalated to: " << escalated_to->name << " (" << escalated_to->position << ")" << std::endl;

//     return 0;
// }
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Forward declaration
class Person;

class Complaint {
public:
    std::string complaint_info;
    Person* assigned_to;
    bool status;
    Person* escalated_to;
    int pending_days;

    Complaint(std::string info, Person* assigned, int days)
        : complaint_info(info), assigned_to(assigned), status(false), escalated_to(nullptr), pending_days(days) {}
};

class Person {
public:
    std::string name;
    std::string position;
    Person* supervisor;

    Person(std::string n, std::string pos, Person* sup = nullptr)
        : name(n), position(pos), supervisor(sup) {}
};

class Department {
public:
    std::string name;
    Person* dean;

    Department(std::string n, Person* d) : name(n), dean(d) {}
};

class ComplaintManagementSystem {
private:
    Person* registrar;

public:
    ComplaintManagementSystem(Person* reg) : registrar(reg) {}

    Person* escalateComplaint(Complaint& complaint) {
        if (complaint.pending_days <= 3) {
            return complaint.assigned_to;
        }

        Person* current = complaint.assigned_to;
        while (current->supervisor != nullptr) {
            current = current->supervisor;
            if (current->position.find("Dean") != std::string::npos) {
                complaint.escalated_to = current;
                return current;
            }
        }

        // If not resolved by Dean, escalate to Registrar
        complaint.escalated_to = registrar;
        return registrar;
    }
};

// Function to parse CSV and find person by name
Person* findPersonFromCSV(const std::string& name, const std::string& file) {
    std::ifstream infile(file);
    std::string line, token;

    // Read the header line
    std::getline(infile, line);

    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string level, position, person_name;

        // Split by commas
        std::getline(ss, level, ',');
        std::getline(ss, position, ',');
        std::getline(ss, person_name, ',');

        // If person found in CSV, return new Person object
        if (person_name == name) {
            return new Person(person_name, position);
        }
    }

    return nullptr;
}

int main() {
    // Create the organizational structure
    Person registrar("Dr. Deepika Bhaskar", "Registrar");

    ComplaintManagementSystem cms(&registrar);

    // Get complaint information from user
    std::string complaint_info;
    int pending_days;
    std::string assigned_to_name;

    std::cout << "Enter complaint information: ";
    std::getline(std::cin, complaint_info);

    std::cout << "Enter number of pending days: ";
    std::cin >> pending_days;
    std::cin.ignore(); // Ignore leftover newline

    std::cout << "Enter the name of the person assigned to the complaint: ";
    std::getline(std::cin, assigned_to_name);

    // Search for the assigned person in the CSV file
    Person* assigned_to = findPersonFromCSV(assigned_to_name, "data.csv");
    if (assigned_to == nullptr) {
        std::cerr << "Error: Person not found in the CSV file!" << std::endl;
        return 1;
    }

    // Create and process the complaint
    Complaint complaint(complaint_info, assigned_to, pending_days);
    Person* escalated_to = cms.escalateComplaint(complaint);

    if (escalated_to) {
        std::cout << "Complaint escalated to: " << escalated_to->name << " (" << escalated_to->position << ")" << std::endl;
    } else {
        std::cout << "Complaint not escalated." << std::endl;
    }

    // Cleanup dynamically allocated memory
    delete assigned_to;

    return 0;
}
