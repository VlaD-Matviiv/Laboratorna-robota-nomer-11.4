// Lab 11.4

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>

using namespace std;

// Функція для створення текстового файлу з матрицею
void createFile(const string& filename) 
{
    int n, m;
    cout << "Введіть кількість рядків (n): ";
    cin >> n;
    cout << "Введіть кількість стовпців (m): ";
    cin >> m;

    ofstream outFile(filename);
    if (!outFile.is_open()) 
    {
        cerr << "Не вдалося створити файл!" << endl;
        return;
    }

    outFile << n << " " << m << endl;
    cout << "Введіть елементи матриці:" << endl;
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
    cout << "Файл створено успішно!" << endl;
}

// Функція для обробки матриці та створення нового файлу
void processFile(const string& inputFile, const string& outputFile) 
{
    ifstream inFile(inputFile);
    if (!inFile.is_open()) 
    {
        cerr << "Не вдалося відкрити файл для читання!" << endl;
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
        cerr << "Не вдалося створити файл для запису!" << endl;
        return;
    }

    outFile << n << " " << m << endl; // Записуємо перший рядок
    for (int i = 0; i < n; ++i) 
    {
        int maxVal = *max_element(matrix[i].begin(), matrix[i].end());
        for (int j = 0; j < m; ++j) 
        {
            outFile << matrix[i][j] << " ";
        }
        outFile << maxVal << endl; // Додаємо максимальне значення до кожного рядка
    }
    outFile.close();
    cout << "Файл оброблено успішно!" << endl;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    while (true) 
    {
        cout << "\nМеню:\n";
        cout << "1. Створити вхідний файл\n";
        cout << "2. Обробити файл і створити вихідний файл\n";
        cout << "3. Вийти\n";
        cout << "Ваш вибір: ";
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
            cout << "Вихід з програми." << endl;
            return 0;
        default:
            cout << "Некоректний вибір. Спробуйте ще раз." << endl;
        }
    }

    return 0;
}
