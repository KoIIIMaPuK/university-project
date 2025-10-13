// #########################################################
// 
//                  Include My libs
// 
// #########################################################
#include "_config.hpp"          // файл с конфигами
#include "ui_button.hpp"        // файл для работы с кнопками
#include "utl_logger.hpp"       // файл для логгирования














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

    bool isOpenWindowTest = false;

    sf::RectangleShape background(sf::Vector2f(288, 576));
    background.setPosition(sf::Vector2f(0, 0));
    background.setFillColor(sf::Color(23, 0, 29));

    
    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    //  
    // @brief:      инициализация надписи
    // 
    // ---------------------------
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
    // @brief:      инициализация ниночки
    // 
    // ---------------------------
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
    // @brief:      инициализация кнопок основого меню
    // 
    // ---------------------------
    //
    ninotchka::user_interface::UIButton button_start_calculator(
        sf::Vector2f(336.f, 48.f), 
        sf::Vector2f(420.f, 250.f), 
        "gfx-assets/_blueprint-button-calculator.png"
    );

    ninotchka::user_interface::UIButton button_start_ninotchka_sketch(
        sf::Vector2f(336.f, 48.f), 
        sf::Vector2f(420.f, 300.f), 
        "gfx-assets/_blueprint-button-ninotchka-sketchpad.png"
    );

    ninotchka::user_interface::UIButton button_start_game(
        sf::Vector2f(336.f, 48.f), 
        sf::Vector2f(420.f, 350.f), 
        "gfx-assets/_blueprint-button-why-did-i-create-this.png"
    );
    //
    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-




    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    //  
    // @brief:      инициализация кнопок калькулятора
    // 
    // ---------------------------
    //
    ninotchka::user_interface::UIButton button_calculator_0(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(83.f, 439.f),
        "gfx-assets/_button-calculator-blueprint-0.png"
    );

    ninotchka::user_interface::UIButton button_calculator_1(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(20.f, 376.f),
        "gfx-assets/_button-calculator-blueprint-1.png"
    );

    ninotchka::user_interface::UIButton button_calculator_2(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(83.f, 376.f),
        "gfx-assets/_button-calculator-blueprint-2.png"
    );

    ninotchka::user_interface::UIButton button_calculator_3(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(146.f, 376.f),
        "gfx-assets/_button-calculator-blueprint-3.png"
    );

    ninotchka::user_interface::UIButton button_calculator_4(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(20, 313.f),
        "gfx-assets/_button-calculator-blueprint-4.png"
    );

    ninotchka::user_interface::UIButton button_calculator_5(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(83.f, 313.f),
        "gfx-assets/_button-calculator-blueprint-5.png"
    );

    ninotchka::user_interface::UIButton button_calculator_6(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(146.f, 313.f),
        "gfx-assets/_button-calculator-blueprint-6.png"
    ); 

    ninotchka::user_interface::UIButton button_calculator_7(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(20.f, 250.f),
        "gfx-assets/_button-calculator-blueprint-7.png"
    );

    ninotchka::user_interface::UIButton button_calculator_8(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(83.f, 250.f),
        "gfx-assets/_button-calculator-blueprint-8.png"
    );

    ninotchka::user_interface::UIButton button_calculator_9(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(146.f, 250.f),
        "gfx-assets/_button-calculator-blueprint-9.png"
    );

    ninotchka::user_interface::UIButton button_calculator_menu(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(18.f, 445.f),
        "gfx-assets/_button-calculator-blueprint-menu.png"
    );

    ninotchka::user_interface::UIButton button_calculator_comma(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(148.f, 445.f),
        "gfx-assets/_button-calculator-blueprint-comma.png"
    );

    ninotchka::user_interface::UIButton button_calculator_plus(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(211.f, 445.f),
        "gfx-assets/_button-calculator-blueprint-plus.png"
    );

    ninotchka::user_interface::UIButton button_calculator_minus(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(211.f, 382.f),
        "gfx-assets/_button-calculator-blueprint-minus.png"
    );

    ninotchka::user_interface::UIButton button_calculator_multiply(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(211.f, 319.f),
        "gfx-assets/_button-calculator-blueprint-multiply.png"
    );

    ninotchka::user_interface::UIButton button_calculator_subdivision(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(211.f, 256.f),
        "gfx-assets/_button-calculator-blueprint-subdivision.png"
    );
    ninotchka::user_interface::UIButton button_calculator_clear(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(112.f, 187.f),
        "gfx-assets/_button-calculator-blueprint-clear.png"
    );
    ninotchka::user_interface::UIButton button_calculator_back(
        sf::Vector2f(84.f, 48.f),
        sf::Vector2f(175.f, 187.f),
        "gfx-assets/_button-calculator-blueprint-back.png"
    );
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

            // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
            //
            // @brief:      Обработка нажатий на кнопки главного меню
            // 
            // ---------------------------
            //
            if (button_start_calculator.isLClicked(window, event))
            {
                isOpenWindowTest = !isOpenWindowTest;
            }
            if (button_start_ninotchka_sketch.isLClicked(window, event))
            {
                std::cout << "2" << std::endl;
            }
            if (button_start_game.isLClicked(window, event))
            {
                std::cout << "3" << std::endl;
            }
            //
            // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
            



            // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
            //
            // @brief:      Обработка нажатий на кнопки калькулятора
            // 
            // ---------------------------
            //
            if (button_calculator_0.isLClicked(window, event))
            {
                
            }
            if (button_calculator_1.isLClicked(window, event))
            {

            }
            if (button_calculator_2.isLClicked(window, event))
            {

            }
            if (button_calculator_3.isLClicked(window, event))
            {

            }
            if (button_calculator_4.isLClicked(window, event))
            {

            }
            if (button_calculator_5.isLClicked(window, event))
            {

            }
            if (button_calculator_6.isLClicked(window, event))
            {

            }
            if (button_calculator_7.isLClicked(window, event))
            {

            }
            if (button_calculator_8.isLClicked(window, event))
            {

            }
            if (button_calculator_9.isLClicked(window, event))
            {

            }
            if (button_calculator_menu.isLClicked(window, event))
            {
                isOpenWindowTest = !isOpenWindowTest;
            }
            if (button_calculator_comma.isLClicked(window, event))
            {

            }
            //
            // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        }




        if (isOpenWindowTest)
        {
            window.clear(sf::Color(39, 0, 34));

            window.draw(background);

            button_calculator_0.draw(window);
            button_calculator_1.draw(window);
            button_calculator_2.draw(window);
            button_calculator_3.draw(window);
            button_calculator_4.draw(window);
            button_calculator_5.draw(window);
            button_calculator_6.draw(window);
            button_calculator_7.draw(window);
            button_calculator_8.draw(window);
            button_calculator_9.draw(window);
            button_calculator_menu.draw(window);
            button_calculator_comma.draw(window);
            button_calculator_plus.draw(window);
            button_calculator_minus.draw(window);
            button_calculator_multiply.draw(window);
            button_calculator_subdivision.draw(window);
            button_calculator_clear.draw(window);
            button_calculator_back.draw(window);

            window.display();
        }
        else
        {
            window.clear(sf::Color(39, 0, 34));

            window.draw(background);
            window.draw(ninotchka);

            button_start_calculator.draw(window);
            button_start_ninotchka_sketch.draw(window);
            button_start_game.draw(window);

            window.draw(title);

            window.display();
        }


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