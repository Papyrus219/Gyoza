#include "simple_electrostatistic_exp.hpp"
#include "../engine/technicals/rendering.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace exp1
{
    std::vector<std::unique_ptr<gyoza::Electric_molecule>> molecules{};

    void Start(std::string &mode)
    {
        sf::Music background{"../../audio/background.wav"};
        background.setLooping(true);
        background.play();

        sf::RenderWindow window{};

       
            if(mode == "-T" || mode == "-t")
            {
                Text_setup();
            }
            else
            {
                Mouse_setup(&window);
            }

        if(!window.isOpen()) window.create(sf::VideoMode{{1200,1000}}, "Gyoza");
        sf::Clock clock{};

        while(window.isOpen())
        {
            window.clear();
            gyoza::Render(molecules, window);
            window.display();

            if(clock.getElapsedTime() >= sf::seconds(0.016666667) )
            {
                gyoza::Molecules_reactions(molecules);

                clock.restart();
            }

            while(std::optional<sf::Event> event = window.pollEvent())
            {
                if(event->is<sf::Event::Closed>())
                {
                    window.close();
                }
                if(auto key = event->getIf<sf::Event::KeyPressed>())
                {
                    if(key->scancode == sf::Keyboard::Scan::Escape)
                    {
                        window.close();
                    }
                    else if(key->scancode == sf::Keyboard::Scan::E && (mode == "-T" || mode == "-t"))
                    {
                        Text_expansion();
                    }
                    else if(key->scancode == sf::Keyboard::Scan::Space)
                    {
                        clock.stop();
                        Mouse_setup(&window);
                        clock.start();
                    }
                }
            }

            if(clock.getElapsedTime() >= sf::seconds(0.016666667))
            {
                gyoza::Molecules_reactions(molecules);

                clock.restart();
            }
        }
    }

    void Mouse_setup(sf::RenderWindow *window)
    {
        if(!window->isOpen()) window->create(sf::VideoMode{{1200,1000}}, "Gyoza");
        gyoza::Molecule_type m_type{gyoza::Molecule_type::proton};

        while(window->isOpen())
        {
            sf::Vector2f mouse_pos = static_cast<sf::Vector2f>( sf::Mouse::getPosition(*window) );
            gyoza::Electric_molecule tmp_mol{m_type, {mouse_pos.x, mouse_pos.y}};

            window->clear();
            gyoza::Render(molecules, *window);
            window->draw(tmp_mol.sprite);
            window->display();

            while(std::optional<sf::Event> event = window->pollEvent())
            {
                if(event->is<sf::Event::Closed>())
                {
                    window->close();
                }
                else if(auto key = event->getIf<sf::Event::KeyPressed>())
                {
                    if(key->scancode == sf::Keyboard::Scan::Escape)
                    {
                        window->close();
                    }
                    else if(key->scancode == sf::Keyboard::Scan::Space)
                    {
                        return;
                    }
                }
                else if(auto mouse_key = event->getIf<sf::Event::MouseButtonPressed>())
                {
                    if(mouse_key->button == sf::Mouse::Button::Left)
                    {
                        molecules.push_back(std::make_unique<gyoza::Electric_molecule>(std::move(tmp_mol)));
                    }
                    else if(mouse_key->button == sf::Mouse::Button::Right)
                    {
                        for(int i=molecules.size()-1; i>=0;i--)
                        {
                            if(molecules[i]->sprite.getGlobalBounds().contains(mouse_pos))
                            {
                                molecules.erase(molecules.begin() + i);
                                break;
                            }
                        }
                    }
                    else if(mouse_key->button == sf::Mouse::Button::Middle)
                    {
                        m_type = (m_type == gyoza::Molecule_type::proton)? gyoza::Molecule_type::electron : gyoza::Molecule_type::proton;
                    }
                }
            }
        }
    }

    void Text_setup()
    {
        char type{};
        std::string buffor;

        gyoza::Molecule_type mole_type{};
        float x{}, y{};
        float size{};

        std::cout << "#SETUP START" << std::endl;;
        std::cout << "#Enter molecule size: \n";
        std::cin >> size;   std::getline(std::cin,buffor);

        std::cout << "#(E - electron, N - neutron, P - Proton, X - end of setup)\n";

        while(true)
        {
            std::cout << "#Enter molecule type to add: \n";
            std::cin >> type;   std::getline(std::cin,buffor);

            if(type == 'X')
                break;
            switch(type)
            {
                case 'E':
                    mole_type = gyoza::Molecule_type::electron;
                    break;
                case 'N':
                    mole_type = gyoza::Molecule_type::neutron;
                    break;
                case 'P':
                    mole_type = gyoza::Molecule_type::proton;
                    break;
                default:
                    std::cerr << "Error! Unrecognised type! Experiment stop!\n";
                    std::exit(1);
                    break;
            }

            std::cout << "#Enter coordinates: \n";
            std::cin >> x >> y;     std::getline(std::cin,buffor);

            molecules.push_back( std::make_unique<gyoza::Electric_molecule>(mole_type,Vec2{x,y},size) );
        }

        std::cout << "SETUP END" << std::endl;
    }

    void Text_expansion()
    {
        char type{};
        std::string buffor;

        gyoza::Molecule_type mole_type{};
        float x{}, y{};

        std::cout << "#Expansion START" << std::endl;;
        std::cout << "#(E - electron, N - neutron, P - Proton, X - end of expansion)\n";

        while(true)
        {
            std::cout << "#Enter molecule type to add: \n";
            std::cin >> type;   std::getline(std::cin,buffor);

            if(type == 'X')
                break;
            switch(type)
            {
                case 'E':
                    mole_type = gyoza::Molecule_type::electron;
                    break;
                case 'N':
                    mole_type = gyoza::Molecule_type::neutron;
                    break;
                case 'P':
                    mole_type = gyoza::Molecule_type::proton;
                    break;
                default:
                    std::cerr << "Error! Unrecognised type! Experiment stop!\n";
                    std::exit(1);
                    break;
            }

            std::cout << "#Enter coordinates: \n";
            std::cin >> x >> y;     std::getline(std::cin,buffor);

            molecules.push_back( std::make_unique<gyoza::Electric_molecule>(mole_type,Vec2{x,y},molecules[ molecules.size()-1 ]->radius) );
        }

        std::cout << "Expansion END" << std::endl;
    }

}


