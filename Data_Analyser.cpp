#include <iostream>
using namespace std;
#include <math.h>

class DataAnalyser
{
private:
	float sortedData[100], sum; // declaring members of class as private to reamin acessible within the class only
	bool sorted;

public:
	int dataCount = 0;

	void addData() // function to add to the dataset
	{
		int num;

		cout << "How many values do you want to add (Should be less than or equal to 100)" << endl;
		cin >> num;
		for (int i = 1; i <= num; i++)
		{
			cout << "Please enter data value : " << endl;
			cin >> sortedData[dataCount];
			dataCount++;
		}
	}

	void set(float sd[100], float s, bool st) // setter to intitialise all members
	{
		sortedData[100] = sd[100];
		sum = s;
		sorted = st;
	}

	float calcMode() // function to calculate mode
	{
		int tempCount, tempIndex, count = 0, index;

		for (tempIndex = 0; tempIndex < dataCount; tempIndex++)
		{
			for (int x = 0; x < dataCount; x++)
			{
				if (sortedData[tempIndex] == sortedData[x])
				{
					tempCount++;
				}
			}

			if (tempCount > count)
			{
				index = tempIndex;
				count = tempCount;
			}
		}

		return sortedData[index];
	}

	float calcMean() //function to calculate mean
	{
		float total;
		for (int i = 0; i <=dataCount-1; i++)
		{
			total += sortedData[i];
		}

		return (total / (dataCount-1));
	}

	float calcMedian() //function to calculate median
	{

		int index1, index2;
		float median;

		if (dataCount % 2 != 0)
		{
			index1 = dataCount / 2;
			index2 = (dataCount / 2) - 1;

			median = (sortedData[index1] + sortedData[index2]) / 2;
		}
		else
		{

			index1 = (dataCount / 2) + 1;
			median = sortedData[index1];
		}

		return median;
	}

	void sort() //sorting function for the array
	{
		float temp;
		if (!sorted)
		{
			for (int i = 0; i < 100; i++)
			{
				if (sortedData[i] > sortedData[i + 1])
				{
					temp = sortedData[i];
					sortedData[i] = sortedData[i + 1];
					sortedData[i + 1] = temp;
				}
			}
		}

		sorted = true;
	}

	float calcSD() //function to calculate standard deviation
	{
		float total;
		float mean;

		mean = calcMean();

		for (int i = 0; i <= dataCount; i++)
		{
			total += ((sortedData[dataCount]) - mean) * ((sortedData[dataCount]) - mean);
		}

		return sqrt((total / dataCount));
	}

	float calcVar() //function to calculate variance
	{
		float total;
		float mean;

		mean = calcMean();

		for (int i = 0; i <= dataCount; i++)
		{
			total += ((sortedData[dataCount]) - mean) * ((sortedData[dataCount]) - mean);
		}

		return (total / (dataCount - 1));
	}

	float calcQ1() //function to calculate quarter 1
	{
		return sortedData[int(((dataCount-1) * 0.25) + 1)];
	}

	float calcQ2() //function to calculate quarter 2
	{
		return calcMedian();
	}

	float calcQ3() //function to calculate quarter 3
	{
		return sortedData[int(((dataCount-1) * 0.75) + 1)];
	}

	float calcCC(float data2[]) //function to calculate correlation coefficient
	{

		float cc;
		float xy, x, y, yS, xS;

		for (int i = 0; i <= dataCount; i++)
		{
			x += sortedData[i];
			y += data2[i];
			xy += (sortedData[i] * data2[i]);
			xS += (sortedData[i] * sortedData[i]);
			yS += (data2[i] * data2[i]);
		}

		cc = (((dataCount * xy) - (x * y)) / sqrt(((dataCount * xS) - (x * x)) * ((dataCount * yS) - (y * y))));

		return cc;
	}
};

int main()
{
	DataAnalyser data1; //declaring object for the class

	int choice;

	while (true) //loop to terminate if the user selects 12
	{
		cout << "---------------------------------------------------------------------" << endl;
		cout << " WELCOME TO THE BEST DATA ANALYSING SOFTWARE ON THE MARKET ;)" << endl;
		cout << "---------------------------------------------------------------------" << endl;
		cout << endl << "Menu:" << endl;
		cout << "\n1. Add Data" << endl;
		cout << "2. Calculate Mean" << endl;
		cout << "3. Calculate Median" << endl;
		cout << "4. Calculate Mode" << endl;
		cout << "5. Sort Data" << endl;
		cout << "6. Calculate Standard Deviation" << endl;
		cout << "7. Calculate Variance" << endl;
		cout << "8. Calculate Q1" << endl;
		cout << "9. Calculate Q2" << endl;
		cout << "10. Calculate Q3" << endl;
		cout << "11. Calculate Coefficient of Correlation" << endl;
		cout << "12. Exit" << endl;
		cout << "Please select an option : ";

		cin >> choice;
		float dataset2[data1.dataCount];

		switch (choice) //calling methods based on user input
		{
		case 1:
			data1.addData();
			break;
		case 2:
			cout << data1.calcMean() << endl;
			break;
		case 3:
			cout << data1.calcMedian() << endl;
			break;
		case 4:
			cout << data1.calcMode() << endl;
			break;
		case 5:
			data1.sort();
			break;
		case 6:
			cout << data1.calcSD() << endl;
			break;
		case 7:
			cout << data1.calcVar() << endl;
			break;
		case 8:
			cout << data1.calcQ1() << endl;
			break;
		case 9:
			cout << data1.calcQ2() << endl;
			break;
		case 10:
			cout << data1.calcQ3() << endl;
			break;
		case 11:
			for (int i = 0; i <= data1.dataCount; i++) //taking second dataset to calculate coefficient
			{
				cout << "Please enter a value to add to the dataset : ";
				cin >> dataset2[i];
			}

			cout << data1.calcCC(dataset2) << endl;
			break;
		case 12:
			exit(0);
		default:
			cout << "Invalid choice" << endl;
		}
	}

	return 0;
}