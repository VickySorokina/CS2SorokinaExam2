/**********************************
* Author: Viktoria Sorokina
* Disclaimer: I affirm that all code given below was written solely by me , Viktoria Sorokina, (or was prewritten by M. Bell)
* and that any help I received adhered to the rules stated for this exam.
***********************************/

#include<iostream>
using namespace std;

//This function takes a number of rows as a first parameter and
//a number of columns as its second parameter. It then returns
//a pointer to a pointer to an int that holds a two-dimensional
//array of integers.
int** fillArray(unsigned int, unsigned int);


//This function takes a dynamically allocated 2D array and sends
//it to the bit bucket in the sky, er, I mean deletes it.
//The first parameter will be the two dimensional array, viewed
//as a pointer to a pointer to an int. The second parameter is
//the number of rows in that array.
void deleteArray(int**, int);



int main() //unchanged main()
{
	int nR, nC; //Number of rows and columns
	cout << "How many rows? ";
	cin >> nR;
	cout << "How many cols? ";
	cin >> nC;

	//Create the array!
	int** myArray = fillArray(nR, nC);

	//Print the array to the screen!
	for (int i = 0; i < nR; i++) {
		for (int j = 0; j < nC; j++)
			cout << myArray[i][j] << " ";
		cout << endl;
	}

	//DESTROY!!!!
	deleteArray(myArray, nR);

	//The end! Ta da!
	return 0;
}


//This function takes a number of rows as a first parameter and
//a number of columns as its second parameter. It then returns
//a pointer to a pointer to an int that holds a two-dimensional
//array of integers.
int** fillArray(unsigned int numRows, unsigned int numCols)
{
	int** My2DArray; // This will hold the array

	My2DArray = new int*[numRows];	//Dynamically allocates an array of pointers to ints

	for (int i = 0; i < numRows; i++) { //create cols:
		int* Columns = new int[numCols]; // allocates the array of ints
		My2DArray[i] = Columns; //assigns it to the current row of your array
		 
		//The code below reads a number into each location in the 2D array.
		for (int j = 0; j < numCols; j++) {
			cout << "Number at position " << i << "," << j << "? ";
			cin >> My2DArray[i][j];
		}
	}
	return My2DArray;
}


//This function takes a dynamically allocated 2D array and sends
//it to the bit bucket in the sky, er, I mean deletes it.
//The first parameter will be the two dimensional array, viewed
//as a pointer to a pointer to an int. The second parameter is
//the number of rows in that array.
void deleteArray(int** A, int size)
{
	for (int i = 0; i < size; i++)
		delete [] A[i]; //deletes every row

	delete [] A; //delete the whole
}