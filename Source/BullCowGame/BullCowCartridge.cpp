// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"



void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();
    //PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord);  // Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    
    if(bGameOver){
        ClearScreen();
        SetupGame();
    }
    else{

        if(Input==HiddenWord){
            PrintLine(TEXT("You have Won!"));
            EndGame();
        }
        else{

            PrintLine(TEXT("Lost a Life!"));
            PrintLine(TEXT("%i"), --Lives);
            if(Lives>0){
                
                if(HiddenWord.Len()!=Input.Len()){
                
                    PrintLine(TEXT("Sorry, try guessing again! \n You have %i Lives remaining"), Lives);
                }

            }
            else{
                PrintLine(TEXT("You have no life.."));
                EndGame();
            }
            
        }
    }


}

void UBullCowCartridge::SetupGame(){
    
    PrintLine(TEXT("welcome to the game !"));

    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len()); // Magic Number Remove
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Type in your guess and \nand Press enter to continue..."));
}

void UBullCowCartridge::EndGame(){

    
    bGameOver = true;
    PrintLine(TEXT("Hit Enter to continue.."));

}