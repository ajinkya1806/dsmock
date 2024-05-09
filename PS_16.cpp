// Consider telephone book database of N clients. Make use of a hash table implementation
// to quickly look up client‘s telephone number. Make use of two collision handling
// techniques and compare them using number of comparisons required to find a set of
// telephone numbers (Note: Use linear probing with replacement and without replacement).
// Perform following operations
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display



#include <bits/stdc++.h>
using namespace std;

class clientData{
    public:
    string name;
    string tele;
    bool isActive;

    clientData(string s1, string s2, bool active){
        this->name = s1;
        this->tele = s2;
        this->isActive = active;
    }
};


class Hashing{
    private:
    vector<clientData*> client;
    int n;

    int hash_func(string tele){
        int hash=0;

        for(char c: tele){
            hash += int(c);
        }

        return ((3*hash) + 5)%10;
    }

    public:

    Hashing(int n){
        client.resize(n);
    }

    void Insert( string name , string tele , bool with_replacement){
        int index = hash_func(tele);
        int orig = index;
        while(client[index] != NULL){
               if(client[index]->name == name && client[index]->isActive ){
                      if(with_replacement){
                        client[index] = new clientData{name , tele, true};
                        
                      }
                      return;
               }

               index = (index + 1)%10;
               if(index == orig){
                 cout<<"Hash Table is full"<<endl;
                 return;
               }
        }

        client[index] = new clientData{name , tele , true};
    }

       string Search( string name, string tele , int &count ){
        int index = hash_func(tele);
        int orig = index;
        count = 1;
        while(client[index] != NULL){
               if(client[index]->name == name && client[index]->isActive ){
                      return client[index]->tele;
               }
                count ++;
               index = (index + 1)%10;
               if(index == orig){
                 break;
               }
        }

        return "key Not Found";
    }

    void Delete( string name, string tele , int &count ){
        int index = hash_func(tele);
        int orig = index;
        while(client[index] != NULL){
               if(client[index]->name == name && client[index]->isActive ){
                      client[index]->isActive = false;
                      return;
               }
            
               index = (index + 1)%10;
               if(index == orig){
                 break;
               }
        }

        cout<<"key Not Found"<<endl;
    }


     void Display() {
        for (int i = 0; i < client.size(); i++) {
            if (client[i] != nullptr) {
                cout << "Index " << i << ": ";
                cout << client[i]->name << " " << client[i]->tele << " " << client[i]->isActive << endl;
            }
        }
    }

};


int main(){

    Hashing Book(10);
    Book.Insert("Arinjay", "7841891587", true);
    Book.Insert("Rohit sharma", "1297891587", true);
    Book.Insert("Nalla", "77777777", true);  //nalla  for many reasons


    Book.Display();

    
     int comparisons;
    string number = Book.Search("Rohit sharma", "1297891587", comparisons);
    if (number != "Key Not Found") {
        cout << "Phone number found: " << number << endl;
        cout << "Number of comparisons: " << comparisons << endl;
    } else {
        cout << "Key not found." << endl;
    }






return 0;
}