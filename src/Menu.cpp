#include "Menu.h"

namespace Jogo{
    void Menu::carregaBotoes(){
        janelaMenu->create(sf::VideoMode(1178,720), "Menu", sf::Style::Titlebar | sf::Style::Close);
        janelaMenu->setPosition(sf::Vector2i(0,0));
        
        
        fonte->loadFromFile("../assets/fonts/8-BIT WONDER.TTF");
        img->loadFromFile("./assets/images/menu.jpg");
        fundo->setTexture(*img);

        coordMouse ={0,0};

        opcoes= {"CONTINUAR","FASE 1","SAIR" };

        texto.resize(5);

        coords = {{274,151},{274,200},{274,250}};
        tamanhoFonte = {20,20,20};

        for (std::size_t i{}; i < texto.size(); i++){
            texto[i].setFont(*fonte); 
            texto[i].setString(opcoes[i]); 
            texto[i].setCharacterSize(tamanhoFonte[i]);
            texto[i].setOutlineColor(sf::Color::White);
            texto[i].setPosition(coords[i]);
        }
    }
    void Menu::loopMenu(){
        sf::Event event;

        while(janelaMenu->pollEvent(event)){
            if( event.type == sf::Event::Closed){
                janelaMenu->close();
            }

            coordMouse = janelaMenu->mapPixelToCoords(sf::Mouse::getPosition(*janelaMenu));

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(texto[0].getGlobalBounds().contains(coordMouse)){
                    //continuar
                    janelaMenu->close();
                }
            }

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(texto[1].getGlobalBounds().contains(coordMouse)){
                    //carregar fase1
                    janelaMenu->close();
                }
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(texto[2].getGlobalBounds().contains(coordMouse)){
                    //sair
                    janelaMenu->close();
                }
            }
        
        
        }


    }

    void Menu::imprimeMenu(){
        janelaMenu->clear();
        janelaMenu->draw(*fundo);
    for(auto t : texto){
        janelaMenu->draw(t); 
    }
        janelaMenu->display();
    }

    void Menu::execMenu(){
    while(janelaMenu->isOpen()){
        loopMenu();
        imprimeMenu();
    }
    }
}