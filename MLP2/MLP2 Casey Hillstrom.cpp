#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

ifstream inFile;
ofstream outFile;
string line, railName, destination ;
int i;
double weightOfCoal, costPerTon, totalValue, totalSur, numOfCars;
const float WEIGHT_PER = 74.5, SURCHARGE = .0031; //set constants


int main() {
	//set counter for reading file lines
	i = 0;

	//open file and set lines to variables
	inFile.open("Trains.txt");
	if (inFile.fail())
		cout << "No file has been found! Oops!" << endl;
	else {
		while (!inFile.eof()) {
			getline(inFile, line);
			
			switch (i) {
			case 0: railName = line;
				break;
			case 1: destination = line;
				break;
			case 2: numOfCars = stoi(line);
				break;
			case 3: costPerTon = stof(line);
				break;
			
			}
			i++;
		}
		inFile.close();

		//calculate variables
		weightOfCoal = numOfCars * WEIGHT_PER;
		totalValue = weightOfCoal * costPerTon;
		totalSur = totalValue * SURCHARGE;

		//open report file for writing
		outFile.open("train report.txt");
 
		if (outFile.fail())
			cout << "File not able to open. Please try again." << endl;
		else {
			outFile << fixed;
			outFile << "KERBAA & M COAL TRAIN REPORT - CASEY HILLSTROM" << endl << endl;
			outFile << left << setw(18) << "Railroad Name:" << railName << endl;
			outFile << left << setw(18) << "Destination:" << destination << endl << endl;
			outFile << setfill('.') << left << setw(31) << "Number of Ore cars:"        << right  << setw(12) << setfill(' ') << setprecision(0) << numOfCars       << endl;
			outFile << setfill('.') << left << setw(31) << "Total weight of coal"       << right  << setw(12) << setfill(' ') << setprecision(2) << weightOfCoal    << " short tons" << endl;
			outFile << setfill('.') << left << setw(31) << "Current Cost per short ton" << " $ "  << right    << setw(9)      << setfill(' ')    << costPerTon      << endl;
			outFile << setfill('.') << left << setw(31) << "Total Value of Shipment"    << " $ "  << right    << setw(9)      << setfill(' ')    << setprecision(2) << totalValue    << endl;
			outFile << setfill('.') << left << setw(31) << "Current Surcharge"          << right  << setw(12) << setfill(' ') << SURCHARGE*100   << "%"             << endl          << endl;
			outFile << setfill('.') << left << setw(31) << "Total Surcharge(Est)"       << " $ "  << right    << setw(9)      << setfill(' ')    << totalSur        << endl;
			outFile.close();
			cout << "The file has been  written succesfully! Congrats!\n";
			cout << double x = .0012345;
			cout << fixed << x << endl;
			cout << scientific << x << endl;
		}
	}
	return(0);
}
