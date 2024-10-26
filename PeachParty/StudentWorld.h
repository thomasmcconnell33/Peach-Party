#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
//#include "Board.h"
//#include "Actor.h"
#include <string>
#include <vector>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
class GameObject;
class Player;

class StudentWorld : public GameWorld
{
public:
  StudentWorld(std::string assetPath);
  virtual int init();
  virtual int move();
  virtual void cleanUp();
  ~StudentWorld() {cleanUp();}
  //void add_player(GameObject* new_player);
  // 
  // Add a new actor to the StudentWorld (not for players, but all other game objects)
  void add_vortex(Player* player);

  bool is_there_a_square_at_location(int x, int y) const;

	// Get a pointer to the square at the specified location
  GameObject* get_square_at_location(int x, int y) const;
  //int get_index_of_go(GameObject* square) const;
  //void erase_go_at_index(int index);

  // get # of coins in the bank
  int get_bank_coins() const { return m_bank_coins; }

  // add coins to the bank (when player passes over a bank square)
  void deposit_bank_coins(int coins) { m_bank_coins += coins; }
  
  // reset # of coins in the bank to zero
  void reset_bank_coins() { m_bank_coins = 0; }

  // Get a random location on the board that contains a square
  GameObject* get_random_square(double x, double y) const;

  // Given a player object pointer, returns a pointer to the other player object. Used for swapping actions.
  Player* get_other_player(Player* p) const;

  Player* get_peach() const { return m_peach; }
  Player* get_yoshi() const { return m_yoshi; }

private:
	Player* m_peach;
	Player* m_yoshi;
	std::vector<GameObject*> m_actors;
	std::string m_displayText;
	int m_bank_coins = 0;
};

#endif // STUDENTWORLD_H_
