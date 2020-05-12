#pragma once
#include "libraries.hpp"

enum Suit { diamond, club, heart, spade };
enum Colour { black, red };

class Card {
public:
	int number_;
	Suit suit_;
	Colour colour_;
	bool show_;

	sf::Texture texture_;
	sf::Sprite sprite_;

	float positionX_;
	float positionY_;
	int pile_;

	Card() {}
	Card(const int &number, const Suit &suit, const bool &show);
	void setShow(bool show);
	int getNumber();
	Suit getSuit();
	bool operator==(Card& a);
	void setPile(const int &number);
	void setPosition(const float &x, const float&y);
	void setPosition(const sf::Vector2f &position);
};


using VectorCards = std::vector<Card>;

VectorCards newVectorAllCards();

VectorCards newVectorPile(const VectorCards &all, int &p, const int &n);

class Board{
public:
	VectorCards all;
	VectorCards clubs_; //8
	VectorCards diamonds_;  //9
	VectorCards hearts_; //10
	VectorCards spades_; //11
	VectorCards pile1_;
	VectorCards pile2_;
	VectorCards pile3_;
	VectorCards pile4_;
	VectorCards pile5_;
	VectorCards pile6_;
	VectorCards pile7_;
	VectorCards stock_;

	void setPositions(VectorCards &vec, int p);

	Board();
	Board(const VectorCards &all);

	VectorCards* get(int n);
	void set(VectorCards vec, int pileNumber);

	void getToMove(int &currentPileNumber, float mousePositionX, float mousePositionY, bool &selected, int &currentHighestCard, int &stockCardNumber, VectorCards* &fromPile_ptr);
	bool canMove(int pileFrom, int pileTo, int numOfCards, int stock);
	void move(int pileFrom, int pileTo, int numOfCards, int &stock);
	void goBack(int pileFrom, int numOfCards);
};