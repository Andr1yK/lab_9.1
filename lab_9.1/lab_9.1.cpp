//#define _test_mode_

#include <iostream>
#include <iomanip>
#include <Windows.h>

#include "extendFunctions.hpp"
#include "Student.hpp"

using namespace std;

struct ScoresCount {
  int one = 0;
  int two = 0;
  int three = 0;
  int four = 0;
  int five = 0;
};

ScoresCount getCountsScore(Student*, const int);
int CountStudents(Student*, const int);

int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  string specialtyList[] = {
    "Матем. та економіка",
    "Трудове навчання",
    "Фізика та інформ.",
    "Інформатика",
    "Комп’ютерні науки"
  };

#ifndef _test_mode_
  int N;

  cout << "Введіть N: "; cin >> N;

  Student* students = new Student[N];

  Fill(students, N);
#endif // !_test_mode_

#ifdef _test_mode_
  cout << "\n\t\t\t\tTEST MODE!!!\tTEST MODE!!!\tTEST MODE!!!\n\n";

  const int N = 10;

  Student students[N] = {
    {"Moroz",     4, KN,  4, 4, 5},
    {"Tkachuk",   4, INF, 4, 3, 4},
    {"Petrenko",  4, ME,  5, 4, 2},
    {"Koval",     4, KN,  3, 3, 3},
    {"Tkachenko", 4, FI,  5, 5, 2},
    {"Rudenko",   4, INF, 3, 5, 5},
    {"Boyko",     4, FI,  2, 4, 4},
    {"Savchenko", 4, MF,  4, 3, 5},
    {"Lysenko",   4, INF, 4, 5, 3},
    {"Melnyk",    4, FI,  1, 3, 5},
  };

#endif // _test_mode_

  Print(students, N, specialtyList);

  ScoresCount scores = getCountsScore(students, N);

  cout << "Кількість 3 з фізики: " << scores.three << endl;
  cout << "Кількість 4 з фізики: " << scores.four  << endl;
  cout << "Кількість 5 з фізики: " << scores.five  << endl;

  cout << endl;

  cout << "Кількість студентів в яких оцінка з фізики та математики 4 або 5: "
    << CountStudents(students, N)
    << endl;

  return 0;
}

ScoresCount getCountsScore(Student* students, const int N)
{
  ScoresCount newCount{};

  for (int index = 0; index < N; index++) {
    switch (students[index].physics)
    {
    case (1):
      newCount.one++;
      break;

    case (2):
      newCount.two++;
      break;

    case (3):
      newCount.three++;
      break;

    case (4):
      newCount.four++;
      break;

    case (5):
      newCount.five++;
      break;
    }
  }

  return newCount;
}

int CountStudents(Student* students, const int N)
{
  int count = 0;

  for (int index = 0; index < N; index++) {
    int physicScore = students[index].physics;
    int mathScore = students[index].mathematics;

    bool physicCond = physicScore == 4 || physicScore == 5;
    bool mathCond = mathScore == 4 || mathScore == 5;

    count += mathCond && physicCond;
  }

  return count;
}
