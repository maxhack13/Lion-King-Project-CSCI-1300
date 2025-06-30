#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
// comparison functions
bool doublesEquals(double a, double b, const double epsilon = 1e-2);
// validation functions
bool validateInteger(string input);  
bool validateDouble(string input);
// print array functions
void printStringArray(string input[], int size);
void printIntegerArray(int input[], int size);
void printDoubleArray(double input[], int size);
// print menu function
int validIntegerMenu(string menu, string error_text, int valid_choices[], int valid_choices_size);
// file functions
bool readFile(string file_location, string lines[], int lines_size);
bool copyFile(string start_location, string end_location);
int main()
{
    // test csci library functions:
    // test string array printing
    //string testString[] = {"hello", "world!", "some", "random", "words"};
    //  printStringArray(testString, 5);
    //  //test integer array printing
    //  int testInteger[] = {1, 2, 3, 4, 5, 6};
    //  printIntegerArray(testInteger, 6);
    //  //test double array printing
    //  double testDouble[] = {1.0, 2.3, 4.5};
    //  printDoubleArray(testDouble, 3);
    //  //test validIntegerMenu
    //  string menu_text = "Choose a menu option: \n 1) Option 1 \n 2) Option 2 \n 3) Option 3";
// int menu_choices[] = {1, 2, 3};
// int choice = validIntegerMenu(menu_text, "Invalid choice", menu_choices, 3);
// cout << choice << endl;
// //test readFile function
// string fileData[15];
// cout << readFile("test.csv", fileData, 15) << endl;
// printStringArray(fileData, 15);
// cout << "Hello world! \n" << endl;
// cout << copyFile("test.txt", "test_copy.txt") << endl;
return 0;
}
bool doublesEqual(double a, double b, const double epsilon = 1e-2)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}
void printStringArray(string input[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (input[i].length() != 0)
            cout << input[i] << endl;
    }
}
void printIntegerArray(int input[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << endl;
    }
}
void printDoubleArray(double input[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << endl;
    }
}
bool validateInteger(string input)
{
    if (input.length() == 0)
    {
        return false;
    }
    if (input.length() == 1)
    {
        return isdigit(input.at(0));
    }
    if (input.at(0) != '-' && !isdigit(input.at(0)))
    {
        return false;
    }
    for (unsigned int i = 1; i < input.length(); i++)
    {
        if (!isdigit(input.at(i)))
        {
            return false;
        }
    }
    return true;
}
bool validateDouble(string input)
{
    // if the string is empty return false
    if (input.length() == 0)
    {
        return false;
    }
    // the string must have at least one numerical digit, but it can also start with a minus sign
        // it can have up to one decimal
    int numDecimals = 0;
    bool seenDigit = false;
    // if the string is longer than 1, the first character can be a digit or a minus sign 
    switch (input[0])
    {
    case '-':
        break;
    case '.':
        numDecimals++;
        break;
    default:
        if (isdigit(input[0]))
        {
            seenDigit = true;
        }
        else
        {
            return false;
        }
    }
    // check if all other digits are valid for index 1 through the end
    for (int i = 1; i < (int)input.length(); i++)
    {
        if (input[i] == '.')
        { // if the character isn't a number return false
            numDecimals++;
        }
        else if (isdigit(input[i]))
        {
            seenDigit = true;
        }
        else
        {
            return false;
        }
    }
    if (numDecimals > 1)
        return false;
    return seenDigit;
}
int validIntegerMenu(string menu, string error_text, int valid_choices[], int valid_choices_size)
{
    // declare variables
    string input;
    int int_input;
    while (true)
    { // until they give us a valid menu choice...
        // print the menu
        cout << menu << endl;
        // get the user input; check if it's a valid integer
        getline(cin, input);
        if (validateInteger(input))
        { // if it's a valid integer, we convert to an integer and check against valid choices
                int_input = stoi(input);
            for (int i = 0; i < valid_choices_size; i++)
            {
                if (valid_choices[i] == int_input)
                { // if it's valid, return the choice
                    return int_input;
                }
            }
            // if it's not valid, print error message and ask again
            cout << error_text << endl;
        }
        else
        { // if it's not a valid integer, print error message and asking again
            cout << error_text << endl;
        }
    }
}
bool readFile(string file_location, string lines[], int lines_size)
{
    // declare variables
    string line;
    ifstream input_file;
    input_file.open(file_location);
    if (input_file.fail())
    {
        return false;
    }
    int i = 0;
    while (getline(input_file, line) && i < lines_size)
    {
        lines[i] = line;
        i++;
    }
    input_file.close();
    return true;
}
bool copyFile(string start_location, string end_location)
{
    // declare variables
    string line;
    // open streams
    ifstream in_file;
    in_file.open(start_location);
    ofstream out_file(end_location);
    // if the start location wasn't found, return false
    if (in_file.fail())
    {
        return false;
    }
    // otherwise...
    while (getline(in_file, line))
    { // for each line in the input file, print it to the output file
                out_file << line << endl;
    }
    // close the streams
    in_file.close();
    out_file.close();
    return true;
}

int split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    // int length = input_string.length();

    if (input_string.length() == 0)
    {
        return 0;
    }
    else
    {
        int count = 0;
        // cout << length << endl;
        for (int i = 0; i < (int)input_string.length(); i++)
        {
            int length = input_string.length();
            // cout << "ENDING: " << i << ", " << length - 1 << ", " << input_string << endl;
            if (input_string[i] == separator)
            {
                // cout<< input_string[i]<<endl;
                if (count == ARR_SIZE)
                {
                    return -1;
                }
                arr[count] = input_string.substr(0, i);
                input_string = input_string.substr(i + 1, length - (i + 1));
                // cout << "new strand: " << input_string << endl;
                i = -1;
                count += 1;
                // cout << "count: " << count << endl;
            }
            else if (i == length - 1)
            {
                // cout << "ENDING" << endl;
                if (count == ARR_SIZE)
                {
                    return -1;
                }
                arr[count] = input_string;
            }
            if (count > ARR_SIZE)
            {
                return -1;
            }
        }
        if (count == 0)
        {
            arr[0] = input_string;
            return 1;
        }
        return count + 1;
    }
}

/////////////VECTOR SPLIT//////////////////////

vector<string> split(string input_string, char separator)
    {
        vector<string> SplitVec;
        
        // int length = input_string.length();
        int count = 0;
        if (input_string.length() == 0)
        {   
            //cout<<"hi";
            return SplitVec;
        }
        else
        {
            for (int i = 0; i < (int)input_string.length(); i++)
            {
                int length = input_string.length();
                //cout<<length;
                // cout << "ENDING: " << i << ", " << length - 1 << ", " << input_string << endl;
                //cout<<SplitVec.size();
                if (input_string[i] == separator)
                {   
                    
                    //cout<<"hi";
                    SplitVec.push_back(input_string.substr(0, i));
                    //cout<<SplitVec.at(count);
                    input_string = input_string.substr(i + 1, length - (i + 1));
                    i = -1;
                    count += 1;
                    //cout<< count;
                    
                }
                else if (i == length - 1)
                {

                    SplitVec.push_back(input_string);
                    count += 1;
                }
            }
            if (count == 0)
            {
                SplitVec.insert(SplitVec.begin()+0, input_string);
            }
            return SplitVec;
        }
    }