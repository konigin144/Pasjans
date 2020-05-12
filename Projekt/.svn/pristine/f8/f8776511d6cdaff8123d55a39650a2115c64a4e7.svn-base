#include "board.hpp"

Card::Card(const int &number, const Suit &suit, const bool &show) : number_(number), suit_(suit), show_(show) {
	if (suit == diamond || suit == heart) colour_ = red;
	else colour_ = black;

	std::string s1;
	std::ostringstream stream;
	stream << number;
	std::string s2 = stream.str();
	if (suit == diamond) s1 = "D";
	else if (suit == heart) s1 = "H";
	else if (suit == club) s1 = "C";
	else if (suit == spade) s1 = "S";
	std::string fileName = s2 + s1 + ".png";
	texture_.loadFromFile(fileName);
	sprite_.setTexture(texture_);
	sprite_.setScale(0.2, 0.2);
}
void Card::setShow(bool show) {
	show_ = show;
}
int Card::getNumber() {
	return number_;
}
Suit Card::getSuit() {
	return suit_;
}
bool Card::operator==(Card& a) {
	return (this->number_ == a.getNumber() && this->suit_ == a.getSuit());
}

void Card::setPile(const int &number) {
	pile_ = number;
}

void Card::setPosition(const float &x, const float&y) {
	positionX_ = x;
	positionY_ = y;
	sprite_.setPosition(x, y);
}

void Card::setPosition(const sf::Vector2f &position) {
	positionX_ = position.x;
	positionY_ = position.y;
	sprite_.setPosition(position);
}

VectorCards newVectorAllCards() {
	VectorCards vec;
	for (int i = 1; i <= 13; i++) {
		vec.push_back(Card(i, Suit::diamond, false));
		vec.push_back(Card(i, Suit::club, false));
		vec.push_back(Card(i, Suit::heart, false));
		vec.push_back(Card(i, Suit::spade, false));
	}
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(vec.begin(), vec.end(), g);
	return vec;
}

VectorCards newVectorPile(const VectorCards &all, int &p, const int &n) {
	VectorCards newVec;
	Card c;
	for (int i = 0; i < n; i++) {
		c = all[p];
		if (i + 1 == n) c.setShow(true);
		else if (n == 24)c.setShow(true);
		c.setPile(n);
		newVec.push_back(c);
		p++;

	}
	return newVec;
}

Board::Board() {
	all = newVectorAllCards();
	int p = 0;
	pile1_ = newVectorPile(all, p, 1);
	pile2_ = newVectorPile(all, p, 2);
	pile3_ = newVectorPile(all, p, 3);
	pile4_ = newVectorPile(all, p, 4);
	pile5_ = newVectorPile(all, p, 5);
	pile6_ = newVectorPile(all, p, 6);
	pile7_ = newVectorPile(all, p, 7);
	stock_ = newVectorPile(all, p, 24);

	setPositions(pile1_, 1);
	setPositions(pile2_, 2);
	setPositions(pile3_, 3);
	setPositions(pile4_, 4);
	setPositions(pile5_, 5);
	setPositions(pile6_, 6);
	setPositions(pile7_, 7);
	setPositions(stock_, 8);
}

Board::Board(const VectorCards &all_old) {
	all = all_old;
	int p = 0;
	pile1_ = newVectorPile(all, p, 1);
	pile2_ = newVectorPile(all, p, 2);
	pile3_ = newVectorPile(all, p, 3);
	pile4_ = newVectorPile(all, p, 4);
	pile5_ = newVectorPile(all, p, 5);
	pile6_ = newVectorPile(all, p, 6);
	pile7_ = newVectorPile(all, p, 7);
	stock_ = newVectorPile(all, p, 24);

	setPositions(pile1_, 1);
	setPositions(pile2_, 2);
	setPositions(pile3_, 3);
	setPositions(pile4_, 4);
	setPositions(pile5_, 5);
	setPositions(pile6_, 6);
	setPositions(pile7_, 7);
	setPositions(stock_, 8);
}

