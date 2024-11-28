#ifndef SE_LAB2_H
#define SE_LAB2_H

#include <string> // For std::string
#include <fstream> // For file I/O
#include <cmath>   // For mathematical functions
#include <stdexcept> // For exceptions

void getInputFromUser(double &a, double &b, double &step, int &n, bool fromFile = false);
void getInputRangeFromFile(double &a, double &b, double &step, int &n);
void calculateAndDisplayResults(double a, double b, double step, int n, bool saveToFile = false);
void saveResultToFile(double a, double b, double step, int n);
bool isStepValid(double step);
double calculateFormulaForXLessThanZero(int n);
double calculateFormulaForXGreaterThanOrEqualToZero(double x, int n);
void displayDivider();
void displayErrorMessage(const std::string &message);
bool askToContinue();
char getValidYNInput(const std::string &promptMessage);
bool isRealNumber(double &value);
bool isNonNegativeInteger(int &value);
bool isValidRange(double a, double b);
bool editFileFromConsole();
void resetInputFileOnExit();
void validateStep(double &step);
void createDefaultInputFile();
void displayFileInstructions();

#endif // SE_LAB2_H
