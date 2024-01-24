#include "ButtonList.h"

ButtonList::ButtonList() {
}

void ButtonList::addButton(Button& button) {
	buttonList.push_back(button);
}

void ButtonList::createList(SDL_Renderer* renderer) {
	Button button1(renderer, "../image/buttonActive1.png", 100, 520, "atakFizyczny",true,1);
	Button button2(renderer, "../image/button2.png", 500, 520, "atak1",false,2);
	Button button3(renderer, "../image/button3.png", 900, 520, "leczenie", false,3);
	Button button4(renderer, "../image/button4.png", 100, 620, "atakMagiczny", false,4);
	Button button5(renderer, "../image/button5.png", 500, 620, "obronaMagiczna", false,5);
	Button button6(renderer, "../image/button6.png", 900, 620, "obronaFizyczna", false,6);
	addButton(button1);
	addButton(button2);
	addButton(button3);
	addButton(button4);
	addButton(button5);
	addButton(button6);
}

void ButtonList::printList(SDL_Renderer* renderer) {
	for (auto& element : buttonList) {
		element.render(renderer);
	}
}

void ButtonList::checkActive(SDL_Renderer* renderer) {
	for (auto& element : buttonList) {
		if (element.getActive() == true) {
			if (element.getID() == 1) { element.setButton(renderer, "../image/buttonActive1.png"); }
			if (element.getID() == 2) { element.setButton(renderer, "../image/buttonActive2.png"); }
			if (element.getID() == 3) { element.setButton(renderer, "../image/buttonActive3.png"); }
			if (element.getID() == 4) { element.setButton(renderer, "../image/buttonActive4.png"); }
			if (element.getID() == 5) { element.setButton(renderer, "../image/buttonActive5.png"); }
			if (element.getID() == 6) { element.setButton(renderer, "../image/buttonActive6.png"); }
		}
		else {
			if (element.getID() == 1) { element.setButton(renderer, "../image/button1.png"); }
			if (element.getID() == 2) { element.setButton(renderer, "../image/button2.png"); }
			if (element.getID() == 3) { element.setButton(renderer, "../image/button3.png"); }
			if (element.getID() == 4) { element.setButton(renderer, "../image/button4.png"); }
			if (element.getID() == 5) { element.setButton(renderer, "../image/button5.png"); }
			if (element.getID() == 6) { element.setButton(renderer, "../image/button6.png"); }
			}
		}
	}

