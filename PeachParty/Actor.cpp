#include "Actor.h"
#include <cmath>
#include <iostream>

using namespace std;

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp

  // checks the state of the player taking in user input if waiting to roll
  // or if at a fork, setting walk direction for move tick function
void Player::doSomething() {
	if (!is_walking()) {
		/*
		a. If the Avatar has an invalid direction (due to being teleported):
			i. Pick a random valid direction (there must be a square in that
				direction).
			ii. Update the direction the Avatar's sprite faces based on the walk
				direction: if the walk direction is left, the sprite direction must be
				180 degrees; for all other walk directions, the sprite direction must
				be 0 degrees.
			iii. Continue with step b.
		*/
		if (just_teleported) {
			just_teleported = false;
			if (getWalkDir() == right) {
				if (getX() >= VIEW_WIDTH || !get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH + SPRITE_WIDTH, getY())) {
					bool isUpEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() + SPRITE_HEIGHT);
					bool isDownEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() - SPRITE_HEIGHT);
					bool isLeftEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH - SPRITE_WIDTH, getY());

					bool done = false;
					while (done != true) {
						int pickDirection = randInt(1, 3);
						cout << "here" << endl;
						switch (pickDirection) {
						case 1:
							if (!isUpEnterLottery)
								break;
							setWalkDir(up);
							done = true;
							break;

						case 2:
							if (!isDownEnterLottery)
								break;
							setWalkDir(down);
							done = true;
							break;
						case 3:
							if (!isLeftEnterLottery)
								break;
							setWalkDir(left);
							done = true;
							break;
						}
					}
				}
			}
			else if (getWalkDir() == left) {
				cout << "LSL:KDFJLKSD:LFKJSKLFJKLFJ" << endl;
				if (getX() < 0 || !get_ptr_to_student_world()->is_there_a_square_at_location(ceil(static_cast<double>(getX()) / SPRITE_WIDTH) * SPRITE_WIDTH - SPRITE_WIDTH, getY())) {
					bool isUpEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() + SPRITE_HEIGHT);
					bool isDownEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() - SPRITE_HEIGHT);
					bool isRightEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH + SPRITE_WIDTH, getY());

					bool done = false;
					while (done != true) {
						int pickDirection = randInt(1, 3);
						cout << "here" << endl;
						switch (pickDirection) {
						case 1:
							if (!isUpEnterLottery)
								break;
							setWalkDir(up);
							done = true;
							break;

						case 2:
							if (!isDownEnterLottery)
								break;
							setWalkDir(down);
							done = true;
							break;
						case 3:
							if (!isRightEnterLottery)
								break;
							setWalkDir(right);
							done = true;
							break;
						}
					}
				}
			}
			else if (getWalkDir() == up) {
				cout << "LSL:KDFJLKSD:LFKJSKLFJKLFJ" << endl;
				if (getY() >= VIEW_HEIGHT || !get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() / SPRITE_HEIGHT * SPRITE_HEIGHT + SPRITE_HEIGHT)) {
					bool isRightEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH + SPRITE_WIDTH, getY());
					bool isDownEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() - SPRITE_HEIGHT);
					bool isLeftEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH - SPRITE_WIDTH, getY());

					bool done = false;
					while (done != true) {
						int pickDirection = randInt(1, 3);
						cout << "here" << endl;
						switch (pickDirection) {
						case 1:
							if (!isRightEnterLottery)
								break;
							setWalkDir(right);
							done = true;
							break;

						case 2:
							if (!isDownEnterLottery)
								break;
							setWalkDir(down);
							done = true;
							break;
						case 3:
							if (!isLeftEnterLottery)
								break;
							setWalkDir(left);
							done = true;
							break;
						}
					}
				}
			}
			else if (getWalkDir() == down) {
				cout << "LSL:KDFJLKSD:LFKJSKLFJKLFJ" << endl;
				if (getY() < 0 || !get_ptr_to_student_world()->is_there_a_square_at_location(getX(), ceil(static_cast<double>(getY()) / SPRITE_HEIGHT) * SPRITE_HEIGHT - SPRITE_HEIGHT)) {
					bool isUpEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() + SPRITE_HEIGHT);
					bool isRightEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH + SPRITE_WIDTH, getY());
					bool isLeftEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH - SPRITE_WIDTH, getY());

					bool done = false;
					while (done != true) {
						int pickDirection = randInt(1, 3);
						cout << "here" << endl;
						switch (pickDirection) {
						case 1:
							if (!isUpEnterLottery)
								break;
							setWalkDir(up);
							done = true;
							break;

						case 2:
							if (!isRightEnterLottery)
								break;
							setWalkDir(right);
							done = true;
							break;
						case 3:
							if (!isLeftEnterLottery)
								break;
							setWalkDir(left);
							done = true;
							break;
						}
					}
				}
			}


			if (getWalkDir() == left)
				setDirection(left);
			else
				setDirection(right);

		}


		switch (get_ptr_to_student_world()->getAction(m_playerNumber))
		{
		case ACTION_NONE:
			// no key relevant to this player was hit ...
			break;
		case ACTION_FIRE:
			//add Vortex object in front of player...;
			if (m_vortex == false)
				break;
			m_vortex = false;
			get_ptr_to_student_world()->add_vortex(this);
			get_ptr_to_student_world()->playSound(SOUND_PLAYER_FIRE);
			break;
		case ACTION_ROLL:
			die_roll = randInt(1, 10);
			changeTicksToMove(die_roll * 8);
			break;
		}
	}

	if (is_walking()) {
		bool leftPossible = false, rightPossible = false, upPossible = false, downPossilbe = false;
		int possibleCount = 0;

		if (getX() % SPRITE_WIDTH == 0 && getY() % SPRITE_HEIGHT == 0) {
			if (getWalkDir() != left)
				rightPossible = getX() >= VIEW_WIDTH || get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH + SPRITE_WIDTH, getY());
			if (getWalkDir() != right)
				leftPossible = getX() < 0 || get_ptr_to_student_world()->is_there_a_square_at_location(ceil(static_cast<double>(getX()) / SPRITE_WIDTH) * SPRITE_WIDTH - SPRITE_WIDTH, getY());
			if (getWalkDir() != down)
				upPossible = getY() >= VIEW_HEIGHT || get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() / SPRITE_HEIGHT * SPRITE_HEIGHT + SPRITE_HEIGHT);
			if (getWalkDir() != up)
				downPossilbe = getY() < 0 || get_ptr_to_student_world()->is_there_a_square_at_location(getX(), ceil(static_cast<double>(getY()) / SPRITE_HEIGHT) * SPRITE_HEIGHT - SPRITE_HEIGHT);
			if (rightPossible)
				possibleCount++;
			if (leftPossible)
				possibleCount++;
			if (upPossible)
				possibleCount++;
			if (downPossilbe)
				possibleCount++;
		}

		
			GameObject* dirSquare = get_ptr_to_student_world()->get_square_at_location(getX(), getY());
			if (dirSquare != nullptr && get_ptr_to_student_world()->get_square_at_location(getX(), getY())->isDirectionalSquare()) {
				dirSquare->doSomething();
				moveTick();
			}
		
		else if (possibleCount > 1 && !game_start)
		{
			switch (get_ptr_to_student_world()->getAction(m_playerNumber))
			{
			case ACTION_NONE:
				// no key relevant to this player was hit ...
				break;
			case ACTION_RIGHT:
				if (!rightPossible)
					break;
				setWalkDir(right);
				moveTick();
				break;
			case ACTION_LEFT:
				if (!leftPossible)
					break;
				setWalkDir(left);
				moveTick();
				break;

			case ACTION_UP:
				if (!upPossible)
					break;
				setWalkDir(up);
				moveTick();
				break;
			case ACTION_DOWN:
				if (!downPossilbe)
					break;
				setWalkDir(down);
				moveTick();
				break;
			}
			
		}
		else if (getWalkDir() == right) {
			if (getX() >= VIEW_WIDTH || !get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH + SPRITE_WIDTH, getY())) {
				if (get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() + SPRITE_HEIGHT)) {
					setWalkDir(up);
				}
				else if (get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() - SPRITE_HEIGHT)) {
					setWalkDir(down);
				}
				else {
					setWalkDir(left);
				}
			}
			moveTick();
		}
		else if (getWalkDir() == left) {
			if (getX() < 0 || !get_ptr_to_student_world()->is_there_a_square_at_location(ceil(static_cast<double>(getX()) / SPRITE_WIDTH) * SPRITE_WIDTH - SPRITE_WIDTH, getY())) {
				if (get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() + SPRITE_HEIGHT)) {
					setWalkDir(up);
				}
				else if (get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() - SPRITE_HEIGHT)) {
					setWalkDir(down);
				}
				else {
					setWalkDir(right);
				}
			}
			moveTick();
		}
		else if (getWalkDir() == up) {
			if (getY() >= VIEW_HEIGHT || !get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() / SPRITE_HEIGHT * SPRITE_HEIGHT + SPRITE_HEIGHT)) {
				if (get_ptr_to_student_world()->is_there_a_square_at_location(getX() + SPRITE_WIDTH, getY())) {
					setWalkDir(right);
				}
				else if (get_ptr_to_student_world()->is_there_a_square_at_location(getX() - SPRITE_WIDTH, getY())) {
					setWalkDir(left);
				}
				else {
					setWalkDir(down);
				}
			}
			moveTick();
		}
		else if (getWalkDir() == down) {
			if (getY() < 0 || !get_ptr_to_student_world()->is_there_a_square_at_location(getX(), ceil(static_cast<double>(getY()) / SPRITE_HEIGHT) * SPRITE_HEIGHT - SPRITE_HEIGHT)) {
				if (get_ptr_to_student_world()->is_there_a_square_at_location(getX() + SPRITE_WIDTH, getY())) {
					setWalkDir(right);
				}
				else if (get_ptr_to_student_world()->is_there_a_square_at_location(getX() - SPRITE_WIDTH, getY())) {
					setWalkDir(left);
				}
				else {
					setWalkDir(up);
				}
			}
			moveTick();
		}
			game_start = false;
		if (getWalkDir() == left)
			setDirection(left);
		else
			setDirection(right);
	}
}
  // moves player in direction and decrements tick to move
