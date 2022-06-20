//File: treasureHunt.cpp
//Author: Robert
//Date: 4/30/2022
//About: Making a treasure hunt game using a true 2d array

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

//Helper function to make it easier to print out the board
void printArray(int myArr[][8]){
  for(int i = 0;i < 8; i++){
    for(int j = 0; j < 8; j++){
      printf("[%d]",myArr[i][j]);
    }
    printf("\n");
  }
}

//Show method which will be used to hide to computer's board
void show(const int myArr[][8]){
  char charArr[8][8];

  //loop through the 2d array
  for(int i = 0; i < 8;i++){
    printf("[");
    for(int j = 0; j < 8; j++) {

      //if statements to change characters in the 2d array
      if(myArr[i][j] == -1) {
        charArr[i][j] = 'X';
      }
      else if (myArr[i][j] >= 0) {
        charArr[i][j] = '-';
      }
      else if(myArr[i][j] < 0) {
        charArr[i][j] = '@';
      }

      printf("[%c]",charArr[i][j]);
    }
    printf("],\n");
  }
  
}

//This method will be used to place the chest
void setByOffset(int myArr[][8], int row, int col, int value, int length,char c){


  //set the elements to a certain value given the length horizontally
  if(c == 'h'){
    for(int x = 0; x < length; x++){

      myArr[row][col+x] = value;
    }
  } 
  //set the elements to a certain value given the length vertically
  else if(c == 'v'){
    for(int y = 0; y < length; y++){

      myArr[row + y][col] = value;
      
    }
  }


}  

//checks if chest length is vertical or horizontal and goes out of
//bounds and if there is a chest already
bool checkPlacement(int myArr[][8],const int row, const int col, const int length, const char c) {

  //h is for horizontal, checks if it goes out of bounds if the given col + length
  //is out of bounds
  if(c == 'v'){
    if(row + length > 8){

      printf("Placement out of bounds!\n");
      
      return false;
    }
    //To check if there is a chest already
    for(int i = 0; i < length; i++){
      
      if(myArr[row+i][col] == 11||
        myArr[row+i][col] == 12 ||
        myArr[row+i][col] == 13 ||
        myArr[row+i][col] == 14 ||
        myArr[row+i][col] == 15) {

        printf("There is already a chest!");
        return false;
        
      }
    }
    
  } 
  //similar case if its 'h' for horizontal
  else if(c == 'h'){
    if(col + length > 8){

      printf("Placement out of bounds!\n");
      
      return false;
    }
    //check if there is a chest already
    for(int j = 0; j < length; j++){
      
      if(myArr[row][col+j] == 11||
        myArr[row][col]+j == 12 ||
        myArr[row][col+j] == 13 ||
        myArr[row][col+j] == 14 ||
        myArr[row][col+j] == 15) {

        printf("There is already a chest!\n");
        
        return false;
      }
    }
  }
  return true;
}

//places the chest on the board
bool placeChest(int myArr[][8], const int row, const int col,
                const int value, const int length, const char c) {

  //First check if the chest is at a valid location if its put
  if(checkPlacement(myArr,row,col,length,c) == true) {
    
    setByOffset(myArr, row, col , value, length, c);
    printf("The treasure has been placed!\n");

    return true;
  } 

  return false;
}