VectorCards* Board::get(int n) {
	VectorCards* pile;
	switch (n) {
	case 0:
		pile = &pile1_;
		return pile;
		break;
	case 1:
		pile = &pile2_;
		return pile;
		break;
	case 2:
		pile = &pile3_;
		return pile;
		break;
	case 3:
		pile = &pile4_;
		return pile;
		break;
	case 4:
		pile = &pile5_;
		return pile;
		break;
	case 5:
		pile = &pile6_;
		return pile;
		break;
	case 6:
		pile = &pile7_;
		return pile;
		break;
	case 7:
		pile = &stock_;
		return pile;
		break;
	case 8:
		pile = &clubs_;
		return pile;
		break;
	case 9:
		pile = &diamonds_;
		return pile;
		break;
	case 10:
		pile = &hearts_;
		return pile;
		break;
	case 11:
		pile = &spades_;
		return pile;
		break;
	}
}

void Board::set(VectorCards vec, int pileNumber) {
	switch (pileNumber) {
	case 0: {
		pile1_ = vec;
		break;
	}
	case 1: {
		pile2_ = vec;
		break;
	}
	case 2: {
		pile3_ = vec;
		break;
	}
	case 3: {
		pile4_ = vec;
		break;
	}
	case 4: {
		pile5_ = vec;
		break;
	}
	case 5: {
		pile6_ = vec;
		break;
	}
	case 6: {
		pile7_ = vec;
		break;
	}
	default: break;
	}
}

void Board::setPositions(VectorCards &vec, int p) {
	if (p == 8) {
		float x = 300.0;
		float y = 100.0;
		for (int i = 0; i < vec.size(); i++) {
			vec[i].setPosition(x, y);
		}
	}
	else if (p == 9) {
		float x = 693.0;
		float y = 100.0;
		for (int i = 0; i < vec.size(); i++) {
			vec[i].setPosition(x, y);
		}
	}
	else if (p == 10) {
		float x = 891.0;
		float y = 100.0;
		for (int i = 0; i < vec.size(); i++) {
			vec[i].setPosition(x, y);
		}
	}
	else if (p == 11) {
		float x = 1088.0;
		float y = 100.0;
		for (int i = 0; i < vec.size(); i++) {
			vec[i].setPosition(x, y);
		}
	}
	else if (p == 12) {
		float x = 1285.0;
		float y = 100.0;
		for (int i = 0; i < vec.size(); i++) {
			vec[i].setPosition(x, y);
		}
	}
	else {
		float x = 300.0 + (138 + 59)*(p - 1);
		float y = 361.0;
		for (int i = 0; i < vec.size(); i++) {
			vec[i].setPosition(x, y);
			if (i + 1 == vec.size()) {
				y += 211;
			}
			else y += 55;
		}
	}
}

void Board::getToMove(int &currentPileNumber, float mousePositionX, float mousePositionY, bool &selected, int &currentHighestCard, int &stockCardNumber, VectorCards* &fromPile_ptr) {
	currentPileNumber = 0;
	while (currentPileNumber < 7) {
		int positionX = 300 + currentPileNumber * (138 + 59);
		if (mousePositionX >= positionX && mousePositionX <= positionX + 138) {
			if (currentPileNumber == 0) {
				if (mousePositionY >= 100 && mousePositionY <= 100 + 211) {
					currentPileNumber = 7;
					selected = true;
					currentHighestCard = stockCardNumber;
					fromPile_ptr = get(currentPileNumber);
				}
			}
			else if (currentPileNumber == 2) {
				if (mousePositionY >= 100 && mousePositionY <= 100 + 211) {
					currentPileNumber = 8;
					selected = true;
					currentHighestCard = stockCardNumber;
					fromPile_ptr = get(currentPileNumber);
				}
			}
			else if (currentPileNumber == 3) {
				if (mousePositionY >= 100 && mousePositionY <= 100 + 211) {
					currentPileNumber = 9;
					selected = true;
					currentHighestCard = stockCardNumber;
					fromPile_ptr = get(currentPileNumber);
				}
			}
			else if (currentPileNumber == 4) {
				if (mousePositionY >= 100 && mousePositionY <= 100 + 211) {
					currentPileNumber = 10;
					selected = true;
					currentHighestCard = stockCardNumber;
					fromPile_ptr = get(currentPileNumber);
				}
			}
			else if (currentPileNumber == 5) {
				if (mousePositionY >= 100 && mousePositionY <= 100 + 211) {
					currentPileNumber = 11;
					selected = true;
					currentHighestCard = stockCardNumber;
					fromPile_ptr = get(currentPileNumber);
				}
			}
			fromPile_ptr = get(currentPileNumber);
			for (int i = fromPile_ptr->size() - 1; i >= 0; i--) {
				if ((*fromPile_ptr)[i].sprite_.getGlobalBounds().contains(mousePositionX, mousePositionY)) {
					if ((*fromPile_ptr)[i].show_) {
						selected = true;
						currentHighestCard = i;
						break;
					}
				}
			}
			break;
		}
		else currentPileNumber++;
	}
}

