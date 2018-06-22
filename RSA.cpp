//Alexandra Kozak
//RSA Program 5
#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <sstream>
using namespace std;

void outputVec(vector<int>);
int ModInver(int, int);
int concat(int, int);
int digits(int);
vector<int> E_Vector(int);
vector<int> D_Vector(vector<int>, int);
vector<int> Decimal(string);
string Alpha(vector<int>);

vector<int> encryption(vector<int>, int, int);
vector<int> decryption(vector<int>, int, int);

int main()
{
	int p = 73;
	int q = 151;
	int n = p * q;
	int phi = (p - 1)*(q - 1);
	vector<int> e;
	vector<int> d;

	//Example 1

	string sentence = "How are you?";
	string dinfo1 = "";

	cout << "Part 1 " << endl;
	cout << "RSA Key Information:" << endl;
	cout << "Phi: " << phi << endl;
	cout << "n: " << n << endl;

	cout << "A List of five e's: [";
	e = E_Vector(phi);
	outputVec(e);
	cout << "]" << endl;

	cout << "A List of five d's: [";
	d = D_Vector(e, phi);
	outputVec(d);
	cout << "]" << endl;

	cout << endl;

	cout << "Original Plaintext: " << sentence << endl;
	vector<int> plaintext = Decimal(sentence);
	vector<int> ctext;
	vector<int> decryptedtext;

	for (int a = 0; a < 5; a++)
	{
		cout << "Public Key: (" << e[a] << ", " << n << ")" << endl;
		cout << "Ciphertext: ";
		ctext = encryption(plaintext, e[a], n);
		outputVec(ctext);
		cout << endl;
		cout << "Private Key: (" << d[a] << ", " << n << ")" << endl;
		cout << "Plaintext: ";
		decryptedtext = decryption(ctext, d[a], n);
		outputVec(decryptedtext);
		cout << endl;

		cout << endl;
	}

	dinfo1 = Alpha(decryptedtext);
	cout << "Decrypted Plaintext: " << dinfo1 << endl;


	//Example 2
	string sentence2 = "Public key cryptography.";
	string dinfo2 = "";

	cout << "\n\nPart 2" << endl;
	cout << "RSA Key Information:" << endl;
	cout << "Phi: " << phi << endl;
	cout << "n: " << n << endl;

	cout << "A List of five e's: [";
	e = E_Vector(phi);
	outputVec(e);
	cout << "]" << endl;

	cout << "A List of five d's: [";
	d = D_Vector(e, phi);
	outputVec(d);
	cout << "]" << endl;

	cout << endl;

	cout << "Original Plaintext: " << sentence2 << endl;
	vector<int> plaintext2 = Decimal(sentence2);
	vector<int> ciphertext2;
	vector<int> decryptedtext2;

	for (int a = 0; a < 5; a++)
	{
		cout << "Public Key: (" << e[a] << ", " << n << ")" << endl;
		cout << "Ciphertext: ";
		ciphertext2 = encryption(plaintext2, e[a], n);
		outputVec(ciphertext2);
		cout << endl;
		cout << "Private Key: (" << d[a] << ", " << n << ")" << endl;
		cout << "Plaintext: ";
		decryptedtext2 = decryption(ciphertext2, d[a], n);
		outputVec(decryptedtext2);
		cout << endl;

		cout << endl;
	}

	dinfo2 = Alpha(decryptedtext2);
	cout << "Decrypted Plaintext: " << dinfo2 << endl;

	system("pause");
	return 0;
}

vector<int> E_Vector(int b)
{
	vector<int> e;
	int nums = 0;
	int a = 2;
	while (nums != 5)
	{
		int gcd = 0;

		for (int x = 1; x <= a && x <= b; x++)
		{
			if (a % x == 0 && b % x == 0)
			{
				gcd = x;
			}
		}

		if (gcd == 1 && nums < 5)
		{
			nums++;
			e.push_back(a);
		}
		a++;
	}

	return e;
}
vector<int> D_Vector(vector<int> e, int phi)
{
	vector<int> d;

	for (int a = 0; a < e.size(); a++)
	{
		d.push_back(ModInver(e[a], phi));
	}

	return d;
}

