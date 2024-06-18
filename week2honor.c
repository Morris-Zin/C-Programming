#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 52
#define MILLION 1000000
typedef enum suit
{
    heart,
    diamond,
    spade,
    club
} suit;

typedef struct card
{
    suit suit;
    short pips;
} card;

// initializing 52 decks
void initializeDeck(card cards[], int size)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < size; i++)
        for (int i = 0; i < size; i++)
        {
            // 2 to 14 pips
            cards[i].pips = rand() % 13 + 2;
            // 0 to 3, 0 being heart and 3 being club
            cards[i].suit = rand() % 4;
        }
}

void shuffleDeck(card cards[], int size)
{
    int i;
    srand(time(NULL));
    for (i = size - 1; i > 0; i--)
    {
        // first loop i = 51
        // generate number between 0 and 52
        int random = rand() % (i + 1);

        card temporary = cards[i];
        cards[i] = cards[random];
        cards[random] = temporary;
    }
}

void dealSevenCards(card cards[], int size)
{
    shuffleDeck(cards, size);
    // select first 7 cards from the shuffled cards;
    int i = 0, j = 0, k = 0;
    int noPair = 0;
    int onePair = 0;
    int twoPair = 0;
    int threeOfAKind = 0;
    int fullHouse = 0;
    int fourOfAKind = 0;
    for (j = 0; j < MILLION; j++)
    {

        int pairs = 0;
        int threes = 0;
        int fours = 0;
        // pips from 2 to 14
        int rankCount[14] = {0};
        for (i = 0; i < 7; i++)
        {
            rankCount[cards[i].pips]++;
        }
        for (int k = 2; k <= 14; k++)
        {
            if (rankCount[k] == 2)
            {
                pairs++;
            }
            else if (rankCount[k] == 3)
            {
                threes++;
            }
            else if (rankCount[k] == 4)
            {
                fours++;
            }
        }

        if (fours == 1)
        {
            fourOfAKind++;
        }
        else if (threes == 1 && pairs >= 1)
        {
            fullHouse++;
        }
        else if (threes == 1)
        {
            threeOfAKind++;
        }
        else if (pairs == 2)
        {
            twoPair++;
        }
        else if (pairs == 1)
        {
            onePair++;
        }
        else
        {
            noPair++;
        }
        shuffleDeck(cards, size); // Reshuffle the deck for the next hand
    }

    printf("Number of hands with no pair: %d\n", noPair);
    double noPairProbability = (double)noPair / MILLION;
    printf("Probability of no pair: %lf\n", noPairProbability);

    printf("Number of hands with one pair: %d\n", onePair);
    double onePairProbability = (double)onePair / MILLION;
    printf("Probability of one pair: %lf\n", onePairProbability);

    printf("Number of hands with two pair: %d\n", twoPair);
    double twoPairProbability = (double)twoPair / MILLION;
    printf("Probability of two pair: %lf\n", twoPairProbability);

    printf("Number of hands with three of a kind: %d\n", threeOfAKind);
    double threeOfAKindProbability = (double)threeOfAKind / MILLION;
    printf("Probability of three of a kind: %lf\n", threeOfAKindProbability);

    printf("Number of hands with full house: %d\n", fullHouse);
    double fullHouseProbability = (double)fullHouse / MILLION;
    printf("Probability of full house: %lf\n", fullHouseProbability);

    printf("Number of hands with four of a kind: %d\n", fourOfAKind);
    double fourOfAKindProbability = (double)fourOfAKind / MILLION;
    printf("Probability of four of a kind: %lf\n", fourOfAKindProbability);
}

int main(void)
{
    card cards[SIZE];
    initializeDeck(cards, SIZE);

    printf("%hd", cards[0].pips);
    dealSevenCards(cards, SIZE);
    return 0;
}
