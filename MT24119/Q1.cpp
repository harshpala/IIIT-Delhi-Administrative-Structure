#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int ROWS = 68;
const string CSV_PATH = "C:/Users/harsh/Documents/MTech/OOPD/Assignment/Assignment 2/Assignment-2A/MT24119/data/data.csv";

class Person {
protected:
    string name;
    string position;
    string phoneNumber;
    string faxNumber;
    string email;
    string secondaryEmail;
    string address;

public:
    Person(string name, string position, string phoneNumber, string faxNumber, string email, string secondaryEmail, string address)
        : name(name), position(position), phoneNumber(phoneNumber), faxNumber(faxNumber), email(email), secondaryEmail(secondaryEmail), address(address) {}

    
    void setPosition(const string& newPosition) {
        position = newPosition;
    }

    // Getter methods
    string getName() const { return name; }
    string getPosition() const { return position; }
    string getPhoneNumber() const { return phoneNumber; }
    string getfaxNumber() const { return faxNumber; }
    string getEmail() const { return email; }
    string getSecondaryEmail() const {return secondaryEmail;}
    string getAddress() const  {return address;}
};

// Derived class for Dean
class Dean : public Person {
public:
    Dean() : Person("", "Dean", "", "", "", "", "") {} // Default constructor

    Dean(string name, string phoneNumber, string faxNumber, string email, string secondaryEmail)
        : Person(name, "Dean", phoneNumber, faxNumber, email, secondaryEmail, "") {}
};

// Derived class for Associate Dean
class AssociateDean : public Dean {
public:
    AssociateDean() : Dean("", "", "", "", "") {} // Default constructor

    AssociateDean(string name, string phoneNumber, string faxNumber, string email, string secondaryEmail, string address)
        : Dean(name, phoneNumber, faxNumber, email, secondaryEmail) {}
};

// Derived class for Administrative Officers
class AdministrativeOfficer : public Person {
public:
    AdministrativeOfficer() : Person("", "Administrative Officer", "", "", "", "", "") {} // Default constructor

    AdministrativeOfficer(string name,string position, string phoneNumber, string faxNumber, string email, string secondaryEmail, string address)
        : Person(name, "Administrative Officer", phoneNumber, faxNumber, email, secondaryEmail, address) {}
};

class AssistantAdministrativeOfficer : public AdministrativeOfficer {
public:
    AssistantAdministrativeOfficer() :  AdministrativeOfficer("","Assistant Administrative Officer", "", "", "", "", "") {} // Default constructor

    AssistantAdministrativeOfficer(string name,string position, string phoneNumber, string faxNumber, string email, string secondaryEmail, string address)
        : AdministrativeOfficer(name,"Assistant Administrative Officer", phoneNumber, faxNumber, email, secondaryEmail, address) {}
};

class JuniorAdministrativeOfficer : public AdministrativeOfficer {
public:
    JuniorAdministrativeOfficer() : AdministrativeOfficer("","Junior Administrative Officer", "", "", "", "", "") {}

    JuniorAdministrativeOfficer(string name,string position, string phoneNumber, string faxNumber, string email, string secondaryEmail, string address)
        : AdministrativeOfficer(name,"Junior Administrative Officer", phoneNumber, faxNumber, email, secondaryEmail, address) {}
};

class DeputyAdministrativeOfficer : public AdministrativeOfficer {
public:
    DeputyAdministrativeOfficer() : AdministrativeOfficer("","Deputy Administrative Officer", "", "", "", "", "") {}

    DeputyAdministrativeOfficer(string name,string position, string phoneNumber, string faxNumber, string email, string secondaryEmail, string address)
        : AdministrativeOfficer(name,"Deputy Administrative Officer", phoneNumber, faxNumber, email, secondaryEmail, address) {}
};


// Derived class for Officers
class Officer : public Person {
public:
    Officer() : Person("", "Officer", "", "", "", "", "") {} // Default constructor

    Officer(string name, string position, string phoneNumber, string faxNumber, string email, string secondaryEmail, string address)
        : Person(name, "Officer", phoneNumber, faxNumber, email, secondaryEmail, address) {}
};

class JuniorOfficer : public Officer {
public:
    JuniorOfficer() : Officer("","Junior Officer","","","","",""){};
    JuniorOfficer(string name,string position, string phoneNumber, string faxNumber, string email, string secondaryEmail, string address)
        : Officer(name, "Junior Officer", phoneNumber, faxNumber, email, secondaryEmail, address) {}
};



