// FatGramCalculator.cpp : Defines the entry point for the console application.
//

/*
Fat Gram Calculator � C++ p. 223
Write a program that asks for the number of calories and fat grams in a food.
The program should display the percentage of calories that come from fat.
If the calories from fat are less than 30% of the total calories of the food,
it should also display a message indicating that the food is low in fat.
One gram of fat has 9 calories, so

Calories from fat = fat grams * 9

The percentage of calories from fat can be calculated as

Calories from fat / total calories
Input Validation: Make sure the number of calories and fat grams are not less than 0.
Also the number of calories from fat cannot be greater than the total number of calories.
If that happens, display an error message indication that either the calories or fat grams were incorrectly entered.
*/

//So to reiterate (and to make copy and pasting the assignment into my program less like cheeting),
//the program is asking the user to enter the amount of fat and the amount of calories in some food item.
//The program will take those values and calculate the percent of calories from fat.
//To do this, the program asks the user for the calories in the food and for the fat in the good.
//calories from fat is then calculated by taking fat in grams times 9. 
//then calories from fat is devided by the total calories found in the food given my user input.
//This gives the percent of calories from fat for the food.

//Equations are: calories from fat = fat grams * 9 and percent fat calories = calroires from fat / total calories

//The program cannot have less than 0 calories and the calories from fat cannot exceed the total calories.
//An error message needs to be displayed if it is out of range stating they were incorrectly entered.
//If there are less than 30% calories from fat, tell the user that.


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Initialized variables
	double totalCalories = 0, //Input by the user and represents the total calories in the food.
		fatGrams = 0, //Input by the user and represents the grams of fat in the food.
		fatCalories = 0; //Calculated by multiplying fatGrams by 9 to find out the amount of calories from fat.

						 // Program introduction to users.

	cout << "\t        CALORIES VS CALORIES FROM FAT\n";
	cout << "\t*************************************************\n";
	cout << "\t  Calories provide a measure of how much\n";
	cout << "\t energy you get from a serving of this food.\n";
	cout << "\t Many Americans consume more calories than\n";
	cout << "\t they need without meeting recommended intakes\n";
	cout << "\t for a number of nutrients.  One gram of fat has\n";
	cout << "\t 9 calories. Foods with less than 30% calories\n";
	cout << "\t are considered low in fat.\n\n";
	cout << "\t This program will calculate the percentage of fat\n";
	cout << "\t in a food based on your input of total calories\n";
	cout << "\t and fat in grams.\n";
	cout << "\t*************************************************\n";

	//Prompt user to input total calories.
	//cout << "\n\tThis is a calculator provided to help users understand \n";
	//cout << "\twhat percentage of fat adds to their caloric intake.\n";//infoms user of programs intent.
	cout << "\n\tPlease enter the total calories present in your food: ";//promt user for total calories.
	cin >> totalCalories; //inputs total calories.

						  //Prompt user to input grams of fat.
	cout << "\n\n\tPlease enter the grams of fat present in your food: "; //prompt user for grams of fat.
	cin >> fatGrams; //inputs total calories.

					 //Calculate calories from fat
	fatCalories = fatGrams * 9;

	//validating input
	if (totalCalories < 0)// If total calories is a negative number it exicutes the error message
	{
		cout << "\n\n\n\tYou have entered a number less than 0 for total calories.\n";//informs user of erronious value.
		cout << "\tPlease find the total calories as a \n";
		cout << "\tpossitive integer and rerun the program.\n\n";//promts for a redu of the program.
	}

	//validating input
	else if (fatGrams < 0)//If fat grams is a negative number it exicutes the error message
	{
		cout << "\n\n\tYou have entered a number less than 0 for grams of fat.\n";//informs user of erronious value.
		cout << "\tPlease find the grams of fat as a \n";
		cout << "\tpossitive integer and rerun the program.\n\n";//promts for a second input of total calories.
	}

	//Validate that calories from fat is not larger than total calories and provide output if it is valid.
	else if (fatCalories > totalCalories)//compares fatCalories to totalCalories if fat calories is more than total calories it exicutes the error message
	{
		cout << "\n\n\tThere are more calories from fat than there are total calories.\n";//If fat calories are greater than total calories it 
		cout << "\tPlease take a moment to reconcider your \n";
		cout << "\tgrams of fat or your total calories and rerun the program.\n\n";//gives an error message and ends the program.
	}
	else//If totalCalories are greater than or equal to the fatCalories it displays the precent of calories from fat.
	{
		//declare an instance variable
		double percentFatCalories = 0; //Will hold a percent of calories per total calories.

									   //calculation of percent of fat calories
		percentFatCalories = fatCalories / totalCalories * 100;//divide fatCalories by total calories and we times it by 100 to create a percent

															   //format and display data
		cout << fixed << showpoint << setprecision(1); //Sets up the formating for the output.
		cout << "\n\n\tWith " << fatGrams << " grams of fat with " << totalCalories;//Displays the input by the user. Just in case.
		cout << " total calories,\n";
		cout << "\t" << percentFatCalories << "% of the calories come from fat.\n\n";//Displays the pertant percentage information

																					 //If the calories from fat are 30% or less it displays a low calories message.
		if (percentFatCalories < 30.0)
		{
			cout << "\tThis food is low in fat.\n\n";
			cout << "\tHurray! Less than 30% calories from fat.\n\tNow we can have cheese cake.\n\n";
		}

		//If the calories from fat are 30% or greater it displays a high calories message.
		if (percentFatCalories > 30.0)
		{
			cout << "\tThis food is high in fat.\n";
			cout << "\tBoo! more than 30% calories from fat.\n\tNow we need to cut back on cheese cake.\n\n";
			cout << "\tCut back on foods that are high in fat.\n\n";//A warning message
		}
	}


	return(0);
}