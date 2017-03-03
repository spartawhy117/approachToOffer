#include <iostream>
using namespace std;

bool Find(int *matrix,int rows,int cols,int number)
{
	bool found = false;

	if(matrix!=nullptr&&rows>0&&cols>0)
	{
		int row = cols-1;
		int col = 0;
		while (row>=0&&col<cols)
		{
			if(matrix[row*cols+col]==number)
			{
				found = true;
				break;
			}
			else if(matrix[row*cols+col]<number)
			{
				++col;
			}
			else
			{
				--row;
			}
		}
	}

	return found;

}

int main()
{
	int matrix[] = {
		1,2,8,9,
		2,4,9,12,
		4,7,10,13,
		6,8,11,15
	};
	if (Find(matrix, 4, 4, 5))
	{
		cout << "find";
	}
	else
		cout << "not find";

	system("pause");

}