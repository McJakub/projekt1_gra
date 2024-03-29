#ifndef UNITS_H
#define UNITS_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


#include<string>
#include<iostream>

class Unit : public sf::Sprite
{
public:
    Unit(std::string name="test", int hp = 10, int movement = 10, int firepower = 0, int player = 1, int actions = 2, int position_x = 0, int position_y = 0);

    void step(sf::Sprite target, int current_player, sf::Event event);
    void Unit::select(sf::Sprite target, int current_player, sf::Event event, Unit selected_unit_1, Unit selected_unit_2);
    void Unit::position(sf::Sprite target);
    void Unit::setActions(int a);
    int Unit::checkActions();
    // ~Unit();
     //std::string getName();
     //int getWalkSpeed();
     //void setStats(int hp, int str, int dex, int con, int intell, int wis, int cha);

 private:
     std::string name_;
     int hp_;
     int movement_;
     int firepower_;
     int player_;
     int actions_;
     int position_x_;
     int position_y_;
     sf::Texture texture_;
     sf::FloatRect bounding_box_;



};

#endif // UNITS_H