bool Board::canMove(int pileFrom, int pileTo, int numOfCards, int stock) {
	if (pileFrom != 7 && pileTo == 7) return false;
	else if (pileFrom == 7 && pileTo == 7) return true;
	else {
		VectorCards* vecFrom = get(pileFrom);
		if (vecFrom->size() == 0) return false;

		VectorCards* vecTo = get(pileTo);
		Card cardFirstFrom;
		if (pileFrom == 7) {
			cardFirstFrom = (*vecFrom)[stock];
		}
		else if (pileFrom == 8 || pileFrom == 9 || pileFrom == 10 || pileFrom == 11) {
			cardFirstFrom = (*vecFrom)[vecFrom->size() - 1];
		}
		else {
			cardFirstFrom = (*vecFrom)[vecFrom->size() - numOfCards];
		}
		if (vecTo->size() == 0) {
			if (pileTo == 8 || pileTo == 9 || pileTo == 10 || pileTo == 11) {
				if (cardFirstFrom.number_ == 1 && numOfCards == 1) return true;
				else return false;
			}
			else {
				if (cardFirstFrom.number_ == 13) return true;
				else return false;
			}
		}
		Card cardLastTo = (*vecTo)[vecTo->size() - 1];

		if (pileTo == 8 || pileTo == 9 || pileTo == 10 || pileTo == 11) {
			if (numOfCards == 1) {
				if (cardFirstFrom.suit_ == cardLastTo.suit_ && cardFirstFrom.number_ - 1 == cardLastTo.number_) {
					return true;
				}
				else return false;
			}
			else return false;
		}

		else if (cardFirstFrom.colour_ != cardLastTo.colour_ && cardFirstFrom.number_ + 1 == cardLastTo.number_) return true;

		else return false;
	}
}

void Board::move(int pileFrom, int pileTo, int numOfCards, int &stock) {
	VectorCards* vecFrom = get(pileFrom);
	VectorCards* vecTo = get(pileTo);
	VectorCards* vecToMove_ptr = new VectorCards;

	if (pileFrom == 7 && pileTo == 7) {
		if (stock_.size() == 0) stock = 0;
		else if (stock != stock_.size() - 1)
			stock++;
		else stock = 0;
	}

	else if (pileFrom == 7) {
		vecTo->push_back((*vecFrom)[stock]);
		vecFrom->erase(vecFrom->begin() + stock);
		if (stock != 0) stock--;
		else if (stock_.size() == 0) stock = 0;
		else stock = stock_.size() - 1;
	}
	else {
		for (int i = numOfCards; i > 0; i--) {
			vecToMove_ptr->push_back((*vecFrom)[vecFrom->size() - i]);
		}
		for (int i = 0; i < numOfCards; i++) {
			vecTo->push_back((*vecToMove_ptr)[i]);
		}
		vecFrom->erase(vecFrom->begin() + vecFrom->size() - numOfCards, vecFrom->begin() + vecFrom->size());
	}
	setPositions(*vecTo, pileTo + 1);
	if (vecFrom->size() != 0) (*vecFrom)[vecFrom->size() - 1].setShow(true);
}

void Board::goBack(int pileFrom, int numOfCards) {
	VectorCards* vecFrom = get(pileFrom);
	setPositions(*vecFrom, pileFrom + 1);
}
