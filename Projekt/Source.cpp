#include "libraries.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Soliatare", sf::Style::Fullscreen);
	sf::Image image;
	image.loadFromFile("aces.png");
	window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
	Board board;

	sf::Texture background_t;
	background_t.loadFromFile("background.jpg");
	sf::Sprite background_s;
	background_s.setTexture(background_t);

	bool selected = false;
	int pileToNumber = 0;
	int currentPileNumber = 0;
	int currentHighestCard = 0;
	int currentPileToNumber = 0;
	int stockCardNumber = 0;
	int numOfCards = 0;
	int numOfMoves = 0;
	sf::Sprite newGameButton;
	sf::Sprite restartButton;
	int newGame_int = 0;
	int restart_int = 0;

	VectorCards* fromPile_ptr = 0;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				break;

			case sf::Event::MouseButtonPressed: {
				if (event.mouseButton.button == sf::Mouse::Left) {
					float mousePositionX = sf::Mouse::getPosition(window).x;
					float mousePositionY = sf::Mouse::getPosition(window).y;

					if (newGameButton.getGlobalBounds().contains(mousePositionX, mousePositionY)) {
						newGame_int = 1;
					}
					else if (restartButton.getGlobalBounds().contains(mousePositionX, mousePositionY)) {
						restart_int = 1;
					}
					else {
						board.getToMove(currentPileNumber, mousePositionX, mousePositionY, selected, currentHighestCard, stockCardNumber, fromPile_ptr);
					}
				}
				else if (event.mouseButton.button == sf::Mouse::Right) {
					float mousePositionX = sf::Mouse::getPosition(window).x;
					float mousePositionY = sf::Mouse::getPosition(window).y;
					board.getToMove(currentPileNumber, mousePositionX, mousePositionY, selected, currentHighestCard, stockCardNumber, fromPile_ptr);
					selected = false;
				}
				break;
			} // fromPile, currentHighestCard

			case sf::Event::MouseMoved: {
				if (selected)
				{
					int n = 0;
					if (currentPileNumber < 7) {
						for (int j = currentHighestCard; j < fromPile_ptr->size(); j++) {
							(*fromPile_ptr)[j].sprite_.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y + n * 55);
							n++;
						}
					}
					else if (currentPileNumber > 7) {
						(*fromPile_ptr)[fromPile_ptr->size()-1].sprite_.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
					}
					else {
						(*fromPile_ptr)[stockCardNumber].sprite_.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
					}
				}
				break;
			}

			case sf::Event::MouseButtonReleased: {
				if (event.mouseButton.button == sf::Mouse::Left) {
					float mousePositionX = sf::Mouse::getPosition(window).x;
					float mousePositionY = sf::Mouse::getPosition(window).y;

					if (newGame_int == 1) {
						if (newGameButton.getGlobalBounds().contains(mousePositionX, mousePositionY)) {
							board = Board();
							pileToNumber = 0;
							currentPileNumber = 0;
							currentHighestCard = 0;
							currentPileToNumber = 0;
							stockCardNumber = 0;
							numOfCards = 0;
							numOfMoves = 0;
							newGame_int = 0;
							selected = false;
						}
						else break;
					}
					else if (restart_int == 1) {
						if (restartButton.getGlobalBounds().contains(mousePositionX, mousePositionY)) {
							board = Board(board.all);
							pileToNumber = 0;
							currentPileNumber = 0;
							currentHighestCard = 0;
							currentPileToNumber = 0;
							stockCardNumber = 0;
							numOfCards = 0;
							numOfMoves = 0;
							restart_int = 0;
							selected = false;
						}
						else break;
					}
					else {
						currentPileToNumber = 0;
						bool goodPosition = false;
						int positionX;

						for (currentPileToNumber = 0; currentPileToNumber < 8; currentPileToNumber++) {
							positionX = 300 + currentPileToNumber * (138 + 59);
							if (sf::Mouse::getPosition(window).x >= positionX && sf::Mouse::getPosition(window).x <= positionX + 138) {
								if (currentPileToNumber == 0) {
									if (sf::Mouse::getPosition(window).y >= 100 && sf::Mouse::getPosition(window).y <= 100 + 211) {
										currentPileToNumber = 7;
										goodPosition = true;
									}
								}
								else if (currentPileToNumber == 2 && sf::Mouse::getPosition(window).y >= 100 && sf::Mouse::getPosition(window).y <= 311) {
									currentPileToNumber = 8;
									goodPosition = true;
								}
								else if (currentPileToNumber == 3) {
									if (sf::Mouse::getPosition(window).y >= 100 && sf::Mouse::getPosition(window).y <= 100 + 211) {
										currentPileToNumber = 9;
										goodPosition = true;
									}
								}
								else if (currentPileToNumber == 4) {
									if (sf::Mouse::getPosition(window).y >= 100 && sf::Mouse::getPosition(window).y <= 100 + 211) {
										currentPileToNumber = 10;
										goodPosition = true;
									}
								}
								else if (currentPileToNumber == 5) {
									if (sf::Mouse::getPosition(window).y >= 100 && sf::Mouse::getPosition(window).y <= 100 + 211) {
										currentPileToNumber = 11;
										goodPosition = true;
									}
								}
								if (sf::Mouse::getPosition(window).y >= 361) {
									goodPosition = true;
									pileToNumber = currentPileToNumber;
								}
								if (goodPosition) {
									pileToNumber = currentPileToNumber;
									break;
								}
							}
						}

						if (currentPileNumber == 7 || currentPileNumber == 8 || currentPileNumber == 9 || currentPileNumber == 10 || currentPileNumber == 11) numOfCards = 1;
						else numOfCards = fromPile_ptr->size() - currentHighestCard;
						if (currentPileToNumber == 7) board.goBack(currentPileNumber, numOfCards);

						if (goodPosition) {
							if (board.canMove(currentPileNumber, pileToNumber, numOfCards, stockCardNumber)) {
								board.move(currentPileNumber, pileToNumber, numOfCards, stockCardNumber);
								numOfMoves++;
							}
							else {
								board.goBack(currentPileNumber, numOfCards);
							}
						}
						else board.goBack(currentPileNumber, numOfCards);
						selected = false;
						break;
					}
				}
				else if (event.mouseButton.button == sf::Mouse::Right) {
					if (currentHighestCard == fromPile_ptr->size() - 1) {
						Card card;
						if (currentPileNumber == 7) {
							card = (*fromPile_ptr)[stockCardNumber];
						}
						else
							card = (*fromPile_ptr)[fromPile_ptr->size() - 1];
						int numOfEmpty = 0;
						int i;
						for (i = 8; i <= 11; i++) {
							VectorCards* upPile = board.get(i);
							if (upPile->size() == 0) {
								if (numOfEmpty == 0) numOfEmpty = i;
							}
							else {
								if (card.suit_ == (*upPile)[0].suit_) {
									if (board.canMove(currentPileNumber, i, 1, stockCardNumber)) {
										board.move(currentPileNumber, i, 1, stockCardNumber);
										numOfMoves++;
										break;
									}
									else {
										board.goBack(currentPileNumber, numOfCards);
									}
								}
							}
						}
						if (numOfEmpty != 0) {
							if (board.canMove(currentPileNumber, numOfEmpty, 1, stockCardNumber)) {
								board.move(currentPileNumber, numOfEmpty, 1, stockCardNumber);
								numOfMoves++;
							}
						}
					}
				}
			} //ToPile 

			default: break;
			}

		}

		window.clear();
		window.draw(background_s);

		if (board.stock_.size() != 0) {
			board.stock_[stockCardNumber].sprite_.setTexture(board.stock_[stockCardNumber].texture_);
			window.draw(board.stock_[stockCardNumber].sprite_);
		}

		sf::Texture back_t;
		back_t.loadFromFile("green_back.png");
		sf::Texture empty_t;
		empty_t.loadFromFile("empty.png");

		for (int i = 0; i < 7; i++) {
			VectorCards *vec = board.get(i);
			if (vec->size() == 0) {
				sf::Sprite empty;
				float x = 300.0 + 198.0*i;
				float y = 361.0;
				empty.setTexture(empty_t);
				empty.setScale(0.2, 0.2);
				empty.setPosition(x, y);
				window.draw(empty);
			}
			else
			for (int j = 0; j < vec->size(); j++) {
				if ((*vec)[j].show_) {
					(*vec)[j].sprite_.setTexture((*vec)[j].texture_);
					window.draw((*vec)[j].sprite_);
				}
				else {
					(*vec)[j].sprite_.setTexture(back_t);
					window.draw((*vec)[j].sprite_);
				}
			}
		}
		for (int i = 8; i < 12; i++) {
			VectorCards *vec = board.get(i);
			if (vec->size() != 0) {
				(*vec)[vec->size() - 1].sprite_.setTexture((*vec)[vec->size() - 1].texture_);
				window.draw((*vec)[vec->size() - 1].sprite_);
			}
			else {
				if (i == 8) {
					sf::Texture S_t;
					S_t.loadFromFile("empty.png");
					sf::Sprite S_s;
					S_s.setTexture(S_t);
					S_s.setScale(0.2, 0.2);
					S_s.setPosition(693.0, 100.0);
					window.draw(S_s);
				}
				if (i == 9) {
					sf::Texture S_t;
					S_t.loadFromFile("empty.png");
					sf::Sprite S_s;
					S_s.setTexture(S_t);
					S_s.setScale(0.2, 0.2);
					S_s.setPosition(891.0, 100.0);
					window.draw(S_s);
				}
				if (i == 10) {
					sf::Texture S_t;
					S_t.loadFromFile("empty.png");
					sf::Sprite S_s;
					S_s.setTexture(S_t);
					S_s.setScale(0.2, 0.2);
					S_s.setPosition(1088.0, 100.0);
					window.draw(S_s);
				}
				if (i == 11) {
					sf::Texture S_t;
					S_t.loadFromFile("empty.png");
					sf::Sprite S_s;
					S_s.setTexture(S_t);
					S_s.setScale(0.2, 0.2);
					S_s.setPosition(1285.0, 100.0);
					window.draw(S_s);
				}
			}
		}
		sf::Font font;
		font.loadFromFile("arial.ttf");
		sf::Text moves;
		std::stringstream ss;
		ss << numOfMoves;
		std::string str = ss.str();
		str.insert(0, "Moves: ");
		moves.setFont(font);
		moves.setString(str);
		moves.setCharacterSize(30);
		moves.setFillColor(sf::Color::Red);
		moves.setPosition(1700, 10);
		window.draw(moves);


		sf::Texture newGame_t;
		newGame_t.loadFromFile("newGameButton.png");
		newGameButton.setTexture(newGame_t);
		newGameButton.setPosition(10.0, 10.0);
		window.draw(newGameButton);

		sf::Texture restart_t;
		restart_t.loadFromFile("restartButton.png");
		restartButton.setTexture(restart_t);
		restartButton.setPosition(150.0, 10.0);
		window.draw(restartButton);

		window.display();
	}
	return 0;
}