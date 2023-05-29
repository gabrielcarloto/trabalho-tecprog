#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Gerenciador_Grafico.h"

namespace Jogo{
    class Menu{
        private:
        sf::RenderWindow * janelaMenu;
        sf::Font * fonte;
        sf::Texture * img;
        sf::Sprite * fundo;


        sf::Vector2f coordMouse;

        std::vector<const char *> opcoes;
        std::vector<sf::Vector2f> coords;
        std::vector<sf::Text> texto;
        std::vector<std::size_t> tamanhoFonte;
        
        public:
        Menu()=default;
        ~Menu() = default;
        
        void loopMenu();
        void carregaBotoes();
        void imprimeMenu();

        void execMenu();

    };
}