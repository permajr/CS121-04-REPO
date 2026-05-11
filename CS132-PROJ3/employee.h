#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "tree.h"
#include <sstream>
using namespace std;

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

class employee
{

public:
	string empName = "0";
	string empSocial = "0";
	string empType = "0";
	string hoursWorked = "0";

	bool compareByName(const employee& other) const { return empName < other.empName; }
	bool compareBySocial(const employee& other) const { return empSocial < other.empSocial; }
	bool compareByType(const employee& other) const { return empType < other.empType; }
	bool compareByHours(const employee& other) const { return hoursWorked < other.hoursWorked; }
	bool operator<(const employee& other) const { return compareByName(other); }
	bool operator>(const employee& other) const { return empName > other.empName; }
	bool operator==(const employee& other) const { return empType == other.empType; }

	bool operator!=(const employee& other) const { return empName != other.empName; }
	friend bool operator>=(const employee& a, const employee& b) { return a.empName >= b.empName; }

	friend ostream& operator<<(ostream& out, const employee& emp)
	{
		out << emp.empName << "\n"
			<< emp.empSocial << "\n"
			<< emp.empType << "\n"
			<< emp.hoursWorked;
		return out;
	}

};

class oxyRecord
{
public:
	string tempS;
	string fileName;
	ifstream inFile;
	ofstream outFile;
	tree<employee> tempTree;
	void checkFile();
	void showFile();
	void updateRecord();
	void newEmployee();
	void saveToFile();
	void deleteRecord();
	void saveTreeRecursive(TreeNode<employee>*, ofstream&);
	void retrieveRecord() const;
	void printGroupRecursive(TreeNode<employee>*, char);
};


void oxyRecord::saveToFile()
{
	if (tempTree.emptyTree()) {
		cout << "Tree is empty!\n";
		return;
	}

	string outFileName;
	cout << "Enter the name of the file to save to: ";
	getline(cin, outFileName);

	outFile.open(outFileName);
	if (!outFile) {
		cout << "Error creating file.\n";
		return;
	}

	saveTreeRecursive(tempTree.root, outFile);

	outFile.close();
	cout << "Records saved to " << outFileName << "\n";
}

void oxyRecord::saveTreeRecursive(TreeNode<employee>* node, ofstream& out) {
	if (!node) return;

	saveTreeRecursive(node->left, out);

	out << node->TreeData.empName << "\n"
		<< node->TreeData.empSocial << "\n"
		<< node->TreeData.empType << "\n"
		<< node->TreeData.hoursWorked << "\n";

	saveTreeRecursive(node->right, out);
}

void oxyRecord::newEmployee()
{
	employee newEmp;
	cout << "=====================================================\n"
		<< "Enter the Name of the New Employee, then press enter: \n";
	getline(cin, newEmp.empName);
	cout << "=====================================================\n"
		<< "Enter the New Employee's Social Security Number (SSN), then press enter: \n";
	getline(cin, newEmp.empSocial);
	cout << "=====================================================\n"
		<< "Enter the New Employee's Employee type then press enter: \n";
	getline(cin, newEmp.empType);
	cout << "=====================================================\n"
		<< "Enter the New Employee's Hours Worked as of today, then press enter: \n";
	getline(cin, newEmp.hoursWorked);
	tempTree.insert(newEmp);
}

void oxyRecord::checkFile()
{
	bool errCheck = false;
	while (!errCheck)
	{
		cout << "=====================================\n"
			<< "Enter the file path of the record you'd like to edit:\n";
		getline(cin, fileName);
		inFile.open(fileName);
		if (!inFile)
		{
			cout << "We were unable to find that record, please try another!\n";
			errCheck = false;
		}

		if (!tempTree.emptyTree())
		{
			tree<employee> freshTree;
			tempTree = freshTree;
		}

		employee tempEmp;
		int fieldNum = 0;
		string line;

		while (getline(inFile, line))
		{
			if (line.empty())
			{
				cout << "line empty\n";
				continue;
			}
			switch (fieldNum)
			{
			case 0:
				tempEmp.empName = line; break;
			case 1:
				tempEmp.empSocial = line; break;
			case 2:
				tempEmp.empType = line; break;
			case 3:
				tempEmp.hoursWorked = line;
				tempTree.insert(tempEmp);
				fieldNum = -1;
				tempEmp = employee();
				break;
			}

			fieldNum++;
			errCheck = true;
		}
		cout << "Record loaded succesfully!\n";
		inFile.close();
	}
}

void oxyRecord::showFile()
{
	employee tempEmp;
	tree<employee> auxTree;
	int choice = 0;
	if (tempTree.emptyTree())
		cout << "Tree is currently empty!\n";
	else
	{
		cout << "===========================================\n"
			<< "Which group would you like to display?\n"
			<< "1. All workers\n"
			<< "2. Office workers\n"
			<< "3. Factory staff\n"
			<< "4. Salaried Employees\n";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			tempTree.writeTree(2);
			break;
		case 2:
			printGroupRecursive(tempTree.root, 'O');
			break;
		case 3:
			printGroupRecursive(tempTree.root, 'F');
			break;
		case 4:
			printGroupRecursive(tempTree.root, 'S');
			break;
		}
	}
}

