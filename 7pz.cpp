#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct nameSurnamePatronymic
{
    string name;
    string surname;
    string patronymic;
};

struct dateOfBirth
{
    int day;
    int month;
    int year;
};

struct Students
{
    nameSurnamePatronymic NSP;
    dateOfBirth birthday;
    int age;
    double averageMark;
    int group;
};

void inputInformation(Students *arrayOfStudents, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Введите данные " << i+1 << "-го студента" << endl;
        cout << "Введите имя, фамилию и отчество:" << endl;
        cout << "Фамилия: ";
        cin >> arrayOfStudents[i].NSP.surname;
        cout << "Имя: ";
        cin >> arrayOfStudents[i].NSP.name;
        cout << "Отчество: ";
        cin >> arrayOfStudents[i].NSP.patronymic;
        cout << "Дата рождения: " << endl;
        cout << "День: ";
        cin >> arrayOfStudents[i].birthday.day;
        cout << "Месяц: ";
        cin >> arrayOfStudents[i].birthday.month;
        cout << "Год: ";
        cin >> arrayOfStudents[i].birthday.year;
        cout << "Средний балл: ";
        cin >> arrayOfStudents[i].averageMark;
        cout << "Группа: ";
        cin >> arrayOfStudents[i].group;
    }
}

void countAndOutputAge(Students *arrayOfStudents, int i)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int monthDifference = arrayOfStudents[i].birthday.month - (1 + ltm->tm_mon);
    if (monthDifference <= 0)
    {
        arrayOfStudents[i].age = 1900 + ltm->tm_year - arrayOfStudents[i].birthday.year;
        cout << "Возраст: " << arrayOfStudents[i].age << " лет" << endl;
    }
    else
    {
        arrayOfStudents[i].age = 1900 + ltm->tm_year - arrayOfStudents[i].birthday.year - 1;
        cout << "Возраст: " << arrayOfStudents[i].age << " лет" << endl;
    }
}

void outputFullInformation(Students *arrayOfStudents, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << endl;
        cout << "Студент " << i+1 << ":" << endl;
        cout << "ФИО: " << arrayOfStudents[i].NSP.surname << " " << arrayOfStudents[i].NSP.name << " " << arrayOfStudents[i].NSP.patronymic << endl;
        cout << "Дата рождения: " << arrayOfStudents[i].birthday.day << "." << arrayOfStudents[i].birthday.month << "." << arrayOfStudents[i].birthday.year << endl;
        countAndOutputAge(arrayOfStudents, i);
        cout << "Средний балл: " << arrayOfStudents[i].averageMark << endl;
        cout << "Группа: " << arrayOfStudents[i].group << endl;
    }
    cout << endl;
}

void outputNSP(Students *arrayOfStudents, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Студент " << i+1 << ":" << endl;
        cout << "ФИО: " << arrayOfStudents[i].NSP.surname << " " << arrayOfStudents[i].NSP.name << " " << arrayOfStudents[i].NSP.patronymic << endl;
    }
}

void mostCommonName(Students *arrayOfStudents, int size)
{
    int maxcount = 1, n = -1;
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = i; j < size; j++)
        {
            if (arrayOfStudents[i].NSP.name == arrayOfStudents[j].NSP.name)
            {
                count++;
            }
            if (maxcount < count)
            {
                maxcount = count;
                n = i;
            }
        }
    }
    if (n > -1)
    {
        cout << "Наиболее часто встречающееся имя - " << arrayOfStudents[n].NSP.name << endl;
    }
    else
    {
        cout << "Все имена разные" << endl;
    }
}

void sortByAverageMark(Students *arrayOfStudents, int size)
{
    cout << endl;
    Students temp;
    for (int i = 1; i < size; i++)
    {
        for(int j = 0; j < size-i; j++)
        {
            if(arrayOfStudents[j].averageMark < arrayOfStudents[j+1].averageMark)
            {
                temp = arrayOfStudents[j];
                arrayOfStudents[j] = arrayOfStudents[j+1];
                arrayOfStudents[j+1] = temp;
            }
        }
    }
    cout << "Сортировка по среднему баллу:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "ФИО: " << arrayOfStudents[i].NSP.surname << " " << arrayOfStudents[i].NSP.name << " " << arrayOfStudents[i].NSP.patronymic << endl;
        cout << "Средний балл: " << arrayOfStudents[i].averageMark << endl;
    }
}

void averageAge(Students *arrayOfStudents, int size)
{
    cout << endl;
    double averageAge;
    int sumOfAges = 0;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    for (int i = 0; i < size; i++)
    {
        int monthDifference = arrayOfStudents[i].birthday.month - (1 + ltm->tm_mon);
        if (monthDifference <= 0)
        {
            arrayOfStudents[i].age = 1900 + ltm->tm_year - arrayOfStudents[i].birthday.year;
        }
        else
        {
            arrayOfStudents[i].age = 1900 + ltm->tm_year - arrayOfStudents[i].birthday.year - 1;
        }
        sumOfAges += arrayOfStudents[i].age;
    }
    averageAge = sumOfAges / (double)(size);
    cout << "Средний возраст студентов " << averageAge << " лет" <<endl;
}

int main()
{
    int size;
    cout << "Введите размер массива студентов: ";
    cin >> size;
    Students *arrayOfStudents = new Students[size];
    inputInformation(arrayOfStudents, size);
    cout << "Выберите вывод информации о студентах: 1 - только ФИО, любая другая клавиша - полная информация" << endl;
    getchar();
    if(getchar() == 1)
    {
        outputNSP(arrayOfStudents, size);
    }
    else
    {
        outputFullInformation(arrayOfStudents, size);
    }
    mostCommonName(arrayOfStudents, size);
    sortByAverageMark(arrayOfStudents, size);
    averageAge(arrayOfStudents, size);
    delete[] arrayOfStudents;
    return 0;
}