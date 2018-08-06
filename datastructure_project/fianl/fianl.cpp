// fianl.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
												//REQUIRED TO CREATE LINKED LIST
struct listnode
{												//DECLARATIONS
	string SKU, prodName, cat;
	double price;
	int quantity;
	struct listnode *next;
};

listnode *head;

											//DISPLAY ALL ITEMS STORED
void showAll() {							//METHOD CALLED BY FUNCTION IN SWITCH CASE
	listnode *nodePtr;
	nodePtr = head;							//ASSIGN NODEPTR TO HEAD
	
	while (nodePtr != NULL) {				//WHILE NODEPTR IS NOT NULL

	cout << nodePtr->SKU << endl; 
	cout << "NAME: " << nodePtr->prodName << endl; 
	cout << "PRICE: " << nodePtr->price << endl; 
	cout << "QUANTITY: " << nodePtr->quantity << endl;
	cout <<"CATEGORY: " << nodePtr->cat << "\n" << endl;
		nodePtr = nodePtr->next;			//MOVES TO NEXT NODE
	}
}
												//DISPLAY WITH SKU FUNCTION
void showSKU(string findSKU) {
	listnode *nodePtr;
	bool error_check = 0;
	nodePtr = head;
	while (nodePtr != NULL)					//WHEN NODE POINTER IS NOT NULL 
	{
		if (nodePtr->SKU == findSKU)		//IF CONDITON IS RUN
		{
		cout << "PRODUCT NAME:	 " << nodePtr->prodName << endl;
		cout << "UNIT PRICE:	 " << nodePtr->price << endl;
		cout << "QUANTITY:		 " << nodePtr->quantity << endl;
		cout << "CATEGORY:		 " << nodePtr->cat << "\n\n";
			error_check = 1;
		}
		nodePtr = nodePtr->next;			//NODE POINTER MOVES TO NEXT NODE
	}
		if (nodePtr == NULL && error_check != 1)	
		{
		cout << "ERROR OCCURED" << endl;		
		}
}

												//DISPLAY CATEGORY FUNCTION
void showCat(string searchcategory)
{
	listnode *nodePtr, *previousnode;		

	nodePtr = head;
	bool error_check = 0;
	while (nodePtr != NULL)
	{
	if (nodePtr->cat == searchcategory)
	{
	cout << nodePtr->SKU << endl;
	cout << "CATEGORY:		" << nodePtr->cat << endl;
	cout << "PRODUCT NAME:		" << nodePtr->prodName << endl;
		error_check = 1;
	}
	nodePtr = nodePtr->next;
		if (nodePtr != NULL && error_check != 1)
		{
		cout << "NO CATEGORY FOUND" << endl;
		}
	}
}
									
												//INSERTION FUNCTION
void insertNode(string sku, string ITEMNAME, double PRICE, int QUANTITY, string CATEGORY) {
	listnode *newNode, *nodePtr = NULL, *previousNode = NULL;

									//CREATING A NEW NODE
	newNode = new listnode;
	newNode->SKU = sku;
	newNode->prodName = ITEMNAME;
	newNode->price = PRICE;
	newNode->quantity = QUANTITY;
	newNode->cat = CATEGORY;

	if (!head)					//IF NOT EQUAL TO HEAD THEN
	{							
		head = newNode;			//INITIALIZE NODEPTR TO HEAD
		newNode->next = NULL;	//NEW NODE WILL BE NULL MAKING HEAD NO LONGER POINT TO NULL
	}
	else						//SINCE HEAD DOESNT POINT TO NULL THE ELSE WILL EXECUTE
	{
		nodePtr = head;			//INITIALISE NODEPTR TO THE HEAD OF THE LIST
		while (nodePtr != NULL && nodePtr->SKU < sku)
		{						//NODE PTR ADDS VALUE
		previousNode = nodePtr;	//PREVIOUS NODE BECOMES NODEPTR
		nodePtr = nodePtr->next;//MOVE TO NEXT NODE
		}
	}

	if (previousNode == NULL)	//IF PREVIOUS NODE IS NULL
	{
		head = newNode;			//HEAD IS EQUAL TO NEW NODE
		newNode->next = nodePtr;//MOVE TO NEXT NODE
	}
	else
	{							
		previousNode->next = newNode;
		newNode->next = nodePtr;
	}
}

												//DELETE FUNCTION
