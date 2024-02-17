#include<iostream>
#include<fstream>//to handle file operations
#include<string>
#include<cstdlib>//for exit function
using namespace std;
bool login()
{
    string username,password,un,pw;

   cout<<"Enter username: "; 
   cin>>username;
   cout<<"Enter passward: "; 
   cin>>password;

   ifstream read("c:\\" + username + ".txt"); //open file '<username>.txt' for read from 'c:\'directory
   getline(read, un);   //read and store in un
   getline(read, pw);   //read and store in pw

   if (un == username && pw == password)
   {
       return true;
   }
   else
   {
       return false;
   }
}

int main()
{
   int ch;
   string username, password;
   cout << "1: register\n2: Login\n3:Exit \n";  //menu 
   cout<<"choose your option"<<endl;
   cin >> ch;
   ofstream file;  //open the file to write username and password
   switch(ch)
   {
        case 1:
            cout << "select a username: ";
            cin >> username;
            cout << "select a password: ";
            cin >> password;

            file.open("c:\\" + username + ".txt");
            file << username << endl << password;
            file.close();
            
            main(); //reursively return to the menu
             break;
        case 2:
            if (login())
            {
                cout << "succesfully logged in" << endl;
                system("PAUSE");//pause the program is terminated, will the original program continue.
                return 1;
            }
            else
            {
                cout << "invalid username or password" << endl;
                system("PAUSE");
                return 0;
            } 
            break;

            case 3:
                exit(0);
            
            default :
               cout<<"error"<<endl;
                

   }
   return 0;
}