void Player::moveTick() {
	if (getWalkDir() == left)
		setDirection(left);
	else
		setDirection(right);
	moveAtAngle(getWalkDir(), 2); // move the object 2 pixels
	set_square_ready(true);
	cout << getX() << "," << getY() << endl;
	changeTicksToMove(-1);
}
  // gets random square and sets as player's new coords
void Player::teleport_me_to_random_sq() {
	 GameObject* newLocation = get_ptr_to_student_world()->get_random_square(BOARD_WIDTH, BOARD_HEIGHT);
	 moveTo(newLocation->getX(), newLocation->getY());
	 just_teleported = true;
}
  // swaps necessary values for player swap using temp vars
void Player::swap_positions(){
	int tempX = get_ptr_to_student_world()->get_other_player(this)->getX();
	int tempY = get_ptr_to_student_world()->get_other_player(this)->getY();
	get_ptr_to_student_world()->get_other_player(this)->moveTo(getX(), getY());
	moveTo(tempX, tempY);

	int tempTicks = get_ptr_to_student_world()->get_other_player(this)->getTicksToMove();
	get_ptr_to_student_world()->get_other_player(this)->changeTicksToMove(-tempTicks + getTicksToMove());
	changeTicksToMove(-getTicksToMove() + tempTicks);

	int tempWalkDirection = get_ptr_to_student_world()->get_other_player(this)->getWalkDir();
	get_ptr_to_student_world()->get_other_player(this)->setWalkDir(getWalkDir());
	setWalkDir(tempWalkDirection);
	
	int tempSpriteDirection = get_ptr_to_student_world()->get_other_player(this)->getDirection();
	get_ptr_to_student_world()->get_other_player(this)->setDirection(getDirection());
	setDirection(tempSpriteDirection);

}
  // function name
