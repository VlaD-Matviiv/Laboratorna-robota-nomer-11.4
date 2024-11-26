// Lab 11.4

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>

using namespace std;

// ������� ��� ��������� ���������� ����� � ��������
void createFile(const string& filename) 
{
    int n, m;
    cout << "������ ������� ����� (n): ";
    cin >> n;
    cout << "������ ������� �������� (m): ";
    cin >> m;

    ofstream outFile(filename);
    if (!outFile.is_open()) 
    {
        cerr << "�� ������� �������� ����!" << endl;
        return;
    }

    outFile << n << " " << m << endl;
    cout << "������ �������� �������:" << endl;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            int value;
            cin >> value;
            outFile << value << " ";
        }
        outFile << endl;
    }
    outFile.close();
    cout << "���� �������� ������!" << endl;
}

// ������� ��� ������� ������� �� ��������� ������ �����
void processFile(const string& inputFile, const string& outputFile) 
{
    ifstream inFile(inputFile);
    if (!inFile.is_open()) 
    {
        cerr << "�� ������� ������� ���� ��� �������!" << endl;
        return;
    }

    int n, m;
    inFile >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            inFile >> matrix[i][j];
        }
    }
    inFile.close();

    ofstream outFile(outputFile);
    if (!outFile.is_open()) 
    {
        cerr << "�� ������� �������� ���� ��� ������!" << endl;
        return;
    }

    outFile << n << " " << m << endl; // �������� ������ �����
    for (int i = 0; i < n; ++i) 
    {
        int maxVal = *max_element(matrix[i].begin(), matrix[i].end());
        for (int j = 0; j < m; ++j) 
        {
            outFile << matrix[i][j] << " ";
        }
        outFile << maxVal << endl; // ������ ����������� �������� �� ������� �����
    }
    outFile.close();
    cout << "���� ��������� ������!" << endl;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    while (true) 
    {
        cout << "\n����:\n";
        cout << "1. �������� ������� ����\n";
        cout << "2. �������� ���� � �������� �������� ����\n";
        cout << "3. �����\n";
        cout << "��� ����: ";
        int choice;
        cin >> choice;

        switch (choice) 
        {
        case 1:
            createFile(inputFile);
            break;
        case 2:
            processFile(inputFile, outputFile);
            break;
        case 3:
            cout << "����� � ��������." << endl;
            return 0;
        default:
            cout << "����������� ����. ��������� �� ���." << endl;
        }
    }

    return 0;
}
