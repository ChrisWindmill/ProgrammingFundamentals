#include <iostream>


#define Example1
//#define Example2
//#define Example3
//#define Example4


#ifdef Example1
/* This is the code with errors in it.
float CountPunctuation()
{
	int counter;

	for (int i = 0; i <= str.size(); i + 1)
	{
		if (str[i] == '.' || '!' || '?')
			counter += 1;
	}
	return counter;
}
*/

// std::string is needed for the string type, therefore we must include the header file
#include <string>
// Return type changed to integer - there is no reason to have fractional punctuation marks so a float is not appropriate
// Added a parameter - a std::string - to allow the function to operate on something
int CountPunctuation(std::string str)
{
	// Initialised the counter variable to 0 to avoid undefined behaviour
	int counter = 0;

	// a for loop takes an index variable, a condition and an increment
	// in this case the increment wasn't updating the index variable, so it would run forever
	for (int i = 0; i <= str.size(); i = i + 1)
	{
		// The original statement would always evaluate to true - the characters '!' and '?' have non-zero ASCII values, 33 and 63 respectively
		// we modify this to compare each to the character at str[i] making it into a comparison rather than "true"
		// while you can remove the braces for a single statement after an if, it's good practice to keep them to avoid mistakes later
		if (str[i] == '.' || str[i] == '!' || str[i] == '?')
		{
			counter += 1;
		}
	}
	return counter;
}
#endif

#ifdef Example2
void PrintArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}
#endif

#ifdef Example4
// This is the original code with errors
/*struct Stage
{
	int stageIndex;
	bool completed;
};

bool IsLevelOver(int playerScore, Stage* stages, int stagesSize)
{
	bool hasEnoughScore = playerScore = > 100;

	int count = 0;

	for (int i = 0; i < stagesSize; i++)
	{
		if (stages[i].completed)
			count += 1;
			std::cout << "stage " << i << " completed!";
	}
	return (hasEnoughScore & count >= 10);
}*/

struct Stage
{
	int stageIndex;
	bool completed;
};

bool IsLevelOver(int playerScore, Stage* stages, int stagesSize)
{
	// group variable declarations and initialisation together
	bool levelOver = false;
	bool hasEnoughScore = false;
	int count = 0;

	// separate out the calculation from the initilisation
	

	for (int i = 0; i < stagesSize; i++)
	{
		// add scope delineators {} to include cout only on completion
		if (stages[i].completed)
		{
			count += 1;
			std::cout << "stage " << i << " completed!\n";
		}
	}

	std::cout << count << " of " << stagesSize << " stages completed\n";
	hasEnoughScore = playerScore >= 100;
	levelOver = hasEnoughScore && count >= stagesSize;

	return (levelOver);
}
#endif


int main(int argc, char* argv[])
{
#ifdef Example1
	std::cout << "\n\t\t Example 1\n";
	// Should output 3
	std::cout << CountPunctuation("Hello! How are you? I'm fine.") << std::endl;
	// Should output 8
	std::cout << CountPunctuation("Hello there? The Angel of my nightmares? Aaargh!!!!!!") << std::endl;
	// Should output 7
	std::cout << CountPunctuation("A last word!? Interrobang! It is an exclaimed question... or is it? ") << std::endl;
#endif

#ifdef Example2
	std::cout << "\n\t\t Example 2\n";
	/* This is the orgiginal code with errors in it.
	int numbers[] = { 3, 4, 5 };
	PrintArray(numbers, sizeof(numbers));
	*/
	// To correct the size parameter, we need to divide the total size of the array by the size of a single element
	int numbers[] = { 3, 4, 5 };
	PrintArray(numbers, sizeof(numbers) / sizeof(int));

	// To make this more readable we can do the math before passing it to the function
	int moreNumbers[] = { 10, 20, 30, 40, 50 };
	int length = sizeof(moreNumbers) / sizeof(int);
	PrintArray(moreNumbers, length);
#endif

#ifdef Example3
	std::cout << "\n\t\t Example 3\n";
	char someString[] = "this is an example";		// someString "this is an example"
	char* strPtr = someString;						// strPtr = 0, *strPtr = 't'

	strPtr += 11;									// strPtr = 11, *strPtr = 'e'
	(*strPtr)++;									// strPtr = 11, *strPtr = 'f'

	strPtr -= 5;									// strPtr = 6, *strPtr = 's'
	*(someString + 1) = *someString;				// copy [0] 't' to [1] 'h'
	*(someString + 2) = strPtr[2];					// strPtr (6+2=8) 'a' to [2] 'i'
	*someString = *(someString + 3);				// copy [3] 's' to [0] 't'

	strPtr += 5;									// strPtr = 11, *strPtr = 'f'
	someString[3] = someString[4] = *strPtr;		// copy 'f' to [4], copy [4] to [3]

	*(strPtr - 6) = *(strPtr - 5);					// copy strPtr (6) to strPtr (5)
	strPtr -= 4;									// strPtr = 7, *strPtr = ' '
	*(--strPtr) = 0;								// set [6] to '0' (null)

	std::cout << someString << std::endl;			// print "staffs"
#endif


#ifdef Example4
	std::cout << "\n\t\t Example 4\n";
	Stage* stages = new Stage[5]{ {1,true}, {2,true}, {3,true}, {4,false}, {5,false} };
	if (IsLevelOver(500, stages, 5))
	{
		std::cout << "Level passed!";
	}
	else
	{
		std::cout << "Level failed!";
	}
#endif

}
