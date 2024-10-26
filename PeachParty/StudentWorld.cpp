#include "StudentWorld.h"
#include "GameConstants.h"
#include <string>
#include "Actor.h"
#include "Board.h" // required to use our provided class
#include <iostream>
#include <sstream>

using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
	return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h, and Actor.cpp

StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
    m_peach = nullptr;
    m_yoshi = nullptr;
}

int StudentWorld::init()
{
	startCountdownTimer(99);  // this placeholder causes timeout after 5 seconds

    Board bd;
    char bdNum = '0' + getBoardNumber();
    string board_file = assetPath() + "board0" + bdNum + ".txt";
    Board::LoadResult result = bd.loadBoard(board_file);
    if (result == Board::load_fail_file_not_found)
        cerr << "Could not find board01.txt data file\n";
    else if (result == Board::load_fail_bad_format)
        cerr << "Your board was improperly formatted\n";
    else if (result == Board::load_success) {
        cerr << "Successfully loaded board\n";
        for (int i = BOARD_WIDTH - 1; i >= 0; i--) {
            for (int j = 0; j < BOARD_HEIGHT; j++) {
                Board::GridEntry ge = bd.getContentsOf(i, j); // x=i, y=j
                switch (ge) {
                case Board::empty:
                    cout << "Location " << i << "," << j <<" is empty\n";
                    break;
                case Board::player:
                    cout << "Location " << i << "," << j << " has Peach & Yoshi and a blue coin square\n";
                    m_peach = new Player(IID_PEACH, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this, 1);
                    m_yoshi = new Player(IID_YOSHI, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this, 2);
                    m_actors.push_back(new CoinSquare(IID_BLUE_COIN_SQUARE, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this, 3));
                    //m_board[i][j] = '+';
                    break;
                case Board::red_coin_square:
                    cout << "Location " << i << "," << j << " has a red coin square\n";
                    m_actors.push_back(new CoinSquare(IID_RED_COIN_SQUARE, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this, -3));
                    //m_board[i][j] = '-';
                    break;
                case Board::blue_coin_square:
                    cout << "Location " << i << "," << j << " has a blue coin square\n";
                    m_actors.push_back(new CoinSquare(IID_BLUE_COIN_SQUARE, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this, 3));
                    //m_board[i][j] = '+';
                    break;
                case Board::star_square:
                    cout << "Location " << i << "," << j << " has a star square\n";
                    m_actors.push_back(new StarSquare(IID_STAR_SQUARE, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this));
                    break;
                case Board::up_dir_square:
                    cout << "Location " << i << "," << j << " has a up square\n";
                    m_actors.push_back(new DirectionalSquare(IID_DIR_SQUARE, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this, 90, 90));
                    break;
                case Board::left_dir_square:
                    cout << "Location " << i << "," << j << " has a left square\n";
                    m_actors.push_back(new DirectionalSquare(IID_DIR_SQUARE, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this, 180, 180));
                    break;
                case Board::down_dir_square:
                    cout << "Location " << i << "," << j << " has a down square\n";
                    m_actors.push_back(new DirectionalSquare(IID_DIR_SQUARE, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this, 270, 270));
                    break;
                case Board::right_dir_square:
                    cout << "Location " << i << "," << j << " has a right square\n";
                    m_actors.push_back(new DirectionalSquare(IID_DIR_SQUARE, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this, 0, 0));
                    break;
                case Board::bank_square:
                    cout << "Location " << i << "," << j << " has a bank square\n";
                    m_actors.push_back(new BankSquare(IID_BANK_SQUARE, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this));
                    break;
                case Board::event_square:
                    cout << "Location " << i << "," << j << " has a event square\n";
                    m_actors.push_back(new EventSquare(IID_EVENT_SQUARE, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this));
                    break;
                case Board::bowser:
                    cout << "Location " << i << "," << j << " has a event square\n";
                    m_actors.push_back(new Bowser(IID_BOWSER, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this));
                    m_actors.push_back(new CoinSquare(IID_BLUE_COIN_SQUARE, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this, 3));
                    break;
                case Board::boo:
                    cout << "Location " << i << "," << j << " has a event square\n";
                    m_actors.push_back(new Boo(IID_BOO, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this));
                    m_actors.push_back(new CoinSquare(IID_BLUE_COIN_SQUARE, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, this, 3));
                    break;
                default:
                    cout << "Not yet implemented" << endl;
                }
            }
        }
    }

    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit ESC.
    // Notice that the return value GWSTATUS_NOT_IMPLEMENTED will cause our framework to end the game.

    ostringstream displayText;
    string peachVOR = "";
    string yoshiVOR = "";
    if (m_peach->has_vortex())
        peachVOR = " VOR";
    if (m_yoshi->has_vortex())
        yoshiVOR = " VOR";
      // display text, varies based on who is which player number
    if (m_peach->getPlayerNumber() == 1)
        displayText << "P1 Roll: " << m_peach->get_dice() << " Stars: " << m_peach->get_stars() << " $$: " << m_peach->get_coins() <<peachVOR<<" | Time: " << timeRemaining() << " | Bank: " << get_bank_coins() << " | P2 Roll: " << m_yoshi->get_dice() << " Stars: " << m_yoshi->get_stars() << " $$: " << m_yoshi->get_coins() <<yoshiVOR<<"";
    else
        displayText << "P1 Roll: " << m_yoshi->get_dice() << " Stars: " << m_yoshi->get_stars() << " $$: " << m_yoshi->get_coins() <<yoshiVOR<<" | Time: " << timeRemaining() << " | Bank: " << get_bank_coins() << " | P2 Roll: " << m_peach->get_dice() << " Stars: " << m_peach->get_stars() << " $$: " << m_peach->get_coins() << peachVOR<<"";

    m_displayText = displayText.str();  
    setGameStatText(m_displayText);
    
      // end game condition
    if (timeRemaining() <= 0) {
        //play SOUND_GAMe...
        playSound(SOUND_GAME_FINISHED);
        // call setFinalScore()...
        int winnerStars = 0;
        int winnerCoins = 0;
        if (m_peach->get_stars() > m_yoshi->get_stars())
            winnerStars = m_peach->get_stars();
        else
            winnerStars = m_yoshi->get_stars();
        if (m_peach->get_coins() > m_yoshi->get_coins())
            winnerCoins = m_peach->get_coins();
        else
            winnerCoins = m_yoshi->get_coins();
        setFinalScore(winnerStars, winnerCoins);
        // if peach won...
        if (m_peach->get_stars() > m_yoshi->get_stars())
            return GWSTATUS_PEACH_WON;
        if (m_peach->get_stars() < m_yoshi->get_stars())
            return GWSTATUS_YOSHI_WON;
        if (m_peach->get_coins() > m_yoshi->get_coins())
            return GWSTATUS_PEACH_WON;
        if (m_peach->get_coins() < m_yoshi->get_coins())
            return GWSTATUS_PEACH_WON;
        int rng = randInt(1, 2);
        if (rng == 1)
            return GWSTATUS_PEACH_WON;
        else
            return GWSTATUS_YOSHI_WON;
    }
    m_peach->doSomething();
    m_yoshi->doSomething();
    
      // make everything do something!
    vector<GameObject*>::iterator it = m_actors.begin();
    while (it != m_actors.end()) {
        (*it)->doSomething();
        it++;
    }

	return GWSTATUS_CONTINUE_GAME;
}
  // cleanup time!
