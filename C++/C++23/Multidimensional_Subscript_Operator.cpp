class Matrix
{
    int data[3][3];

public:

    int& operator[](size_t row, size_t col)
    {
        return data[row][col];
    }
};

int main()
{
	matrix[1, 2];
	matrix.operator[](1, 2)
}
