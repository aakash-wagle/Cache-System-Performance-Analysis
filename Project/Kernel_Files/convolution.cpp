#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

void parsec_roi_begin() 
{

}

void parsec_roi_end() 
{

}


struct Result {
	vector< vector<int> > A;
	vector< vector<int> > B;
};

// struct DataPoint {
// 	int i;
// 	int j;
// 	// int data;
// };

Result read(string filename) {
	vector< vector<int> > A, B;
	Result ab;
	string line;
	ifstream infile;
	infile.open (filename.c_str());

	int i = 0;
	while (getline(infile, line) && !line.empty()) {
		istringstream iss(line);
		A.resize(A.size() + 1);
		int a, j = 0;
		while (iss >> a) {
			A[i].push_back(a);
			j++;
		}
		i++;
	}

	// i = 0;
	// while (getline(infile, line)) {
	// 	istringstream iss(line);
	// 	B.resize(B.size() + 1);
	// 	int a;
	// 	int j = 0;
	// 	while (iss >> a) {
	// 		B[i].push_back(a);
	// 		j++;
	// 	}
	// 	i++;
	// }

	infile.close();
	ab.A = A;
	// ab.B = B;
	return ab;
}

// n = 3 || 5 || 7
vector<vector<int>> generateRandomKernel(int n){
	vector<vector<int>> kernel(n, std::vector<int>(n));

	srand((unsigned) time(NULL));

  for (int i = 0; i <= n / 2; ++i) {
    for (int j = 0; j <= n / 2; ++j) {
			// Generate a random value
      int value = rand() % 10;

      // Fill the corresponding symmetric positions
      kernel[i][j] = value;                 // Upper-left
      kernel[i][n - j - 1] = value;         // Upper-right
      kernel[n - i - 1][j] = value;         // Bottom-left
      kernel[n - i - 1][n - j - 1] = value; // Bottom-right
    }
  }

	return kernel;
}

vector<vector<int>> convolution_algo(vector<vector<int>> inputMatrix, vector< vector<int> > kernel) {
	vector<vector<int>> result(inputMatrix.size(), vector<int>(inputMatrix.size(), 0));
	int pad = kernel.size() / 2;

	for (int i = pad; i < inputMatrix.size() - pad; ++i) {
		for (int j = pad; j < inputMatrix.size() - pad; ++j) {
      int sum = 0;

      // Convolve kernel with the corresponding patch in the matrix
      for (int ki = 0; ki < kernel.size(); ++ki) {
        for (int kj = 0; kj < kernel.size(); ++kj) {
					int row = i + ki - pad;
					int col = j + kj - pad;
          sum += kernel[ki][kj] * inputMatrix[row][col];
        }
      }
      result[i][j] = sum;
    }
  }
	
	return result;
}

void printMatrix(vector< vector<int> > matrix) {
	vector< vector<int> >::iterator it;
	vector<int>::iterator inner;
	for (it=matrix.begin(); it != matrix.end(); it++) {
		for (inner = it->begin(); inner != it->end(); inner++) {
			cout << *inner;
			if(inner+1 != it->end()) {
				cout << "\t";
			}
		}
		cout << endl;
	}
}

int main (int argc, char* argv[]) {
	string filename;
	if (argc < 3) {
		filename = "2000.in";
	} else {
		filename = argv[2];
	}
	Result result = read (filename);
	int n = 3; // n = 3 || 5 || 7
	vector<vector<int>> kernel = generateRandomKernel(n);
    parsec_roi_begin();
	vector<vector<int>> C = convolution_algo(result.A, kernel);
    parsec_roi_end();
		cout<<"Program executed";
	//printMatrix(C);
	return 0;
}