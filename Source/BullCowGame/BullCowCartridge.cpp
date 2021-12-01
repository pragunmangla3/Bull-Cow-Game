// Fill out your copyright notice in the Description page of Project Settings.

#include "BullCowCartridge.h"
#include "HiddenWordList.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();
    PrintLine(TEXT("The number of possible words is %i."), Words.Num());
    //PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord);  // Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    
    if(bGameOver){
        ClearScreen();
        SetupGame();
    }
    else{

        ProcessGuess(Input);

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

    const TCHAR HW[] = TEXT("cakes") ;

}

void UBullCowCartridge::EndGame(){

    
    bGameOver = true;
    PrintLine(TEXT("\nHit Enter to continue.."));

}


void UBullCowCartridge::ProcessGuess(FString Guess){

        if(Guess==HiddenWord){

            PrintLine(TEXT("You have Won!"));
            EndGame();
            return;
        }



        if(HiddenWord.Len()!=Guess.Len()){
                
            PrintLine(TEXT("Sorry, try guessing again! \n You have %i Lives remaining"), Lives);
            PrintLine(TEXT("The Hidden word is %i letter long"), HiddenWord.Len());
            return;
        }


        if(!IsIsogram(Guess)){

            PrintLine(TEXT("No repeating letters, guess again"));
            return;

        }

        PrintLine(TEXT("Lost a life!"));
        --Lives;

        if(Lives<=0){

            ClearScreen();
            PrintLine(TEXT("You have no life.."));
            PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
            EndGame();
            return;
        }    
         
        PrintLine(TEXT("Guess again! \n You have %i Lives left"), Lives);
        
}

bool UBullCowCartridge::IsIsogram(FString Word) const{

    for(int32 Index{0} ; Index<Word.Len() ; Index++){

        for(int32 Comparison = Index+1; Comparison<Word.Len(); Comparison++){
            
            if(Word[Index] == Word[Comparison]){
                return false;
            }
        }


    }

    return true;
}