#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

int cost(std::string sel){

	std::string item = sel;

	int amt = 0;
	if (item.compare("e1") == 0){amt = 7;}
	else if (item.compare("e2") == 0){amt = 6;}
	else if (item.compare("e3") == 0){amt = 9;}
	else if (item.compare("s1") == 0){amt = 2;}
	else if (item.compare("s2") == 0){amt = 3;}
	else if (item.compare("s3") == 0){amt = 2;}
	else if (item.compare("b1") == 0){amt = 0;}
	else if (item.compare("b2") == 0){amt = 2;}
	else if (item.compare("b3") == 0){amt = 4;}
	else if (item.compare("b4") == 0){amt = 6;}
	else if (item.compare("b5") == 0){amt = 7;}
	else if (item.compare("b6") == 0){amt = 7;}
	else if (item.compare("b7") == 0){amt = 1;}
	else if (item.compare("b8") == 0){amt = 1;}

	return amt;
}


int main(void) {
	

	int price = 0;
	std::string item1 = "", item2 = "", item3 = "";
	std::vector<int> indeces;



	

	std::cout << "Please enter three selections from the following:" << std::endl
		       	<< "Entrees:" << std::endl 
			<< "e1. Veggie burger: $7" << std::endl
			<< "e2. Falafel wrap: $6" << std::endl
			<< "e3. Salami sandwich: $9" << std::endl
			<< std::endl
			<< "Sides : " << std::endl
			<< std::endl
			<< "s1. French fries. $2" << std::endl
			<< "s2. Hummus with pita chips. $3" << std::endl
			<< "s3. Celery and carrots $2" << std::endl
			<< std::endl
			<< "Beverages:" << std::endl
			<< std::endl
			<< "b1. Tap Water. Free of charge." << std::endl
			<< "b2. Sparkling water. $2" << std::endl
			<< "b3. Domestic beer. $4." << std::endl
			<< "b4. Imported beer. $6." << std::endl
			<< "b5. Red wine. $7." << std::endl
			<< "b6. White wine. $7." << std::endl
			<< "b7. Coffee. $1." << std::endl
			<< "b8. Tea. $1." << std::endl
			<< "___________________________________________________"
			<< "\n\n\n";

	std::string option = "";
	std::getline(std::cin, option);
	std::stringstream ss(option); 
	std::vector<std::string> selections;
	while (ss >> option){ selections.push_back(option); }


	if (selections.size() < 3){
		
		std::cout << "Please enter three options" << std::endl;
		return 0;	
	}

	std::string items[14][3] = {

		{"e1","Veggie Burger"},
		{"e2","Falafel Wrap",},
		{"e3","Salami Sandwich"},
		{"s1","French Fries"},
		{"s2","Hummus with Pita Chips"},
		{"s3","Celery and Carrots"},
		{"b1","Tap Water"},
		{"b2","Sparkling Water"},
		{"b3","Domestic Beer"},
		{"b4","Imported Beer"},
		{"b5","Red Wine"},
		{"b6","White Wine"},
		{"b7","Coffee"},
		{"b8","Tea"}};
	
	
	for(int j=0; j<3; j++){
		bool founditem = false;
		for(int i = 0; i<14; i++){
			if(selections[j].compare(items[i][0]) == 0){
				founditem=true;
				price += cost(items[i][0]);
				indeces.push_back(i);
				}
			}
		
		if(!founditem){
			indeces.push_back(6);
			if(j==0){item1 = "ITEM NOT FOUND";}
			else if(j==1){item2 = "ITEM NOT FOUND";}
			else if(j==2){item3 = "ITEM NOT FOUND";}
		}

		else {
			if (j==0) item1 = items[indeces[j]][1];
			else if (j==1) item2 = items[indeces[j]][1];
			else if (j==2) item3 = items[indeces[j]][1];
		}
	}




	std::cout << "You ordered a " << item1 << " with " << item2 << " and with " << item3 << ". Your cost is $" << price <<"." << std::endl;
	return 0;


}