class Department {
private:
    Dean dean;
    AssociateDean associateDean;
    AdministrativeOfficer administrativeOfficer;
    int assistantOfficerCount;
    int juniorOfficerCount;
    AssistantAdministrativeOfficer assistantAdministrativeOfficers[10];
    JuniorAdministrativeOfficer juniorAdministrativeOfficers[35];
    DeputyAdministrativeOfficer deputyAdministrativeOfficer;
    Officer officer;
    JuniorOfficer juniorOfficer;

    

public:
    Department() :dean(), associateDean(), administrativeOfficer(),assistantOfficerCount(0), juniorOfficerCount(0),assistantAdministrativeOfficers(),juniorAdministrativeOfficers(),deputyAdministrativeOfficer(), officer(),juniorOfficer() {}

    void setDean(Dean d) { dean = d; }
    void setAssociateDean(AssociateDean ad) { associateDean = ad; }
    void setAdministrativeOfficer(AdministrativeOfficer ao) { administrativeOfficer = ao; }
    void setAssistantOfficerCount(int c){assistantOfficerCount = c;}
    void setJuniorOfficerCount(int c){juniorOfficerCount = c;}

    void addAssistantAdministrativeOfficer(AssistantAdministrativeOfficer aao) {
        if (assistantOfficerCount < 10) { // Check if there's space in the array
            assistantAdministrativeOfficers[assistantOfficerCount] = aao;
            assistantOfficerCount++;
        } else {
            // Handle the case where the array is full (optional)
            cout << "Cannot add more Assistant Administrative Officers." << endl;
        }
    }

    // Add a Junior Administrative Officer
    void addJuniorAdministrativeOfficer(JuniorAdministrativeOfficer jao) {
        if (juniorOfficerCount < 35) { // Check if there's space in the array
            juniorAdministrativeOfficers[juniorOfficerCount] = jao;
            juniorOfficerCount++;
        } else {
            // Handle the case where the array is full (optional)
            cout << "Cannot add more Junior Administrative Officers." << endl;
        }
    }
    void setDeputyAdministrativeOfficer(DeputyAdministrativeOfficer dao) { deputyAdministrativeOfficer = dao; }
    void setOfficer(Officer o){officer = o;}
    void setJuniorOfficer(JuniorOfficer jo){juniorOfficer = jo;}




    Dean getDean()  { return dean; }
    AdministrativeOfficer getAdministrativeOfficer() { return administrativeOfficer; }
    AssociateDean getAssociateDean()  { return associateDean; }
    int getAssistantAdministrativeCount() {return assistantOfficerCount;}
    int getJuniorCount() {return juniorOfficerCount;}
    AssistantAdministrativeOfficer getAssistantAdministrativeOfficer(int index) {
        if (index >= 0 && index < assistantOfficerCount) {
            return assistantAdministrativeOfficers[index];
        }
        // Handle the case where index is out of bounds (optional)
        throw std::out_of_range("Index out of bounds for Assistant Administrative Officers.");
    }

    // Get Junior Administrative Officers
    JuniorAdministrativeOfficer getJuniorAdministrativeOfficer(int index) {
        if (index >= 0 && index < juniorOfficerCount) {
            return juniorAdministrativeOfficers[index];
        }
        // Handle the case where index is out of bounds (optional)
        throw std::out_of_range("Index out of bounds for Junior Administrative Officers.");
    }
    DeputyAdministrativeOfficer getDeputyAdministrativeOfficer() { return deputyAdministrativeOfficer; }
    Officer getOfficer(){ return officer;}
    JuniorOfficer getJuniorOfficer(){return juniorOfficer;}

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

class AdministrativeStructure {
private:
    Department ird;
    Department academics;
    Department studentAffairs;
    Department storePurchase;
    Department library;
    Person* registrar;

public:
    AdministrativeStructure() : registrar(nullptr) {}

    void setRegistrar(Person* r) { registrar = r; }

    void setIRD(Dean d, AssociateDean ad, AdministrativeOfficer ao, AssistantAdministrativeOfficer *aao, int assistantCount, JuniorAdministrativeOfficer *jao, int juniorCount) {
        ird.setDean(d);
        ird.setAssociateDean(ad);
        ird.setAdministrativeOfficer(ao);
        ird.setAssistantOfficerCount(assistantCount);
        ird.setJuniorOfficerCount(juniorCount);
    for (int i = 0; i < assistantCount; i++) {
        ird.addAssistantAdministrativeOfficer(aao[i]);
    }

    for (int i = 0; i < juniorCount; i++) {
        ird.addJuniorAdministrativeOfficer(jao[i]);
    }

    }

