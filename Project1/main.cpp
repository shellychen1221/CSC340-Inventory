//
//  main.cpp
//  Project1
//
//  Created by Hsin Yu Chen on 10/25/22.
//

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Menu{
public:
   
    void mainMenu(){
        cout<<"--------Welcome--------"<<endl;
        cout<<"1)   Start"<<endl;
        cout<<"2)   exit"<<endl;
        cout<<"Please Enter your choice: ";
        int ch;
        cin>>ch;
        switch (ch) {
            case 1:
                cout<<"Welcome!!! Start Successfully~"<<endl;
                InventoryMenu();
                break;
            case 2:
                cout << "Bye" << endl;
                return;
                break;
        }
    }
    void InventoryMenu() {
        cout<<"--------Start Your Inventory--------"<<endl;
        cout<<"1.   Add new boxes"<<endl;
        cout<<"2.   Load an inventory / Print the detail"<<endl;
        cout<<"3.   Delete the original inventory / Start a new one"<<endl;
        cout<<"0.   exit"<<endl;
        cout<<"Please Enter your choice: ";
        int ch;
        cin>>ch;
        switch (ch) {
            
            case 1:
            {
                addBoxs();
                break;
            }
            case 2:
            {
                loadMenu();
                break;
            }
            case 3:
            {
                deletemenu();
                break;
            }
            case 0:
            {
                cout<<"Thanks for playing!"<<endl;
                break;
            }
        }
        if(ch!=0){
            cout<<"\nDo you want to continue?\n1. yes     2. no"<<endl;
                   int con;
                   cin>>con;
                   if(con==1){
                       InventoryMenu();
                   }
                   if(con==2){
                       cout<<"Thanks for playing!"<<endl;
                   }
        }
       
    }
    void addBoxs(){
        int num;
        string text;
        int wei;
        int c;
        fstream storeFile;
        storeFile.open("inventory.txt", ios::app);
        cout<<"The ID number: ";
        cin>>num;
        c=getchar();
        cout<<"Text description: ";
        getline(cin, text);
        cout<<"Weight: ";
        cin>>wei;
        cout<<"Do you want to store in file?"<<endl;
        cout<<"1. Yes   2.No"<<endl;
        int ch;
        cin>>ch;
        if(ch==1){
            storeFile << num << ","<< text << "," << wei<<endl;
            storeFile.close();
            cout<<endl<<"Add it successfully!"<<endl;
        }
        else if(ch==2){
            cout<<"Ok, you can back to Menu"<<endl;
        }
        else{
            cout<<"Error"<<endl;
        }
        
        storeFile.open("inventory.txt");
        cout<<"Do you want to print the detail?"<<endl;
        cout<<"1. Yes       2.No"<<endl;
        int ccc;
        cin>>ccc;
        if(ccc==1){
            if(storeFile) {
                string line;
                while (getline(storeFile,line,',')) {
                    //cout<<line<<"   ";
                    cout << line << "   ";
                }
             }
            else {
                cout<<"It's empty!"<<endl;
             }
        }
        else if(ccc==2){
            cout<<"OK, you can back to menu!"<<endl;
        }
        else{
            cout<<"Error!"<<endl;
        }
    }
    void loadMenu(){
        fstream storeFile;
        storeFile.open("inventory.txt");
        cout<<"Successfully loaded file"<<endl;
        cout<<"Do you want to print the detail?"<<endl;
        cout<<"1. Yes       2.No"<<endl;
        
        int ch;
        cin>>ch;
        if(ch==1){
            if(storeFile) {
                cout<<"---- Inventory Details ----"<<endl;
                string line;
                while (getline(storeFile,line,',')) {
                    cout << line<<"     ";
                }
             }
            else {
                cout<<"It's empty!"<<endl;
             }
        }
        else if(ch==2){
            cout<<"OK, you can back to menu!"<<endl;
        }
        else{
            cout<<"Error!"<<endl;
        }
    }
    
    void deletemenu(){
        char filename[] = "inventory.txt";
        int status = remove(filename);
        if(status==0){
            cout<<"Deleted Successfully!"<<endl;
            cout<<"You can start your new inventory"<<endl;
        }
        else{
            cout<<"Error Occurred!"<<endl;
        }
    }

};


int main() {
    Menu m;
    m.mainMenu();
    return 0;
}