void Player::swap_coins() {
	int tempCoins = get_ptr_to_student_world()->get_other_player(this)->get_coins();
	get_ptr_to_student_world()->get_other_player(this)->adjust_coins(-tempCoins + get_coins());
	adjust_coins(-get_coins() + tempCoins);
}
  // function name
void Player::swap_stars() {
	int tempStars = get_ptr_to_student_world()->get_other_player(this)->get_stars();
	get_ptr_to_student_world()->get_other_player(this)->adjust_stars(-tempStars + get_stars());
	adjust_stars(-get_stars() + tempStars);
}
  // calls doActivity of derived objects differently depending on if square
void ActivatingObject::doSomething() {
	if (!is_active())
		return;
	//if (getWorld()->landedOnPeach(getX(), getY())) {
		//do something to peach
		//return;
	//}
	//get_ptr_to_student_world()->
	if (is_a_square()) {
		doActivity(get_ptr_to_student_world()->get_peach());
		doActivity(get_ptr_to_student_world()->get_yoshi());
	}
	else
		doActivity(get_ptr_to_student_world()->get_peach(), get_ptr_to_student_world()->get_yoshi());
}
  // + or - coins and plays sound
void CoinSquare::doActivity(Player* player) {
	if (player->getX() != getX() || player->getY() != getY())
		return;
	if (!player->is_walking() && player->is_square_ready()) {
		player->adjust_coins(adjust_coins_by_);
		player->set_square_ready(false);
		if (adjust_coins_by_ > 0)
			get_ptr_to_student_world()->playSound(SOUND_GIVE_COIN);
		else
			get_ptr_to_student_world()->playSound(SOUND_TAKE_COIN);
	}
}
  // + star and - coins if eligible