void deleteNode(string removeSKU)				//FUNCTION WITH STRING AS AN ARGUMENT
{
	bool error_check = 0;					
	listnode *nodePtr, *previousNode;			//KEEP LIST IN MEMORY

	if (head->SKU == removeSKU)					//CHECK WITH HEAD TO SEE IF IT MATCHES THE ARGUMENT
		{
		nodePtr = head->next;
		delete head;							//IF IT MATCHES DELETE IT
		head = nodePtr;							//REPLACE HEAD WITH NODEPTR
		}
		else									//ELSE WILL RUN IF THE HEAD DOENST MATCH ARGUMENT
		{
		nodePtr = head;							//POINTER IS HEAD
		previousNode = NULL;					//PREVIOUS NODE IS EQUAL TO NULL
		
		while (nodePtr != NULL && nodePtr->SKU != removeSKU)
		{										 //TRAVEL UP TO THE NODE WHICH HAS A DATA AS STRING, PASSED AS ARGUMENT
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		previousNode->next = nodePtr->next;
		delete nodePtr;							//IF FOUND THEN DELETE THAT NODE
		}
}

												//MAIN METHOD
void main()					
{									
	int	amount, quantity, choice;				//DECLARE ITEMS
	string SKU, prodName, cat, findSKU, removeSKU, searchCategory;
	double price;
	char ans = 'Y';
												//SAMPLE ITEMS
	insertNode("ABC01", "PARTY DRESS", 3.50, 60, "Female");
	insertNode("ABC02", "BUSINESS SUIT", 2.00, 100, "Male");

	while(ans=='Y'||ans=='y')					//WHILE LOOP FOR INPUT
	{
	cout << "MENU:" << endl;					//MENU WITH OUTPUT 
	cout << "PRESS 1 TO INSERT SKU" << endl;
	cout << "PRESS 2 TO DELETE SKU" << endl;
	cout << "PRESS 3 TO SEARCH SKU" << endl;
	cout << "PRESS 4 TO SEARCH CATEGORY" << endl;
	cout << "PRESS 5 TO SHOW ALL ITEMS" << endl;
	cin >> choice;

	switch (choice)								//SWITCH STATEMENT
	{
	case 1: cout << "ENTER AMOUNT OF ITEMS" << endl;
			cin >> amount;
			for (int i = 0; i < amount; i++)
			{
				cout << "ENTER SKU NUMBER:" << endl;
				getchar();
				cin >> SKU;
				cout << "ENTER PRODUCT NAME:";
				getchar();
				cin >> prodName;
				cout << "ENTER PRODUCT PRICE:";
				cin >> price;
				cout << "ENTER QUANTITY:";
				cin >> quantity;
				cout << "ENTER CATEGORY [MALE OR FEMALE]:";
				getchar();
				cin >> cat;

				insertNode(SKU, prodName, price, quantity, cat);
	  } break;
		case 2: cout << "REMOVE SKU:" << endl;
			cin >> removeSKU;
			deleteNode(removeSKU); break;
		case 3: cout << "SEARCH SKU:" << endl;
			cin >> findSKU;
			showSKU(findSKU); break;
		case 4: cout << "SEARCH WITH CATEGORY [MALE OR FEMALE]:" << endl;
			cin >> searchCategory;
			showCat(searchCategory); break;
		case 5: showAll(); break;
		default: cout << "ERROR OCCURED"; break;
		}
		cout << "\nWOULD YOU LIKE TO CONTINUE?(Y or N)";
		cin >> ans;
		}

	system("pause");
}