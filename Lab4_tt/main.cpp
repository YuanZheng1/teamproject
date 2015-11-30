#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "Database.h"

// visits --------------------------------

void printPerson(Person& n){
	std::cout << n << std::endl;
}

void printDob(Person& n){
	std::cout << n.getDOB() << std::endl;
}

void printName(Person& n){
	std::cout << n.getFirstName() << " " << n.getLastName() << std::endl;
}


// output visits ----------------------

void DobToFile(Person& n){
	std::ofstream outfile;
	outfile.open("BirthdayOutput.txt", std::ios_base::app);
	outfile << n.getDOB() << "\n";
	outfile.close();
}

void NamesToFile(Person& n){
	std::ofstream outfile;
	outfile.open("NameOutput.txt", std::ios_base::app);
	outfile << n.getFirstName() << " " << n.getLastName() << "\n";
	outfile.close();
}

void WriteToTemp(Person& n) {
	std::ofstream outfile;
	outfile.open("temp.txt", std::ios_base::app);
	outfile << n << "\n";
	outfile.close();
}

void ClearFile(std::string filename) {
	std::ofstream outfile;
	outfile.open(filename);
	outfile << "";
	outfile.close();
}


int main() {

	ClearFile("NameOutput.txt");
	ClearFile("BirthdayOutput.txt");
	Database db("Input.txt");
	while (db.QueryLoop(printPerson, WriteToTemp) != 'q') {}
	db.Output(DobToFile, NamesToFile);
	
	//ClearFile("temp.txt");
	
	system("pause");
	return 0;
}