void oxyRecord::printGroupRecursive(TreeNode<employee>* node, char targetType)
{
	if (!node)
		return;

	//left
	printGroupRecursive(node->left, targetType);

	//check
	if (node->TreeData.empType[0] == targetType)
	{
		cout << "--------------------------------" << endl;
		cout << "Name:    " << node->TreeData.empName << endl;
		cout << "SSN:     " << node->TreeData.empSocial << endl;
		cout << "Type:    " << node->TreeData.empType << endl;
		cout << "Hours:   " << node->TreeData.hoursWorked << endl;
		cout << "--------------------------------" << endl;
	}

	//right
	printGroupRecursive(node->right, targetType);
}

//searches for name recursively using < to determine what side to move to next
TreeNode<employee>* findNode(TreeNode<employee>* node, string name)
{
	if (!node)
		return nullptr;

	if (node->TreeData.empName != name)
	{
	
		if (name < node->TreeData.empName)
		{
	
			return findNode(node->left, name);
		}
		else
		{
		
			return findNode(node->right, name);
		}
	}

	return node;
}

void oxyRecord::retrieveRecord() const
{
	if (tempTree.emptyTree()) {
		cout << "Tree is currently empty!\n";
		return;
	}

	employee target;
	cout << "Enter the name of the employee to retrieve: ";
	getline(cin, target.empName);

	
	TreeNode<employee>* foundNode = findNode(tempTree.root, target.empName);

	if (foundNode) {
		cout << "--------------------------------" << endl;
		cout << "Name:    " << foundNode->TreeData.empName << endl;
		cout << "SSN:     " << foundNode->TreeData.empSocial << endl;
		cout << "Type:    " << foundNode->TreeData.empType << endl;
		cout << "Hours:   " << foundNode->TreeData.hoursWorked << endl;
		cout << "--------------------------------" << endl;
	}
	else 
	{
		cout << "Employee not found.\n";
	}
}

void oxyRecord::updateRecord() 
{
	if (tempTree.emptyTree()) 
	{
		cout << "Tree is empty! Load a file first.\n";
		return;
	}

	string searchName;
	cout << "Enter the name of the employee to update: ";
	getline(cin, searchName);

	TreeNode<employee>* targetNode = findNode(tempTree.root, searchName);

	if (!targetNode) 
	{
		cout << "Employee '" << searchName << "' not found.\n";
		return;
	}

	cout << "\n--- Updating: " << targetNode->TreeData.empName << endl
		<< "Current SSN:  " << targetNode->TreeData.empSocial << endl
		<< "Current Type: " << targetNode->TreeData.empType << endl
		<< "Current Hours:" << targetNode->TreeData.hoursWorked << endl << endl;

	string newName, newSocial, newType, hoursInput, newHours;
	bool hoursChanged = false;

	cout << "New Name (Enter to skip): ";
	getline(cin, newName);

	cout << "New SSN (Enter to skip): ";
	getline(cin, newSocial);

	cout << "New Type (Enter to skip): ";
	getline(cin, newType);

	cout << "New Hours (Enter to skip): ";
	getline(cin, hoursInput);

	if (!hoursInput.empty()) 
	{
		stringstream ss(hoursInput);
		if (ss >> newHours) 
		{
			hoursChanged = true;
		}
		else 
		{
			cout << "Invalid number for hours. Keeping original.\n";
			hoursChanged = false;
		}
	}

	bool nameChanged = false;
	if (!newName.empty() && newName != searchName) 
	{
		nameChanged = true;
	}

	if (nameChanged) 
	{
		employee updatedData = targetNode->TreeData;

		if (newName.empty()) 
		{
			updatedData.empName = searchName;
		}
		else 
		{
			updatedData.empName = newName;
		}

		if (!newSocial.empty()) 
		{
			updatedData.empSocial = newSocial;
		}
		if (!newType.empty()) 
		{
			updatedData.empType = newType;
		}
		if (hoursChanged) 
		{
			updatedData.hoursWorked = newHours;
		}

		tempTree.SearchAndDestroy(targetNode->TreeData);
		tempTree.insert(updatedData);

		cout << "Record updated (Re-inserted due to name change).\n";
	}
	else 
	{

		if (!newSocial.empty()) 
		{
			targetNode->TreeData.empSocial = newSocial;
		}
		if (!newType.empty()) 
		{
			targetNode->TreeData.empType = newType;
		}
		if (hoursChanged) 
		{
			targetNode->TreeData.hoursWorked = newHours;
		}

		cout << "Record updated successfully.\n";
	}
}


void oxyRecord::deleteRecord()
{
	if (tempTree.emptyTree()) 
	{
		cout << "Tree is empty!\n";
		return;
	}

	employee target;
	cout << "Enter the name of the employee to delete: ";
	getline(cin, target.empName);
	cout << "searching for " << target.empName;

	TreeNode<employee>* found = findNode(tempTree.root, target.empName);
	if (!found) 
	{
		cout << "Employee not found.\n";
		return;
	}

	tempTree.SearchAndDestroy(target);
	cout << "Employee deleted.\n";
}

#endif