#include <iostream>
#include <string>
using namespace std;

void printHeader(const string &headerText);
void clearConsole();
void pause();
void findMax();
void findMin();
void sortAscending();
void sortDescending();
void calculateTablePrice();
void calculateEmployeeBonus();
void chooseVacationDestination();
void showGradeLevel();

string headerName[8] = {"Find maximum value", "Find minimum value", "Sort ascending"
                        , "Sort descending", "Calculate table price", "Calculate employee bonus"
                        , "Choose vacation destination", "Show grade level "};
//67113160 [--<#>--]
int main()
{
    int choice;

    do
    {
        clearConsole();
        cout << "\n [Menu:]------------------------------------*\n";
        cout << "   |   1. Find maximum value               |\n";
        cout << "   |   2. Find minimum value               |\n";
        cout << "   |   3. Sort ascending (Min->Max)        |\n";
        cout << "   |   4. Sort descending (Max->Min)       |\n";
        cout << "   |   5. Calculate table price            |\n";
        cout << "   |   6. Calculate employee bonus         |\n";
        cout << "   |   7. Choose vacation destination      |\n";
        cout << "   |   8. Show grade level                 |\n";
        cout << "   |   0. Exit                             |\n";
        cout << "   *--------------------------------------*\n";
        cout << "   Enter your choice>>\n       -[#]>$  ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            clearConsole();
            printHeader(headerName[0]);
            findMax();
            pause();
            break;
        case 2:
            clearConsole();
            printHeader(headerName[1]);
            findMin();
            pause();
            break;
        case 3:
            clearConsole();
            printHeader(headerName[2]);
            sortAscending();
            pause();
            break;
        case 4:
            clearConsole();
            printHeader(headerName[3]);
            sortDescending();
            pause();
            break;
        case 5:
            clearConsole();
            printHeader(headerName[4]);
            calculateTablePrice();
            pause();
            break;
        case 6:
            clearConsole();
            printHeader(headerName[5]);
            calculateEmployeeBonus();
            pause();
            break;
        case 7:
            clearConsole();
            printHeader(headerName[6]);
            chooseVacationDestination();
            pause();
            break;
        case 8:
            clearConsole();
            printHeader(headerName[7]);
            showGradeLevel();
            pause();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!, please try again.(0-8)" << endl;
            pause();
        }
    } while (choice != 0);

    return 0;
}

void findMax()
{
    int x, y, z;
    cout << "Enter three numbers: ";
    cin >> x >> y >> z;

    int maxVal = (x > y && x > z) ? x : (y > z ? y : z);
    cout << "The maximum value is: " << maxVal << endl;
}

void findMin()
{
    int x, y, z;
    cout << "Enter three numbers: ";
    cin >> x >> y >> z;

    int minVal = (x < y && x < z) ? x : (y < z ? y : z);
    cout << "The minimum value is: " << minVal << endl;
}

void sortAscending()
{
    int number[3];
    cout << "Enter three numbers: ";
    cin >> number[0] >> number[1] >> number[2];

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (number[i] > number[j])
            {
                int temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }

    cout << "sortAscending: ";
    for (int k = 0; k < 3; k++)
    {
        cout << number[k] << " ";
    }
    cout << endl;
}

void sortDescending()
{
    int number[3];
    cout << "Enter three numbers: ";
    cin >> number[0] >> number[1] >> number[2];

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (number[i] < number[j])
            {
                int temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }

    cout << "sortDescending: ";
    for (int k = 0; k < 3; k++)
    {
        cout << number[k] << " ";
    }
    cout << endl;
}

void calculateTablePrice()
{
    string customerName, woodType;
    float length, width, price = 1500;

    cout << "Enter customer name: ";
    getline(cin, customerName);

    cout << "Enter table dimensions (length and width in inches): ";
    cin >> length >> width;

    cout << "\n*-| WOOD TYPE |------------*\n";
    cout << "|   1.)Mahogany\n|   2.)Oak\n|   3.)Normal\n*-------------------------*\nEnter wood type: ";
    cin >> woodType;

    if (woodType != "Mahogany" && woodType != "mahogany" && woodType != "MAHOGANY" && woodType != "Oak" && woodType != "oak" && woodType != "OAK" && woodType != "Normal" && woodType != "normal" && woodType != "NORMAL" && woodType != "1" && woodType != "2" && woodType != "3")
    {
        cout << "Invalid wood type. Please enter Mahogany, Oak, or Normal." << endl;
        return;
    }

    if (length * width > 750)
        price += 500;
    if (woodType == "Mahogany")
        price += 200;
    else if (woodType == "Oak")
        price += 125;

    cout << "Total price for " << customerName << ": " << price << " Baht" << endl;
}

void calculateEmployeeBonus()
{
    float salary, sales, bonus;

    cout << "Enter salary: ";
    cin >> salary;
    cout << "Enter total sales: ";
    cin >> sales;

    if (sales < 120000)
        bonus = salary * 0.05;
    else if (sales <= 240000)
        bonus = salary * 0.10;
    else if (sales <= 360000)
        bonus = salary * 0.20;
    else
        bonus = salary * 0.30;

    float totalIncome = salary + bonus;

    cout << "Total income: " << totalIncome << endl;
}

void chooseVacationDestination()
{
    float savings;
    int vacationDays;

    cout << "Enter your savings: ";
    cin >> savings;
    cout << "Enter number of vacation days: ";
    cin >> vacationDays;

    if (savings > 100001 && vacationDays > 7)
    {
        cout << "Go Japan" << endl;
    }
    else if (savings >= 10001 && savings <= 100000 && vacationDays >= 3 && vacationDays <= 6)
    {
        cout << "Go Hong Kong" << endl;
    }
    else if (savings >= 5000 && savings <= 10000 && vacationDays >= 1 && vacationDays <= 3)
    {
        cout << "Go Domestic" << endl;
    }
    else
    {
        cout << "Stay at home" << endl;
    }
}

void showGradeLevel()
{
    char grade;
    cout << "Enter your grade: ";
    cin >> grade;

    switch (grade)
    {
    case 'A':
    case 'a':
        cout << "Excellent" << endl;
        break;
    case 'B':
    case 'b':
        cout << "Good" << endl;
        break;
    case 'C':
    case 'c':
        cout << "O.K." << endl;
        break;
    case 'D':
    case 'd':
    case 'F':
    case 'f':
        cout << "Poor, student is on probation" << endl;
        break;
    default:
        cout << "Invalid letter grade" << endl;
    }
}

void printHeader(const string &headerText)
{
    int width = 40;
    int padding = (width - headerText.length()) / 2;

    cout << string(padding, '*');
    cout << " " << headerText << " ";
    cout << string(padding, '*');

    if ((width - headerText.length()) % 2 != 0)
    {
        cout << "*";
    }

    cout << endl;
}
void clearConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void pause()
{
    cout << "\n\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}