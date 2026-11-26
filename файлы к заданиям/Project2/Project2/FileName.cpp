#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
const string FILE_NAME = "settings.txt";
// check that the string is not empty
bool isValidString(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isspace(static_cast<unsigned char>(c))) return true;
    }
    return false;
}
// apply text color 
void applyTextColor(int textColor) {
    string cmd = "color 0" + to_string(textColor);
    system(cmd.c_str());
}
// color name by code 
string colorName(int code) {
    switch (code) {
    case 0: return "black";
    case 1: return "blue";
    case 2: return "green";
    case 3: return "cyan";
    case 4: return "red";
    case 5: return "purple";
    case 6: return "yellow";
    case 7: return "white";
    default: return "unknown";
    }
}
void saveAndShowBook() {
    string book;

    ifstream fin(FILE_NAME);
    bool fileExists = fin.is_open();
    string savedBook;

    if (fileExists) {
        getline(fin, savedBook);
        fin.close();
    }

    if (fileExists && isValidString(savedBook)) {
        cout << "Saved favorite book: " << savedBook << endl;
        cout << "Do you want to change the book? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore(); // clear the buffer after cin >> choice

        if (choice == 'y' || choice == 'Y') {
            do {
                cout << "Enter a new favorite book: ";
                getline(cin, book);
                if (!isValidString(book)) {
                    cout << "Error: the book cannot be empty. Please try again.\n";
                }
            } while (!isValidString(book));

            ofstream fout(FILE_NAME);
            fout << book;
            fout.close();
            cout << "Book updated!\n";
        }
    }
    else {
        // no file or no book saved — enter it for the first time
        do {
            cout << "Enter your favorite book: ";
            getline(cin, book);
            if (!isValidString(book)) {
                cout << "Error: the book cannot be empty. Please try again.\n";
            }
        } while (!isValidString(book));

        ofstream fout(FILE_NAME);
        fout << book;
        fout.close();
        cout << "Book saved!\n";
    }
}
void saveAndApplyTextColor() {
    int color = 7; // default: white text

    // Read the color from a separate file so it doesn't clash with the book
    const string COLOR_FILE = "color.txt";
    ifstream fin(COLOR_FILE);
    bool fileExists = fin.is_open();
    int savedColor = -1;

    if (fileExists) {
        fin >> savedColor;
        fin.close();
    }

    if (fileExists && savedColor >= 0 && savedColor <= 7) {
        cout << "Saved text color: " << colorName(savedColor)
            << " (code " << savedColor << ")\n";
        applyTextColor(savedColor);
        cout << "Color applied.\n";

        cout << "Do you want to change the text color? (y/n): ";
        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            do {
                cout << "Enter the text color code (0-7):\n"
                    << "0 - black, 1 - blue, 2 - green, 3 - cyan,\n"
                    << "4 - red, 5 - purple, 6 - yellow, 7 - white\n";
                cout << "Your choice: ";
                if (!(cin >> color)) {
                    cout << "Error: please enter a number.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    color = -1;
                    continue;
                }
                if (color < 0 || color > 7) {
                    cout << "Error: the code must be between 0 and 7.\n";
                }
            } while (color < 0 || color > 7);

            ofstream fout(COLOR_FILE);
            fout << color;
            fout.close();
            applyTextColor(color);
            cout << "Text color updated and applied!\n";
        }
    }
    else {
        do {
            cout << "Enter the text color for displaying the book (0-7):\n"
                << "0 - black, 1 - blue, 2 - green, 3 - cyan,\n"
                << "4 - red, 5 - purple, 6 - yellow, 7 - white\n";
            cout << "Your choice: ";
            if (!(cin >> color)) {
                cout << "Error: please enter a number.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                color = -1;
                continue;
            }
            if (color < 0 || color > 7) {
                cout << "Error: the code must be between 0 and 7.\n";
            }
        } while (color < 0 || color > 7);

        ofstream fout(COLOR_FILE);
        fout << color;
        fout.close();
        applyTextColor(color);
        cout << "Text color saved and applied!\n";
    }
}
int main() {
    setlocale(LC_ALL, "ru");

    // 1) Save/display the book
    saveAndShowBook();

    // 2) Save/apply the text color
    cout << "\nText color setup \n";
    saveAndApplyTextColor();

    // 3) Final output of the book in the chosen color
    cout << "\nResult \n";
    ifstream fin(FILE_NAME);
    string book;
    if (fin.is_open()) {
        getline(fin, book);
        fin.close();
        cout << "Your favorite book: " << book << endl;
    }

    system("pause");
    return 0;
}