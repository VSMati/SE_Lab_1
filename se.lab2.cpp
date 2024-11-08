#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>
#include <cctype>
#include <stdexcept>
//prototypes of functions
void getInputFromUser(double &a, double &b, double &step, int &n, bool fromFile = false);
void getInputRangeFromFile(double &a, double &b, double &step, int &n);
void calculateAndDisplayResults(double a, double b, double step, int n, bool saveToFile = false);
void saveResultToFile(double a, double b, double step, int n);
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

int main() {
    double a, b, step;
    int n;
    char inputChoice;
    bool continueProgram = true;

    while (continueProgram) {
        std::cout << "Welcome to the formula solver application!" << std::endl;
        displayDivider();

        inputChoice = getValidYNInput("Do you want to input values from a file? (y/n): ");

        if (inputChoice == 'y') {
            createDefaultInputFile();
            displayFileInstructions();

            char editChoice = getValidYNInput("Do you want to edit the 'input.txt' file before reading? (y/n): ");
            if (editChoice == 'y') {
                editFileFromConsole();  // Prompt to manually edit the file
            }
            getInputFromUser(a, b, step, n, true);  // Read from the file after decision
        } else {
            getInputFromUser(a, b, step, n);  // Manual input from the console
        }

        displayDivider();
        bool saveToFile = getValidYNInput("Do you want to save the results to 'result.txt'? (y/n): ") == 'y';
        calculateAndDisplayResults(a, b, step, n, saveToFile);

        continueProgram = askToContinue();
    }

    resetInputFileOnExit();
    std::cout << "That's all for today...\nThank you very much.\nGoodbye! :)" << std::endl;
    return 0;
}

