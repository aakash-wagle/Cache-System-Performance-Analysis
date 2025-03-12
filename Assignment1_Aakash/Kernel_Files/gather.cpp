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

struct DataPoint {
	int i;
	int j;
	// int data;
};

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

// n = 128 or n = 150
vector<DataPoint> generateRandomDataPoints(int n){
	vector<DataPoint> vec;
	
	// int random = offset + (rand() % range);
	srand((unsigned) time(NULL));
	// int numElements = numRows*numCols;

	for(int x=0; x<1000; x++){
		// Offset = 0
		// Range = number of columns
		int i = (rand() % n);
		int j = (rand() % n);
		// int data = rand();
		vec.push_back({i,j});
	}

	return vec;
}

vector<int> gather_algorithm(vector< vector<int> > inputMatrix, vector< DataPoint > dataPoints) {
	vector<int> vec;
	
	// Slighlty faster than dynamic allocation
	vec.reserve(dataPoints.size());
	
	for (int index = 0; index < dataPoints.size(); index++) {
		vec.push_back(inputMatrix[dataPoints[index].i][dataPoints[index].j]);
	}
	
	return vec;
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
	vector<DataPoint> dataPoints = generateRandomDataPoints(result.A.size());
    parsec_roi_begin();
	vector<int> C = gather_algorithm(result.A, dataPoints);
    parsec_roi_end();
		cout<<"Program executed";
	//printMatrix(C);
	return 0;
}