void StarSquare::doActivity(Player* player) {
	if (player->getX() != getX() || player->getY() != getY())
		return;
	if (player->is_square_ready()) {
		if (player->get_coins() < 20)
			return;
		else {
			player->set_square_ready(false);
			player->adjust_stars(1);
			player->adjust_coins(-20);
			get_ptr_to_student_world()->playSound(SOUND_GIVE_STAR);
		}
	}
}
  // change direction of player
void DirectionalSquare::doActivity(Player* player) {
	if (player->getX() != getX() || player->getY() != getY())
		return;
	if (player->is_square_ready()) {
		player->set_square_ready(false);
		player->setWalkDir(angle_);
	}
}
  // if land on give contents of bank, if passing take up to 5
void BankSquare::doActivity(Player* player) {
	if (player->getX() != getX() || player->getY() != getY())
		return;
	if (!player->is_square_ready())
		return;
	if (!player->is_walking()) {
		player->set_square_ready(false);
		player->adjust_coins(get_ptr_to_student_world()->get_bank_coins());
		get_ptr_to_student_world()->reset_bank_coins();
		get_ptr_to_student_world()->playSound(SOUND_WITHDRAW_BANK);
		return;
	}
	if (player->get_coins() >= 5)
		get_ptr_to_student_world()->deposit_bank_coins(5);
	else
		get_ptr_to_student_world()->deposit_bank_coins(player->get_coins());
	player->adjust_coins(-5);
	get_ptr_to_student_world()->playSound(SOUND_DEPOSIT_BANK);
	player->set_square_ready(false);

}
  // chooses to tp to random, swap players, or give vortex