vector<int> encryption(vector<int> plaintext, int e, int n)
{
	vector<int> encryptionedText;

	for (int x = 0; x < plaintext.size(); x++)
	{
		int a = 1;
		for (int b = 0; b < e; b++)
		{
			a = a * plaintext[x];
			a = a % n;
		}
		encryptionedText.push_back(a);
	}

	return encryptionedText;
}

vector<int> decryption(vector<int> ciphertext, int d, int n)
{
	vector<int> decryptedText;

	for (int a = 0; a < ciphertext.size(); a++)
	{
		int b = 1;
		for (int c = 0; c < d; c++)
		{
			b = b * ciphertext[a];
			b = b % n;
		}
		decryptedText.push_back(b);
	}

	return decryptedText;
}

void outputVec(vector<int> x)
{
	for (int a = 0; a < x.size(); a++)
	{
		cout << x[a];

		if ((a + 1) < x.size())
		{
			cout << ", ";
		}
	}
}

int ModInver(int a, int b)
{
	a = a % b;
	for (int x = 1; x < b; x++)
	{
		if ((x * a) % b == 1)
		{
			return x;
		}
	}
}


vector<int> Decimal(string plaintext)
{
	vector<int> decimal;
	vector<int> decimal_concat;

	char arr[67] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', '.', ',', ';', '?' };

	for (int i = 0; i < plaintext.length(); i++)
	{
		for (int j = 0; j < sizeof(arr); j++)
		{
			if (plaintext[i] == arr[j])
			{
				decimal.push_back(j);
			}
		}
	}

	for (int i = 0; i < decimal.size(); i++)
	{
		if (i % 2 == 0)
		{
			int temp = concat(decimal[i], decimal[i + 1]);
			decimal_concat.push_back(temp);
		}
	}

	return decimal_concat;
}

string Alpha(vector<int> decimal)
{
	int size = decimal.size() * 2;
	string ptext;
	string ptext2;
	vector<string> ptextv(size);

	char arr[67] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', '.', ',', ';', '?' };

	for (int i = 0; i < decimal.size(); i++)
	{
		ostringstream convert;
		convert << decimal[i];

		if (digits(decimal[i]) == 1)
		{
			string integer = "000" + convert.str();
			ptext.append(integer);
		}
		else if (digits(decimal[i]) == 2)
		{
			string integer = "00" + convert.str();
			ptext.append(integer);
		}
		else if (digits(decimal[i]) == 3)
		{
			string integer = "0" + convert.str();
			ptext.append(integer);
		}
		else
		{
			string integer = convert.str();
			ptext.append(integer);
		}
	}

	for (int a = 0; a < size; a++)
	{
		ptextv[a] = ptext.substr(a * 2, 2);
	}

	for (int b = 0; b < size; b++)
	{
		ptext2 = ptext2 + " ";
	}

	for (int i = 0; i < size; i++)
	{
		int temp = atoi(ptextv[i].c_str());

		for (int j = 0; j < sizeof(arr); j++)
		{
			if (temp == j)
			{
				ptext2[i] = arr[j];
			}
		}
	}

	return ptext2;
}
int digits(int a)
{
	int digits = 1;
	int powersoften = 10;

	while (powersoften <= a)
	{
		digits++;
		powersoften *= 10;
	}
	return digits;
}
int concat(int a, int b)
{
	int c;
	ostringstream os;

	if (digits(a) == 1)
	{
		os << 0 << a;
	}
	else
	{
		os << a;
	}

	if (digits(b) == 1)
	{
		os << 0 << b;
	}
	else
	{
		os << b;
	}
	istringstream is(os.str());
	is >> c;

	return c;
}