    void setAcademics(Dean d,  AdministrativeOfficer ao, AssistantAdministrativeOfficer *aao, int assistantCount, JuniorAdministrativeOfficer *jao, int juniorCount,  DeputyAdministrativeOfficer dao ) {
        academics.setDean(d);
        academics.setAdministrativeOfficer(ao);
    for (int i = 0; i < assistantCount; i++) {
        academics.addAssistantAdministrativeOfficer(aao[i]);
    }
    for (int i = 0; i < juniorCount; i++) {
        academics.addJuniorAdministrativeOfficer(jao[i]);
    }
        academics.setDeputyAdministrativeOfficer(dao);

    }

    void setStudentAffairs(Dean d,  AdministrativeOfficer ao, JuniorAdministrativeOfficer *jao, int juniorCount ) {
        studentAffairs.setDean(d);
        studentAffairs.setAdministrativeOfficer(ao);
        for (int i = 0; i < juniorCount; i++) {
        studentAffairs.addJuniorAdministrativeOfficer(jao[i]);
        }
        
    }

    void setStorePurchase( AdministrativeOfficer ao, AssistantAdministrativeOfficer *aao, int assistantCount, JuniorAdministrativeOfficer *jao, int juniorCount) {
        storePurchase.setAdministrativeOfficer(ao);
        for (int i = 0; i < assistantCount; i++) {
        storePurchase.addAssistantAdministrativeOfficer(aao[i]);
        }
    
        for (int i = 0; i < juniorCount; i++) {
            storePurchase.addJuniorAdministrativeOfficer(jao[i]);
        }
    }

    void setLibrary(Officer o, JuniorOfficer jo) {
        library.setOfficer(o);
        library.setJuniorOfficer(jo);
        }