void getInputFromUser(double &a, double &b, double &step, int &n, bool fromFile) {
    if (fromFile) {
        getInputRangeFromFile(a, b, step, n);
    } else {
        bool validInput = false;

        do {
            std::cout << "Please enter the start of the range (a): ";
            while (!(std::cin >> a)) {
                displayErrorMessage("Invalid input for 'a'. Please enter a real number.");
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter the start of the range (a): ";
            }

            std::cout << "Please enter the end of the range (b): ";
            while (!(std::cin >> b)) {
                displayErrorMessage("Invalid input for 'b'. Please enter a real number.");
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter the end of the range (b): ";
            }

            if (!isValidRange(a, b)) {
                displayErrorMessage("'b' must be greater than 'a'. Try again.");
            } else {
                validInput = true;
            }
        } while (!validInput);

        validateStep(step);

        bool validN = false;
        double tempN;
        while (!validN) {
            std::cout << "Please enter a positive integer for n (n > 0): ";  // Updated prompt
            if (std::cin >> tempN && tempN == floor(tempN) && tempN > 0) {  // Ensure n > 0
                n = static_cast<int>(tempN);
                validN = true;
            } else {
                displayErrorMessage("Invalid input! n must be a positive integer (greater than 0).");
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
}

void validateStep(double &step) {
    bool validStep = false;
    while (!validStep) {
        std::cout << "Please enter a positive step size: ";
        if (std::cin >> step && step > 0) {
            validStep = true;
        } else {
            displayErrorMessage("Step size must be a positive real number.");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void getInputRangeFromFile(double &a, double &b, double &step, int &n) {
    std::ifstream inputFile("input.txt");

    if (!inputFile) {
        displayErrorMessage("Error: File not found. Default values will be used.");
        a = 0.0;
        b = 1.0;
        step = 0.5;
        n = 3;
        calculateAndDisplayResults(a, b, step, n, false);
        getInputFromUser(a, b, step, n, false);
        return;
    }

    inputFile >> a >> b >> step >> n;

    if (inputFile.fail()) {
        displayErrorMessage("Error: Non-numeric data found in the file. Default values will be used.");
        a = 0.0;
        b = 1.0;
        step = 0.5;
        n = 3;
        calculateAndDisplayResults(a, b, step, n, false);
        getInputFromUser(a, b, step, n, false);
        inputFile.close();
        return;
    }

    bool hasError = false;
    if (a >= b) {
        displayErrorMessage("Error: Invalid range! 'a' must be less than 'b'.");
        hasError = true;
    }
    if (step <= 0) {
        displayErrorMessage("Error: Step size must be a positive number.");
        hasError = true;
    }
    if (n <= 0) {  // Ensure n > 0
        displayErrorMessage("Error: 'n' must be a positive integer (greater than 0).");
        hasError = true;
    }

    if (hasError) {
        displayErrorMessage("Using default values: a = 0.0, b = 1.0, step = 0.5, n = 3.");
        a = 0.0;
        b = 1.0;
        step = 0.5;
        n = 3;
        calculateAndDisplayResults(a, b, step, n, false);
        getInputFromUser(a, b, step, n, false);
    } else {
        std::cout << "Values read from file:\n";
        std::cout << "Range: a = " << a << ", b = " << b << "\n";
        std::cout << "Step size: " << step << "\n";
        std::cout << "n = " << n << "\n";
    }

    inputFile.close();
}

void calculateAndDisplayResults(double a, double b, double step, int n, bool saveToFile) {
    double x = a;
    std::ofstream outputFile;

    if (saveToFile) {
        outputFile.open("result.txt", std::ios::app);
        if (!outputFile) {
            displayErrorMessage("Error: Unable to open 'result.txt' for writing.");
            return;
        }
        outputFile << "Calculations for range [" << a << ", " << b << "] with step size = " << step << " and n = " << n << ":\n";
    }

    while (x <= b) {
        double result;
        if (x < 0) {
            result = calculateFormulaForXLessThanZero(n);
        } else {
            result = calculateFormulaForXGreaterThanOrEqualToZero(x, n);
        }

        std::cout << "x = " << x << ", result = " << result << "\n";

        if (saveToFile) {
            outputFile << "x = " << x << ", result = " << result << "\n";
        }

        x += step;
    }

    if (saveToFile) {
        outputFile << "----------------------------------------\n";
        outputFile.close();
        std::cout << "Results saved to 'result.txt'\n";
    }
}

double calculateFormulaForXLessThanZero(int n) {
    double sum = 0.0;
    for (int i = 0; i <= n; ++i) {
        double product = 1.0;
        for (int j = 0; j <= n + 1; ++j) {
            product *= (static_cast<double>(i) - static_cast<double>(j)) / 2.0;
        }
        sum += product;
    }
    return sum;
}

double calculateFormulaForXGreaterThanOrEqualToZero(double x, int n) {
    double product = 1.0;

    for (int j = 1; j <= n; ++j) {
        if ((x + 3.0 * j) == 0) {
            displayErrorMessage("Division by zero encountered. Adjust the step or range.");
            return 0;
        }
        product *= static_cast<double>(j) / (x + 3.0 * j);
    }

    return x + product;
}

void createDefaultInputFile() {
    std::ofstream inputFile("input.txt");
    if (inputFile) {
        inputFile << "0.0\n1.0\n0.5\n3\n";
        inputFile.close();
        std::cout << "A default 'input.txt' file has been created.\n";
    } else {
        displayErrorMessage("Error: Unable to create the 'input.txt' file.");
    }
}

void displayFileInstructions() {
    std::cout << "\nInstructions for editing 'input.txt':\n";
    std::cout << "1. The first line should contain the start of the range (a).\n";
    std::cout << "2. The second line should contain the end of the range (b).\n";
    std::cout << "3. The third line should contain the step size (positive number).\n";
    std::cout << "4. The fourth line should contain a non-negative integer (n).\n";
    std::cout << "Example:\n";
    std::cout << "0.0\n1.0\n0.5\n3\n";
    displayDivider();
}

void displayErrorMessage(const std::string &message) {
    std::cerr << message << std::endl;
    displayDivider();
}

bool isValidRange(double a, double b) {
    return a < b;
}

bool isNonNegativeInteger(int &value) {
    return value >= 0;
}

void displayDivider() {
    std::cout << "----------------------------------------\n";
}

bool askToContinue() {
    char choice = getValidYNInput("Do you want to perform another calculation? (y/n): ");
    return choice == 'y';
}

char getValidYNInput(const std::string &promptMessage) {
    char input;
    bool validInput = false;
    do {
        std::cout << promptMessage;
        std::cin >> input;

        input = std::tolower(input);

        if (input == 'y' || input == 'n') {
            validInput = true;
        } else {
            displayErrorMessage("Invalid input! Please enter 'y' or 'n'.");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!validInput);

    return input;
}

bool editFileFromConsole() {
    std::cout << "Please edit the 'input.txt' file manually in your text editor.\n";
    std::cout << "Press Enter when done editing.";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return true;
}

void resetInputFileOnExit() {
    std::ofstream inputFile("input.txt");
    
    if (inputFile) {
        inputFile << "0.0\n1.0\n0.5\n3\n";
        std::cout << "The 'input.txt' file has been reset to its default values.\n";
        inputFile.close();
    } else {
        displayErrorMessage("Error: Unable to reset the input file.");
    }
}
