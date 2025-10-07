#include "gfx_calculator.hpp"

namespace ninotchka
{
    namespace user_interface
    {
        /** ****************************************************
            *
            * @brief:			дефолтный конструктор класса
            *
            * ***************************
            * @description:	    инициализирует размер и позицию
            */
        UICalculator::UICalculator() :
            size(sf::Vector2f(300.f, 400.f)),
            position(sf::Vector2f(100.f, 100.f)),
            operation('\0'),
            isResultDisplayed(false)
        {
            this->background.setSize(this->size);
            this->background.setPosition(this->position);
            this->background.setFillColor(sf::Color::White);  // Дефолтный цвет, если нет текстуры

            /**
            * @brief:	создание лога о создании объекта класса
            */
            objectULogManager.addLogMessage(config_logger::text::USER_INTERFACE_CALCULATOR, config_logger::text::CONSTRUCTOR_DEFAULT_WAS_CREATED);
        }







        /** ****************************************************
            *
            * @brief:			конструктор класса
            *
            * ***************************
            * @description:	    добавлена перегрузка размера и позиции.
            */
        UICalculator::UICalculator(sf::Vector2f size, sf::Vector2f position) :
            size(size),
            position(position),
            operation('\0'),
            isResultDisplayed(false)
        {
            this->background.setSize(this->size);
            this->background.setPosition(this->position);
            this->background.setFillColor(sf::Color::White);  // Дефолтный цвет, если нет текстуры

            /**
            *	@brief:		создание лога о создании объекта класса
            */
            objectULogManager.addLogMessage(config_logger::text::USER_INTERFACE_CALCULATOR, config_logger::text::CONSTRUCTOR_DEFAULT_WAS_CREATED);
        }







        /** ****************************************************
            *
            * @brief:			функция
            *
            * ***************************
            * @description:	    отрисовывает калькулятор на экране (фон и кнопки)
            */
        void UICalculator::draw(sf::RenderWindow& window)
        {
            if (this->backgroundTexture.getSize().x > 0) {
                this->background.setTexture(&this->backgroundTexture);
            }
            window.draw(this->background);

            for (auto& button : this->buttons) {
                button.draw(window);
            }

            // Здесь можно добавить отрисовку дисплея (sf::Text), если добавите его в класс
        }







        /** ****************************************************
            *
            * @brief:           функция
            *
            * ***************************
            * @description:     обрабатывает события (клики на кнопки)
            *                   и обновляет логику калькулятора
            */
        void UICalculator::handleEvent(sf::RenderWindow& window, sf::Event& event)
        {
            for (auto& button : this->buttons) {
                if (button.isLClicked(window, event)) {
                    // Здесь логика: в зависимости от кнопки (нужно добавить идентификатор кнопок или текст)
                    // Например, если кнопка - цифра, добавить к currentInput
                    // Если операция, сохранить previousInput, operation
                    // Если '=', вызвать calculate()
                }
            }
        }







        /** ****************************************************
            *
            * @brief:           функция - сеттер
            *
            * ***************************
            * @description:     инициализирует текстуру фона по пути к файлу
            */
        void UICalculator::setBackgroundTexture(const std::string& texturePath)
        {
            if (!this->backgroundTexture.loadFromFile(texturePath)) {
                objectULogManager.addLogMessage(config_logger::text::USER_INTERFACE_CALCULATOR, "Failed to load background texture from path: " + texturePath);
                return;
            }
            this->background.setTexture(&this->backgroundTexture);
        }







        /** ****************************************************
            *
            * @brief:           функция
            *
            * ***************************
            * @description:     добавляет кнопку в калькулятор
            */
        void UICalculator::addButton(const UIButton& button)
        {
            
        }







        void UICalculator::processInput(const std::string& input)
        {
            if (isResultDisplayed) {
                currentInput.clear();
                isResultDisplayed = false;
            }
            currentInput += input;
        }







        void UICalculator::calculate()
        {
            if (previousInput.empty() || currentInput.empty()) return;

            double prev = std::stod(previousInput);
            double curr = std::stod(currentInput);
            double result = 0.0;

            switch (operation) {
            case '+': result = prev + curr; break;
            case '-': result = prev - curr; break;
            case '*': result = prev * curr; break;
            case '/': if (curr != 0) result = prev / curr; break;
            default: return;
            }

            currentInput = std::to_string(result);
            isResultDisplayed = true;
        }
    }
}