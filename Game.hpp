/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.hpp
 * Author: Tberdy
 *
 * Created on 9 mars 2017, 23:03
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "lib/XPlatform/XPlatform.h"

#include "Box.hpp"

#include "Navire/Navire.hpp"
#include "Navire/Croiseur.hpp"
#include "Navire/Cuirasse.hpp"
#include "Navire/Destroyer.hpp"
#include "Navire/SousMarin.hpp"

#include "const.hpp"

struct Cursor {
    int lig;
    int col;
};

class Game {
public:
    Game();
    virtual ~Game();
    
    void loop();
    
    void initBoat(int player);
private:
    std::vector<std::vector<std::vector<Box*> > > m_grids;
    std::vector<std::vector<Navire*> > m_boats;
    std::vector<std::string> m_messageBus;
    std::vector<Cursor*> m_cursors;
    int m_state;
    std::vector<int> m_tabState;
    int m_memoryMove;
    
    int other(int player);
    bool checkKeys(char move, int action);
    void eventManager(int player);
    void eventManager2(int player);
    
    void fire(int player, Navire* attaquant, Box* cible);
    
    bool checkTurn(int player, Navire* selected, const std::vector<Position*>& newPos);
    void genTurnPos(int player, Navire* selected, std::vector<Position*>& newPos);
    bool turn(int player, Navire* selected);
    
    void makeVisible(int player, Box* cible);
    void display2(int player);
    
    char keyToDir(char key);
    void genBoat(int player, int type);
    bool findPlace(int player, int size, std::vector<Position*>& pos,char& dir);
    bool checkIfPosValid(int player, const std::vector<Position*>& pos);
    
    void moveCursor(int player, int lig, int col);
    void resetCursor(int player);
};

#endif /* GAME_HPP */

