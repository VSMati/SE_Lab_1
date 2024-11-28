# Software Engineering Lab Project

## Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Example Output](#example-output)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

---

## Project Overview
This project was developed as part of the "Beginning of Software Engineering" course at NTU "KhPI." The project focuses on creating a command-line application for calculating mathematical expressions based on user inputs, with options to display intermediate results and optionally save the output.

The project follows a structured Software Requirements Specification (SRS) approach, ensuring clarity and maintainability.

---

## Features
- **Input Options**:
  - Accepts inputs manually through the keyboard or from a file.
- **Calculations**:
  - Processes a range of values and performs calculations using specified formulas.
  - Displays intermediate results step-by-step.
- **Result Saving (Optional)**:
  - Users can save results to a file in a structured format.

---

## Requirements
- **Operating System**: Windows, Linux, or macOS.
- **Dependencies**: C++ compiler (e.g., GCC or Visual Studio).
- **Hardware**: Standard PC with at least 4GB RAM.

---

## Installation
1. Clone the repository:
   `git clone https://github.com/VSMati/SE_Lab_1.git`

   Navigate to the project folder:
   `cd SE_Lab_1`

3. Compile the code:
   If using GCC:
   `g++ -o lab_project main.cpp`

4. Prepare input files (optional):
   - Create an `input.txt` file in the project directory and add input data in the expected format.

---

## Usage
1. Run the program:
   `./SE_Lab_1`

2. Input options:
   - Enter input manually when prompted by the program.
   - Or, ensure an `input.txt` file exists, and the program will automatically read from it.

3. Output:
   - Results will display step-by-step in the console.
   - Optionally, save the results to a file (`output.txt`).

---

## Example Output
**Inputs:**
- `Range`: `a = 0, b = 3`
- `Step Size`: `0.5`
- `n`: `3`

**Console Output:**

<img width="427" alt="SCR-20241106-mdor" src="https://github.com/user-attachments/assets/8c772559-4ded-4488-8be0-4074b0e53a70">


---

## Testing
- **Unit Testing**:
  Validates individual functions for correctness.
- **Integration Testing**:
  Ensures smooth interaction between input, calculation, and output modules.
- **System Testing**:
  Confirms the program operates as intended with typical and edge-case inputs.

---

## Contributing
1. Fork the repository:
   Click on "Fork" at the top right of the repository page.

2. Create a branch:
   `git checkout -b feature-name`

3. Make changes and commit:
   `git commit -m "Add feature or fix bug"`

4. Push changes:
   `git push origin feature-name`

5. Create a Pull Request:
   Open a pull request to merge your changes into the `main` branch.

---

## License
This project is licensed under the [MIT License](LICENSE).

