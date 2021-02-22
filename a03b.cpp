// Activity 3: SignUp Application.
#include <iostream> //cin & cout
#include <sstream> // strin I/O
#include <vector>
#include <string>
#include <stdexcept> //logic and runtime errors.

using namespace std;
//*********************************************  
struct Person { // declare structure (record)
    int age = 0;
    std::string name = "";
};
//*********************************************     
vector<Person> records;
//*********************************************  
void AddRecord(std::string newName, int newAge); //declare prototype
Person FetchRecord(int userID); //declare prototype
int get_int(int min, string prompt); //declare prototype
bool check_number(string str);
//*********************************************   
int main() {
    string inputString; int intOption; char charOption; 
    cout << "*** User SignUp Application ***" << endl;
    bool bIsRunning = true;
    while (bIsRunning) {
        cout << "* Select an option:" << endl;
        cout << "1: Add Record" << endl;
        cout << "2: Fetch Record" << endl;
        cout << "3: Quit" << endl;
        cout << "Enter option: "; 

        inputString = "";
        intOption = get_int(1, inputString);
        switch (intOption) {
            case 1: {
                string name = "";
                int age = 0;
                cout << "** Add User. Enter user name and age:" << endl;
                cout << "Name: ";
                getline(cin, name);
                age = get_int(1, "Age: ");
                AddRecord(name, age);
            }
            break;
            case 2: {
                int userID = 0;
                cout << "*** Enter user ID" << endl;
                cout << "User ID: ";
                userID = get_int(1, inputString)-1; // adjust human rec# to computer rec#
                Person person;
                try {
                    person = FetchRecord(userID);
                }
                catch (const out_of_range &oor) {
                    cout  << endl << "! Error: Invalid UserID." << endl << endl;
                    break;
                }
                cout << "User Name: " << person.name << endl;
                cout << "User Age: " << person.age << endl;
            }
            break;
            case 3: {
                cout << "!!! Program has been exited. Have a good day!" << endl;
                bIsRunning = false;
            }
            break;
            default:
                cout << "!! Error: Invalid option selection." << endl;
            break;
        }
    }
}

//*********************************************
void AddRecord(string newName, int newAge) {
    Person newRecord;
    newRecord.name = newName;
    newRecord.age = newAge;
    records.push_back(newRecord);
    std::cout << "User record added successfully." << endl << endl;
};

//*********************************************
Person FetchRecord(int userID) {
    return records.at(userID);
};
//*********************************************
int get_int(int min, string prompt)
{
	int ret_integer = -1;
	string str_number = "";

	while(true) {
		cout << prompt;
		getline(cin, str_number); //get string input
        if (check_number(str_number)) 
            return(stoi(str_number));
        else 
            cout << "Please enter a number!" << endl;
	}
}
//*********************************************
bool check_number(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == false)
            return false;
    }
    return true;
}