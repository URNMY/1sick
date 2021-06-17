#include <iostream>
#include <fstream>

using namespace std;
 
//ifstream in("input.txt");

int main() {
	int countOfNode, countOfEdges;

	cin >> countOfNode >> countOfEdges;

	int** mi = new int* [countOfNode];
	for (int i = 0; i < countOfNode; i++) {
		mi[i] = new int[countOfEdges];
	}
	for (int i = 0; i < countOfNode; i++) {
		for (int j = 0; j < countOfEdges; j++)
			mi[i][j] = 0;
	}

	int fN, sN;
	double totalOutIn = 0;

	for (int i = 0; i < countOfEdges; i++) {
		cin >> fN >> sN;
		if (fN == sN) mi[fN - 1][i] = 3;
		else {
			mi[fN - 1][i] = 2;
			mi[sN - 1][i] = 1;
		}
		totalOutIn+=2;
	}



	for (int i = 0; i < countOfNode; i++) {
		for (int j = 0; j < countOfEdges; j++)
			cout << mi[i][j] << " ";
		cout << endl;
	}

	int output = 0, input = 0;
	
	for (int i = 0; i < countOfNode; i++) {
		for (int j = 0; j < countOfEdges; j++) {
			if (mi[i][j] == 2 || mi[i][j] == 3) output++;
			if (mi[i][j] == 1 || mi[i][j] == 3) input++;
		}
		cout << "Node: " << i + 1 << "\n" << "Income: " << input << endl << "Outcome: " << output << endl << endl;
		output = 0;
		input = 0;
	}
	double averageSemiExtent = totalOutIn / countOfNode;
	cout << "Average income & outcome: " << averageSemiExtent << endl;
}
