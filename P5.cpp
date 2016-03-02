#include "stdafx.h"

#include "imageCollage.h"
#include "cyclicCollage.h"
#include "bitCollage.h"
#include <iostream>

void displayCollage(vector<int> imgCol);

int main()
{
	const int NO_ERRORS = 0;

	cout << "Testing overloaded operator+ with two imageCollage objects: " << endl;

	vector<int> testDisplay1 = { 1, 2, 3, 4 };
	vector<int> testDisplay2 = { 5, 6, 7, 8 };

	imageCollage testCollage1(testDisplay1);
	imageCollage testCollage2(testDisplay2);

	imageCollage sumCollage = testCollage1 + testCollage2;
	imageCollage sumCollage2 = testCollage2 + testCollage1;

	displayCollage(sumCollage.getDisplay());

	cout << endl << endl;

	displayCollage(sumCollage2.getDisplay());

	imageCollage testCollage3(testDisplay1);
	int testInt = 9;
	imageCollage intCollage = testCollage3 + testInt;

	cout << endl << endl;

	displayCollage(intCollage.getDisplay());

	cin.get();

	return NO_ERRORS;
}

//Description - Used as a helper method to display a collage
//preconditions: Must be passed a valid vector
void displayCollage(vector<int> imgCol)
{
	if (imgCol.size() == 0)
	{
		cout << "Nothing to display.";
	}

	else
	{
		int index = 0;
		cout << imgCol[index];
		for (unsigned index = 0; index < imgCol.size(); index++)
		{
			if (index != 0)
			{
				cout << ", ";
				cout << imgCol[index];
			}
		}
	}
}

imageCollage operator+(int addID, imageCollage& imgCol)
{
	imageCollage sumImgCol(*this);
	sumImgCol.addID(addID);
	return sumImgCol;
}