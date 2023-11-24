#include <stdio.h>

void inputMatrix(int matrix[][10], int rows, int cols)
{
    printf("Enter matrix elements row by row:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[][10], int rows, int cols)
{
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int matrix[][10], int result[][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

int isSymmetric(int matrix[][10], int rows, int cols)
{
    if (rows != cols)
    {
        return 0;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return 0;
            }
        }
    }

    return 1;
}
// Function to find the inverse of a matrix (not implemented here)

int main()
{
    int rows, cols;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0 || rows > 10 || cols > 10)
    {
        printf("Invalid matrix size. Please enter valid dimensions (1-10).\n");
        return 1;
    }

    int matrix[10][10], result[10][10];

    inputMatrix(matrix, rows, cols);

    printf("\n");
    printMatrix(matrix, rows, cols);

    transposeMatrix(matrix, result, rows, cols);
    printf("\nTranspose:\n");
    printMatrix(result, cols, rows);

    if (isSymmetric(matrix, rows, cols))
    {
        printf("\nThe matrix is symmetric.\n");
    }
    else
    {
        printf("\nThe matrix is not symmetric.\n");
    }

    return 0;
}
