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
	bool special1[3] = {0,0,0}, special2[3] = {0,0,0}, special3[3] = {0,0,0};



	

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

		{"e1","Veggie Burger"}, //0
		{"e2","Falafel Wrap",}, //1
		{"e3","Salami Sandwich"}, //2
		{"s1","French Fries"}, //3
		{"s2","Hummus with Pita Chips"}, //4
		{"s3","Celery and Carrots"}, //5
		{"b1","Tap Water"}, //6
		{"b2","Sparkling Water"}, //7
		{"b3","Domestic Beer"}, //8
		{"b4","Imported Beer"}, //9
		{"b5","Red Wine"}, //10
		{"b6","White Wine"}, //11
		{"b7","Coffee"}, //12
		{"b8","Tea"}}; //13
	
	
	for(int j=0; j<3; j++){
		bool founditem = false;
		for(int i = 0; i<14; i++){
			if(selections[j].compare(items[i][0]) == 0){
				founditem=true;
				price += cost(items[i][0]);
				indeces.push_back(i);

				if(i==0){special1[0] = 1;}
				else if(i==1){special2[0] = 1;}
				else if(i==2){special3[0] = 1;}
				else if(i==3){
					special1[1] = 1;
					special3[1] = 1;}
				else if(i==4){
					special2[1] = 1;
					special3[1] = 1;}
				else if(i==5){special3[1] = 1;}
				else if(i==6 || i==7){special1[2] = 1;}
				else if(i==8 || i==9 || i ==10 || i==11){special3[2] = 1;}
				else if(i==12 || i==13){
					special1[2] = 1;
					special2[2] = 1;}

				
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

	if(special1[0] && special1[1] && special1[2]){price = 8;}
	else if(special2[0] && special2[1] && special2[2]){price = 7;}
	else if(special3[0] && special3[1] && special3[2]){price = 13;}


	std::cout << "You ordered a " << item1 << " with " << item2 << " and with " << item3 << ". Your cost is $" << price <<"." << std::endl;


	return 0;


}
