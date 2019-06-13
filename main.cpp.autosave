#include"header.h"
#include"unit.h"




int main()
{


    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 512), "Tilemap");

    sf::Sprite Target;
    sf::Texture target_texture;
    target_texture.loadFromFile("target.png");
    Target.setTexture(target_texture);
    sf::FloatRect target_box = Target.getGlobalBounds();


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


   Unit tank("tank", 10, 10, 1, 1, 1, 1);
   tank.setTexture(target_texture);
   //tank.setPosition(32,32);
    


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




            while ( window.pollEvent( event ) )
                    {
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && Target.getPosition().y + Target.getLocalBounds().height +16 <= window.getSize().y ){
                Target.move (0.0, 2*16.f);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && Target.getPosition().y -16 >= 0){
                Target.move (0.0, 2*-16.f);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && Target.getPosition().x - 16 >= 0){
                Target.move (2*-16.f, 0.0);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && Target.getPosition().x + Target.getLocalBounds().width + 16 <= window.getSize().x){
                Target.move (2*16.f, 0.0);
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){
                if (current_player == 1){
                    current_player = 2;
                    str = std::to_string(current_player);
                    }
                else if (current_player == 2){
                    current_player = 1;
                    str = std::to_string(current_player);
                }
                text.setString(str);
                std::cout<<str << std::endl;
            }


        tank.step(Target, current_player, event);








        }

        // draw the map

        window.clear();
        window.draw(map);
        window.draw(Target);
        window.draw(text);
        window.draw(tank);



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