//this function sets up five valid placements for the computers board
void computer_setup(int computer_Arr[][8]){
  //while the 5 chests is not placed in the computers board

  int computer_Length = 0;
  char computer_Direction;
  int chestPieces = 5;

  srand(time(NULL));
  
  while(chestPieces != 0){
      int computer_Row = rand() % 8;
      int computer_Col = rand() % 8;
      int computer_Chest = rand() % 5 + 11;
      int computer_Direction = rand() % 2 + 1;

      int myRow;
      int myCol;
      int myChest;
      char myDirection;
    
      if(computer_Direction == 1){
        computer_Direction = 'h';
      
      } else {
        computer_Direction = 'v';
      }
      if(computer_Chest == 11){
        computer_Length = 5;
      } 
      else if (computer_Chest == 12){
        computer_Length = 4;
      }
      else if (computer_Chest == 13){
        computer_Length = 3;
      }
      else if (computer_Chest == 14){
        computer_Length = 2;
      }
      else if (computer_Chest == 15){
        computer_Length = 1;
      }

      //checks the placement of the randomly placed chest, if its valid, take one 
      //off of the chestPieces
      if(checkPlacement(computer_Arr,computer_Row,computer_Col,computer_Length,computer_Direction) == true){
        placeChest(computer_Arr,computer_Row,computer_Col,computer_Chest,computer_Length,computer_Direction);
        chestPieces--;
      }
  }  
}

//This function sets up five valid chest placements for my board
void my_setup(int arr[][8]){

  int myLength = 0;
  char myDirection;
  int myChestPieces = 5;
  
  while(myChestPieces != 0){
      //local variables to store input
      int myRow;
      int myCol;
      int myChest;
      char myDirection;
      int direction;
    
      printf("\nEnter your row (1 to 8): ");
      scanf("%d", &myRow);
      printf("Enter your column (1 to 8): ");
      scanf("%d", &myCol);
      printf("Enter the value assigned with the chest you will place( 11 to 15): ");
      scanf("%d", &myChest);
      printf("Enter your direction (1 for horizontal, 2 for vertical): ");
      scanf("%d", &direction);

      //if statements for direction and chest 
      if(direction == 1){
        myDirection = 'h';
      
      } else {
        myDirection = 'v';
      }

      if(myChest == 11){
        myLength = 5;
      } 
      else if (myChest == 12){
        myLength = 4;
      }
      else if (myChest == 13){
        myLength = 3;
      }
      else if (myChest == 14){
        myLength = 2;
      }
      else if (myChest == 15){
        myLength = 1;
      } else {
        printf("Enter a valid value!");
      }

      //check if placements is valid, if it is valid, reduce myChestPieces by 1
      if(checkPlacement(arr,myRow-1,myCol-1,myLength,myDirection) == true){
        placeChest(arr,myRow-1,myCol-1,myChest,myLength,myDirection);
        myChestPieces--;

        printf("\n\n");
      } else {
        printf("\nPlace the chest at a valid location!\n");
      }
  }  
}

//This method is SETTING UP THE BOARDS
void setup(int arr[][8] ,int computer_Arr[][8])  {
  //bunch of local variables to keep track because only 5 chests 
  //should be placed on both the computer and my board

  int myLength = 0;
  char myDirection;
  int myChestPieces = 5;
  
  computer_setup(computer_Arr);

  my_setup(arr);

  //prints your board and shows computer board 
  printf("Your Board\n");
  printArray(arr);
  printf("\n\nComputer Board\n");
  show(computer_Arr);
  
}
  

//Helper function that takes in 2D array paremeter and checks if there is any
//positive values in the array which would mean a undugged chest.
bool checkWinners(int myArr[][8]){

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(myArr[i][j] > 0){
        return false;
      }
    }
  }
  
  return true;
  
}

