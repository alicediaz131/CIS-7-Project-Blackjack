# CIS-7-Project-Blackjack
Author: Alice Diaz

Description: 
    I created a blackjack game that is realistic to actual blackjack one would play at a casino. I start the player with a high amount of money, and I allow them to make a bet before a game starts. I also 
included the ability to double-down, which doubles their bet, and the ability to forfeit, which lets them keep half their bet. The final piece to making the game feel realistic was giving the cards the 
ability to be “facedown”. This means that when the player is making decisions, they’re only able to see one of the dealer’s cards. However, I’m also providing the player with certain calculations to incorporate discrete structures. For each hand, I provide the chance the player has to hit twenty-one or bust on their next hit, and the chance the dealer has to hit twenty-one before they reveal their facedown card and potentially hit one more time. My objective is to provide the player with a realistic blackjack experience that offers them the ability to use probability to learn and strategize to their own advantage.
    I programmed the game with an object oriented method. I the main classes are Game, Player, Deck, and Card. Each time the player plays a game, a new Game object is created. The game object has a gameLoop()
method that incorporates all of the other classes and their associated method calls. Discrete structure concepts are used to calculate the chance to bust or to hit twenty-one on a given hand. One such method
is the use of combinatorics to create a forumla that represents the dealer's chance to hit twenty-one within their first potential hit. 

Instructions:
    To play the game, you will have to open the CIS 7 Project.sln file in Microsoft Visual Studio. Once open, you can start the program. It will ask you to enter your name. Then it'll ask you if you'd like to
play a game. Type 'y' for yes and hit enter. It'll then ask for you to enter a bet. Type a number between 0 and 1000. The game will initialize by drawing two cards each for you and the dealer. To proceed through
the game sequence, you'll be asked to hit any key to continue. This is done for clarity purpose, and to avoid too much happening all in one instant. Once you see your hand and the dealer's hand, you'll be given
a list of options to choose from. Type the character associated with each option choice, and hit enter. Again, you will be expected to hit any key to proceed through each step of the game sequence as acknowledgement
that you're ready to see the next condition of the game state. Once the game is decided, you will either be rewarded for winning, penalized for losing, or returned your bet in a tie. You will then see your new amount
of money and asked if you'd like to play again.
