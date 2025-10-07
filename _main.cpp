// #########################################################
// 
//                  Include My libs
// 
// #########################################################
#include "_config.hpp"      // файл с конфигами
#include "utl_logger.hpp"   // файл для логгирования
#include "ui_button.hpp"    // файл для работы с кнопками



// ---------------------------------------------------------
//
// @brief:          Main func
//
// --------------------------- 
// @description:    основная функция программы.
// 
// @return:         при успешном выполнении программы,
//                  возвращает 0, он же:
//                      
//                      config_window::application_exit_code::WINDOW_COMPLETE
// ---------------------------------------------------------
int main()
{
    /** ****************************************************
        *   @brief:         объект SFML-класса. 
        *   
        ****************************
        *   @description:   создается окно, на данный момент
        *                   является основным окном программы.
        * 
        *   [ 1 ] @param:   config_window::WINDOW_WIDTH  - ширина окна
        *   [ 2 ] @param:   config_window::WINDOW_HEIGHT - высота окна
        *   [ 3 ] @param:   config_window::WINDOW_TITLE  - название окна окна
        */
    sf::RenderWindow window(sf::VideoMode(config_window::WINDOW_WIDTH, config_window::WINDOW_HEIGHT), config_window::WINDOW_TITLE);
    window.setFramerateLimit(60);

    sf::RectangleShape background(sf::Vector2f(288, 576));
    background.setPosition(sf::Vector2f(0, 0));
    background.setFillColor(sf::Color(23, 0, 29));

    
    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
   //
    sf::Texture texture_title;
    if (!texture_title.loadFromFile("gfx-assets/_text-title-project-ninotchka-hub.png"));

    sf::Sprite title(texture_title);
    title.setPosition(sf::Vector2f(420.f, 150.f));
    title.setScale(3.f, 3.f);
    //
    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    //
    sf::Texture texture_ninotchka;
    if (!texture_ninotchka.loadFromFile("gfx-assets/_first-version-ninotchka.png"));

    sf::Sprite ninotchka(texture_ninotchka);
    ninotchka.setPosition(sf::Vector2f(40.f, 0.f));
    ninotchka.setScale(3.f, 3.f);
    //
    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    //
    sf::Texture texture_calculator;
    if (!texture_calculator.loadFromFile("gfx-assets/_blueprint-button-calculator.png"));

    sf::Sprite button_calculator(texture_calculator);
    button_calculator.setPosition(sf::Vector2f(420.f, 250.f));
    button_calculator.setScale(3.f, 3.f);
    //
    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    //
    sf::Texture texture_ninotchka_sketch;
    if (!texture_ninotchka_sketch.loadFromFile("gfx-assets/_blueprint-button-ninotchka-sketchpad.png"));

    sf::Sprite button_ninotchka_sketch(texture_ninotchka_sketch);
    button_ninotchka_sketch.setPosition(sf::Vector2f(420.f, 300.f));
    button_ninotchka_sketch.setScale(3.f, 3.f);
    //
    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    //
    sf::Texture texture_game;
    if (!texture_game.loadFromFile("gfx-assets/_blueprint-button-why-did-i-create-this.png"));

    sf::Sprite button_game(texture_game);
    button_game.setPosition(sf::Vector2f(420.f, 350.f));
    button_game.setScale(3.f, 3.f);
    //
    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-


    // -----------------------------------------------------
    //
    // @brief:          Main while 
    // 
    // ---------------------------
    // @description:    основной цикл в котором происходит
    //                  отслеживание событий и отрисовка
    //                  графики в окне.
    //
    // -----------------------------------------------------
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::Resized) 
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        window.clear(sf::Color(39, 0, 34));

        window.draw(background);
        window.draw(ninotchka);
        window.draw(button_calculator);
        window.draw(button_ninotchka_sketch);
        window.draw(button_game);
        window.draw(title);

        window.display();
    }

    return config_window::application_exit_code::WINDOW_COMPLETE;   // Конец :D https://www.youtube.com/watch?v=6EXB2Of1zLY
}
////////////////////////////////////////////////////////////////////
/// Код писал под:
///     1. DVRST, polnalyubvi - Falling Stars (Lyrics video):   https://youtu.be/r-z3mVtXa-Q
///     2. DVRST, Leah Julia - Across The Sky (Lyrics Video):   https://youtu.be/UJQZNJr7Ppg
///     3. Скриптонит, Райда - Baby mama[Official Audio]:       https://youtu.be/eXLSBdxm_cs
////////////////////////////////////////////////////////////////////






////////////////////////////////////////////////////////////////////
// 
//      идеи
// 
////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////
/// - gfx_user_interface:
///    button:
///        [ text ] *can click
///    checkbox:
///        [ 0 ] not clicked
///        [ 1 ] was clicked
///    slider:
///        -----I-- *can slider :D
///    text input field:
///        [ pls input text ]
///    dropdown list:
///        [ click me ] -> [ click me ]
///                        [ oh no    ]
///                        [ what are ]
///                        [ u doing  ]
///   mb more :D
////////////////////////////////////////////////////////////////////




// $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $ - $




////////////////////////////////////////////////////////////////////
// 
//      код в качестве наработак + сохраненки
// 
////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////
/// [  base main function  ]
///
/// int main()
/// {
///     sf::RenderWindow window(sf::VideoMode(cfgwnd::WINDOW_HEIGHT, cfgwnd::WINDOW_WIDTH), cfgwnd::WINDOW_TITLE);
///
///     while (window.isOpen())
///     {
///         sf::Event event;
///         while (window.pollEvent(event))
///         {
///             if (event.type == sf::Event::Closed)
///                 window.close();
///         }
///
///
///
///         window.clear(sf::Color::Black);
///
///         window.display();
///     }
///
///     return cfgwnd::appexcd::WINDOW_COMPLETE;
/// }
////////////////////////////////////////////////////////////////////