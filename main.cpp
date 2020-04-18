#include <iostream>
#include <iomanip>

using namespace std;

void algorithmOfThomas(double* diagonalUnderMainDiagonal, double* mainDiagonal, double* diagonalAboveMainDiagonal, double* vector, int unknows)
{

    unknows--;

    diagonalAboveMainDiagonal[0] /= mainDiagonal[0];
    vector[0] /= mainDiagonal[0];

    for (int i = 1; i < unknows; i++)
    {
        diagonalAboveMainDiagonal[i] /= mainDiagonal[i] - diagonalUnderMainDiagonal[i] * diagonalAboveMainDiagonal[i - 1];
        vector[i] = (vector[i] - diagonalUnderMainDiagonal[i] * vector[i - 1]) / (mainDiagonal[i] - diagonalUnderMainDiagonal[i] * diagonalAboveMainDiagonal[i - 1]);
    }

    vector[unknows] = (vector[unknows] - diagonalUnderMainDiagonal[unknows] * vector[unknows - 1]) / (mainDiagonal[unknows] - diagonalUnderMainDiagonal[unknows] * diagonalAboveMainDiagonal[unknows - 1]);

    for (int i = unknows; i >= 0; i--)
    {
        vector[i] -= diagonalAboveMainDiagonal[i] * vector[i + 1];
    }

}

int main()
{
    int  unknows= 7;

    double diagonalUnderMainDiagonal[unknows] = {1, 1, 1, 1, 1, 1, 1 };
    double mainDiagonal[unknows] = {4, 4, 4, 4, 4, 4, 4 };
    double diagonalAboveMainDiagonal[unknows] = {1, 1, 1, 1, 1, 1, 1};

    double vector[unknows] = {1, 2, 3, 4, 5, 6, 7  };


    algorithmOfThomas(diagonalUnderMainDiagonal, mainDiagonal, diagonalAboveMainDiagonal, vector, unknows);

    cout<<"Result:  "<<endl;

    for (int i = 0; i < unknows; i++)
    {
        cout << setprecision(5) << "x" << i+1 << " = " << vector[i] << endl;
    }

    return 0;
}