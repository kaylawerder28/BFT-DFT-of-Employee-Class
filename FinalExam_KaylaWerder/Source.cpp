// Final Exam Employee using Depth First Traversal and Breadth First Traversal

#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class Employee {
public:
	string name; string company; string position; string degree;
	Employee()
	{
		name = ""; company = ""; position = ""; degree = "";
	}
	Employee(string n, string c, string p, string d)
	{
		name = n; company = c; position = p; degree = d; 
	}
	void setName(string n) { name = n; }
	void setCompany(string c) { company=c; }
	void setPosition(string p) { position = p; }
	void setDegree(string d) { degree = d; }
	string getName() { return name; }
	string getCompany() { return company; }
	string getPosition() { return position; }
	string getDegree() { return degree; }
};


class Node {
public:
	Employee data;
	Node() {};
	Node(Employee x)
	{
		data = x;
	}
};
class AdjacencyMatrix {
public:
	Node* V;
	int size = -1;
	int last = -1;
	int** M;
	AdjacencyMatrix() {}
	AdjacencyMatrix(int n) {
		size = n;
		V = new Node[size];
		M = new int*[size];
		for (int i = 0; i < size; i++) {
			M[i] = new int[size];
			for (int j = 0; j < size; j++) {
				M[i][j] = 0;
			}
		}
	}
	void InsertVertex(Employee x) {
		Node vertex(x);
		last++;
		V[last] = vertex;
	}

	void InsertEdge(Employee src, Employee dest, int weight) {
		int s = Search(src);
		int d = Search(dest);
		//M[s][d] = weight;
		M[s][d] = 1;
		M[d][s] = 1;
	}
	int Search(Employee key) {
		for (int i = 0; i <= last; i++) {
			if (V[i].data.getName() == key.getName()) return i;
		}
		return -1;
	}
	void BFT(Employee key) {
		int start = Search(key);
		bool* visited = new bool[size];
		for (int i = 0; i < size; i++) { visited[i] = 0; }
		queue <int> q;
		visited[start] = true;
		q.push(start);
		cout << "-----------Breadth First Traversal----------" << endl;
		while (!q.empty()) {
			start = q.front();
			q.pop();
			cout << start << " | " << V[start].data.getName() << " " << V[start].data.getCompany() << " " << V[start].data.getPosition() << " " << V[start].data.getDegree() << endl;
			for (int i = 0; i < size; i++) {
				if (M[start][i] > 0 && !visited[i]) {
					visited[i] = true;
					q.push(i);
				}
			}
		}
		cout << "---------------------------------------" << endl;
	}
	void DFT(Employee key) {
		int start = Search(key);
		bool* visited = new bool[size];
		for (int i = 0; i < size; i++) { visited[i] = 0; }
		stack <int> s;
		visited[start] = true;
		s.push(start);
		cout << "-----------Depth First Traversal------------" << endl;
		while (!s.empty()) {
			start = s.top();
			s.pop();
			cout << start << " | " << V[start].data.getName() << " " << V[start].data.getCompany() << " " << V[start].data.getPosition() << " " << V[start].data.getDegree() << endl;
			for (int i = 0; i < size; i++) {
				if (M[start][i] > 0 && !visited[i]) {
					visited[i] = true;
					s.push(i);
				}
			}
		}
		cout << "-----------------------------------" << endl;
	}
};


int main() {

	AdjacencyMatrix* matrix = new AdjacencyMatrix(5);

	Employee E1 = { "Mike", "Apple", "Software Engineer", "CS" };
	Employee E2 = { "Sam", "Microsoft", "Manager" , "Business" };
	Employee E3 = { "Kayla", "FDU", "Teacher", "Math" };
	Employee E4 = { "Fahad", "FDU", "Teacher", "Marketing" };
	Employee E5 = { "Julie", "Apple", "Saleman", "marketing" };
	

	
	matrix->InsertVertex(E1);
	matrix->InsertVertex(E2);
	matrix->InsertVertex(E3);
	matrix->InsertVertex(E4);
	matrix->InsertVertex(E5);




	matrix->InsertEdge(E1, E2, 1);
	matrix->InsertEdge(E3, E4, 1);
	matrix->InsertEdge(E5, E1, 1);
	matrix->InsertEdge(E4, E2, 1);
	matrix->InsertEdge(E3, E1, 1);
	matrix->InsertEdge(E2 ,E5, 1);
	matrix->InsertEdge(E1, E3, 1);
	

	matrix->BFT(E1);
	matrix->DFT(E4);




	return 0;
}
