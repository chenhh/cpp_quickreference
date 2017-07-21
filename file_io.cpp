/*
 * http://www2.lssh.tp.edu.tw/~hlf/class-1/lang-c/c++file.htm
 * https://www.cnblogs.com/JCSU/articles/1190685.html
 */
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
    char filename[] = "HappyDay.txt";

    // write file
    fstream fout;
    fout.open(filename, ios::out);
    if (!fout) {
        cout << "Fail to open file: " << filename << endl;
    }
    cout << "File Descriptor: " << fout << endl;
    fout << "Hello HappyMan!!" << endl;
    fout.close();

    // read file
    fstream fin;
    string line;
    fin.open(filename, ios::in);
    // by word
    while (fin >> line) {
        cout << line << endl;
    }


    fin.close();
    return EXIT_SUCCESS;
}