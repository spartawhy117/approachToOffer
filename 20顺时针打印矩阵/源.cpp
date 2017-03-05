#include <iostream>
#include <vector>
using namespace std;
void PrintCore(int** matrix, int cols, int rows,int start, vector<vector<bool>>& visted)
{

	//while����в�����Խ��

	//��������
	int row = start;
	int i = start;
	while (i <= cols - 1&&!visted[row][i])
	{
		cout << matrix[row][i] << " ";
		visted[row][i] = true;
		i++;
	}

	//���ϵ���

	int col = i - 1;
	i = row + 1;
	while (i<=rows-1&&!visted[i][col])
	{
		cout << matrix[i][col] << " ";
		visted[i][col] = true;
		i++;
	}

	//���ҵ���
	int row_end = i - 1;
	i = col - 1;
	while (i>=0&&!visted[row_end][i])
	{
		cout << matrix[row_end][i] << " ";
		visted[row_end][i] = true;
		i--;
	}

	//���µ���
	int col_end = i + 1;
	i = row_end -1;
	while(i>=0&&!visted[i][col_end])
	{
		cout << matrix[i][col_end] << " ";
		visted[i][col_end] = true;
		i--;
	}

	cout << endl;

}
void PrintMatrixClockwisely(int** matrix,const int cols,int rows)
{
	if(matrix==nullptr||cols==0||rows==0)
		return;

	int start = 0;
	//һ��Ҫ�пո񣬲�Ȼ�ᱨ�� row*col
	vector< vector<bool> > visted(rows,vector<bool>(cols,false));
	
	
	while (cols>start*2&&rows>start*2)
	{
		PrintCore(matrix, cols, rows, start, visted);
		++start;
	}


}

int main(int argc, char* argv[])
{
	const int cols = 3;
	const int rows = 5;
	int **matrix = new int*[rows];
	for(int i=0;i<rows;i++)
	{
		matrix[i] = new int[cols];
		for(int j=0;j<cols;j++)
		{
			matrix[i][j] = j + 1+i*cols;
		}

	}

	PrintMatrixClockwisely(matrix, cols, rows);
	system("pause");
}
