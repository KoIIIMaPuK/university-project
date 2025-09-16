// #########################################################
// 
//                  Include My libs
// 
// #########################################################
#include "_config.hpp"
#include "utl_logger.hpp"
#include "ui_object.hpp"





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
    /**
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

    UIButton objectButton0;
    UIButton objectButton1(sf::Vector2f(150.f, 150.f), sf::Vector2f(0.f, 60.f));

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
                window.close();
        }

        

        window.clear(sf::Color::Black);

        objectButton0.draw(window);
        objectButton1.draw(window);

        window.display();
    }

    return config_window::application_exit_code::WINDOW_COMPLETE;   // ����� :D https://www.youtube.com/watch?v=6EXB2Of1zLY
}
////////////////////////////////////////////////////////////////////
/// ��� ����� ���:
///     1. Kill Eva, Encassator - Psycho Dreams ( SWEEQTY x yungalligator hardstyle remix ):    https://youtu.be/WTQ5tLGFIm4
///     2. Liza Evans - ������ ( SWEEQTY hardstyle edit ):      https://youtu.be/Qmezd5yTGRQ
///     3. DVRST, polnalyubvi - Falling Stars (Lyrics video):   https://youtu.be/r-z3mVtXa-Q
///     4. DVRST, Leah Julia - Across The Sky (Lyrics Video):   https://youtu.be/UJQZNJr7Ppg
///     5. ����������, ����� - Baby mama[Official Audio]:       https://youtu.be/eXLSBdxm_cs
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