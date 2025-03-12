# Cache System Performance Analysis

This project analyzes the performance of cache systems under various configurations and workloads, focusing on operations such as **scatter**, **gather**, and **convolution**. The analysis aims to understand how different cache parameters affect system performance metrics like **Average Memory Access Time (AMAT)**, **hit rates**, **miss rates**, and **total execution cycles**.

## Features

- **Implementation of Memory-Intensive Operations**:
  - **Scatter Operation**: Distributes data across a 2D matrix using generated indices.
  - **Gather Operation**: Collects data from specified indices within a 2D matrix.
  - **Convolution Operation**: Applies a kernel over a matrix with different configurations.

- **Cache Simulation**:
  - Evaluates cache behavior under different architectures.
  - Simulates **L1, L2, and L3 cache** levels.
  - Configurable **block sizes**, **associativity**, and **cache depth**.

- **Performance Analysis**:
  - Computes **AMAT**, **hit/miss rates**, and **execution cycles**.
  - Visualizes trends using **graphs and reports**.

## Project Structure

```
Cache-System-Performance-Analysis/
│── Assignment1_Aakash/            # Contains source code and scripts
│   ├── scatter.cpp                # Scatter operation implementation
│   ├── gather.cpp                 # Gather operation implementation
│   ├── convolution.cpp            # Convolution operation implementation
│   ├── cache_simulator.py         # Python script for cache simulation
│   └── analyze_results.py         # Script to analyze simulation results
│── SH_Commands/                   # Shell scripts for automation
│   ├── run_simulations.sh         # Executes simulations with various configurations
│   └── process_data.sh            # Processes simulation output data
│── .gitignore                     # Specifies files to ignore in version control
│── Convolution.txt                # Detailed analysis of convolution operation
│── Data.xlsx                      # Collected data from simulations
│── Data_v2.xlsx                   # Updated dataset with additional simulations
│── Gather.txt                     # Detailed analysis of gather operation
│── Report.docx                    # Comprehensive report of the analysis
│── Scatter.xlsx                   # Data specific to scatter operation
```

## Installation & Setup

1. **Clone the repository**:

   ```bash
   git clone https://github.com/aakash-wagle/Cache-System-Performance-Analysis.git
   cd Cache-System-Performance-Analysis
   ```

2. **Set up the environment**:

   - Ensure you have a C++ compiler (e.g., `g++`) and Python installed.
   - Install necessary Python packages:

     ```bash
     pip install -r requirements.txt
     ```

## Usage

1. **Compile the C++ source code**:

   Navigate to the `Assignment1_Aakash` directory and compile the source files:

   ```bash
   cd Assignment1_Aakash
   g++ -o scatter scatter.cpp
   g++ -o gather gather.cpp
   g++ -o convolution convolution.cpp
   ```

2. **Run simulations**:

   Use the provided shell script to execute simulations with various cache configurations:

   ```bash
   cd ../SH_Commands
   ./run_simulations.sh
   ```

   This script will run the compiled binaries and simulate cache behavior based on predefined configurations.

3. **Analyze results**:

   After simulations, process the data to extract insights:

   ```bash
   ./process_data.sh
   ```

   Then, use the Python analysis script to generate visualizations:

   ```bash
   cd ../Assignment1_Aakash
   python analyze_results.py
   ```

## Observations & Insights

The analysis revealed the following:

- **Scatter Operation**:
  - Increasing the number of cache blocks and associativity generally decreases AMAT and total cycles.
  - Larger matrices (e.g., 150x150) exhibit slightly higher AMAT and miss rates due to increased data volume.

- **Gather Operation**:
  - Anomalies observed where higher associativity leads to increased AMAT and miss rates.
  - Larger matrices amplify this effect, suggesting inefficiencies in cache usage for gather operations.

- **Convolution Operation**:
  - More predictable behavior with improvements in cache parameters leading to better performance metrics.
  - Structured memory access patterns contribute to smoother improvements in hit rates.

## Documentation

For a detailed analysis, refer to the [Project Report](./Report.docx), which includes:

- Cache block diagrams.
- Graphs for hit/miss rates, AMAT trends, and execution times.
- Observations on how cache parameters affect different operations.
