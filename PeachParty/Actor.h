#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "StudentWorld.h"

#include <vector>

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

//class StudentWorld;

class GameObject : public GraphObject
{
public:
	GameObject(int imageID, int startX, int startY, StudentWorld* world, int dir = right, int depth = 0) :GraphObject(imageID, startX, startY, dir, depth), sw_(world) {}
	virtual void doSomething() = 0; // DO I NEED?
	virtual bool is_a_square() const = 0;
	virtual bool can_be_hit_by_vortex() const = 0;
	virtual void hit_by_vortex() {}  // tell an game object it has been hit by a vortex  bool is_active() const;        // is a game object still alive or should it be removed from game?
	bool is_active() const { return active_; }        // is a game object still alive or should it be removed from game?
	void set_inactive() { active_ = false; }
	StudentWorld* get_ptr_to_student_world()  {return sw_; }
	virtual bool isDirectionalSquare() { return false; }
private:
	StudentWorld* sw_;
	bool active_ = true;
	bool isPeachNew = true;
	bool isYoshiNew = true;
};

class Player : public GameObject {
public:
	Player(int imageID, int startX, int startY, StudentWorld* world, int playerNumber) : GameObject(imageID, startX, startY, world) {
		m_playerNumber = playerNumber;
		m_walking;
	}
	void doSomething();
	void reset_coins() { m_coins = 0; }
	void reset_stars() { m_stars = 0; }
	bool is_a_square() const { return false; }
	bool can_be_hit_by_vortex() const { return false; }
	int get_dice() const { return die_roll; }   // used to display stats on status line
	int get_stars() const {	return m_stars;}   // used to display stats on status line
	int get_coins() const { return m_coins; }   // used to display stats on status line
	bool has_vortex() const { return m_vortex; } // used to display stats on status line
	bool is_walking() const { return ticks_to_move!=0; }
	void adjust_stars(const int this_much) { m_stars += this_much; if (m_stars < 0) m_stars = 0; }
	void adjust_coins(const int this_much) { m_coins += this_much; if (m_coins < 0) m_coins = 0; }
	void swap_positions();  // with other player
	void swap_stars();  // with other player
	void swap_coins();  // with other player
	void equip_with_vortex_projectile() { m_vortex = true; }
	void teleport_me_to_random_sq();
	bool is_square_ready() const { return square_ready; }
	void set_square_ready(bool value) { square_ready = value; }
	int getPlayerNumber() const { return m_playerNumber; }
	void moveTick();


	int getTicksToMove() const {
		return ticks_to_move;
	}
	void changeTicksToMove(int ticks) {
		ticks_to_move += ticks;
		if (ticks_to_move <= 0)
			m_walking = false;
		else
			m_walking = true;
	}
	void setTicksToMove(int ticks) {
		ticks_to_move = ticks;
	}
	int getWalkDir() const {
		return m_walkDirection;
	}
	void setWalkDir(int newDir) {
		m_walkDirection = newDir;
	}

private:
	int ticks_to_move = 0;
	int m_walkDirection = right;
	int m_playerNumber;
	int die_roll = 0;
	int m_coins = 0;
	int m_stars = 0;
	bool square_ready = false;
	bool m_vortex = false;
	bool just_teleported = false;
	bool m_walking = false;
	bool game_start = true;
};

  // Objects!

class ActivatingObject : public GameObject {
public:
	ActivatingObject(int imageID, int startX, int startY, StudentWorld* world, int dir = right, int depth = 1) : GameObject(imageID, startX, startY, world, dir, depth) {}
	virtual void doSomething();
	virtual void doActivity(Player*) = 0;
	virtual void doActivity(Player* player1, Player* player2) { return; }

private:

};

class ActivateOnPlayer : public ActivatingObject {
public:
	ActivateOnPlayer(int imageID, int startX, int startY, StudentWorld* world, bool activate_when_go_lands = true, int dir = right, int depth = 1 ) : ActivatingObject(imageID, startX, startY, world, dir, depth) {}

};

class Vortex : public ActivatingObject {
public:
	Vortex(int imageID, int startX, int startY, StudentWorld* sw, int dir, int depth = 0) : ActivatingObject(imageID, startX, startY, sw, dir, depth), direction(dir) {}//?char dir or DIR dir
	bool is_a_square() const { return false; }
	bool can_be_hit_by_vortex() const { return false; }
	virtual void doActivity(Player* player1, Player* player2);
	virtual void doActivity(Player* player) { return; }
	
private:
	int direction;
};

