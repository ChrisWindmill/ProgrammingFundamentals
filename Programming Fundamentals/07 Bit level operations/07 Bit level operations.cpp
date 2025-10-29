#include <iostream>
#include <string>
#include <cstdint>
#include <regex>
#include <bitset>

void printFormat(uint16_t num)
{
    std::cout << std::dec << num << "\t" << std::oct << num << "\t" << std::hex << num << "\t" << std::bitset<16>{num} << "\n";
}

int main()
{
    std::cout << "\t\t\t\t\tProgramming Fundamentals" << std::endl;
    std::cout << "\t\t\t\t\t  Bit Level Operations" << std::endl;
#pragma region Base Equivalencies
    uint16_t base10 = 67;
    uint16_t base8 = 067;
    uint16_t base16 = 0x67;
    uint16_t base2 = 0b0000000010000111;

    std::cout << "Base 10\t Base 8\t Base 16\t Base 2" << std::endl;
    printFormat(base10); printFormat(base8); printFormat(base16); printFormat(base2);
#pragma endregion

    // Variables for input: string, uint16_t set to 0, and control variable
    uint16_t userInput = 0;
    std::string intermediateInput;
    bool invalidInput = true;

    // Regex: matches the first 4 characters are only 1's and 0's - and there is only a single 1 in that group, then there are 12 1's or 0's
    std::regex word_regex("^((?=[01]{4})[0]*1[0]*)([01]{12})$");
    /*
#pragma region get user input and validate
    do
    {
        userInput = 0;
        std::cout << "Please enter a 16 bit value (16x [0-1]): ";
        std::cin >> intermediateInput;
        if (std::regex_search(intermediateInput, word_regex))
        {
            invalidInput = false;
            std::cout << "yay";
        }
        else
        {
            std::cout << "That wasn't a valid pattern" << std::endl;
        }
    } while (invalidInput);
#pragma endregion

#pragma region string to binary value
    for (int i = 0; i < 16; i++)
    {
        userInput = userInput << 1;
        if (intermediateInput[i] == '1')
            userInput++;
    }
    printFormat(userInput);
#pragma endregion
*/
    // Now we do stuff with the numbers.

    // Bitwise AND
    uint16_t andValue1 = 0b1100000011110000;
    uint16_t andValue2 = 0b1000000000000001;
    uint16_t andOutput = andValue1 & andValue2;

    std::cout << "\nThe bitwise and takes each position in the data and performs a logical and between the two bits." << "\n";
    std::cout << "\t" << std::bitset<16>{andValue1} << "\n";
    std::cout << "\t" << std::bitset<16>{andValue2} << "\n";
    std::cout << "\t" << std::bitset<16>{andOutput} << "\n";

    // Bitwise OR
    std::cout << "\nThe bitwise or takes each position in the data and performs a logical OR between the two bits." << "\n";
    uint16_t orValue1 = 0b1100000011110000;
    uint16_t orValue2 = 0b1000000000000001;
    uint16_t orOutput = orValue1 | orValue2;

    std::cout << "\t" << std::bitset<16>{orValue1} << "\n";
    std::cout << "\t" << std::bitset<16>{orValue2} << "\n";
    std::cout << "\t" << std::bitset<16>{orOutput} << "\n";

    // Bitwise XOR
    std::cout << "\nThe bitwise xor takes each position in the data and performs a logical XOR between the two bits." << "\n";
    uint16_t xorValue1 = 0b1100000011110000;
    uint16_t xorValue2 = 0b1000000000000001;
    uint16_t xorOutput = xorValue1 ^ xorValue2;

    std::cout << "\t" << std::bitset<16>{xorValue1} << "\n";
    std::cout << "\t" << std::bitset<16>{xorValue2} << "\n";
    std::cout << "\t" << std::bitset<16>{xorOutput} << "\n";
    
    // Bitwise NOT
    std::cout << "\nThe bitwise not takes each position in the data and performs a logical not on the bit." << "\n";
    uint16_t notValue1 = 0b1100000011110000;
    uint16_t notOutput = ~notValue1;

    std::cout << "\t"<< std::bitset<16>{notValue1} << "\n";
    std::cout << "\t" << std::bitset<16>{notOutput} << "\n";


    // Bitwise shifts
    std::cout << "\nThe shift operators move a bit n positions to the left (bigger) or right (smaller)" << "\n";
    std::cout << "a left is shift is the same as multiplying by 2, a right shift the same as dividing by 2.\n";
    uint16_t shValue1 = 0b0000101001010101;
    uint16_t shValue2 = 0b1011011101011100;
    int shift = 2;
    uint16_t lshValue1 = shValue1 << shift;
    uint16_t rshValue2 = shValue2 >> shift;

    std::cout << "\t" << std::bitset<16>{shValue1} << "(" << std::dec << shValue1 << ") left shifted by " << shift << " is \n";
    std::cout << "\t" << std::bitset<16>{lshValue1} << "(" << std::dec << lshValue1 << ")\n\n";

    std::cout << "\t" << std::bitset<16>{shValue2} << "(" << std::dec << shValue2 << ") left shifted by " << shift << " is\n";
    std::cout << "\t" << std::bitset<16>{rshValue2} << "(" << std::dec << rshValue2 << ")\n";
    
    // Masking
    std::cout << "\nMasking lets us pull out specific values or sections of a bitfield" << "\n";
    uint16_t maskValue1 = 0b1100000011110000;
    uint16_t maskMask = 0b0000000000000001;
    uint16_t maskOutput = 0b0;
    std::cout << "\nPrinting out each individual bit - MSB is on the left (bit 16), and LSB on the right (bit value 1)" << "\n";
    std::cout << "a left is shift is the same as multiplying by 2, a right shift the same as dividing by 2.\n";
    for (int i = 0; i < 16; i++)
    {
        maskOutput = maskValue1 >> i;
        maskOutput = maskOutput & maskMask;
        std::cout << "Bit value " << powf(2,15-i) << " is\t" << maskOutput << "\n";
    }

    // Extracting sets of bytes for colours
    std::cout << "\nMasking lets us pull out specific values or sections of a bitfield" << "\n";
    uint16_t colourValue1 = 0b1100000011110000;
    uint16_t redMask = 12;
    uint16_t greenMask = 8;
    uint16_t blueMask = 4;

    uint16_t colourMask = 0xff;

    uint16_t redValue= (colourValue1 >> redMask) & colourMask;
    uint16_t greenValue = (colourValue1 >> greenMask) & colourMask;
    uint16_t blueValue = (colourValue1 >> blueMask) & colourMask;
    uint16_t alphaValue = colourValue1 & colourMask;
    
    std::cout << "Colour value\t " << colourValue1 << "is composed of:\n";
    std::cout << "Red value\t " << std::hex << redValue << "\n";
    std::cout << "Green value\t " << std::hex << greenValue << "\n";
    std::cout << "Blue value\t " << std::hex << blueValue  << "\n";
    std::cout << "Alpha value\t " << alphaValue << "\n";

}
