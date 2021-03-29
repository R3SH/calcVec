#include <iostream>
#include "lVec.h"

int main()
{
	char mnCh = 0;
	double tmp = 0;
	LVec fVec, tVec;

	do
	{
		system("CLS");
		std::cout << "1. Set first vector\n2. Set second vector\n3. Length of first vector\n4. Length of second vector\n5. Get angle\n";
		std::cout << "6. Scalar multiplication\n7. First vector multiplication by number\n8. Invert first vector\n9. Copy First vector into another\n";
		std::cout << "e. Enter e to exit.\nMenu choice: ";
		std::cin >> mnCh;
		system("CLS");
		switch (mnCh)
		{
		case '1': 
			fVec.set_sp();
			fVec.set_ep();
			break;
		case '2':
			tVec.set_sp();
			tVec.set_ep();
			break;
		case '3':
			tmp = fVec.getLength();
			std::cout << "Length of fVec: " << tmp << std::endl;
			system("PAUSE");
			break;
		case '4': 
			tmp = tVec.getLength();
			std::cout << "Length of the second vector: " << tmp << std::endl;
			system("PAUSE");
			break;
		case '5':
			tmp = fVec.getAngle(fVec, tVec);
			std::cout << "Angle: " << tmp << std::endl;
			system("PAUSE");
			break;
		case '6':
			tmp = fVec * tVec;
			std::cout << "Scalar multiplication: " << round(tmp) << std::endl;
			system("PAUSE");
			break;
		case '7':
			std::cout << "Enter number to multiply vector with:";
			std::cin >> tmp;
			fVec * tmp;
			fVec.printVec();
			system("PAUSE");
			break;
		case '8':
			std::cout << "Orig contents: " << std::endl;
			fVec.printVec();
			-fVec;
			std::cout << "Inverted vector: " << std::endl;
			fVec.printVec();
			system("PAUSE");
		}
		if(mnCh == '9')
		{
			std::cout << "Orig contents: " << std::endl;
			fVec.printVec();
			LVec thVec(fVec);
			std::cout << "Copied vector" << std::endl;
			thVec.printVec();
			system("PAUSE");
		}
	} while (mnCh != 'e');

	return 0;
}