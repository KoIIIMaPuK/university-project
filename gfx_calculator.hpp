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
        // @description:    ����� ��� ������ � �������������.
        //                  ���������� UIButton ��� ������ �
        //                  sf::RectangleShape ��� ����.
        // 
        // [ 1 ] field:     sf::RectangleShape background   -   ��� �������� ����� ���� ������������
        // [ 2 ] field:     sf::Texture backgroundTexture   -   ��� �������� �������� ����
        // [ 3 ] field:     sf::Vector2f position;          -   ��� �������� ������� ������������
        // [ 4 ] field:     sf::Vector2f size;              -   ��� �������� �������� ������������
        // [ 5 ] field:     std::vector<UIButton> buttons   -   ��� �������� ������ ������������
        // ---------------------------------------------------------
        class UICalculator
        {
        protected:
            sf::RectangleShape background;      // ��� �������� ����� ���� ������������
            sf::Texture backgroundTexture;      // ��� �������� �������� ����
            sf::Vector2f position;              // ��� �������� ������� ������������
            sf::Vector2f size;                  // ��� �������� �������� ������������
            std::vector<UIButton> buttons;      // ��� �������� ������ ������������

            ninotchka::logger::ULogManager objectULogManager;  // ��� ������� �����

            // ��� ������� ������ ������������
            std::string currentInput;           // ������� ����
            std::string previousInput;          // ���������� ����
            char operation;                     // ������� �������� (+, -, *, /)
            bool isResultDisplayed;             // ����, ������������, ��������� �� ���������

        public:
            /** ****************************************************
                *
                * @brief:			��������� ����������� ������
                *
                * ***************************
                * @description:	    �������������� ������ � �������
                */
            UICalculator();

            /** ****************************************************
                *
                * @brief:			����������� ������
                *
                * ***************************
                * @description:	    ��������� ���������� ������� � �������.
                */
            UICalculator(sf::Vector2f size, sf::Vector2f position);

            /** ****************************************************
                *
                * @brief:			�������
                *
                * ***************************
                * @description:	    ������������ ����������� �� ������ (��� � ������)
                */
            void draw(sf::RenderWindow& window);

            /** ****************************************************
                *
                * @brief:           �������
                *
                * ***************************
                * @description:     ������������ ������� (����� �� ������)
                *                   � ��������� ������ ������������
                */
            void handleEvent(sf::RenderWindow& window, sf::Event& event);

            /** ****************************************************
                *
                * @brief:           ������� - ������
                *
                * ***************************
                * @description:     �������������� �������� ���� �� ���� � �����
                */
            void setBackgroundTexture(const std::string& texturePath);

            /** ****************************************************
                *
                * @brief:           �������
                *
                * ***************************
                * @description:     ��������� ������ � �����������
                */
            void addButton(const UIButton& button);

            // (������ ������� ����������)
            void processInput(const std::string& input);
            void calculate();
        };
    }
}