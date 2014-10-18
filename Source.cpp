//////////////////////////////////////////////////////////////////
// Program Name: RPG Character Generator                        //
// Student ID: 13003946                                         //
// Date: November 2013										                      //
// Purpose: To manipulate cstrings, arrays and loops to create  //
//          a RPG generator to fit the criteria of Assignment 2 //
//////////////////////////////////////////////////////////////////

#include <iostream> //inclues basic I/O library
#include <time.h> //includes time library for seeding rand
#include <cstring> //includes c-string library to allow manipulation
using namespace std;

//Constant Declarations -------------------------------------------------------
const int numNames = 24; //each name array will have 13 names
const int lenNames = 15; //each name array will be 15 chars long
const int numChoices = 7; //number of choice is array
const int lenChoices = 300; //length of each choice
const int totalAttributes = 5; //number of total attributes to generate
const int sentenceLength = 25000; //total sentence length of sentence/backstory

//Male Character Names
const char maleCharNames[numNames][lenNames] =
{ "Aiden", "Calden", "Beeron",
"Xeus", "Undin", "Marceus",
"Rythen", "Mylo", "Niro", "Jaska",
"Daran", "Davius" };

//Female Character Names
const char femaleCharNames[numNames][lenNames] = { "Brenna", "Mari",
"Brynda", "Eyslk", "Danna",
"Ceola", "Ana", "Iona",
"Jessika", "Fayne", "Tabika", "Urda" };

//Character Descriptors (used in names)
const char charDesc[8][lenChoices] = { "Brave", "Mighty", "Great", "Small", "Killer",
"Creepy", "Awesome", "Artful" };

//Names of Character Attributes
const char charAttributes[5][lenChoices] = { "Strength", "Agility", "Toughness",
"Intelligence", "Charisma" };

//Names of locations
const char location[numChoices][lenChoices] = { "Draimac", "Joukl", "Cramea", "Maenos",
"Cyska", "Vellana", "Trossal" };

//Names of classes
const char classOfChar[7][lenChoices] = { "Warrior", "Elf", "Troll", "Brute",
"Mage", "Ninja", "Assassin" };

//Types of personality
const char personality[7][lenChoices] = { "kind", " willing",
"well intentioned", " peaceful",
"war-mongering", "a loose cannon",
"irrational" };

//Types of achievements
const char achievement[numChoices][lenChoices] = { "winning the Great War of Draimac",
"slaying a dragon",
"saving the kingdom",
"winning gold in an egg and spoon race",
"having a book written about their life",
"knowing the words to the classic song \"On Ilkla Moor Baht'at\"",
"looting over 700 treasure chests" };

//Types of hobbies
const char activity[numChoices][lenChoices] = { " looking after animals",
" playing the hirtenschalmei", " drinking in the local inn",
" hunting local wildlife", " helping others",
" rebelling against the King", " training for battle" };


//Sub-programs-----------------------------------------------------------------

//This subprogram generates the attributes of each character and has each
//attribute stored in a different array location using a for loop. Each
//attribute is then checked by a series of if statements, and if validated,
//has a different bit of text written to another array location, which is used
//to generate the descriptors.
void attributeGenerator(int attributeValues[totalAttributes], char descriptorAttributes
  [totalAttributes][25], int &totalValue, bool validStats)
{
  srand((unsigned)time(NULL));//used to seed random number
  int zero = 0;//integer used to count up attributeValue array positions
  validStats = false; //set to true when stats are valid
  totalValue = 0;//integer to store total value of the five attributes

  while (!validStats)//run while stats is false
  {
    for (zero = 0; zero < totalAttributes; zero++)
    {//for loop checks array values and randomly generates them
      attributeValues[zero] = rand() % 10 + 1;
      totalValue = totalValue + attributeValues[zero];
      //total value equals all the attribute values

      //series of if statements - if the attribute value in the array location
      //is X, a string literal is written into the descriptor array location
      //adjacent to the attribute value (as they both use int 'zero'):
      if (attributeValues[zero] > 0 && attributeValues[zero] <= 2)
      {//if attribute value is between 1 and 2
        strcpy_s(descriptorAttributes[zero], 25, "Puny");
        //the word "puny" is copied to descriptorAttributes[0]
      }//if ends
      else if (attributeValues[zero] > 2 && attributeValues[zero] <= 4)
      {//if attribute value is between 3 and 4
        strcpy_s(descriptorAttributes[zero], 25, "Weak");
        //the word "weak" is copied to descriptorAttributes[1]
      }//if ends
      else if (attributeValues[zero] > 4 && attributeValues[zero] <= 6)
      {//if attribute value is between 5 and 6
        strcpy_s(descriptorAttributes[zero], 25, "Moderate");
        //the word "moderate" is copied to descriptorAttributes[2]
      }//if ends
      else if (attributeValues[zero] > 6 && attributeValues[zero] <= 9)
      {//if attribute value is between 7 and 9
        strcpy_s(descriptorAttributes[zero], 25, "Strong");
        //the word "strong" is copied to descriptorAttributes[3]
      }//if ends
      else if (attributeValues[zero] > 9 && attributeValues[zero] <= 10)
      {//if attribute value is 10
        strcpy_s(descriptorAttributes[zero], 25, "Like A God");
        //the literal "like a god" is copied to descriptorAttributes[4]
      }//if ends
    }//for ends
    break;
  }//while loop ends
}//sub program ends