        // Fetching details by name
    // Fetching details by name
    void fetchDetailsByName(const string& inputName) {        
        // Convert input name to lowercase and trim spaces
        string searchName = toLower(trim(inputName));

        // Check Registrar
        if (registrar != nullptr) {
            string registrarName = toLower(trim(registrar->getName()));
            if (registrarName == searchName) {
                cout << " → Registrar: " << registrar->getName()<<endl
                    << " → Position: " << registrar->getPosition()<<endl
                    << " → Phone: " << registrar->getPhoneNumber()<<endl
                    << " → Fax: " << registrar->getfaxNumber()<<endl
                    << " → Email: " << registrar->getEmail()<<endl;
                    if (registrar->getSecondaryEmail()!="")
                    cout<< " → Secondary Email: "<<registrar->getSecondaryEmail()<<endl;          
                    cout<< " → Address: " << registrar->getAddress() << endl;
                return;
            }
        }


        // Check IRD Department
        if (toLower(trim(ird.getDean().getName())) == searchName) {
            cout << " → Dean of Innovation, Research & Development (DIRD): " << ird.getDean().getName()<<endl
                << " → Phone: " << ird.getDean().getPhoneNumber()<<endl
                << " → Email: " << ird.getDean().getEmail()<<endl;
            if (ird.getDean().getSecondaryEmail()!="")
            cout << " → Secondary Email: " << ird.getDean().getSecondaryEmail()<<endl;
            return;
        }

        if (toLower(trim(ird.getAssociateDean().getName())) == searchName) {
            cout << " → Associate Dean of Innovation, Research & Development (ADIRD): " << ird.getAssociateDean().getName()<< endl
                << " → Phone: " << ird.getAssociateDean().getPhoneNumber()<< endl
                << " → Email: " << ird.getAssociateDean().getEmail()<< endl;
            if (ird.getAssociateDean().getSecondaryEmail()!="")
                cout<< " → Secondary Email: " << ird.getAssociateDean().getSecondaryEmail()<< endl;
                cout<< " → Address: " << ird.getAssociateDean().getAddress() << endl;
            return;
        }

        if (toLower(trim(ird.getAdministrativeOfficer().getName())) == searchName) {
            cout << " → Administrative Officer (IRD): " << ird.getAdministrativeOfficer().getName()<< endl
                << " → Phone: " << ird.getAdministrativeOfficer().getPhoneNumber()<< endl
                << " → Email: " << ird.getAdministrativeOfficer().getEmail()<< endl;
            if (ird.getAdministrativeOfficer().getSecondaryEmail()!="")
            cout<< " → Secondary Email: " << ird.getAdministrativeOfficer().getSecondaryEmail()<< endl;
            cout<< " → Address: " << ird.getAdministrativeOfficer().getAddress() << endl;
            return;
        }

        // Check Assistant Administrative Officers in IRD
        for (int i = 0; i < ird.getAssistantAdministrativeCount(); ++i) {
            if (toLower(trim(ird.getAssistantAdministrativeOfficer(i).getName())) == searchName) {
                cout << " → Assistant Administrative Officer (IRD): " << ird.getAssistantAdministrativeOfficer(i).getName() << endl
                    << " → Phone: " << ird.getAssistantAdministrativeOfficer(i).getPhoneNumber() << endl
                    << " → Email: " << ird.getAssistantAdministrativeOfficer(i).getEmail() << endl;
                if (ird.getAssistantAdministrativeOfficer(i).getSecondaryEmail() != "")
                    cout << " → Secondary Email: " << ird.getAssistantAdministrativeOfficer(i).getSecondaryEmail() << endl;
                cout << " → Address: " << ird.getAssistantAdministrativeOfficer(i).getAddress() << endl;
                return;
            }
        }

        // Check Junior Administrative Officers in IRD
        for (int i = 0; i < ird.getJuniorCount(); ++i) {
            if (toLower(trim(ird.getJuniorAdministrativeOfficer(i).getName())) == searchName) {
                cout << " → Junior Administrative Officer (IRD): " << ird.getJuniorAdministrativeOfficer(i).getName() << endl
                    << " → Phone: " << ird.getJuniorAdministrativeOfficer(i).getPhoneNumber() << endl
                    << " → Email: " << ird.getJuniorAdministrativeOfficer(i).getEmail() << endl;
                if (ird.getJuniorAdministrativeOfficer(i).getSecondaryEmail() != "")
                    cout << " → Secondary Email: " << ird.getJuniorAdministrativeOfficer(i).getSecondaryEmail() << endl;
                cout << " → Address: " << ird.getJuniorAdministrativeOfficer(i).getAddress() << endl;
                return;
            }
        }


        // Check Academics Department
        if (toLower(trim(academics.getDean().getName())) == searchName) {
            cout << " → Dean of Academic Affairs (DoAA): " << academics.getDean().getName()<< endl
                << " → Phone: " << academics.getDean().getPhoneNumber()<< endl
                << " → Email: " << academics.getDean().getEmail()<< endl;
            if (academics.getDean().getSecondaryEmail()!="")
            cout<< " → Secondary Email: " << academics.getDean().getSecondaryEmail()<<endl;
            return;
        }

        if (toLower(trim(academics.getAdministrativeOfficer().getName())) == searchName) {
            cout << " → Administrative Officer (Academics): " << academics.getAdministrativeOfficer().getName()<<endl
                << " → Phone: " << academics.getAdministrativeOfficer().getPhoneNumber()<<endl
                << " → Email: " << academics.getAdministrativeOfficer().getEmail()<<endl;
            if (academics.getAdministrativeOfficer().getSecondaryEmail()!="")
            cout << " → Secondary Email: " << academics.getAdministrativeOfficer().getSecondaryEmail()<<endl;
            cout << " → Address: " << academics.getAdministrativeOfficer().getAddress() << endl;
            return;
        }

    for (int i = 0; i < academics.getAssistantAdministrativeCount(); ++i) {
        if (toLower(trim(academics.getAssistantAdministrativeOfficer(i).getName())) == searchName) {
            cout << " → Assistant Administrative Officer (Academics): " << academics.getAssistantAdministrativeOfficer(i).getName() << endl
                << " → Phone: " << academics.getAssistantAdministrativeOfficer(i).getPhoneNumber() << endl
                << " → Email: " << academics.getAssistantAdministrativeOfficer(i).getEmail() << endl;
            if (academics.getAssistantAdministrativeOfficer(i).getSecondaryEmail() != "")
                cout << " → Secondary Email: " << academics.getAssistantAdministrativeOfficer(i).getSecondaryEmail() << endl;
            cout << " → Address: " << academics.getAssistantAdministrativeOfficer(i).getAddress() << endl;
            return;
        }
    }


    for (int i = 0; i < academics.getJuniorCount(); ++i) {
        if (toLower(trim(academics.getJuniorAdministrativeOfficer(i).getName())) == searchName) {
            cout << " → Junior Administrative Officer (Academics): " << academics.getJuniorAdministrativeOfficer(i).getName() << endl
                << " → Phone: " << academics.getJuniorAdministrativeOfficer(i).getPhoneNumber() << endl
                << " → Email: " << academics.getJuniorAdministrativeOfficer(i).getEmail() << endl;
            if (academics.getJuniorAdministrativeOfficer(i).getSecondaryEmail() != "")
                cout << " → Secondary Email: " << academics.getJuniorAdministrativeOfficer(i).getSecondaryEmail() << endl;
            cout << " → Address: " << academics.getJuniorAdministrativeOfficer(i).getAddress() << endl;
            return;
        }
    }
        
    if (toLower(trim(academics.getDeputyAdministrativeOfficer().getName())) == searchName) {
            cout << " → Deputy Administrative Officer (Academics): " << academics.getDeputyAdministrativeOfficer().getName()<< endl
                << " → Phone: " << academics.getDeputyAdministrativeOfficer().getPhoneNumber()<< endl
                << " → Email: " << academics.getDeputyAdministrativeOfficer().getEmail()<< endl;
            if (academics.getDeputyAdministrativeOfficer().getSecondaryEmail()!="")
            cout<< " → Secondary Email: " << academics.getDeputyAdministrativeOfficer().getSecondaryEmail()<<endl;
            cout<< " → Address: " << academics.getDeputyAdministrativeOfficer().getAddress() << endl;
            return;
        }

        



        // Check Student Affairs Department
            if (toLower(trim(studentAffairs.getDean().getName())) == searchName) {
            cout << " → Dean of Student Affairs (DoSA): " << studentAffairs.getDean().getName()<< endl
                << " → Phone: " << studentAffairs.getDean().getPhoneNumber()<< endl
                << " → Email: " << studentAffairs.getDean().getEmail()<< endl;
            if (studentAffairs.getDean().getSecondaryEmail()!="")
            cout<< " → Secondary Email: " << studentAffairs.getDean().getSecondaryEmail()<<endl;
            return;
        }

        if (toLower(trim(studentAffairs.getAdministrativeOfficer().getName())) == searchName) {
            cout << " → Administrative Officer (Student Affairs): " << studentAffairs.getAdministrativeOfficer().getName()<<endl
                << " → Phone: " << studentAffairs.getAdministrativeOfficer().getPhoneNumber()<<endl
                << " → Email: " << studentAffairs.getAdministrativeOfficer().getEmail()<<endl;
            if (studentAffairs.getAdministrativeOfficer().getSecondaryEmail()!="")
            cout<< " → Secondary Email: " << studentAffairs.getAdministrativeOfficer().getSecondaryEmail()<<endl;
            cout << " → Address: " << studentAffairs.getAdministrativeOfficer().getAddress() << endl;
            return;
        }

        for (int i = 0; i < studentAffairs.getJuniorCount(); ++i) {
        if (toLower(trim(studentAffairs.getJuniorAdministrativeOfficer(i).getName())) == searchName) {
            cout << " → Junior Administrative Officer (Student Affairs): " << studentAffairs.getJuniorAdministrativeOfficer(i).getName() << endl
                << " → Phone: " << studentAffairs.getJuniorAdministrativeOfficer(i).getPhoneNumber() << endl
                << " → Email: " << studentAffairs.getJuniorAdministrativeOfficer(i).getEmail() << endl;
            if (studentAffairs.getJuniorAdministrativeOfficer(i).getSecondaryEmail() != "")
                cout << " → Secondary Email: " << studentAffairs.getJuniorAdministrativeOfficer(i).getSecondaryEmail() << endl;
            cout << " → Address: " << studentAffairs.getJuniorAdministrativeOfficer(i).getAddress() << endl;
            return;
        }
    }



        // Check Store Purchase Department
        if (toLower(trim(storePurchase.getAdministrativeOfficer().getName())) == searchName) {
            cout << " → Administrative Officer (Store & Purchase): " << storePurchase.getAdministrativeOfficer().getName()<<endl
                << " → Phone: " << storePurchase.getAdministrativeOfficer().getPhoneNumber()<<endl
                << " → Email: " << storePurchase.getAdministrativeOfficer().getEmail()<<endl;
            if (storePurchase.getAdministrativeOfficer().getSecondaryEmail()!="")
            cout<< " → Secondary Email: " << storePurchase.getAdministrativeOfficer().getSecondaryEmail()<<endl;
            cout<< " → Address: " << storePurchase.getAdministrativeOfficer().getAddress() << endl;
            return;
        }

        for (int i = 0; i < storePurchase.getAssistantAdministrativeCount(); ++i) {
        if (toLower(trim(storePurchase.getAssistantAdministrativeOfficer(i).getName())) == searchName) {
            cout << " → Assistant Administrative Officer (Store & Purchase): " << storePurchase.getAssistantAdministrativeOfficer(i).getName() << endl
                << " → Phone: " << storePurchase.getAssistantAdministrativeOfficer(i).getPhoneNumber() << endl
                << " → Email: " << storePurchase.getAssistantAdministrativeOfficer(i).getEmail() << endl;
            if (storePurchase.getAssistantAdministrativeOfficer(i).getSecondaryEmail() != "")
                cout << " → Secondary Email: " << storePurchase.getAssistantAdministrativeOfficer(i).getSecondaryEmail() << endl;
            cout << " → Address: " << storePurchase.getAssistantAdministrativeOfficer(i).getAddress() << endl;
            return;
        }
    }


    for (int i = 0; i < storePurchase.getJuniorCount(); ++i) {
        if (toLower(trim(storePurchase.getJuniorAdministrativeOfficer(i).getName())) == searchName) {
            cout << " → Junior Administrative Officer (Store & Purchase): " << storePurchase.getJuniorAdministrativeOfficer(i).getName() << endl
                << " → Phone: " << storePurchase.getJuniorAdministrativeOfficer(i).getPhoneNumber() << endl
                << " → Email: " << storePurchase.getJuniorAdministrativeOfficer(i).getEmail() << endl;
            if (storePurchase.getJuniorAdministrativeOfficer(i).getSecondaryEmail() != "")
                cout << " → Secondary Email: " << storePurchase.getJuniorAdministrativeOfficer(i).getSecondaryEmail() << endl;
            cout << " → Address: " << storePurchase.getJuniorAdministrativeOfficer(i).getAddress() << endl;
            return;
        }
    }



    // Check Library Department
    if (toLower(trim(library.getOfficer().getName())) == searchName) {
        cout << " → Library Officer (SG): " << library.getOfficer().getName()<<endl
             << " → Phone: " << library.getOfficer().getPhoneNumber()<<endl
             << " → Email: " << library.getOfficer().getEmail()<<endl;
        if (library.getOfficer().getSecondaryEmail()!="")
        cout<< " → Secondary Email: " << library.getOfficer().getSecondaryEmail()<<endl;
        cout<< " → Address: " << library.getOfficer().getAddress() << endl;
        return;
    }
    if (toLower(trim(library.getJuniorOfficer().getName())) == searchName) {
        cout << " → Junior Library Officer: " << library.getJuniorOfficer().getName()<<endl
             << " → Phone: " << library.getJuniorOfficer().getPhoneNumber()<<endl
             << " → Email: " << library.getJuniorOfficer().getEmail()<<endl;
        if (library.getJuniorOfficer().getSecondaryEmail()!="")
        cout<< " → Secondary Email: " << library.getJuniorOfficer().getSecondaryEmail()<<endl;
        cout<< " → Address: " << library.getJuniorOfficer().getAddress() << endl;
        return;
    }

    // If no match found
    cout << "No details found for: " << inputName << endl;
}


