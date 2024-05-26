#include "libincludes.h"
#include "functions.h"

int main()
{
    constexpr std::uint32_t tex_width = 1024u, tex_height = 1024u;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "CSG2D");
    sf::View view(sf::Vector2f(0.f, 0.f), sf::Vector2f(1920.f/1080.f*tex_width, tex_height));

    window.setFramerateLimit(60);

    sf::Texture csg2d_output_texture;
    csg2d_output_texture.create(tex_width, tex_height);
    sf::Sprite csg2d_sprite;
    csg2d_sprite.setTexture(csg2d_output_texture);
    csg2d_sprite.setOrigin(csg2d_output_texture.getSize().x/2.f, csg2d_output_texture.getSize().y/2.f);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Resized)
            {
                std::cout << "Resize: " << event.size.width << ", " << event.size.height << std::endl;

                view.setSize(float(event.size.width)/event.size.height*tex_width, tex_height);
            }

            if(event.type == sf::Event::Closed) { window.close(); }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            if(auto shape_shp = createCSG2DScene())
            {
                updateTexture(csg2d_output_texture, *shape_shp, sf::Color(0u, 0u, 0u, 255u), sf::Color(255u, 255u, 255u, 255u));
            }
        }

        window.clear();
        window.setView(view);


//        sf::CircleShape insideCircleShape;
//        insideCircleShape.setRadius(150);
//        insideCircleShape.setOutlineColor(sf::Color::Red);
//        insideCircleShape.setOutlineThickness(5);
//        insideCircleShape.setPosition(0, 0);
//
//        window.draw(insideCircleShape);

//        sf::ConvexShape polygon;
//        polygon.setPointCount(7);
//        polygon.setPoint(1, sf::Vector2f(170.f, -120.f));
//        polygon.setPoint(2, sf::Vector2f(170.f, -260.f));
//        polygon.setPoint(3, sf::Vector2f(000.f, -360.f));
//        polygon.setPoint(4, sf::Vector2f(-170.f, -260.f));
//        polygon.setPoint(5, sf::Vector2f(-170.f, -120.f));
//        polygon.setOutlineColor(sf::Color::Blue);
//        polygon.setOutlineThickness(5);
//        polygon.setPosition(10, 20);
//
//        window.draw(polygon);
        window.draw(csg2d_sprite);

        window.setView(window.getDefaultView());
        window.display();
    }

    return 0;
}

