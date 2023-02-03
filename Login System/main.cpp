#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main();


bool LoggedIn()
{
	string username, password, usnam, passwo;
	cout << "Please Enter your username: ";
	cin >> username;
	cout << "Please Enter your password: ";
	cin >> password;

	ifstream read("data\\" + username + ".txt");
	getline(read, usnam);
	getline(read, passwo); 

	if (usnam == username && password == passwo)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Register() {
	string username, password;
	cout << "Select a username: ";
	cin >> username;
	cout << "Select a password: ";
	cin >> password;

	ofstream file;
	file.open("data\\" + username + ".txt");
	file << username << endl << password;
	file.close();

	system("CLS");
	main();
}


void LogIn() {
	bool status = LoggedIn();

	if (!status)
	{
		cout << "Invalid Log In" << endl;
		system("PAUSE");
		cout << "Please try again" << endl;

		main();
	}
	else 
	{
		cout << "Successfully logged in" << endl;
		system("PAUSE");
		
	}
}

int main()
{
	int choice;

	cout << "1: Register an account" << endl;
	cout << "2. Login" << endl;
	cout << "3. Quit program." << endl;
	cin >> choice;

	switch (choice) {
		case 1:
			Register();
			break;
		case 2:
			LogIn();
			break;
		case 3:
				return false;
		default:
			cout << "Sorry that choice was invalid";
			system("CLS");
			main();
	}
		

}