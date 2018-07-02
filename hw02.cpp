/*******************************************************************************
 * AUTHOR         : Samuel Vilchez
 * STUDENT ID     : 1078959
 * HOMEWORK #2    : Deck of Cards
 * CLASS          : CS1C
 * SECTION        : MTWTh 4:30 - 7:25pm
 * DUE DATE       : 6/14/2018
 ******************************************************************************/
#include"MyHeader.h"
/*******************************************************************************
 * DECK OF CARDS
 * -----------------------------------------------------------------------------
 * This program will simulate a deck of cards.
 * It will perform a couple shuffles and will indicate how many shuffles are
 * necessary for the deck to return to its original position
 * -----------------------------------------------------------------------------
 * INPUT
 * <no input for this program>
 *
 * OUTPUT
 * outputs the deck of cards dependent on the shuffle
 ******************************************************************************/
int main()
{
	bool perfectShuffles;   // CALC - determines when it returned to original
	int  numOfShuffles;     // CALC - how many shuffles it takes to original
	Deck myOriginalDeck;    // CALC & OUT - first deck to be shuffled
	Deck deckToBeShuffled;  // CALC & OUT - second deck to be shuffled

	cout << PrintHeader("Deck Of Cards", 'A', 2);
	
	//INITIALIZATION
	myOriginalDeck.InitializeDeckOfCards();
	deckToBeShuffled.InitializeDeckOfCards();

	//OUTPUT - orginial deck
	cout << "The original deck is: \n";
	myOriginalDeck.PrintDeckOfCards();
	cout << endl;

	//PROCESSING & OUTPUT - output after first shuffle
	cout << "The deck after the first perfect shuffle: \n";
	myOriginalDeck.PerformPerfectShuffle();
	myOriginalDeck.PrintDeckOfCards();

	//RE-INITIALIZE
	myOriginalDeck.InitializeDeckOfCards();

	//PROCESSING - check how many perfect shuffles until original
	numOfShuffles = 0;
	perfectShuffles = false;

	while(!perfectShuffles)
	{
		deckToBeShuffled.PerformPerfectShuffle();
		perfectShuffles = (myOriginalDeck == deckToBeShuffled);

		numOfShuffles++;
	}

	cout << endl << endl;

	//OUTPUT - final deck of cards
	cout << "FINAL DECK IN ITS ORGINAL POSITION:" << endl;
	deckToBeShuffled.PrintDeckOfCards();

	cout << "It took " << numOfShuffles << " shuffles "
			"for the deck to return to its original deck";
	cout << endl;

	return 0;
}


