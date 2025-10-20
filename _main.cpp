// #########################################################
// 
//                  Include My libs
// 
// #########################################################
#include "_config.hpp"          // Файл с настройками
#include "ui_button.hpp"        // Файл для кнопок в интерфейсе
#include "utl_logger.hpp"       // Файл для логирования






// ---------------------------------------------------------
//
// @brief:          Функция-калькулятор
//
// --------------------------- 
// @description:    Функция для вычисления значения строки выражений
// 
// @return:         Возвращает вычисленное значение
//                      
//                      config_window::application_exit_code::WINDOW_COMPLETE
// ---------------------------------------------------------
double calculateResult(const std::string& expression) {
    double num1 = 0, num2 = 0;
    char op = '\0';
    std::string temp;

    size_t i = 0;
    while (i < expression.size() && (std::isdigit(expression[i]) || expression[i] == '.')) {
        temp += expression[i];
        i++;
    }
    if (!temp.empty()) {
        num1 = std::stod(temp);
        temp.clear();
    }

    // Получаем оператор
    if (i < expression.size()) {
        op = expression[i];
        i++;
    }

    // Получаем второе число
    while (i < expression.size() && (std::isdigit(expression[i]) || expression[i] == '.')) {
        temp += expression[i];
        i++;
    }
    if (!temp.empty()) {
        num2 = std::stod(temp);
    }

    // Выполняем вычисление
    switch (op) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/':
        if (num2 != 0) return num1 / num2;
        else throw std::runtime_error("Division by zero");
    default: return num1;
    }
}