void EventSquare::doActivity(Player* player) {
	if (player->getX() != getX() || player->getY() != getY())
		return;
	if (!player->is_square_ready() || player->is_walking())
		return;
	int choice = randInt(1, 3);
	switch (choice) {
	case 1:
		player->teleport_me_to_random_sq();
		get_ptr_to_student_world()->playSound(SOUND_PLAYER_TELEPORT);
		break;
	case 2:
		player->swap_positions();
		player->set_square_ready(false);
		get_ptr_to_student_world()->get_other_player(player)->set_square_ready(false);
		break;
	case 3:
		player->equip_with_vortex_projectile();
		player->set_square_ready(false);
		get_ptr_to_student_world()->playSound(SOUND_GIVE_VORTEX);
		break;
	}
}
  // Baddies walk algorithm, calling specific mischief when necesary
  // similar logic to player's movement with small but major changes which
  // makes keeping them as separate classes much easier
void Enemy::doActivity(Player* player1, Player* player2) {
	if (get_ticks_paused() != 0) {
		doMischief(player1);
		doMischief(player2);
		set_ticks_paused(get_ticks_paused()-1);//fix
	}
	if (get_ticks_paused() == 0 && !is_walking()) {
		set_squares_to_move(random_num());
		set_ticks_to_move(get_squares_to_move() * 8);
		set_walking(true);
	}
	if (is_walking()){
		bool isRightValid = false;
		bool isLeftValid = false;
		bool isUpValid = false;
		bool isDownValid = false;
		int walkingDirections = 0;
		bool onSquare = getX() % SPRITE_WIDTH == 0 && getY() % SPRITE_HEIGHT == 0;
		if (onSquare) {
			isRightValid = get_ptr_to_student_world()->is_there_a_square_at_location(getX() + SPRITE_WIDTH, getY());
			isLeftValid = get_ptr_to_student_world()->is_there_a_square_at_location(getX() - SPRITE_WIDTH, getY());
			isUpValid = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY()+SPRITE_HEIGHT);
			isDownValid = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY()-SPRITE_HEIGHT);
			if (isRightValid)
				walkingDirections++;
			if (isLeftValid)
				walkingDirections++;
			if (isDownValid)
				walkingDirections++;
			if (isUpValid)
				walkingDirections++;
		}
		int walkDir = getWalkDir();
		bool squareInFront = 
			getWalkDir() == right && isRightValid ||
			getWalkDir() == left && isLeftValid ||
			getWalkDir() == down && isDownValid ||
			getWalkDir() == up && isUpValid;

		if (onSquare && walkingDirections > 2) {
			bool done = false;
			while (done != true) {
				int pickDirection = randInt(1, 4);
				cout << "here" << endl;
				switch (pickDirection) {
				case 1:
					if (!isUpValid)
						break;
					setWalkDir(up);
					done = true;
					break;

				case 2:
					if (!isDownValid)
						break;
					setWalkDir(down);
					done = true;
					break;
				case 3:
					if (!isLeftValid)
						break;
					setWalkDir(left);
					done = true;
					break;
				case 4:
					if (!isRightValid)
						break;

					setWalkDir(right);
					done = true;
					break;
				}
			}
		}
		else if (onSquare && !squareInFront) {
			if (walkDir == right) {
				if (isUpValid)
					setWalkDir(up);
				else if (isDownValid)
					setWalkDir(down);
			}
			else if (walkDir == left) {
				if (isUpValid)
					setWalkDir(up);
				else if (isDownValid)
					setWalkDir(down);
			} 
			else if (walkDir == up) {
				if (isRightValid)
					setWalkDir(right);
				else if (isLeftValid)
					setWalkDir(left);
			}
			else if (walkDir == down) {
				if (isRightValid)
					setWalkDir(right);
				else if (isLeftValid)
					setWalkDir(left);
			}

		}
		if (getWalkDir() == left)
			setDirection(left);
		else
			setDirection(right);
		moveTick();
		if (ticks_to_move == 0) {
			set_ticks_paused(180);
			//DEPOSIT DROPPING 25%
			drop_time();
		}
		/*
		if (getX() % SPRITE_WIDTH == 0 && getY() % SPRITE_HEIGHT == 0) {
			if (getWalkDir() == right) {
				bool isRightEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH + SPRITE_WIDTH, getY());
				bool isUpEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() + SPRITE_HEIGHT);
				bool isDownEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() - SPRITE_HEIGHT);
				bool isLeftEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH - SPRITE_WIDTH, getY());

				bool done = false;
				while (done != true) {
					int pickDirection = randInt(1, 4);
					cout << "here" << endl;
					switch (pickDirection) {
					case 1:
						if (!isUpEnterLottery)
							break;
						setWalkDir(up);
						done = true;
						break;

					case 2:
						if (!isDownEnterLottery)
							break;
						setWalkDir(down);
						done = true;
						break;
					case 3:
						if (!isLeftEnterLottery)
							break;
						setWalkDir(left);
						done = true;
						break;
					case 4:
						if (!isRightEnterLottery)
							break;

						setWalkDir(right);
						done = true;
						break;
					}
				}
			}

			else if (getWalkDir() == left) {
				cout << "LSL:KDFJLKSD:LFKJSKLFJKLFJ" << endl;
				bool isLeftEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(ceil(static_cast<double>(getX()) / SPRITE_WIDTH) * SPRITE_WIDTH - SPRITE_WIDTH, getY());
				bool isUpEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() + SPRITE_HEIGHT);
				bool isDownEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() - SPRITE_HEIGHT);
				bool isRightEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH + SPRITE_WIDTH, getY());

				bool done = false;
				while (done != true) {
					int pickDirection = randInt(1, 4);
					cout << "here" << endl;
					switch (pickDirection) {
					case 1:
						if (!isUpEnterLottery)
							break;
						setWalkDir(up);
						done = true;
						break;

					case 2:
						if (!isDownEnterLottery)
							break;
						setWalkDir(down);
						done = true;
						break;
					case 3:
						if (!isRightEnterLottery)
							break;
						setWalkDir(right);
						done = true;
						break;
					case 4:
						if (!isLeftEnterLottery)
							break;
						setWalkDir(left);
						done = true;
						break;
					}
				}
			}

			else if (getWalkDir() == up) {
				cout << "LSL:KDFJLKSD:LFKJSKLFJKLFJ" << endl;
				bool isUpEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() / SPRITE_HEIGHT * SPRITE_HEIGHT + SPRITE_HEIGHT);
				bool isRightEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH + SPRITE_WIDTH, getY());
				bool isDownEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() - SPRITE_HEIGHT);
				bool isLeftEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH - SPRITE_WIDTH, getY());

				bool done = false;
				while (done != true) {
					int pickDirection = randInt(1, 4);
					cout << "here" << endl;
					switch (pickDirection) {
					case 1:
						if (!isRightEnterLottery)
							break;
						setWalkDir(right);
						done = true;
						break;

					case 2:
						if (!isDownEnterLottery)
							break;
						setWalkDir(down);
						done = true;
						break;
					case 3:
						if (!isLeftEnterLottery)
							break;
						setWalkDir(left);
						done = true;
						break;
					case 4:
						if (!isUpEnterLottery)
							break;
						setWalkDir(up);
						done = true;
						break;
					}
				}
			}

			else if (getWalkDir() == down) {
				cout << "LSL:KDFJLKSD:LFKJSKLFJKLFJ" << endl;
				bool isDownEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), ceil(static_cast<double>(getY()) / SPRITE_HEIGHT) * SPRITE_HEIGHT - SPRITE_HEIGHT);
				bool isUpEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() + SPRITE_HEIGHT);
				bool isRightEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH + SPRITE_WIDTH, getY());
				bool isLeftEnterLottery = get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH - SPRITE_WIDTH, getY());

				bool done = false;
				while (done != true) {
					int pickDirection = randInt(1, 4);
					cout << "here" << endl;
					switch (pickDirection) {
					case 1:
						if (!isUpEnterLottery)
							break;
						setWalkDir(up);
						done = true;
						break;

					case 2:
						if (!isRightEnterLottery)
							break;
						setWalkDir(right);
						done = true;
						break;
					case 3:
						if (!isLeftEnterLottery)
							break;
						setWalkDir(left);
						done = true;
						break;
					case 4:
						if (!isDownEnterLottery)
							break;
						setWalkDir(down);
						done = true;
						break;
					}
				}
			}
			if (getWalkDir() == left)
				setDirection(left);
			else
				setDirection(right);
		}
		bool leftPossible = false, rightPossible = false, upPossible = false, downPossilbe = false;
		int possibleCount = 0;

		if (getX() % SPRITE_WIDTH == 0 && getY() % SPRITE_HEIGHT == 0) {
			if (getWalkDir() != left)
				rightPossible = getX() >= VIEW_WIDTH || get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH + SPRITE_WIDTH, getY());
			if (getWalkDir() != right)
				leftPossible = getX() < 0 || get_ptr_to_student_world()->is_there_a_square_at_location(ceil(static_cast<double>(getX()) / SPRITE_WIDTH) * SPRITE_WIDTH - SPRITE_WIDTH, getY());
			if (getWalkDir() != down)
				upPossible = getY() >= VIEW_HEIGHT || get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() / SPRITE_HEIGHT * SPRITE_HEIGHT + SPRITE_HEIGHT);
			if (getWalkDir() != up)
				downPossilbe = getY() < 0 || get_ptr_to_student_world()->is_there_a_square_at_location(getX(), ceil(static_cast<double>(getY()) / SPRITE_HEIGHT) * SPRITE_HEIGHT - SPRITE_HEIGHT);
			if (rightPossible)
				possibleCount++;
			if (leftPossible)
				possibleCount++;
			if (upPossible)
				possibleCount++;
			if (downPossilbe)
				possibleCount++;
		}

		if (possibleCount > 1)
		{

			bool done = false;
			while (done != true) {
				int pickDirection = randInt(1, 4);
				cout << "here" << endl;
				switch (pickDirection) {
				case 1:
					if (!upPossible)
						break;
					setWalkDir(up);
					done = true;
					break;

				case 2:
					if (!downPossilbe)
						break;
					setWalkDir(down);
					done = true;
					break;
				case 3:
					if (!leftPossible)
						break;
					setWalkDir(left);
					done = true;
					break;
				case 4:
					if (!rightPossible)
						break;

					setWalkDir(right);
					done = true;
					break;
				}
			}
		}
		else if (getWalkDir() == right) {
			if (getX() >= VIEW_WIDTH || !get_ptr_to_student_world()->is_there_a_square_at_location(getX() / SPRITE_WIDTH * SPRITE_WIDTH + SPRITE_WIDTH, getY())) {
				if (get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() + SPRITE_HEIGHT)) {
					setWalkDir(up);
				}
				else if (get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() - SPRITE_HEIGHT)) {
					setWalkDir(down);
				}
				else {
					setWalkDir(left);
				}
			}
			moveTick();
		}
		else if (getWalkDir() == left) {
			if (getX() < 0 || !get_ptr_to_student_world()->is_there_a_square_at_location(ceil(static_cast<double>(getX()) / SPRITE_WIDTH) * SPRITE_WIDTH - SPRITE_WIDTH, getY())) {
				if (get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() + SPRITE_HEIGHT)) {
					setWalkDir(up);
				}
				else if (get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() - SPRITE_HEIGHT)) {
					setWalkDir(down);
				}
				else {
					setWalkDir(right);
				}
			}
			moveTick();
		}
		else if (getWalkDir() == up) {
			if (getY() >= VIEW_HEIGHT || !get_ptr_to_student_world()->is_there_a_square_at_location(getX(), getY() / SPRITE_HEIGHT * SPRITE_HEIGHT + SPRITE_HEIGHT)) {
				if (get_ptr_to_student_world()->is_there_a_square_at_location(getX() + SPRITE_WIDTH, getY())) {
					setWalkDir(right);
				}
				else if (get_ptr_to_student_world()->is_there_a_square_at_location(getX() - SPRITE_WIDTH, getY())) {
					setWalkDir(left);
				}
				else {
					setWalkDir(down);
				}
			}
			moveTick();
		}
		else if (getWalkDir() == down) {
			if (getY() < 0 || !get_ptr_to_student_world()->is_there_a_square_at_location(getX(), ceil(static_cast<double>(getY()) / SPRITE_HEIGHT) * SPRITE_HEIGHT - SPRITE_HEIGHT)) {
				if (get_ptr_to_student_world()->is_there_a_square_at_location(getX() + SPRITE_WIDTH, getY())) {
					setWalkDir(right);
				}
				else if (get_ptr_to_student_world()->is_there_a_square_at_location(getX() - SPRITE_WIDTH, getY())) {
					setWalkDir(left);
				}
				else {
					setWalkDir(up);
				}
			}
			moveTick();
		}
		if (getWalkDir() == left)
			setDirection(left);
		else
			setDirection(right);
	}
	*/
	}
}
  // 50/50 to reset player's coins and stars if both not moving and play sound