void StudentWorld::cleanUp()
{
    if (m_peach != nullptr) {
        delete m_peach;
        m_peach = nullptr;
    }
    if (m_yoshi != nullptr) {
        delete m_yoshi;
        m_yoshi = nullptr;
    }
    vector<GameObject*>::iterator it = m_actors.begin();
    while (it != m_actors.end()) {
        if (*it!=nullptr)
            delete* it;
        it = m_actors.erase(it);
    }
}

// Add a new vortex to the StudentWorld (not for players, but all other game objects)
void StudentWorld::add_vortex(Player* player) {
    m_actors.push_back(new Vortex(IID_VORTEX, player->getX(), player->getY(), this, player->getWalkDir()));
}
/* in progress...
int StudentWorld::get_index_of_go(GameObject* square) const {
    std::vector<GameObject*>::const_iterator it;
    it = m_actors.begin();
    int count = 0;
    while (it != m_actors.end()) {
        if ((*it)->getX() == square->getX() && (*it)->getY() == square->getY())
            return count;
        it++;
        count++;
    }
    return count;
}


void StudentWorld::erase_go_at_index(int index)  {
    if (index < 0)
        return;
    m_actors.erase(m_actors.begin()+ index);
}
*/
  // function name
bool StudentWorld::is_there_a_square_at_location(int x, int y) const {

    std::vector<GameObject*>::const_iterator it;
    it = m_actors.begin();
    while (it != m_actors.end()) {
        if ((*it)->getX() == x && (*it)->getY() == y)
            return true;
        it++;
    }
    return false;
} 
  // function name
GameObject* StudentWorld::get_square_at_location(int x, int y) const {
    std::vector<GameObject*>::const_iterator it;
    it = m_actors.begin();
    while (it != m_actors.end()) {
        if ((*it)->getX() == x && (*it)->getY() == y)
            return *it;
        it++;
    }
    return nullptr;
}

  // function name
GameObject* StudentWorld::get_random_square(double x, double y) const {
    for (;;) {
        int squareIndex = randInt(0, m_actors.size());
        if (m_actors[squareIndex]->is_a_square())
            return m_actors[squareIndex];
    }
}
  // function name
Player* StudentWorld::get_other_player(Player* p) const
{ if (p->getPlayerNumber() == m_peach->getPlayerNumber())
        return m_yoshi; 
  return m_peach; 
}



