#include <iostream>
#include <bitset>

using namespace std;


void dissociate(unsigned short int n);

unsigned short int sum16bit(unsigned short int numA, unsigned short int numB);

int main()
{
	unsigned short int result;

	result = sum16bit(1560, 1564);

	cout << "result : " << result << endl;
	cout << "result : " << bitset<8>((result & 0xFF00) >> 8) << " " << bitset<8>(result & 0x00FF) << endl;
}

void dissociate(unsigned short int n)
{
	cout << "summand: " << n << endl;
	cout << "summand: " << bitset<8>((n & 0xFF00) >> 8) << " " << bitset<8>(n & 0x00FF) << endl;
}

unsigned short int sum16bit(unsigned short int numA, unsigned short int numB)
{

	unsigned char msbA;
	unsigned char lsbA;

	unsigned char msbB;
	unsigned char lsbB;

	msbA = (numA & 0xFF00) >> 8;
	lsbA = (numA & 0x00FF);

	msbB = (numB & 0xFF00) >> 8;
	lsbB = (numB & 0x00FF);

	dissociate(numA);
	dissociate(numB);

	unsigned char mResult;
	unsigned char lResult;

	lResult = lsbA + lsbB;

	if ((lsbA > 0) && (lsbB > 0) && (lsbA > (255 - lsbB)))
	{
		mResult = msbA + msbB + 0x0001;
	}
	else
	{
		mResult = msbA + msbB;
	}

	return  (mResult << 8) | (lResult & 0xFFFF);
}
