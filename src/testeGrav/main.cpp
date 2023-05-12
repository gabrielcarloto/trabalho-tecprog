#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(384, 240), "teste"/*,sf::Style::Titlebar | sf::Style::Close*/);
    window.setFramerateLimit(60); //60fps

    const float altchao = 16.f,vel = 0.3f;
    float frame = 0.f; //para usar o spritesheet

    /*sf::RectangleShape chao(sf::Vector2f(window.getSize().x,altchao));
    
    chao.setFillColor(sf::Color::White);*/

    sf::Texture texture,texChao,texFundo;
    texChao.loadFromFile("./img/chao.png");
    texFundo.loadFromFile("./img/back.png");
    texture.loadFromFile("./img/player-idle.png");

    sf::Sprite jogador(texture,sf::IntRect(0,0,32,33)),chao(texChao),fundo(texFundo);
    jogador.setPosition(0.f,window.getSize().y-(jogador.getGlobalBounds().height+altchao));
    chao.setPosition(0.f,window.getSize().y-altchao);
    sf::Font fonte;
    fonte.loadFromFile("./img/8-BIT WONDER.TTF");

    
    sf::Text texto;

    texto.setFont(fonte);
    texto.setString("Teste");
    
    texto.setFillColor(sf::Color(255,0,0));
    texto.setPosition(10.f,10.f);
    

    window.setFramerateLimit(60);

    int ground = window.getSize().y - (jogador.getGlobalBounds().height+altchao); //definindo alturachao
    float dx=0,dy=0;
    bool on_ground = true;

    sf::FloatRect rect(0,ground,32,33);
    sf::Clock clock;

    while (window.isOpen())
    {   
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            dx = vel;
            //jogador.move(vel * time,0);
            frame+=0.5f;
            if(frame>4){//loop dos frames
                frame-=4;
            }
            //jogador.setTextureRect(sf::IntRect(32 * (int)frame,0,32,33));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            dx=-vel;
            //jogador.move(-vel * time,0);
            frame+=0.5f;
            if(frame>4){//loop dos frames
                frame-=4;
            }
            //jogador.setTextureRect(sf::IntRect(32 * (int)frame +32,0,-32,33));//inverter imagem quando mover para esquerda
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(on_ground){
                dy = -vel;
            }
        }
        rect.left += dx * time;
        rect.top += dy * time;
        if(!on_ground){
            dy = dy+0.0006 * time;
            jogador.move(jogador.getPosition().x,dy);
        }

        on_ground = false;

        if(rect.top > ground){
            rect.top = ground;
            dy = 0;
            on_ground = true;
        }

        if(dx > 0){
            jogador.setTextureRect(sf::IntRect(32 * (int)frame,0,32,33));
        }
        if(dx < 0){
            jogador.setTextureRect(sf::IntRect(32 * (int)frame +32,0,-32,33));
        }

        jogador.setPosition(rect.left,rect.top);
        dx=0;
        window.clear();
        window.draw(fundo);
        window.draw(chao);
        window.draw(jogador);
        window.draw(texto);
        
        window.display();
    }

    return 0;
}
