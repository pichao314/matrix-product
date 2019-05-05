/*This program can read two matrix from the file indicated by the command line and product it
The program can process with any size of matrix, product-possiblity is checked
Negative element is allowed in the matrix

Wrote by Chao Pi 09/25/2018*/


#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;


//New structure matrix to store the matrix read from file
struct matrix
{
	int row, column;

	vector<vector<int>> Matrix;		//use a two-dimension vector to store matrix
	vector<int> currentRow;			//use a vector to store a line read from file
};


void readArg(int argc, char* argv[], string& f1, string& f2);
void readMatrix(string filename, matrix& m);
void matrixProduct(matrix m1, matrix m2);
int poRC(matrix m1, matrix m2, int r, int c);


//Read two matrix from two file , product them and output
int main(int argc, char *argv[])
{
	matrix m1, m2;
	string f1, f2;

	readArg(argc, argv, f1, f2);
	readMatrix(f1, m1);
	readMatrix(f2, m2);
	matrixProduct(m1, m2);
	return 0;
}

//Read the command line arguments while the name after "-m" stands for fisrt matrix, the name after "-M" stands for second matrix
void readArg(int argc, char* argv[], string& f1, string& f2)
{
	if (argc < 5)
	{
		cout << "No enough arguments" << endl;
		exit(1);
	}
	else if (argc > 5)
	{
		cout << "Too much arguments" << endl;
		exit(1);
	}

	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "-m"))
			f1 = argv[i + 1];
		else if (!strcmp(argv[i], "-M"))
			f2 = argv[i + 1];
	}
}

//read a outside file into a matrix and count the scale
void readMatrix(string filename, matrix& m)
{
	fstream in;
	string current_line;			//use a string to store a whole line form file 

	//open a file and check the posibility of reading
	in.open(filename);
	if (in.fail()) {
		cout << "The file " << filename << " cannot read successfully!" << endl;
		exit(1);
	}

	//read the file and put the value in to matrix
	while (!in.eof())
	{
		getline(in, current_line);
		int value = 0;
		int state = 0;
		int sign = 0;

		//find each number in the string and push it into currentRow
		for (int i = 0; i <= current_line.length(); i++)
		{
			if (isdigit(current_line[i]))
			{
				state = 1;			//the variable state used to identify whether the instream is inside a number(1) or outside a number(0) 
				value = value * 10 + current_line[i] - '0';			//in case of number more than 1 digit
			}

			else if (current_line[i] == '-')
			{
				sign = 1;
				state = 1;
			}

			else if (state == 0)	//while the current and former char both are not number
				;

			else					//while meet a non-digit and prepare to push back the value and clean for next number
			{
				if (sign == 1)
				{
					value = -value;
				}

				m.currentRow.push_back(value);

				value = 0;
				state = 0;
				sign = 0;
			}
		}

		//jump the empty line
		if (!m.currentRow.size())
			continue;
		//push currentRow to the Matrix and clean the row
		m.Matrix.push_back(m.currentRow);
		m.currentRow.resize(0);
	}

	//set the matrix scale by the vector size
	m.row = m.Matrix.size();
	m.column = m.Matrix[0].size();

	in.close();
}


//check the possiblity of producting two matrix first and then print out the result
void matrixProduct(matrix m1, matrix m2)
{
	if (m1.column != m2.row)
	{
		cerr << "These matrixes cannot be producted!" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < m1.row; i++)
		{
			for (int j = 0; j < m2.column; j++)
			{
				cout.setf(ios::left);
				cout << setw(5) << poRC(m1, m2, i, j);
			}
			cout << endl;
		}
	}
}


//product m1's row[r] with m2's column[c]
int poRC(matrix m1, matrix m2, int r, int c)
{
	int val1 = 0;
	int val2 = 0;
	for (int i = 0; i < m1.column; i++) {
		val1 = m1.Matrix[r][i] * m2.Matrix[i][c];
		val2 = val2 + val1;
	}
	return val2;
}