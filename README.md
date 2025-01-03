# A* for Optimal Pathfinding

## Overview
This repository implements the A* (A-Star) algorithm for optimal pathfinding on a grid. The algorithm leverages heuristic-based search to find the shortest path between a start and end point.

## Features
- Efficient pathfinding using A*.
- Heuristics to guide the search.
- Customizable grid sizes and configurations.
- Visualized output of the computed path.

## Prerequisites
- Ensure you have `g++` installed (part of GCC).
- A code editor such as Visual Studio Code (VSCode) is recommended for development.

## Compilation Instructions
1. Open a terminal.
2. Navigate to the `A_star` folder:
    ```sh
    cd A_star
    ```
3. Compile the program using the following command:
    ```sh
    g++ grid.cpp node.cpp algo.cpp -o main.exe
    ```

## Running the Program
### Option 1: Run Directly from the Terminal
Execute the compiled program:
```sh
./main.exe
```
You can optionally provide start and end indices as command-line arguments:
```sh
./main.exe <start_index> <end_index>
```
Example:
```sh
./main.exe 0 8
```

### Option 2: Using Visual Studio Code
1. Open the `A_star` folder in VSCode.
2. Press `Ctrl+Shift+B` to open the Command Palette.
3. Select the `Build` option to compile the code.
4. Debug or run the program using the integrated terminal or debugger.

## Notes
- I have added gvalues and hvalues statically,however hvals and gvals can be generated dynamically.
- The grid and heuristic values can be customized in the `Grid` class.
- Ensure proper input values are provided to avoid runtime errors.
- To modify the pathfinding logic, refer to the `algo.cpp` file.

## Contributions
Contributions to improve the algorithm or enhance features are welcome. Please fork the repository and submit a pull request with your changes.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

