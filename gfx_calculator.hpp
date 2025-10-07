#pragma once

// #########################################################
// 
//                  Include My libs
// 
// #########################################################
#include "_config.hpp"
#include "utl_logger.hpp"
#include "ui_button.hpp"
#include <vector>


namespace ninotchka
{
    namespace user_interface
    {
        // ---------------------------------------------------------
        //
        // @brief:          class UICalculator
        //
        // --------------------------- 
        // @description:    класс для работы с калькулятором.
        //                  Использует UIButton для кнопок и
        //                  sf::RectangleShape для фона.
        // 
        // [ 1 ] field:     sf::RectangleShape background   -   для хранения формы фона калькулятора
        // [ 2 ] field:     sf::Texture backgroundTexture   -   для хранения текстуры фона
        // [ 3 ] field:     sf::Vector2f position;          -   для хранения позиции калькулятора
        // [ 4 ] field:     sf::Vector2f size;              -   для хранения размеров калькулятора
        // [ 5 ] field:     std::vector<UIButton> buttons   -   для хранения кнопок калькулятора
        // ---------------------------------------------------------
        class UICalculator
        {
        protected:
            sf::RectangleShape background;      // для хранения формы фона калькулятора
            sf::Texture backgroundTexture;      // для хранения текстуры фона
            sf::Vector2f position;              // для хранения позиции калькулятора
            sf::Vector2f size;                  // для хранения размеров калькулятора
            std::vector<UIButton> buttons;      // для хранения кнопок калькулятора

            ninotchka::logger::ULogManager objectULogManager;  // для ведения логов

            // Для простой логики калькулятора
            std::string currentInput;           // Текущий ввод
            std::string previousInput;          // Предыдущий ввод
            char operation;                     // Текущая операция (+, -, *, /)
            bool isResultDisplayed;             // Флаг, показывающий, отображен ли результат

        public:
            /** ****************************************************
                *
                * @brief:			дефолтный конструктор класса
                *
                * ***************************
                * @description:	    инициализирует размер и позицию
                */
            UICalculator();

            /** ****************************************************
                *
                * @brief:			конструктор класса
                *
                * ***************************
                * @description:	    добавлена перегрузка размера и позиции.
                */
            UICalculator(sf::Vector2f size, sf::Vector2f position);

            /** ****************************************************
                *
                * @brief:			функция
                *
                * ***************************
                * @description:	    отрисовывает калькулятор на экране (фон и кнопки)
                */
            void draw(sf::RenderWindow& window);

            /** ****************************************************
                *
                * @brief:           функция
                *
                * ***************************
                * @description:     обрабатывает события (клики на кнопки)
                *                   и обновляет логику калькулятора
                */
            void handleEvent(sf::RenderWindow& window, sf::Event& event);

            /** ****************************************************
                *
                * @brief:           функция - сеттер
                *
                * ***************************
                * @description:     инициализирует текстуру фона по пути к файлу
                */
            void setBackgroundTexture(const std::string& texturePath);

            /** ****************************************************
                *
                * @brief:           функция
                *
                * ***************************
                * @description:     добавляет кнопку в калькулятор
                */
            void addButton(const UIButton& button);

            // (пример простой арифметики)
            void processInput(const std::string& input);
            void calculate();
        };
    }
}