#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    string file_name = "image.dat";

    // WRITING TO FILE
    cout << "=== WRITING TO FILE ===" << endl;
    {
        ofstream file(file_name, ios_base::out | ios_base::binary);
        if (!file) {
            cout << "Error creating file!" << endl;
            return EXIT_FAILURE;
        }

        int rows = 2;
        int col = 3;
        
        // Initialize vector with some sample data
        vector<float> vec(rows * col);
        for (int i = 0; i < vec.size(); i++) {
            vec[i] = static_cast<float>(i + 1) * 1.5f;  // Sample data: 1.5, 3.0, 4.5, 6.0, 7.5, 9.0
        }

        cout << "Writing dimensions: " << rows << " x " << col << endl;
        cout << "Writing data: ";
        for (float d : vec) {
            cout << d << " ";
        }
        cout << endl;

        // Write dimensions and data to file
        file.write(reinterpret_cast<char*>(&rows), sizeof(rows));
        file.write(reinterpret_cast<char*>(&col), sizeof(col));
        file.write(reinterpret_cast<char*>(&vec.front()), vec.size() * sizeof(float));
        
        file.close();
        cout << "Data written successfully!" << endl;
    }

    // READING FROM FILE
    cout << "\n=== READING FROM FILE ===" << endl;
    {
        ifstream in(file_name, ios_base::in | ios_base::binary);
        if (!in) {
            cout << "Error opening file for reading!" << endl;
            return EXIT_FAILURE;
        }

        int r = 0, c = 0;
        
        // Read dimensions
        in.read(reinterpret_cast<char*>(&r), sizeof(r));
        in.read(reinterpret_cast<char*>(&c), sizeof(c));
        
        cout << "Dim: " << r << " x " << c << endl;
        
        // Read data
        vector<float> data(r * c, 0);
        in.read(reinterpret_cast<char*>(&data.front()), data.size() * sizeof(data.front()));
        
        // Print the data
        cout << "Read data: ";
        for (float d : data) {
            cout << d << " ";
        }
        cout << endl;
        
        in.close();
    }

    return EXIT_SUCCESS;
}