//Reveal would be used when a winner has been chosen so that you can see the
//spots that weren't dug yet that had treasure
void reveal(const int myArr[][8]){

  char charArr[8][8];
  for(int i = 0; i < 8;i++){
    printf("[");
    for(int j = 0; j < 8; j++) {

      //manually use several if statment
      //Capital letters mean it has been dug, small letter means not digged
      if(myArr[i][j] == -1) {
        charArr[i][j] = 'X';
      }
      else if (myArr[i][j] >= 11 && myArr[i][j] <= 15) {
        if(myArr[i][j] == 11) charArr[i][j] = 'a';
        else if(myArr[i][j] == 12) charArr[i][j] = 'b';
        else if(myArr[i][j] == 13) charArr[i][j] = 'c';
        else if(myArr[i][j] == 14) charArr[i][j] = 'd';
        else if(myArr[i][j] == 15) charArr[i][j] = 'e';
      }
      else if(myArr[i][j] <= -11 && myArr[i][j] >= -15) {
        if(myArr[i][j] == -11) charArr[i][j] = 'A';
        else if(myArr[i][j] == -12) charArr[i][j] = 'B';
        else if(myArr[i][j] == -13) charArr[i][j] = 'C';
        else if(myArr[i][j] == -14) charArr[i][j] = 'D';
        else if(myArr[i][j] == -15) charArr[i][j] = 'E';
      } else {

        charArr[i][j] = '-';
      }

      printf("[%c]",charArr[i][j]);
    }
    printf("],\n");
  }
}

//This is used to dig a spot in the boards
void dig(int myArr[][8],const int row , const int col){

  
  for(int i = 0; i < 8; i++){
    

    for(int j = 0; j < 8; j++){

      
      if(i == row && j == col ){
        
        if(myArr[row][col] == 0) {

          myArr[row][col] = -1;

        
        }
        //changes any postive numbers to a negative
        else if (myArr[row][col] > 0) {
  
          myArr[row][col] = myArr[row][col] * -1;
        } else {

          printf("You have already dug that spot!");
        }
        
      } 

      

    }
  }
}

//The main method to play the game that uses input to dig at a specified location
void play(int computer_Arr[][8], int arr[][8]) {
  
  bool winner = false;
  
  printf("\nWELCOME TO THE TREASURE HUNT!!!!!\n\n");
  //First sets up the two boards
  setup(arr,computer_Arr);

  //winner is initally false but if there is a winner, when we checkWinners at the
  //end then winner will become true
  while(winner == false) {

    int inputRow;
    int inputCol;
    int computer_Row = rand() % 8;
    int computer_Col = rand() % 8;

    //dig at a random spot for the computer
    dig(arr, computer_Row, computer_Col);
    
    //input statments for row and column to dig on the computer board
    printf("\nWhere would you like to dig?\n\n");
    
    printf("Enter the row you want to dig (1 - 8): ");
    scanf("%d", &inputRow);
    
    printf("Enter the column you want to dig (1 - 8): ");
    scanf("%d", &inputCol);    

    //loses a turn if coordinates were out of the board
    if(inputCol > 8 || inputCol < 1 || inputRow > 8 || inputRow < 1){
      printf("\nYou lose a turn! Dig at a valid location!\n");
    }

    //dig at your wanted coordinate on the computer's board
    dig(computer_Arr, inputRow - 1, inputCol - 1);

    //printing out your board
    printf("\nYour Board \n");
    printArray(arr);


    //showing computers board
    printf("\nComputer Board\n");
    show(computer_Arr);

    //After both you and the computer have dugged a spot, check if all the
    //chests have been found, and if its all found, declare the winner and make 
    //change winner to be true and break out of the while loop and end the game
    
    if(checkWinners(arr) == true){
      printf("\nYOU LOST, COMPUTER WON!\n");
      winner = true;
      printf("\n\nComputer Board revealed!\n\n");
      reveal(computer_Arr);
      printf("\n\nYour Board revealed!\n\n");
      reveal(arr);
    }
    else if(checkWinners(computer_Arr) == true){
      printf("\nYOU WON, COMPUTER LOST!!\n");
      winner = true;
      printf("\n\nComputer Board revealed!\n\n");
      reveal(computer_Arr);
      printf("\n\nYour Board revealed!\n\n");
      reveal(arr);
    }
    

 }
  
}


int main(int argc, char** argv) {


  //Initialized an 8 by 8 2d array filled with zeros for both arr and computer_Arr

  int arr[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
  
  int computer_Arr[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};



  play(computer_Arr,arr);


}