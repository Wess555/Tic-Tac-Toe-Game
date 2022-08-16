// Import Built in Libraries.
#include <iostream>
#include <string>

using namespace std;
	//Array for the board.
	char position[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	//Variables Declaration.
	int row,column;
	bool tie =false;
	char sign='x';
	
// Function that displays the board.	
void Display()
{
	cout<<"    |     |    "<<endl;
	cout<<" "<<position[0][0]<<"  |   "<<position[0][1]<<" |  "<<position[0][2]<<endl;
	cout<<"____|_____|____"<<endl;
	cout<<"    |     |    "<<endl;
	cout<<" "<<position[1][0]<<"  |   "<<position[1][1]<<" |  "<<position[1][2]<<endl;
	cout<<"____|_____|____"<<endl;
	cout<<"    |     |    "<<endl;
	cout<<" "<<position[2][0]<<"  |   "<<position[2][1]<<" |  "<<position[2][2]<<endl;

}
//Function that will allow player to pick a position on the board from 1 to 9 then assign the sign to the picked position.
void Playerchoice(string name1,string name2)
{
	int choice;
	
	if(sign=='x')
	{
		cout<<name1<<"  Please Enter Position "<<endl;
		cin>>choice;
		cin.ignore();
	}
	
	if(sign=='0')
	{
		cout<<name2<<"  Please Enter Position "<<endl;
		cin>>choice;
		cin.ignore();
	}
			

	switch(choice)
	{
		case 1: row=0;column=0 ;break;
		case 2: row=0;column=1 ;break;
		case 3: row=0;column=2 ;break;
		case 4: row=1;column=0 ;break;
		case 5: row=1;column=1 ;break;
		case 6: row=1;column=2 ;break;
		case 7: row=2;column=0 ;break;
		case 8: row=2;column=1 ;break;
		case 9: row=2;column=2 ;break;
		default:
			cout<<"Invalid Choice"<<endl; 
	}
	
	if(sign=='x' && position[row][column]!='x'&& position[row][column]!='0')
	{
		position[row][column]='x';
		sign='0';  //enables the players to take turns.
	}
	else if (sign=='0' && position[row][column]!='x' && position[row][column]!='0')
	{
		position[row][column]='0';
		sign='x';
	}
	else
	{
		cout<<"Position is taken Please pick another one"<<endl;
	}


}

//Function to check the result of the game.
bool Result()
{	
	//check the columns and rows results.
	for (int i=0;i<3;i++)
	{
		if(position[i][0]==position[i][1] && position[i][0]==position[i][2] || position[0][i]==position[1][i] && position[0][i]==position[2][i])
		return false;
	}
	//Check the diagonal result.
		if (position[0][0]==position[1][1] && position[0][0]==position[2][2] || position[2][0]==position[1][1] && position[2][0]==position[0][2])
		return false;
		
	// Continue playing if condition is met.
 	for (int i=0;i<3;i++)
	{	for(int j=0;j<3;j++)
		{
			if(position[i][j]!='x' && position[i][j]!='0')
			return true;
		}
			
	}

	tie=true;	//will break out of the game if none of the conditions are met.
	return false;
}
//Program Main Method.

int main ()
{
	string name1,name2;
	char ans;

	cout<<"Player One Enter Name :"<<endl;
	getline(cin,name1);

	cout<<"Player Two Enter Name :"<<endl;
	getline(cin,name2);
	
	//While no win or no tie:
	while(Result())
		{
			Display();
			Playerchoice(name1,name2);
			Result();
		}
	
	if (sign=='x' && tie==false)
	{
		cout<< name2<<" Congratulations You Won!!!!!"<<endl;
	}

	else if (sign=='0' && tie==false)
	{
		cout<< name1<<" Congratulations You Won!!!!!"<<endl;
	}

	//Will occur if all position are taken and no player won: tie==true.
	else 
	cout<<"It is a Tie!"<<endl;
	
	return 0;
}
