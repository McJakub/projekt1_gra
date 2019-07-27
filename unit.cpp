#include "unit.h"

Unit::Unit(std::string name, int hp, int movement, int firepower, int player, int actions, int position_x, int position_y)
{
    name_ = name;
    hp_ =hp;
    movement_ = movement;
    firepower_ = firepower;
    player_ = player;
    actions_ = actions;
    position_x_ =position_x;
    position_y_ = position_y;

    setPosition(position_x * 32, position_y * 32);
}

void Unit::setActions(int a){
    actions_ = a;
}

int Unit::checkActions(){
    return actions_;
}

void Unit::position(sf::Sprite target){
    setPosition(target.getPosition());
}

void Unit::step(sf::Sprite target, int current_player, sf::Event event){


    sf::Vector2f vect1;
    vect1.x = 5;
    vect1.y = 5;





    if(getPosition() - target.getPosition() == vect1 ){

    }




/*

    switch (event.type) {
    case sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::Space:
            if (getGlobalBounds() == target.getGlobalBounds() && player_ == current_player){
                    std::cout<<"test2"<<std::endl;
                    if (event.key.code == sf::Keyboard::Key::X){
                        std::cout << "X"<<std::endl;
                        setPosition(target.getPosition());
                    }
            }
            }
        }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){
        std::cout << "X"<<std::endl;
        setPosition(target.getPosition());
    }

    if (event.type == sf::Event::EventType::KeyPressed && player_==current_player) {

        if (getGlobalBounds() == target.getGlobalBounds() && player_ == current_player && event.key.code == sf::Keyboard::Key::Space){
           std::cout<<"test"<<std::endl;
           }
    }




*/

}