// ---------------------------------------------------------
//
// @brief:          Main func
//
// --------------------------- 
// @description:    Главная функция приложения.
// 
// @return:         Код завершения приложения,
//                  возвращает 0, если:
//                      
//                      config_window::application_exit_code::WINDOW_COMPLETE
// ---------------------------------------------------------
int main()
{
    /** ****************************************************
        *   @brief:         Создание SFML-окна.
        *
        ****************************
        *   @description:   Создание окна, в котором будет
        *                   отображаться весь пользовательский интерфейс.
        *
        *   [ 1 ] @param:   config_window::WINDOW_WIDTH  - ширина окна
        *   [ 2 ] @param:   config_window::WINDOW_HEIGHT - высота окна
        *   [ 3 ] @param:   config_window::WINDOW_TITLE  - название окна приложения
        */
    sf::RenderWindow window(sf::VideoMode(config_window::WINDOW_WIDTH, config_window::WINDOW_HEIGHT), config_window::WINDOW_TITLE);
    window.setFramerateLimit(60);

    bool isOpenWindowTest = false;


    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    //  
    // @brief:      Инициализация заднего фона
    // 
    // ---------------------------
    //
    sf::RectangleShape background(sf::Vector2f(288, 576));
    background.setPosition(sf::Vector2f(0, 0));
    background.setFillColor(sf::Color(23, 0, 29));
    //
    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    



    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    //  
    // @brief:      Инициализация текстуры
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
    // @brief:      Инициализация текстуры
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
    // @brief:      Инициализация кнопок главного меню
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
    // @brief:      Инициализация текста калькулятора
    // 
    // ---------------------------
    //
    sf::Font font;
    if (!font.loadFromFile(config_window::fonts::FONT_MONOCRAFT)) // Загрузка шрифта
    {
        return config_window::application_exit_code::WINDOW_ERROR;
    }

    sf::Text displayText;
    displayText.setFont(font);
    displayText.setCharacterSize(24);               // Размер текста
    displayText.setFillColor(sf::Color(255, 5, 70));     // Цвет текста
    displayText.setPosition(15.f, 150.f);           // Позиция текста на экране (ось X, ось Y)

    std::string inputString;    // Строка ввода выражения
    //
    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-


    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    //  
    // @brief:      Инициализация текстуры разделения интерфейса калькулятора
    // 
    // ---------------------------
    //
    sf::Texture texture;
    if (!texture.loadFromFile("gfx-assets/_line-for-calculator.png"))
    {
        return config_window::application_exit_code::WINDOW_ERROR;
    }
    
    sf::Sprite line_for_calculator;
    line_for_calculator.setTexture(texture);
    line_for_calculator.setPosition(sf::Vector2f(15.f, 175.f));
    line_for_calculator.setScale(3.f, 3.f);
    //
    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-


    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    //  
    // @brief:      Инициализация кнопок калькулятора
    // 
    // ---------------------------
    //
    ninotchka::user_interface::UIButton button_calculator_0(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(83.f, 489.f),
        "gfx-assets/_button-calculator-blueprint-0.png"
    );

    ninotchka::user_interface::UIButton button_calculator_1(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(20.f, 426.f),
        "gfx-assets/_button-calculator-blueprint-1.png"
    );

    ninotchka::user_interface::UIButton button_calculator_2(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(83.f, 426.f),
        "gfx-assets/_button-calculator-blueprint-2.png"
    );

    ninotchka::user_interface::UIButton button_calculator_3(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(146.f, 426.f),
        "gfx-assets/_button-calculator-blueprint-3.png"
    );

    ninotchka::user_interface::UIButton button_calculator_4(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(20.f, 363.f),
        "gfx-assets/_button-calculator-blueprint-4.png"
    );

    ninotchka::user_interface::UIButton button_calculator_5(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(83.f, 363.f),
        "gfx-assets/_button-calculator-blueprint-5.png"
    );

    ninotchka::user_interface::UIButton button_calculator_6(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(146.f, 363.f),
        "gfx-assets/_button-calculator-blueprint-6.png"
    );

    ninotchka::user_interface::UIButton button_calculator_7(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(20.f, 300.f),
        "gfx-assets/_button-calculator-blueprint-7.png"
    );

    ninotchka::user_interface::UIButton button_calculator_8(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(83.f, 300.f),
        "gfx-assets/_button-calculator-blueprint-8.png"
    );

    ninotchka::user_interface::UIButton button_calculator_9(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(146.f, 300.f),
        "gfx-assets/_button-calculator-blueprint-9.png"
    );

    ninotchka::user_interface::UIButton button_calculator_menu(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(18.f, 495.f),
        "gfx-assets/_button-calculator-blueprint-menu.png"
    );

    ninotchka::user_interface::UIButton button_calculator_comma(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(148.f, 495.f),
        "gfx-assets/_button-calculator-blueprint-comma.png"
    );

    ninotchka::user_interface::UIButton button_calculator_plus(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(211.f, 495.f),
        "gfx-assets/_button-calculator-blueprint-plus.png"
    );

    ninotchka::user_interface::UIButton button_calculator_minus(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(211.f, 432.f),
        "gfx-assets/_button-calculator-blueprint-minus.png"
    );

    ninotchka::user_interface::UIButton button_calculator_multiply(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(211.f, 369.f),
        "gfx-assets/_button-calculator-blueprint-multiply.png"
    );

    ninotchka::user_interface::UIButton button_calculator_subdivision(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(211.f, 306.f),
        "gfx-assets/_button-calculator-blueprint-subdivision.png"
    );

    ninotchka::user_interface::UIButton button_calculator_equal(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(49.f, 237.f),
        "gfx-assets/_button-calculator-blueprint-equal.png"
    );

    ninotchka::user_interface::UIButton button_calculator_clear(
        sf::Vector2f(48.f, 48.f),
        sf::Vector2f(112.f, 237.f),
        "gfx-assets/_button-calculator-blueprint-clear.png"
    );

    ninotchka::user_interface::UIButton button_calculator_back(
        sf::Vector2f(84.f, 48.f),
        sf::Vector2f(175.f, 237.f),
        "gfx-assets/_button-calculator-blueprint-back.png"
    );
    // 
    // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-




    // -----------------------------------------------------
    //
    // @brief:          Main while 
    // 
    // ---------------------------
    // @description:    Главный цикл обработки событий
    //                  отрисовки интерфейса и обработки
    //                  ввода данных в окне.
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
            // @brief:      Обработка кликов по кнопкам главного меню
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
            // @brief:      Обработка кликов по кнопкам калькулятора
            // 
            // ---------------------------
            //
            if (button_calculator_0.isLClicked(window, event)) {
                inputString += "0";
            }
            if (button_calculator_1.isLClicked(window, event)) {
                inputString += "1";
            }
            if (button_calculator_2.isLClicked(window, event)) {
                inputString += "2";
            }
            if (button_calculator_3.isLClicked(window, event)) {
                inputString += "3";
            }
            if (button_calculator_4.isLClicked(window, event)) {
                inputString += "4";
            }
            if (button_calculator_5.isLClicked(window, event)) {
                inputString += "5";
            }
            if (button_calculator_6.isLClicked(window, event)) {
                inputString += "6";
            }
            if (button_calculator_7.isLClicked(window, event)) {
                inputString += "7";
            }
            if (button_calculator_8.isLClicked(window, event)) {
                inputString += "8";
            }
            if (button_calculator_9.isLClicked(window, event)) {
                inputString += "9";
            }
            if (button_calculator_comma.isLClicked(window, event)) {
                inputString += ".";
            }
            if (button_calculator_plus.isLClicked(window, event)) {
                inputString += "+";
            }
            if (button_calculator_minus.isLClicked(window, event)) {
                inputString += "-";
            }
            if (button_calculator_multiply.isLClicked(window, event)) {
                inputString += "*";
            }
            if (button_calculator_subdivision.isLClicked(window, event)) {
                inputString += "/";
            }
            if (button_calculator_equal.isLClicked(window, event)) {
                try {
                    double result = calculateResult(inputString);
                    inputString = std::to_string(result);

                    inputString.erase(inputString.find_last_not_of('0') + 1, std::string::npos);
                    if (inputString.back() == '.') {
                        inputString.pop_back();
                    }
                }
                catch (const std::exception& e) {
                    inputString = "Error";
                }
            }
            if (button_calculator_clear.isLClicked(window, event)) {
                inputString.clear();
            }
            if (button_calculator_back.isLClicked(window, event)) {
                if (!inputString.empty()) {
                    inputString.pop_back(); // Удаляем последний символ
                }
            }
            if (button_calculator_menu.isLClicked(window, event)) {
                isOpenWindowTest = !isOpenWindowTest;
            }
            //
            // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        }



        if (isOpenWindowTest)
        {
            displayText.setString(inputString);

            window.clear(sf::Color(39, 0, 34));

            window.draw(background);
            window.draw(displayText);
            window.draw(line_for_calculator);
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
            button_calculator_equal.draw(window);
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

    return config_window::application_exit_code::WINDOW_COMPLETE;   // Пока :D https://www.youtube.com/watch?v=6EXB2Of1zLY
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



////////////////////////////////////////////////////////////////////
// 
//      наработки по парсингу мосбиржы
// 
////////////////////////////////////////////////////////////////////
/*
sf::Http http("https://iss.moex.com/iss/engines/stock/markets/shares/boards/TQBR/securities/SBER.json");
sf::Http::Request request;
request.setMethod(sf::Http::Request::Get);

sf::Http::Response response = http.sendRequest(request);
std::cout << "status: " << response.getStatus() << std::endl;
std::cout << "HTTP version: " << response.getMajorHttpVersion() << "." << response.getMinorHttpVersion() << std::endl;
std::cout << "Content-Type header:" << response.getField("Content-Type") << std::endl;
std::cout << "body: " << response.getBody() << std::endl;
*/
////////////////////////////////////////////////////////////////////