void Bowser::doMischief(Player* player) {
	if (!player->is_square_ready())
		return;
	if (player->getX() == getX() && player->getY() == getY() && !player->is_walking()) {
		int FUN = randInt(1, 2);
		if (FUN == 1) {
			player->set_square_ready(false);
			player->reset_coins();
			player->reset_stars();
			get_ptr_to_student_world()->playSound(SOUND_BOWSER_ACTIVATE);
		}
	}

}
  // for dropping square
void Bowser::drop_time() {
	/*
	if (randInt(1, 1) == 1) {
		get_ptr_to_student_world()->playSound(SOUND_DROPPING_SQUARE_CREATED);
		GameObject* toDelete = get_ptr_to_student_world()->get_square_at_location(getX(), getY());
		int index = get_ptr_to_student_world()->get_index_of_go(toDelete);
		delete toDelete;
		get_ptr_to_student_world()->erase_go_at_index(index);
	}
	*/

}
  // 50/50 swap coins or stars of players and play sound
void Boo::doMischief(Player* player) {
	if (!player->is_square_ready())
		return;
	if (player->getX() == getX() && player->getY() == getY() && !player->is_walking()) {
		int FUN = randInt(1, 2);
		if (FUN == 1) {
			player->swap_coins();
		}
		else {
			player->swap_stars();
		}
		player->set_square_ready(false);
		get_ptr_to_student_world()->playSound(SOUND_BOO_ACTIVATE);

	}
}
  // move baddie 
void Enemy::moveTick() {
	if (getWalkDir() == left)
		setDirection(left);
	else
		setDirection(right);
	moveAtAngle(getWalkDir(), 2); // move the object 2 pixels
	cout << ticks_to_move << endl;
	set_ticks_to_move(get_ticks_to_move()-1);
	if (ticks_to_move == 0)
		set_walking(false);
}
  // move vortex, set inactive if hits edge
void Vortex::doActivity(Player* player1, Player* player2) {
	if (!is_active())
		return;
	moveAtAngle(direction, 2); // move the object 2 pixels
	if (getX() < 0 || getX() >= VIEW_WIDTH || getY() < 0 || getY() >= VIEW_HEIGHT) {
		set_inactive();
	}
}