class StarSquare : public ActivateOnPlayer {
public:
	StarSquare(int imageID, int startX, int startY, StudentWorld* sw) : ActivateOnPlayer(imageID, startX, startY, sw, true) {}
	bool is_a_square() const { return true; }
	bool can_be_hit_by_vortex() const { return false; }
	virtual void doActivity(Player*);

};

class CoinSquare : public ActivateOnPlayer {
public:
	CoinSquare(int imageID, int startX, int startY, StudentWorld* world, int adjust_coins_by) : ActivateOnPlayer(imageID, startX, startY, world, true), adjust_coins_by_(adjust_coins_by) {}
	virtual bool is_a_square() const { return true; }
	virtual bool can_be_hit_by_vortex() const { return false; }
	virtual void doActivity(Player*);
private:
	int adjust_coins_by_; // determines if +3 or -3
};

class DirectionalSquare : public ActivateOnPlayer {
public:
	DirectionalSquare(int imageID, int startX, int startY, StudentWorld* sw, int dir, int angle) : ActivateOnPlayer(imageID, startX, startY, sw, true, dir), angle_(angle) {}//?char dir
	bool is_a_square() const { return true; }
	bool can_be_hit_by_vortex() const { return false; }
	virtual void doActivity(Player*);
	bool isDirectionalSquare() { return true; }
private:
	int angle_;
};

class BankSquare : public ActivateOnPlayer {
public:
	BankSquare(int imageID, int startX, int startY, StudentWorld* sw) : ActivateOnPlayer(imageID, startX, startY, sw, true) {}
	bool is_a_square() const { return true; }
	bool can_be_hit_by_vortex() const { return false; }
	virtual void doActivity(Player*);
};

class EventSquare : public ActivateOnPlayer {
public:
	EventSquare( int imageID, int startX, int startY, StudentWorld* sw) : ActivateOnPlayer(imageID, startX, startY, sw, true) {}
	bool is_a_square() const { return true; }
	bool can_be_hit_by_vortex() const { return false; }
	virtual void doActivity(Player*);
};

class Enemy : public ActivateOnPlayer {
public:
	Enemy( int imageID, int startX, int startY, StudentWorld* sw,
		int dir = right, double size = 1, int depth = 0, bool activate_when_go_lands = true, int num_sq_to_move = 0, int number_of_ticks_to_pause=180)
		: ActivateOnPlayer(imageID, startX, startY, sw, true, dir, depth), ticks_paused(number_of_ticks_to_pause), squares_to_move(num_sq_to_move) {}
	virtual void doMischief(Player*) = 0;
	void doActivity(Player* player) { return; }
	void doActivity(Player* player1, Player* player2);
	bool is_a_square() const { return false; }
	bool can_be_hit_by_vortex() const { return true; }
	void hit_by_vortex() { return; }  // called when enemy is hit by a vortex projectile (called by vortex projectile)
	void set_ticks_to_move(int ticks) { ticks_to_move = ticks; }
	int get_ticks_to_move() { return ticks_to_move; }
	void set_ticks_paused(int ticks) { ticks_paused = ticks; }
	int get_ticks_paused() { return ticks_paused; }
	void set_squares_to_move(int squares) { squares_to_move = squares; }
	int get_squares_to_move() { return squares_to_move; }
	virtual int random_num() = 0;
	void set_walking(bool value) { m_walking = value; }
	bool is_walking() const { return m_walking; }
	void Enemy::moveTick();
	virtual void drop_time() = 0;
	
	int getWalkDir() const {
		return m_walkDirection;
	}
	void setWalkDir(int newDir) {
		m_walkDirection = newDir;
	}
private:
	int ticks_paused;
	int squares_to_move;
	int ticks_to_move;
	int m_walkDirection = right;
	bool m_walking = false;
	
};

class DroppingSquare : public ActivateOnPlayer {
public:
	DroppingSquare( int imageID, int startX, int startY, StudentWorld* sw);
	bool is_a_square() const { return true; }
	bool can_be_hit_by_vortex() const { return false; }
};

class Bowser : public Enemy {
public:
	Bowser(int imageID, int startX, int startY, StudentWorld* sw) : Enemy(imageID, startX, startY, sw) {}
	void doMischief(Player*);
	virtual int random_num() { return randInt(1, 10); }
	virtual void drop_time();
};

class Boo : public Enemy {
public:
	Boo( int imageID, int startX, int startY, StudentWorld* sw) : Enemy(imageID, startX, startY, sw) {}
	void doMischief(Player*);
	virtual int random_num() { return randInt(1, 3); }
	virtual void drop_time() { return; }

};


#endif // ACTOR_H_
