#include <iostream>
#include <time.h>
using namespace std;
inline double valueAtPoint(double point)
{
	return 1 / point;
}

inline double valueAtPoint(double point, double point2)
{
	return (pow(point, 2) + 3*point2 -7);
}
double f2(double x, double y) { return x * x + 3 * y - 7; }

double metodaMonteCarloXY(double xp, double xk, double yp, double yk, int n)
{
	double pole = 0;
	for (int i = 0; i < n; i++)
	{
		double r = (double)rand() / RAND_MAX;
		pole += f2(xp + r * (xk - xp), yp + r * (yk - yp)) / n;
	}

	pole = pole * fabs(xk - xp) * fabs(yp - yk);
	return pole;
}
double countingIntegralsUsingTrapezeMethod(int startingPoint, int endingPoint, int numberOfPoints);
double countingIntegralsUsingMonteCarloMethod(int startingPoint, int endingPoint, int numberofPoints);
double countingIntegralsUsingTrapezeMethod(int startingPointOfX, int endingPointOfX, int startingPointOfY, int endingPointOfY, int numberOfPoints);
double countingIntegralsUsingMonteCarloMethod(int startingPoint, int endingPoint, int startingPointOfY, int endingPointOfY, int numberOfPoints);

int main()
{
	srand(time(NULL));
	cout << "1000 el: \t" << metodaMonteCarloXY(-3, 5, 2, 6, 1000) << endl;
	cout << "5000 el: \t" << metodaMonteCarloXY(-3, 5, 2, 6, 10000) << endl;
	cout << "10000 el: \t" << metodaMonteCarloXY(-3, 5, 2, 6, 1000000) << endl;
	cout << endl;
	cout << countingIntegralsUsingTrapezeMethod(-1, 2, 1000) << endl;
	cout << countingIntegralsUsingMonteCarloMethod(-1, 2, 1000000) << endl;
	cout << countingIntegralsUsingTrapezeMethod(-3, 5, 2, 6, 1000) << endl;
	cout << countingIntegralsUsingMonteCarloMethod(-3, 5, 2, 6, 100000) << endl;
	system("PAUSE");
}

double countingIntegralsUsingTrapezeMethod(int startingPoint, int endingPoint, int numberOfPoints)
{
	double integralValue = (valueAtPoint(startingPoint) + valueAtPoint(endingPoint)) / 2;
	double altitude = double(endingPoint - startingPoint) / numberOfPoints;
	double currentPoint = startingPoint + altitude;

	for (int i = 0; i < numberOfPoints - 1; i++)
	{
		integralValue += valueAtPoint(currentPoint);
		currentPoint += altitude;
	}

	integralValue *= altitude;

	return integralValue;
}

double countingIntegralsUsingTrapezeMethod(int startingPointOfX, int endingPointOfX, int startingPointOfY, int endingPointOfY, int numberOfPoints)
{
	double integralValue = 0.0;
	double dx = ((double)endingPointOfX - (double)startingPointOfX) / numberOfPoints;
	double dy = ((double)endingPointOfY - (double)startingPointOfY) / numberOfPoints;
	double area = dx * dy;

	for (int i = 0; i < numberOfPoints; i++)
	{
		for (int j = 0; j < numberOfPoints; j++)
		{
			integralValue += valueAtPoint((startingPointOfX + dx * i), (startingPointOfY + dy * j)) * area;
		}
	}

	return integralValue;
}

double countingIntegralsUsingMonteCarloMethod(int startingPoint, int endingPoint, int numberOfPoints)
{
	double averageFunctionValue = 0.0;
	for (int i = 0; i < numberOfPoints; i++)
		averageFunctionValue += valueAtPoint((double)startingPoint + (double)rand() / (double)(RAND_MAX) * ((double)endingPoint - (double)startingPoint));

	averageFunctionValue *= (double)endingPoint - (double)startingPoint;
	averageFunctionValue /= numberOfPoints;

	return averageFunctionValue;
}

double countingIntegralsUsingMonteCarloMethod(int startingPointOfX, int endingPointOfX, int startingPointOfY, int endingPointOfY, int numberOfPoints)
{
	double averageFunctionValue = 0.0;
	for (int i = 0; i < numberOfPoints; i++)
		averageFunctionValue += valueAtPoint((double)startingPointOfX + (double)rand() / (double)(RAND_MAX) * ((double)endingPointOfX - (double)startingPointOfX),
		(double)startingPointOfY + (double)rand() / (double)(RAND_MAX) * ((double)endingPointOfY - (double)startingPointOfY));

	averageFunctionValue *= (double)endingPointOfX - (double)startingPointOfX;
	averageFunctionValue *= (double)endingPointOfY - (double)startingPointOfY;
	averageFunctionValue /= numberOfPoints;

	return averageFunctionValue;
}