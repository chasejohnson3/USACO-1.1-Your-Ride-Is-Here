/*
ID: chaser.1
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int decipherMod(string code);

int main()
{
    string firstLine, secondLine;
    int groupProductMod, cometProductMod;


    ifstream fin("ride.in");
    if (fin.fail())
    {
        cerr << "Unable to open ride.txt";
        return 0;
    }
    ofstream fout("ride.out");

    fin >> firstLine;
    fin >> secondLine;

    groupProductMod = decipherMod(firstLine);
    cometProductMod = decipherMod(secondLine);

    if (groupProductMod == cometProductMod)
    {
        // If the remainder of the product of the numbers of the comet equals that of the group, print GO.
        fout << "GO" << endl;
    }
    else
    {
        // If the remainder of the product of the numbers of the comet do not equal that of the group, print STAY.
        fout << "STAY" << endl;
    }
    return 0;
}

int decipherMod(string code)
{
    int product(1), letterValue;

    // Find the product of the integers corresponding to the letters in the name of the group/comet name
    for (int i=0; i<code.length(); i++)
    {
        // Converts the ASCII letters to their corresponding numbers
        // then converts it so that A=1 ... Z=26. (ASCII for A is 65)
        letterValue = (int) code[i] - 64;
        product *= letterValue;
    }
    return product % 47;
}
