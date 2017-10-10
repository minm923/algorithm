#include <iostream>

int isFound(const int* const matrix, const int rows, const int columns, const int value)
{
    int flg = 0;

    if (matrix != NULL && rows>0 && columns>0)
    {
        int row    = 0;                    
        int column = columns - 1;
        int num = 0;

        while (row >=0 && columns >=0)
        {
            num = *(matrix + row*rows + column);
            if (num == value)
            {
                flg = 1;
                break;
            }
            else if (num > value)
            {
                --column;
            }
            else
            {
                ++row;
            }

        }
    }

    return flg;
}

int main(int argc, char* argv[])
{

    return 0;    
}
