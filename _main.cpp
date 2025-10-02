// #########################################################
// 
//                  Include My libs
// 
// #########################################################
#include "_config.hpp"      // ���� � ���������
#include "utl_logger.hpp"   // ���� ��� ������������
#include "ui_button.hpp"    // ���� ��� ������ � ��������



// ---------------------------------------------------------
//
// @brief:          Main func
//
// --------------------------- 
// @description:    �������� ������� ���������.
// 
// @return:         ��� �������� ���������� ���������,
//                  ���������� 0, �� ��:
//                      
//                      config_window::application_exit_code::WINDOW_COMPLETE
// ---------------------------------------------------------
int main()
{
    /** ****************************************************
        *   @brief:         ������ SFML-������. 
        *   
        ****************************
        *   @description:   ��������� ����, �� ������ ������
        *                   �������� �������� ����� ���������.
        * 
        *   [ 1 ] @param:   config_window::WINDOW_WIDTH  - ������ ����
        *   [ 2 ] @param:   config_window::WINDOW_HEIGHT - ������ ����
        *   [ 3 ] @param:   config_window::WINDOW_TITLE  - �������� ���� ����
        */
    sf::RenderWindow window(sf::VideoMode(config_window::WINDOW_WIDTH, config_window::WINDOW_HEIGHT), config_window::WINDOW_TITLE);
    window.setFramerateLimit(60);

    sf::RectangleShape background(sf::Vector2f(288, 576));
    background.setPosition(sf::Vector2f(0, 0));
    background.setFillColor(sf::Color(23, 0, 29));

    // -----------------------------------------------------
    //
    // @brief:          Main while 
    // 
    // ---------------------------
    // @description:    �������� ���� � ������� ����������
    //                  ������������ ������� � ���������
    //                  ������� � ����.
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

        window.display();
    }

    return config_window::application_exit_code::WINDOW_COMPLETE;   // ����� :D https://www.youtube.com/watch?v=6EXB2Of1zLY
}
////////////////////////////////////////////////////////////////////
/// ��� ����� ���:
///     1. DVRST, polnalyubvi - Falling Stars (Lyrics video):   https://youtu.be/r-z3mVtXa-Q
///     2. DVRST, Leah Julia - Across The Sky (Lyrics Video):   https://youtu.be/UJQZNJr7Ppg
///     3. ����������, ����� - Baby mama[Official Audio]:       https://youtu.be/eXLSBdxm_cs
////////////////////////////////////////////////////////////////////






////////////////////////////////////////////////////////////////////
// 
//      ����
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
//      ��� � �������� ��������� + ����������
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