    void loadData() {
        int recordCount = 0;
        ifstream file(CSV_PATH);
        string line;
        Dean deanIRD;
        AssociateDean associateIRD;
        AdministrativeOfficer administrativeOfficerIRD;
        int juniorCountIRD = 0;
        const int MAX_ASSISTANT_IRD = 5; // Set an appropriate size
        AssistantAdministrativeOfficer assistantadministrativeOfficerIRD[MAX_ASSISTANT_IRD];
        const int MAX_JUNIOR_IRD = 5; // Set an appropriate size
        JuniorAdministrativeOfficer junioradministrativeOfficerIRD[MAX_JUNIOR_IRD];

        Dean deanAcademic;
        AdministrativeOfficer administrativeOfficerAcademic;
        const int MAX_ASSISTANTS_ACADEMIC = 2;
        int assistantAdministrativeOfficersAcademicCount = 0;
        AssistantAdministrativeOfficer assistantAdministrativeOfficersAcademic[MAX_ASSISTANTS_ACADEMIC];
        const int MAX_JUNIOR_OFFICERS = 6;
        JuniorAdministrativeOfficer juniorAdministrativeOfficersAcademic[MAX_JUNIOR_OFFICERS];
        int juniorAdministrativeOfficersAcademicCount = 0;
        DeputyAdministrativeOfficer deputyAdministrativeOfficerAcademic;

        Dean deanStudentAffairs;
        AdministrativeOfficer administrativeOfficerStudentAffairs;
        int juniorCountStudentAffairs = 0;
        const int MAX_JUNIOR_STUDENT_AFFAIRS = 1;
        JuniorAdministrativeOfficer juniorAdministrativeOfficersStudentAffairs[MAX_JUNIOR_STUDENT_AFFAIRS];

        AdministrativeOfficer administrativeOfficerSNP;
        int assistantCountSNP = 0;
        const int MAX_ASSISTANT_SNP = 1;
        AssistantAdministrativeOfficer assistantAdministrativeOfficerSNP[MAX_ASSISTANT_SNP];
        const int MAX_JUNIOR_SNP = 1;
        int juniorCountSNP = 0;
        JuniorAdministrativeOfficer juniorAdministrativeOfficerSNP[MAX_JUNIOR_SNP];

        Officer officerLibrary;
        JuniorOfficer juniorOfficerLibrary;



        if (!file.is_open()) {
            cout << "Unable to open file" << endl;
            return;
        }

        else
        {
            getline(file, line);
            while (getline(file, line) && recordCount < ROWS) {
                stringstream ss(line);
                string level, position, name, phoneNumber, faxNumber, emails, secondaryEmail, address;

                getline(ss, level, ',');
                getline(ss, position, ',');
                getline(ss, name, ',');
                getline(ss, phoneNumber, ',');
                getline(ss, faxNumber, ',');
                getline(ss, emails, ',');
                getline(ss, secondaryEmail, ',');
                getline(ss, address, ',');

                    


                if (position == "Registrar") {
                    setRegistrar(new Person(name, "Registrar", phoneNumber, faxNumber, emails, secondaryEmail, address));
                } 
                
                
                else if (position.find("IRD") != string::npos) 
                {
                    if (level == "Dean" && position == "Dean of Innovation- Research & Development (DIRD)") 
                    {
                        deanIRD = Dean(name, phoneNumber, faxNumber, emails, secondaryEmail);
                    }
                    else if (level == "Dean" && position == "Associate Dean of Innovation- Research & Development (ADIRD)") 
                    {
                        associateIRD = AssociateDean(name, phoneNumber, faxNumber, emails, secondaryEmail, address);
                    }
                    else if (level == "Officers" && position == "Administrative Officer (IRD)") 
                    {
                        administrativeOfficerIRD = AdministrativeOfficer(name, position, phoneNumber, faxNumber, emails, secondaryEmail, address);
                    }
                    else if (level == "Officers" && position == "Assistant Administrative Officer (IRD)")
                    {
                        if (juniorCountIRD < MAX_ASSISTANT_IRD) {
                            assistantadministrativeOfficerIRD[juniorCountIRD++] = AssistantAdministrativeOfficer(name, position, phoneNumber, faxNumber, emails, secondaryEmail, address);
                        }
                    }
                    else if (level == "Officers" && position == "Junior Administrative Officer (IRD) (SG)") 
                    {
                        if (juniorCountIRD < MAX_JUNIOR_IRD) {
                            junioradministrativeOfficerIRD[juniorCountIRD++] = JuniorAdministrativeOfficer(name, position, phoneNumber, faxNumber, emails, secondaryEmail, address);
                        }
                    }
                    setIRD(deanIRD, associateIRD, administrativeOfficerIRD, assistantadministrativeOfficerIRD, juniorCountIRD, junioradministrativeOfficerIRD, juniorCountIRD);
                }

                else if (position.find("Academic") != string::npos) 
                {
                    if (level == "Dean" && position == "Dean of Academic Affairs (DoAA)") 
                    {
                        deanAcademic = Dean(name, phoneNumber, faxNumber, emails, secondaryEmail);
                    }
                    else if (level == "Officers" && position == "Administrative Officer (Academics)") 
                    {
                        administrativeOfficerAcademic = AdministrativeOfficer(name, position, phoneNumber, faxNumber, emails, secondaryEmail, address);
                    }
                    else if (level == "Officers" && position == "Assistant Administrative Officer (Academics) (SG)") 
                    {
                        if (assistantAdministrativeOfficersAcademicCount < MAX_ASSISTANTS_ACADEMIC) 
                        {
                            assistantAdministrativeOfficersAcademic[assistantAdministrativeOfficersAcademicCount++] = AssistantAdministrativeOfficer(name, position, phoneNumber, faxNumber, emails, secondaryEmail, address);
                        }
                    }
                    else if (level == "Officers" && position == "Junior Administrative Officer (Academics)") 
                    {
                        if (juniorAdministrativeOfficersAcademicCount < MAX_JUNIOR_OFFICERS) 
                        {
                            juniorAdministrativeOfficersAcademic[juniorAdministrativeOfficersAcademicCount++] = JuniorAdministrativeOfficer(name, position, phoneNumber, faxNumber, emails, secondaryEmail, address);
                        }
                    }
                    else if (level == "Officers" && position == "Deputy Administrative Officer (Academics)") 
                    {
                        deputyAdministrativeOfficerAcademic = DeputyAdministrativeOfficer(name, position, phoneNumber, faxNumber, emails, secondaryEmail, address);
                    }
                    setAcademics(deanAcademic, administrativeOfficerAcademic, assistantAdministrativeOfficersAcademic, assistantAdministrativeOfficersAcademicCount, juniorAdministrativeOfficersAcademic, juniorAdministrativeOfficersAcademicCount, deputyAdministrativeOfficerAcademic);
                }
                
                else if (position.find("Student Affairs") != string::npos) 
                {
                    if (level == "Dean" && position == "Dean of Student Affairs (DoSA)") 
                    {
                        deanStudentAffairs = Dean(name, phoneNumber, faxNumber, emails, secondaryEmail);
                    }
                    else if (level == "Officers" && position == "Administrative Officer (Student Affairs)") 
                    {
                        administrativeOfficerStudentAffairs = AdministrativeOfficer(name, position, phoneNumber, faxNumber, emails, secondaryEmail, address);
                    }
                    else if (level == "Officers" && position == "Junior Administrative Officer (Student Affairs) (SG)") 
                    {
                        if (juniorCountStudentAffairs < MAX_JUNIOR_STUDENT_AFFAIRS) 
                        {
                            juniorAdministrativeOfficersStudentAffairs[juniorCountStudentAffairs++] = JuniorAdministrativeOfficer(name, position, phoneNumber, faxNumber, emails, secondaryEmail, address);
                        }
                    }
                    setStudentAffairs(deanStudentAffairs, administrativeOfficerStudentAffairs, juniorAdministrativeOfficersStudentAffairs, juniorCountStudentAffairs);
                }

                else if (position.find("Store & Purchase") != string::npos) 
                {
                    if (level == "Officers" && position == "Administrative Officer (Store & Purchase)") 
                    {
                        administrativeOfficerSNP = AdministrativeOfficer(name, position, phoneNumber, faxNumber, emails, secondaryEmail, address);
                    }
                    else if (level == "Officers" && position == "Assistant Administrative Officer (Store & Purchase) (SG)") 
                    {
                        if (assistantCountSNP < MAX_ASSISTANT_SNP) 
                        {
                            assistantAdministrativeOfficerSNP[assistantCountSNP++] = AssistantAdministrativeOfficer(name, position, phoneNumber, faxNumber, emails, secondaryEmail, address);
                        }
                    }
                    else if (level == "Officers" && position == "Junior Administrative Officer (Store & Purchase)") 
                    {
                        if (juniorCountSNP < MAX_JUNIOR_SNP) 
                        {
                            juniorAdministrativeOfficerSNP[juniorCountSNP++] = JuniorAdministrativeOfficer(name, position, phoneNumber, faxNumber, emails, secondaryEmail, address);
                        }
                    }
                    setStorePurchase(administrativeOfficerSNP, assistantAdministrativeOfficerSNP, assistantCountSNP, juniorAdministrativeOfficerSNP, juniorCountSNP);
                }


                else if (position.find("Library") != string::npos) 
                {
                    if (level == "Officers" && position == "Library Officer (SG)") 
                    {
                        officerLibrary = Officer(name, position, phoneNumber, faxNumber, emails, secondaryEmail, address);
                    }
                    else if (level == "Officers" && position == "Junior Library Officer") 
                    {
                        juniorOfficerLibrary = JuniorOfficer(name, position, phoneNumber, faxNumber, emails, secondaryEmail, address);
                    }
                    setLibrary(officerLibrary, juniorOfficerLibrary);
                }
            }

                recordCount++;
            }
            file.close();
        }
        
    };

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
    AdministrativeStructure structure;

    structure.loadData();

    string nameToSearch;
    cout << "Enter the name to search for: ";
    getline(cin, nameToSearch);
   // Validate the input
    if (isValidName(nameToSearch)) {
        structure.fetchDetailsByName(nameToSearch);
    } else {
        cerr << "Invalid name entered. Please enter a valid name (letters and spaces only)." << endl;
    }

    return 0;
}
