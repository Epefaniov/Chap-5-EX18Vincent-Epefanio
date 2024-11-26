/*
  Assignment: Chapter 5 Excersise 18

  Programmer: Vincent Epefanio

  Date: 11/25/2024

  Assignment: Write a program that produces a bar chart showing the population growth of Prairieville, a small town in the Midwest, at 20-year intervals during the past 100 years. The program should read in the population figures (rounded to the nearest 1,000 people) for 1900, 1920, 1940, 1960, 1980, and 2000 from a file. For each year, it should display the date and a bar consisting of one asterisk for each 1,000 people. The data can be found in the People.txt file.

*/
  
  
  #include <iostream>
  #include <fstream>
  #include <string>
  #include <vector>

  using namespace std;

  int main() {
      // the input file
      ifstream inputFile("People.txt");

      if (!inputFile) {
          cout << "Error opening file!" << endl;
          return 1;
      }

      // years and corresponding population values
      vector<int> years = {1900, 1920, 1940, 1960, 1980, 2000};
      vector<int> populations;

      int population;

      // population data from the file
      while (inputFile >> population) {
          populations.push_back(population);
      }

      inputFile.close();

      if (populations.size() != years.size()) {
          cout << "Error: Number of population data does not match the number of years!" << endl;
          return 1;
      }

      // the bar chart
      cout << "Population Growth in Prairieville (1900-2000):\n";

      for (size_t i = 0; i < years.size(); ++i) {
          // the number of asterisks needed for the bar chart
          int numAsterisks = populations[i] / 1000;

          // the year and the corresponding number of asterisks
          cout << years[i] << ": ";
          for (int j = 0; j < numAsterisks; ++j) {
              cout << "*";
          }
          cout << " (" << populations[i] << " people)" << endl;
      }

      return 0;
  }

  
  