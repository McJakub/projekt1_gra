#include"header.h"
#include"unit.h"



void select(sf::Sprite target, int current_player, sf::Event event, Unit selected_unit_1, Unit selected_unit_2, std::vector<Unit>units_player_1, std::vector<Unit>units_player_2){

    if(current_player == 1){
        if (event.type == sf::Event::EventType::KeyPressed) {
            if (event.key.code == sf::Keyboard::Key::Space){
                for (int i=0;i < units_player_1.size();i++) {
                    if (units_player_1[i].getGlobalBounds() == target.getGlobalBounds()){
                     std::cout<<"selected"<<std::endl;
                     units_player_1.erase(units_player_1.begin());
                    }
                 }
            }
        }

    }
}





void move(sf::Sprite target, int current_player, sf::Event event, Unit tank, Unit tank2, Unit tank3, Unit tank4){

    if (event.type == sf::Event::EventType::KeyPressed && current_player == 1) {
        if (event.key.code == sf::Keyboard::Key::Num1){
        std::cout<<"test"<<std::endl;

        tank.setPosition(target.getPosition());
        }

}
}


int main()
{

    sf::Vector2f vect1;
    vect1.x = 5;
    vect1.y = 5;

    unsigned int movement = 5;

    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 512), "Tilemap");

    sf::Sprite Target;
    sf::Texture target_texture;
    target_texture.loadFromFile("target.png");
    Target.setTexture(target_texture);
    sf::FloatRect target_box = Target.getGlobalBounds();

    sf::Texture blue_tank1_texture;
    blue_tank1_texture.loadFromFile("bluetank1.png");
    sf::Texture blue_tank2_texture;
    blue_tank2_texture.loadFromFile("bluetank2.png");
    sf::Texture blue_tank3_texture;
    blue_tank3_texture.loadFromFile("bluetank3.png");
    sf::Texture blue_tank4_texture;
    blue_tank4_texture.loadFromFile("bluetank4.png");
    sf::Texture blue_tank5_texture;
    blue_tank5_texture.loadFromFile("bluetank5.png");

    sf::Texture red_tank1_texture;
    red_tank1_texture.loadFromFile("redtank1.png");
    sf::Texture red_tank2_texture;
    red_tank2_texture.loadFromFile("redtank2.png");
    sf::Texture red_tank3_texture;
    red_tank3_texture.loadFromFile("redtank3.png");
    sf::Texture red_tank4_texture;
    red_tank4_texture.loadFromFile("redtank4.png");
    sf::Texture red_tank5_texture;
    red_tank5_texture.loadFromFile("redtank5.png");



    int current_player = 1;


    sf::Font font;
    if (!font.loadFromFile("arial.ttf")){
        std::cout << "failed" << std::endl;
    }


    sf::Text text;

    std::string str = std::to_string(current_player);
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);


    Unit selected_unit_1("unit", 10, 5, 1, 1, 2, 0, 0);
    //selected_unit_1.setTexture(target_texture);
    Unit selected_unit_2("unit", 10, 5 ,1, 2, 2, 0, 0);
   // selected_unit_2.setTexture(target_texture);

   Unit tank_1_0("tank", 10, 5, 1, 1, 2, 1, 1);
   tank_1_0.setTexture(blue_tank1_texture);
   Unit tank_1_1("tank", 10, 5, 1, 1, 2, 1, 2);
   tank_1_1.setTexture(blue_tank2_texture);
   Unit tank_1_2("tank", 10, 5, 1, 1, 2, 1, 3);
   tank_1_2.setTexture(blue_tank3_texture);
   Unit tank_1_3("tank", 10, 5, 1, 1, 2, 1, 4);
   tank_1_3.setTexture(blue_tank4_texture);
   Unit tank_1_4("tank", 10, 5, 1, 1, 2, 1, 5);
   tank_1_4.setTexture(blue_tank5_texture);

   Unit tank_2_0("tank", 10, 5, 1, 2, 2, 9, 1);
   tank_2_0.setTexture(red_tank1_texture);
   Unit tank_2_1("tank", 10, 5, 1, 2, 2, 9, 2);
   tank_2_1.setTexture(red_tank2_texture);
   Unit tank_2_2("tank", 10, 5, 1, 2, 2, 9, 3);
   tank_2_2.setTexture(red_tank3_texture);
   Unit tank_2_3("tank", 10, 5, 1, 2, 2, 9, 4);
   tank_2_3.setTexture(red_tank4_texture);
   Unit tank_2_4("tank", 10, 5, 1, 2, 2, 9, 5);
   tank_2_4.setTexture(red_tank5_texture);




   std:: vector<Unit> units_player_1;
   std:: vector<Unit> units_player_2;

   units_player_1.push_back(tank_1_0);
   units_player_1.push_back(tank_1_1);
   units_player_1.push_back(tank_1_2);
   units_player_1.push_back(tank_1_3);
   units_player_1.push_back(tank_1_4);

   units_player_2.push_back(tank_2_0);
   units_player_2.push_back(tank_2_1);
   units_player_2.push_back(tank_2_2);
   units_player_2.push_back(tank_2_3);
   units_player_2.push_back(tank_2_4);




    int x = window.getSize().x;
    int y = window.getSize().y;

    // define the level with an array of tile indices
    const int level[] =
    {
        2, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        1, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 16, 16))
        return -1;


    sf::Clock clock;

    // run the main loop
    while (window.isOpen())
    {   float delta = float(clock.getElapsedTime().asSeconds());
        clock.restart();

        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();



            if(current_player == 1){
                switch (event.type) {
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                    case sf::Keyboard::Num1:
                        std::cout<<"test2"<<std::endl;
                        if(units_player_1[0].checkActions()>=1  && Target.getPosition().x - units_player_1[0].getPosition().x <= movement*32 && Target.getPosition().y - units_player_1[0].getPosition().y <=movement*32){

                            for (int i=0; i <units_player_2.size();i++) {
                                if(Target.getGlobalBounds()==units_player_2[i].getGlobalBounds()){
                                units_player_2.erase(units_player_2.begin()+i);
                                }
                            }
                         units_player_1[0].setPosition(Target.getPosition());
                         units_player_1[0].setActions(0);
                        }
                        break;
                    case sf::Keyboard::Num2:
                        std::cout<<"test2"<<std::endl;
                        if(units_player_1[1].checkActions()>=1&& Target.getPosition().x - units_player_1[1].getPosition().x <= movement*32 && Target.getPosition().y - units_player_1[1].getPosition().y <=movement*32){

                            for (int i=0; i <units_player_2.size();i++) {
                                if(Target.getGlobalBounds()==units_player_2[i].getGlobalBounds()){
                                units_player_2.erase(units_player_2.begin()+i);
                                }
                            }
                         units_player_1[1].setPosition(Target.getPosition());
                         units_player_1[1].setActions(0);
                        }
                        break;
                    case sf::Keyboard::Num3:
                        std::cout<<"test2"<<std::endl;
                        if(units_player_1[2].checkActions()>=1 && Target.getPosition().x - units_player_1[2].getPosition().x <= movement*32 && Target.getPosition().y - units_player_1[2].getPosition().y <=movement*32){

                            for (int i=0; i <units_player_2.size();i++) {
                                if(Target.getGlobalBounds()==units_player_2[i].getGlobalBounds()){
                                units_player_2.erase(units_player_2.begin()+i);
                                }
                            }
                         units_player_1[2].setPosition(Target.getPosition());
                         units_player_1[2].setActions(0);
                        }
                        break;
                    case sf::Keyboard::Num4:
                        std::cout<<"test2"<<std::endl;
                        if(units_player_1[3].checkActions()>=1 && Target.getPosition().x - units_player_1[3].getPosition().x <= movement*32 && Target.getPosition().y - units_player_1[3].getPosition().y <=movement*32){

                            for (int i=0; i <units_player_2.size();i++) {
                                if(Target.getGlobalBounds()==units_player_2[i].getGlobalBounds()){
                                units_player_2.erase(units_player_2.begin()+i);
                                }
                            }
                         units_player_1[3].setPosition(Target.getPosition());
                         units_player_1[3].setActions(0);
                        }
                        break;
                    case sf::Keyboard::Num5:
                        std::cout<<"test2"<<std::endl;
                        if(units_player_1[4].checkActions()>=1 && Target.getPosition().x - units_player_1[4].getPosition().x <= movement*32 && Target.getPosition().y - units_player_1[4].getPosition().y <=movement*32){

                            for (int i=0; i <units_player_2.size();i++) {
                                if(Target.getGlobalBounds()==units_player_2[i].getGlobalBounds()){
                                units_player_2.erase(units_player_2.begin()+i);
                                }
                            }
                         units_player_1[4].setPosition(Target.getPosition());
                         units_player_1[4].setActions(0);
                        }
                        break;
     }
   }
}

            if(current_player == 2){
                switch (event.type) {
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                    case sf::Keyboard::Num1:
                        std::cout<<"test2"<<std::endl;
                        if(units_player_2[0].checkActions()>=1 && Target.getPosition().x - units_player_2[0].getPosition().x <= movement*32 && Target.getPosition().y - units_player_2[0].getPosition().y <=movement*32){

                            for (int i=0; i <units_player_1.size();i++) {
                                if(Target.getGlobalBounds()==units_player_1[i].getGlobalBounds()){
                                units_player_1.erase(units_player_1.begin()+i);
                                }
                            }
                         units_player_2[0].setPosition(Target.getPosition());
                         units_player_2[0].setActions(0);
                        }
                        break;
                    case sf::Keyboard::Num2:
                        std::cout<<"test2"<<std::endl;
                        if(units_player_2[1].checkActions()>=1&& Target.getPosition().x - units_player_2[1].getPosition().x <= movement*32 && Target.getPosition().y - units_player_2[1].getPosition().y <=movement*32){

                            for (int i=0; i <units_player_1.size();i++) {
                                if(Target.getGlobalBounds()==units_player_1[i].getGlobalBounds()){
                                units_player_1.erase(units_player_1.begin()+i);
                                }
                            }
                         units_player_2[1].setPosition(Target.getPosition());
                         units_player_2[1].setActions(0);
                        }
                        break;
                    case sf::Keyboard::Num3:
                        std::cout<<"test2"<<std::endl;
                        if(units_player_2[2].checkActions()>=1&& Target.getPosition().x - units_player_2[2].getPosition().x <= movement*32 && Target.getPosition().y - units_player_2[2].getPosition().y <=movement*32){

                            for (int i=0; i <units_player_1.size();i++) {
                                if(Target.getGlobalBounds()==units_player_1[i].getGlobalBounds()){
                                units_player_1.erase(units_player_1.begin()+i);
                                }
                            }
                         units_player_2[2].setPosition(Target.getPosition());
                         units_player_2[2].setActions(0);
                        }
                        break;
                    case sf::Keyboard::Num4:
                        std::cout<<"test2"<<std::endl;
                        if(units_player_2[3].checkActions()>=1 && Target.getPosition().x - units_player_2[3].getPosition().x <= movement*32 && Target.getPosition().y - units_player_2[3].getPosition().y <=movement*32){

                            for (int i=0; i <units_player_1.size();i++) {
                                if(Target.getGlobalBounds()==units_player_1[i].getGlobalBounds()){
                                units_player_1.erase(units_player_1.begin()+i);
                                }
                            }
                         units_player_2[3].setPosition(Target.getPosition());
                         units_player_2[3].setActions(0);
                        }
                        break;
                    case sf::Keyboard::Num5:
                        std::cout<<"test2"<<std::endl;
                        if(units_player_2[4].checkActions()>=1 && Target.getPosition().x - units_player_2[4].getPosition().x <= movement*32 && Target.getPosition().y - units_player_2[4].getPosition().y <=movement*32){

                            for (int i=0; i <units_player_1.size();i++) {
                                if(Target.getGlobalBounds()==units_player_1[i].getGlobalBounds()){
                                units_player_1.erase(units_player_1.begin()+i);
                                }
                            }
                         units_player_2[4].setPosition(Target.getPosition());
                         units_player_2[4].setActions(0);
                        }
                        break;
     }
   }
}



            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Key::Enter){
                    if (current_player == 1){
                        current_player = 2;
                        str = std::to_string(current_player);
                        for (int i=0; i <units_player_2.size();i++) {
                            units_player_2[i].setActions(1);
                        }

                        }
                    else if (current_player == 2){
                        current_player = 1;
                        str = std::to_string(current_player);
                        for (int j=0; j <units_player_1.size();j++) {
                            units_player_1[j].setActions(1);
                        }
                    }
                    text.setString(str);
                    std::cout<<str << std::endl;
                }


                if (event.key.code == sf::Keyboard::Key::S && Target.getPosition().y + Target.getLocalBounds().height +16 <= window.getSize().y){
                    Target.move (0.0, 2*16.f);
                }
                if (event.key.code == sf::Keyboard::Key::W && Target.getPosition().y -16 >= 0){
                    Target.move (0.0, 2*-16.f);
                }
                if (event.key.code == sf::Keyboard::Key::A && Target.getPosition().x - 16 >= 0){
                    Target.move (2*-16.f, 0.0);
                }
                if (event.key.code == sf::Keyboard::Key::D && Target.getPosition().x + Target.getLocalBounds().width + 16 <= window.getSize().x){
                    Target.move (2*16.f, 0.0);
                }
            }

            //move(Target,current_player, event, tank, tank2, tank3, tank4);


            //select(Target, current_player,event,selected_unit_1,selected_unit_2,units_player_1,units_player_2);







            for (int i=0; i <units_player_1.size();i++) {
                units_player_1[i].step(Target, current_player, event);
            }
            for (int i=0; i <units_player_2.size();i++) {
                units_player_2[i].step(Target, current_player, event);
            }









        }

        // draw the map

        window.clear();
        window.draw(map);
        window.draw(Target);
        window.draw(text);

        for (int i=0; i <units_player_1.size();i++) {
            window.draw( units_player_1[i]);
        }
        for (int i=0; i <units_player_2.size();i++) {
            window.draw( units_player_2[i]);
        }
        //window.draw(selected_unit_1);
        //window.draw(selected_unit_2);



        window.display();






    }

    return 0;
}
















/*
int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create some shapes






    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...


        // end the current frame
        window.display();
    }

    return 0;
}

*/