//////////////////////////////
///Main program starts here///
//////////////////////////////
void main()
{
  //Variable Declarations-------------------------------------------------------
  srand((unsigned)time(NULL));//array to store full generated name
  char fullName[35] = { '\0' }; //array to store character's full name
  char firstName[20] = { '\0' }; //array to store character's first name
  char descriptorAttributes[totalAttributes][25] = { '\0' };
  //array is used to store the string for descriptions of the attributes
  char fullBio[sentenceLength] = { '\0' }; //array that stores all five sentences
  int orderOfNames = rand() % 2 + 1; //generates random number (1-2)
  //to decide order of names
  int whichName = rand() % 11; //generates random number up to 11
  //to pick which name will be used in array
  int whichDesc = rand() % 7; //generates random number up to 7 to
  //pick which descriptor will be used
  int maleOrFemale = rand() % 2 + 1; //generates number between 1 - 2
  //to pick character's gender
  int attributeValues[totalAttributes]; //array used to store the numerical
  //values of the attributes
  int totalValue = 0; //integer that stores total value of all attributes
  bool validStats = true; //if true, the generated stats are valid, if false,
  //stats are regenerated

  //These variables are used in sentence generation further in the program.
  //The first char array stores the final generated sentence that is selected
  //from the three options. The three arrays that follow store each sentence
  //option, which in turn have randomly inserted constants (see line 263)

  //Sentence 1 - location
  char locationSentence[sentenceLength] = { '\0' };//stores final sentence
  char locationOptionOne[sentenceLength] = { '\0' };//option 1
  char locationOptionTwo[sentenceLength] = { '\0' };//option 2
  char locationOptionThree[sentenceLength] = { '\0' };//option 3
  //Sentence 2 - class
  char classSentence[sentenceLength] = { '\0' };//stores final sentence
  char classOptionOne[sentenceLength] = { '\0' };//option 1
  char classOptionTwo[sentenceLength] = { '\0' };//option 2
  char classOptionThree[sentenceLength] = { '\0' };//option 3
  //Sentence 3 - personality
  char personalitySentence[sentenceLength] = { '\0' };//stores final sentence
  char personalityOptionOne[sentenceLength] = { '\0' };//option 1
  char personalityOptionTwo[sentenceLength] = { '\0' };//option 2
  char personalityOptionThree[sentenceLength] = { '\0' };//option 3
  //Sentence 4 - achievement
  char achievementSentence[sentenceLength] = { '\0' };//stores final sentence
  char achievementOptionOne[sentenceLength] = { '\0' };//option 1
  char achievementOptionTwo[sentenceLength] = { '\0' };//option 2
  char achievementOptionThree[sentenceLength] = { '\0' };//option 3
  //Sentence 5 - hobby/activity
  char hobbiesSentence[sentenceLength] = { '\0' };//stores final sentence
  char hobbiesOptionOne[sentenceLength] = { '\0' };//option 1
  char hobbiesOptionTwo[sentenceLength] = { '\0' };//option 2
  char hobbiesOptionThree[sentenceLength] = { '\0' };//option 3

  //Generators - each of these ints generates a random number between
  //one and three for each of the sentence backstory categories (location,
  //class, personality, achievement and hobby). The number is then tested
  //against three if statements, which prints out the correct sentence option

  int locationOption = rand() % 3 + 1; //generates for location sentence
  int classOption = rand() % 3 + 1; //generates for class sentence
  int personalityOption = rand() % 3 + 1; //generates for personality sentence
  int achievementOption = rand() % 3 + 1; //generates for achievement sentence
  int hobbyOption = rand() % 3 + 1; //generates for hobby sentence




  //Name Generator -------------------------------------------------------------
  //These if loops determine the character's gender based on the number of the
  //declared integer (maleOrFemale = rand() % 2 + 1)
  if (maleOrFemale == 1) //if the character is male, this if is used
  {
    if (orderOfNames == 1)//order of names is randomly selected via rand.
      //if maleOrFemale is 1 and the order is 1, these
      //if statements are used
    { //a name randomly chosen from maleCharNames (chosen by the generated value
      //of "whichName") is selected and copied into the fullName array:
      strcpy_s(fullName, maleCharNames[whichName]);
      strcat_s(fullName, " The "); //'the' is concatenated into middle of name
      strcat_s(fullName, charDesc[whichDesc]); //a randomly chosen descriptor from
      //charDesc is concatenated into 
      //the fullName array
      strcpy_s(firstName, maleCharNames[whichName]); //the character's first name
      //is also copied into
      //firstName 
    }
    if (orderOfNames == 2)//if maleOrFemale is 1 and the order is 2, these
      //if statements are used
    {
      strcpy_s(fullName, "The "); //"the" is copied into fullName array
      strcat_s(fullName, charDesc[whichDesc]); //randomly chosen descriptor is
      //concatenated into fullName
      //array
      strcat_s(fullName, " "); //a space is added
      strcat_s(fullName, maleCharNames[whichName]); //randomly chosen male name
      //is concatenated into
      //fullName
      strcpy_s(firstName, maleCharNames[whichName]); //the character's first name
      //is also copied into
      //firstName 
    }
  }

  else if (maleOrFemale == 2) //or if the character is female, this is used
  {
    if (orderOfNames == 1) //if maleOrFemale is 2 and the order is 1, these
      //if statements are used
    {
      strcpy_s(fullName, femaleCharNames[whichName]); //randomly generated female
      //name is copied into
      //fullName array
      strcat_s(fullName, " The "); //"the" is concatenated into middle
      strcat_s(fullName, charDesc[whichDesc]);//randomly chosen descriptor is
      //concatenated into fullName
      //array
      strcpy_s(firstName, femaleCharNames[whichName]);//the character's first name
      //is also copied into
      //firstName 
    }
    if (orderOfNames == 2) //if maleOrFemale is 2 and the order is 2, these
      //if statements are used
    {
      strcpy_s(fullName, "The "); //"The" is copied first into fullName array
      strcat_s(fullName, charDesc[whichDesc]);//randomly chosen descriptor is
      //concatenated into fullName
      //array
      strcat_s(fullName, " "); //a space is concatenated into fullName array
      strcat_s(fullName, femaleCharNames[whichName]);//randomly generated female
      //name is copied into
      //fullName array
      strcpy_s(firstName, femaleCharNames[whichName]);//the character's first name
      //is also copied into
      //firstName 
    }
  }

  cout << "Name: " << fullName << "\n" << endl; //the fully generated name is
  //now printed out

  //Attributes Generation ------------------------------------------------------
  attributeGenerator(attributeValues, descriptorAttributes, totalValue,
    validStats); //attributeGenerator sub program is called (line 79)

  //Total value integer is passed by reference and checked here:
  if (totalValue >= 15 && totalValue <= 35)
  { //if the integer "totalValue" is between 15 and 35
    validStats = true; //the stats are valid and are outputted below
  }//if ends
  else
  {
    while (totalValue < 15 || totalValue > 35)
    {//if any other values are returned, the subprogram is run again until
      //valid results are generated - this slows the program down and may
      //make it appear to hang
      attributeGenerator(attributeValues, descriptorAttributes, totalValue,
        validStats); //sub program is called again
    }
  }

  //Attributes are printed out here using different locations of the
  //descriptorAttributes char array, which matches values from
  //attributeValues:
  cout << "Their strength is: " << descriptorAttributes[0] << endl;
  cout << "Their agility is: " << descriptorAttributes[1] << endl;
  cout << "Their toughness is: " << descriptorAttributes[2] << endl;
  cout << "Their intelligence is: " << descriptorAttributes[3] << endl;
  cout << "Their charisma is: " << descriptorAttributes[4] << endl;

  //Sentence Generation --------------------------------------------------------

  ///////////////////////////////////////////////////////////////////////////////
  //Sentence One/////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////
  //Sentence 1, Option 1 is concatenated:
  strcat_s(locationOptionOne, sentenceLength, firstName);
  strcat_s(locationOptionOne, sentenceLength, " was born in ");
  strcat_s(locationOptionOne, sentenceLength, location[whichDesc]); //random
  //location is picked using integer generated in whichDesc
  strcat_s(locationOptionOne, sentenceLength, ".");
  //Full stops are concatenated at the end of options, and spaces are added at
  //the start of the next sentences. For example, Sentence 1s end its concats
  //with full stops, and Sentence 2s start their concatenation with a space

  //Sentence 1, Option 2 is concatenated:
  strcat_s(locationOptionTwo, sentenceLength, "Descending from ");
  strcat_s(locationOptionTwo, sentenceLength, location[whichDesc]);
  strcat_s(locationOptionTwo, sentenceLength, ", ");
  strcat_s(locationOptionTwo, sentenceLength, firstName);//firstName is added
  //as opposed to using fullName
  strcat_s(locationOptionTwo, sentenceLength, " has wandered aimlessly for");
  strcat_s(locationOptionTwo, sentenceLength, " years.");

  //Sentence 1, Option 3 is concatenated:
  strcat_s(locationOptionThree, sentenceLength, "Nobody quite knows where ");
  strcat_s(locationOptionThree, sentenceLength, firstName);
  strcat_s(locationOptionThree, sentenceLength, " came from. Some say ");
  if (maleOrFemale == 1)//if loop is used to concatenate the correct word baed
    //on the character's gender
  {
    strcat_s(locationOptionThree, sentenceLength, "he");
    //if the gender is 1 (male), then "he" is concatenated into the option
  }
  else if (maleOrFemale == 2)
  {
    strcat_s(locationOptionThree, sentenceLength, "she");
    //if the gender is 2 (female), then "she" is concatenated into the option
  }
  strcat_s(locationOptionThree, sentenceLength, "'s from ");
  strcat_s(locationOptionThree, sentenceLength, location[whichDesc]);
  strcat_s(locationOptionThree, sentenceLength, ", while others say ");
  if (maleOrFemale == 1)
  {
    strcat_s(locationOptionThree, sentenceLength, "he ");
    //if the gender is 1 (male), then "he" is concatenated into the option
  }
  else if (maleOrFemale == 2)
  {
    strcat_s(locationOptionThree, sentenceLength, "she ");
    //if the gender is 2 (female), then "she" is concatenated into the option
  }
  strcat_s(locationOptionThree, sentenceLength, "arose from a bottomless ");
  strcat_s(locationOptionThree, sentenceLength, "pit one stormy night.");

  ////////////////////////////////////////////////////////////////////
  //Sentence 1 Generator - this is where sentence 1 is randomly picked 
  //and stored in another array. The sentence is picked by the integer
  //locationOption, which calls a subprogram that generates a random
  //number between 1 and 3. 
  if (locationOption == 1) //If the number generated is 1, this is valid:
  {
    strcat_s(locationSentence, sentenceLength, locationOptionOne);
    //Option 1 is concatenated into locationSentence using the size of
    //sentenceLength
  }
  else if (locationOption == 2) //If the number generated is 2, this is valid:
  {
    strcat_s(locationSentence, sentenceLength, locationOptionTwo);
    //Option 2 is concatenated into locationSentence using the size of
    //sentenceLength
  }
  else if (locationOption == 3) //If the number generated is 3, this is valid:
  {
    strcat_s(locationSentence, sentenceLength, locationOptionThree);
    //Option 3 is concatenated into locationSentence using the size of
    //sentenceLength
  }

  ///////////////////////////////////////////////////////////////////////////////
  //Sentence Two/////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////
  //Sentence 2, Option 1 is concatenated:
  strcpy_s(classOptionOne, sentenceLength, " From an early age, ");
  //Concatenation is started with a space in the c-string in order to format
  //the text correctly when it is printed out
  strcat_s(classOptionOne, sentenceLength, firstName);
  strcat_s(classOptionOne, sentenceLength, " has trained hard to become a ");
  strcat_s(classOptionOne, sentenceLength, classOfChar[whichDesc]);
  strcat_s(classOptionOne, sentenceLength, ".");

  //Sentence 2, Option 2 is concatenated:
  strcat_s(classOptionTwo, sentenceLength, " Despite ");
  if (maleOrFemale == 1)
  {
    strcat_s(classOptionTwo, sentenceLength, "his ");
    //if the gender is 1 (male), then "his" is concatenated into the option
  }
  else if (maleOrFemale == 2)
  {
    strcat_s(classOptionTwo, sentenceLength, "her ");
    //if the gender is 2 (female), then "her" is concatenated into the option
  }
  strcat_s(classOptionTwo, sentenceLength, "parent's interests, ");
  strcat_s(classOptionTwo, sentenceLength, firstName);
  strcat_s(classOptionTwo, sentenceLength, " was mesmerized by the ");
  strcat_s(classOptionTwo, sentenceLength, classOfChar[whichDesc]);
  strcat_s(classOptionTwo, sentenceLength, " way of life and trained hard ");
  strcat_s(classOptionTwo, sentenceLength, "to learn its ways.");

  //Sentence 2, Option 3 is concatenated:
  strcat_s(classOptionThree, sentenceLength, " People know ");
  strcat_s(classOptionThree, sentenceLength, firstName);
  strcat_s(classOptionThree, sentenceLength, " as ");
  strcat_s(classOptionThree, sentenceLength, fullName);
  strcat_s(classOptionThree, sentenceLength, ". Many couldn't put ");
  if (maleOrFemale == 1)
  {
    strcat_s(classOptionThree, sentenceLength, "him ");
    //if the gender is 1 (male), then "him" is concatenated into the option
  }
  else if (maleOrFemale == 2)
  {
    strcat_s(classOptionThree, sentenceLength, "her ");
    //if the gender is 2 (female), then "her" is concatenated into the option
  }
  strcat_s(classOptionThree, sentenceLength, "into a traditional class!");

  ////////////////////////////////////////////////////////////////////
  //Sentence 2 Generator - this is where sentence 2 is randomly picked 
  //and stored in another array. The sentence is picked by the integer
  //locationOption, which calls a subprogram that generates a random
  //number between 1 and 3. 
  if (classOption == 1)
  {
    strcat_s(classSentence, sentenceLength, classOptionOne);
    //Option 1 is concatenated into classSentence using the size of
    //sentenceLength
  }
  else if (classOption == 2)
  {
    strcat_s(classSentence, sentenceLength, classOptionTwo);
    //Option 2 is concatenated into classSentence using the size of
    //sentenceLength
  }
  else if (classOption == 3)
  {
    strcat_s(classSentence, sentenceLength, classOptionThree);
    //Option 3 is concatenated into classSentence using the size of
    //sentenceLength
  }

  ///////////////////////////////////////////////////////////////////////////////
  //Sentence Three///////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////
  //Sentence 3, Option 1 is concatenated:
  strcat_s(personalityOptionOne, sentenceLength, " ");
  strcat_s(personalityOptionOne, sentenceLength, firstName);
  strcat_s(personalityOptionOne, sentenceLength, " is said to be ");
  strcat_s(personalityOptionOne, sentenceLength, personality[whichDesc]);
  strcat_s(personalityOptionOne, sentenceLength, " and the majority of ");
  strcat_s(personalityOptionOne, sentenceLength, "people seem to agree.");

  //Sentence 3, Option 2 is concatenated:
  strcat_s(personalityOptionTwo, sentenceLength, " Influenced by ");
  if (maleOrFemale == 1)
  {
    strcat_s(personalityOptionTwo, sentenceLength, "his ");
    //if the gender is 1 (male), then "his" is concatenated into the option
  }
  else if (maleOrFemale == 2)
  {
    strcat_s(personalityOptionTwo, sentenceLength, "her ");
    //if the gender is 2 (female), then "her" is concatenated into the option
  }
  strcat_s(personalityOptionTwo, sentenceLength, "parents, ");
  strcat_s(personalityOptionTwo, sentenceLength, firstName);
  strcat_s(personalityOptionTwo, sentenceLength, " has always been ");
  strcat_s(personalityOptionTwo, sentenceLength, personality[whichDesc]);
  strcat_s(personalityOptionTwo, sentenceLength, ".");

  //Sentence 3, Option 3 is concatenated:
  strcat_s(personalityOptionThree, sentenceLength, " While ");
  strcat_s(personalityOptionThree, sentenceLength, firstName);
  strcat_s(personalityOptionThree, sentenceLength, " seems to be ");
  strcat_s(personalityOptionThree, sentenceLength, personality[whichDesc]);
  strcat_s(personalityOptionThree, sentenceLength, ", rumor has it ");
  strcat_s(personalityOptionThree, sentenceLength, "everything may not be");
  strcat_s(personalityOptionThree, sentenceLength, " as it seems...");

  /////////////////////////////////////////////////////////////////////
  //Sentence 3 Generator - this is where sentence 3 is randomly picked 
  //and stored in another array. The sentence is picked by the integer
  //locationOption, which calls a subprogram that generates a random
  //number between 1 and 3. 
  if (personalityOption == 1)
  {
    strcat_s(personalitySentence, sentenceLength, personalityOptionOne);
    //Option 1 is concatenated into personalitySentence using the size of
    //sentenceLength
  }
  else if (personalityOption == 2)
  {
    strcat_s(personalitySentence, sentenceLength, personalityOptionTwo);
    //Option 2 is concatenated into personalitySentence using the size of
    //sentenceLength
  }
  else if (personalityOption == 3)
  {
    strcat_s(personalitySentence, sentenceLength, personalityOptionThree);
    //Option 3 is concatenated into personalitySentence using the size of
    //sentenceLength
  }

  //////////////////////////////////////////////////////////////////////////////
  //Sentence Four///////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  //Sentence 4, Option 1 is concatenated:
  strcpy_s(achievementOptionOne, sentenceLength, " A personal high point for ");
  strcat_s(achievementOptionOne, sentenceLength, firstName);
  strcat_s(achievementOptionOne, sentenceLength, " was ");
  strcat_s(achievementOptionOne, sentenceLength, achievement[whichDesc]);
  strcat_s(achievementOptionOne, sentenceLength, ".");

  //Sentence 4, Option 2 is concatenated:
  strcat_s(achievementOptionTwo, sentenceLength, " ");
  strcat_s(achievementOptionTwo, sentenceLength, firstName);
  strcat_s(achievementOptionTwo, sentenceLength, " has always dreamed of ");
  strcat_s(achievementOptionTwo, sentenceLength, achievement[whichDesc]);
  strcat_s(achievementOptionTwo, sentenceLength, ", but then ");
  if (maleOrFemale == 1)
  {
    strcat_s(achievementOptionTwo, sentenceLength, "he ");
    //if the gender is 1 (male), then "he" is concatenated into the option
  }
  else if (maleOrFemale == 2)
  {
    strcat_s(achievementOptionTwo, sentenceLength, "she ");
    //if the gender is 2 (female), then "she" is concatenated into the option
  }
  strcat_s(achievementOptionTwo, sentenceLength, "took an arrow ");
  strcat_s(achievementOptionTwo, sentenceLength, "to the knee...");

  //Sentence 4, Option 3 is concatenated:
  strcat_s(achievementOptionThree, sentenceLength, " Alas, ");
  strcat_s(achievementOptionThree, sentenceLength, firstName);
  strcat_s(achievementOptionThree, sentenceLength, " has not yet ");
  strcat_s(achievementOptionThree, sentenceLength, "accomplished anything ");
  strcat_s(achievementOptionThree, sentenceLength, "noteworthy...");

  ////////////////////////////////////////////////////////////////////  
  //Sentence 4 Generator - this is where sentence 4 is randomly picked 
  //and stored in another array. The sentence is picked by the integer
  //locationOption, which calls a subprogram that generates a random
  //number between 1 and 3. 
  if (achievementOption == 1)
  {
    strcat_s(achievementSentence, sentenceLength, achievementOptionOne);
    //Option 1 is concatenated into achievementSentence using the size of
    //sentenceLength
  }
  else if (achievementOption == 2)
  {
    strcat_s(achievementSentence, sentenceLength, achievementOptionTwo);
    //Option 2 is concatenated into achievementSentence using the size of
    //sentenceLength
  }
  else if (achievementOption == 3)
  {
    strcat_s(achievementSentence, sentenceLength, achievementOptionThree);
    //Option 3 is concatenated into achievementSentence using the size of
    //sentenceLength
  }

  ///////////////////////////////////////////////////////////////////////////////
  //Sentence Five////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////
  //Sentence 5, Option 1 is concatenated:
  strcat_s(hobbiesOptionOne, sentenceLength, " Despite ");
  strcat_s(hobbiesOptionOne, sentenceLength, firstName);
  strcat_s(hobbiesOptionOne, sentenceLength, "'s impression ");
  if (maleOrFemale == 1)
  {
    strcat_s(hobbiesOptionOne, sentenceLength, "he ");
    //if the gender is 1 (male), then "he" is concatenated into the option
  }
  else if (maleOrFemale == 2)
  {
    strcat_s(hobbiesOptionOne, sentenceLength, "she ");
    //if the gender is 2 (female), then "she" is concatenated into the option
  }
  strcat_s(hobbiesOptionOne, sentenceLength, "has always loved");
  strcat_s(hobbiesOptionOne, sentenceLength, activity[whichDesc]);
  strcat_s(hobbiesOptionOne, sentenceLength, ".");

  //Sentence 5, Option 2 is concatenated:
  strcat_s(hobbiesOptionTwo, sentenceLength, " With hatred in ");
  if (maleOrFemale == 1)
  {
    strcat_s(hobbiesOptionTwo, sentenceLength, "his ");
    //if the gender is 1 (male), then "his" is concatenated into the option
  }
  else if (maleOrFemale == 2)
  {
    strcat_s(hobbiesOptionTwo, sentenceLength, "her ");
    //if the gender is 2 (female), then "her" is concatenated into the option
  }
  strcat_s(hobbiesOptionTwo, sentenceLength, "eyes, ");
  strcat_s(hobbiesOptionTwo, sentenceLength, firstName);
  strcat_s(hobbiesOptionTwo, sentenceLength, " cannot stand the chore of");
  strcat_s(hobbiesOptionTwo, sentenceLength, activity[whichDesc]);
  strcat_s(hobbiesOptionTwo, sentenceLength, ".");

  //Sentence 5 has no option 3 - a space is written into hobbiesSentence
  //in this case, resulting in no sentence and only the space being
  //printed if 'hobbyOption == 3'.

  ////////////////////////////////////////////////////////////////////
  //Sentence 5 Generator - this is where sentence 5 is randomly picked
  //and stored in another array. The sentence is picked by the integer
  //locationOption, which calls a subprogram that generates a random
  //number between 1 and 3. 
  if (hobbyOption == 1)
  {
    strcat_s(hobbiesSentence, sentenceLength, hobbiesOptionOne);
    //Option 1 is concatenated into hobbiesSentence using the size of
    //sentenceLength
  }
  else if (hobbyOption == 2)
  {
    strcat_s(hobbiesSentence, sentenceLength, hobbiesOptionTwo);
    //Option 2 is concatenated into hobbiesSentence using the size of
    //sentenceLength
  }
  else if (hobbyOption == 3)
  {
    strcat_s(hobbiesSentence, sentenceLength, " ");
    //A space is concatenated into hobbiesSentence using the size of
    //sentenceLength
  }
  //Backstory Generator - concatenates entire backstory into one array - fullBio
  //Each sentence is already formatted and can therefore be concatenated into
  //the array:
  strcat_s(fullBio, sentenceLength, locationSentence);
  strcat_s(fullBio, sentenceLength, classSentence);
  strcat_s(fullBio, sentenceLength, personalitySentence);
  strcat_s(fullBio, sentenceLength, achievementSentence);
  strcat_s(fullBio, sentenceLength, hobbiesSentence);
  cout << "" << endl; //a line gap is left
  cout << fullName << "'s backstory is:" << endl;
  cout << fullBio << endl; //the character's backstory is printed out

  cout << "\n" << "\n" << endl; //new line escape sequences used to leave space
                                //following the generation of the backstory

  system("PAUSE"); //used to pause the generator and require to key presses
                   //to exit
} //program end