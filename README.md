# Cache System Performance Analysis

This project analyzes **cache performance** for various **memory-intensive kernels** (scatter, gather, and convolution) using **Intel PIN tool** for trace generation and a **Python-based cache simulator** for performance evaluation. The objective is to study the impact of **cache hierarchy depth, associativity, and block size** on system performance.

## Features

- **Implements three key memory-intensive operations**:
  - **Scatter Operation**: Distributes data across a 2D matrix using generated indices.
  - **Gather Operation**: Collects data from specified indices within a 2D matrix.
  - **Convolution Operation**: Applies a kernel over a matrix with different configurations.
- **Cache Simulation**:
  - Evaluates cache behavior under different architectures.
  - Simulates **L1, L2, and L3 cache** levels.
  - Configurable **block sizes, associativity, and cache depth**.
- **Performance Analysis**:
  - Computes **AMAT (Average Memory Access Time)**, **hit/miss rates**, and **execution cycles**.
  - Visualizes trends using **graphs and reports**.

## Project Structure

```
Cache-System-Performance-Analysis/
│── Kernel_Files/                  # C++ kernel implementations
│   ├── convolution.cpp             # Convolution operation
│   ├── gather.cpp                  # Gather operation
│   ├── scatter.cpp                 # Scatter operation
│── Records/                        # Simulation results, logs, and graphs
│   ├── Convolution.txt             # Raw results for convolution operation
│   ├── Gather.txt                  # Raw results for gather operation
│   ├── Scatter.txt                 # Raw results for scatter operation
│   ├── Data with Graphs.xlsx       # Graphs and processed data
│   ├── Report.pdf                  # Final report detailing analysis
│── SH_Commands/                    # Shell scripts for automation
│── .gitignore                      # Files to exclude from version control
│── Convolution.txt                 # Summary of convolution results
│── Data.xlsx                        # Collected data from simulations
│── Data_v2.xlsx                     # Updated dataset with additional simulations
│── Gather.txt                       # Summary of gather results
│── README.md                        # Project documentation
│── Report.docx                      # Detailed report (editable version)
│── Scatter.xlsx                      # Data specific to scatter operation
```

## Installation & Setup

1. **Clone the repository**:

   ```bash
   git clone https://github.com/aakash-wagle/Cache-System-Performance-Analysis.git
   cd Cache-System-Performance-Analysis
   ```

2. **Set up the environment**:

   - Ensure you have a **C++ compiler (g++)** and **Python** installed.
   - Install necessary Python dependencies:

     ```bash
     pip install -r requirements.txt
     ```

## Running the Experiments

### 1️⃣ Compile the C++ Kernel Code

Navigate to the `Kernel_Files` directory and compile the source files:

```bash
cd Kernel_Files
g++ -o scatter scatter.cpp
g++ -o gather gather.cpp
g++ -o convolution convolution.cpp
```

### 2️⃣ Run Simulations

Execute the **scatter, gather, and convolution** simulations:

```bash
./scatter
./gather
./convolution
```

Alternatively, you can use the provided **shell script** in `SH_Commands` to **automate the process**:

```bash
cd SH_Commands
./run_simulations.sh
```

### 3️⃣ Analyze Results

Once the simulations are completed, process the data:

```bash
./process_data.sh
```

Then, use the **Python analysis script** to generate **visualizations**:

```bash
cd Kernel_Files
python analyze_results.py
```

## Observations & Insights

Key findings from the cache performance analysis:

- **Scatter Operation**:
  - Increasing cache blocks and associativity **reduces AMAT** and **improves hit rates**.
  - Larger matrices (e.g., **150x150**) exhibit **higher AMAT and miss rates** due to increased data volume.

- **Gather Operation**:
  - Shows **anomalous behavior** where **higher associativity leads to increased AMAT**.
  - Larger matrices amplify this effect, suggesting inefficiencies in cache utilization.

- **Convolution Operation**:
  - **More predictable behavior** with **better cache optimizations** improving performance.
  - **Structured memory access** contributes to **higher hit rates**.

## Documentation

For a **detailed analysis**, refer to the **[Project Report](./Report.pdf)**, which contains:

- **Cache block diagrams**.
- **Graphs for hit/miss rates, AMAT trends, and execution times**.
- **Observations on cache parameter effects**.
