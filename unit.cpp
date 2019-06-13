#include "unit.h"

Unit::Unit(std::string name, int hp, int movement, int firepower, int player, int position_x, int position_y)
{
    name_ = name;
    hp_ =hp;
    movement_ = movement;
    firepower_ = firepower;
    player_ = player;
    position_x_ =position_x;
    position_y_ = position_y;

    setPosition(position_x * 32, position_y * 32);
}



void Unit::step(sf::Sprite target, int current_player, sf::Event event){

    if(getGlobalBounds() == target.getGlobalBounds() && player_ == current_player){

        switch ( event.type ){
        case sf::Event::KeyReleased:
                        std::cout << "Key has been released" << std::endl;

                        switch (event.key.code)
                        {
                        case sf::Keyboard::Space:

                                 setPosition(target.getPosition());

                            std::cout << "SPACE RELEASED" << std::endl;

                            break;
                        }

        break;
    }

 }


}














