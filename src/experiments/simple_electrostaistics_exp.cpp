#include "simple_electrostatistic_exp.hpp"
#include "../engine/technicals/rendering.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace exp1
{
    std::vector<gyoza::Electric_molecule> molecules{};

    void Setup()
    {
        char type{};
        std::string buffor;

        gyoza::Molecule_type mole_type{};
        float x{}, y{};
        float size{};

        std::cout << "#ELECTRONS AND PROTONS REACTIONS\n";
        std::cout << "#Powered with Gyoza by: Papyrus219\n\n";
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

            molecules.push_back( {mole_type,{x,y},size} );
        }

        std::cout << "SETUP END" << std::endl;
    }

    void Start()
    {
        sf::Music background{"../../audio/background.wav"};
        background.setLooping(true);
        background.play();

        sf::RenderWindow window{sf::VideoMode{{1200,1000}}, "Gyoza"};

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
                        window.close();
                    if(key->scancode == sf::Keyboard::Scan::E)
                        Expansion();
                }
            }

        }
    }

    void Expansion()
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

            molecules.push_back( {mole_type,{x,y},molecules[ molecules.size()-1 ].size} );
        }

        std::cout << "Expansion END" << std::endl;
    }

}


