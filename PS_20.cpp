// Department maintains a student information. The file contains roll number, name, division
// and address. Allow user to add, delete information of student. Display information of
// particular employee. If record of student does not exist an appropriate message is
// displayed. If it is, then the system displays the student details. Use sequential file to
// maintain the data.


#include <bits/stdc++.h>
using namespace std;


class Student{
    private:

    int roll_num;
    string name;
    char div;
    string address;

    public:
     
     Student(){
        this->roll_num = 0;
        this->name = "";
        this->div = ' ';
        this->address = " ";
     }

     Student(int r, string s, char d, string a){
        this->roll_num = r;
        this->name = s;
        this->div = d;
        this->address = a;
     }

     void Add_Info(const Student& student ){
        ofstream file;
        file.open("student.txt",ios::app);

        if(!file){
            cerr<<"Enable to open the file"<<endl;
            return;
        }

        file<<student.roll_num<<" "<<student.name<<" "<<student.div<<" "<<student.address<<" "<<endl;

        file.close();
     }

     void Deletion(int roll_number){

        ifstream ifile;
        ifile.open("student.txt");
        ofstream temp("temp.txt");

        if(!ifile || !temp){
            cerr<<"Error in opening the file"<<endl;
            return;
        }
        Student student;

        bool found = false;

        while(ifile>>student.roll_num>>student.name>>student.div>>student.address){
            if(student.roll_num != roll_num){
                temp<<student.roll_num<<" "<<student.name<<" "<<student.div<<" "<<student.address<<endl;
            }else{
                found = true;
            }
        }

        ifile.close();
        temp.close();

        remove("student.txt");
        rename("temp.txt", "student.txt");

        if(found){
            cout<<"Student found and deleted "<<endl;
        }else{
            cout<<"No information found"<<endl;
        }


     }
void Display(int roll_num) {
    ifstream ifile("student.txt");

    if (!ifile) {
        cerr << "Error: Unable to open the file" << endl;
        return;
    }

    bool found = false;
    Student student;

    while (ifile >> student.roll_num >> student.name >> student.div >> student.address) {
        if (ifile.fail()) {
            cerr << "Error: Invalid file format" << endl;
            return;
        }

        if (student.roll_num == roll_num) {
            cout << "The Student information:" << endl;
            cout << "Name: " << student.name << endl;
            cout << "Roll Number: " << student.roll_num << endl;
            cout << "Division: " << student.div << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    ifile.close();

    if (!found) {
        cout << "The information was not found" << endl;
    }
}



};


int main() {
    int choice;
    Student std;

    while (true) {
        cout << "1. Add Student\n2. Delete Student\n3. Display Student\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int roll_num;
            cout << "Enter the roll number: ";
            cin >> roll_num;
            string name;
            cout << "Enter the name: ";
            cin>>name;
            char div;
            cout << "Enter the division: ";
            cin>>div;
            string add;
            cout << "Enter the address: ";
            cin>>add;
            getline(cin, add);
            Student std1(roll_num, name, div, add);
            std.Add_Info(std1);
        } else if (choice == 2) {
            int roll_num;
            cout << "Enter the roll number to be deleted: ";
            cin >> roll_num;
            std.Deletion(roll_num);
        } else if (choice == 3) {
            int roll_num;
            cout << "Enter the roll number to be displayed: ";
            cin >> roll_num;
            std.Display(roll_num);
        } else if (choice == 4) {
            break; // Exit the loop and end the program
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}