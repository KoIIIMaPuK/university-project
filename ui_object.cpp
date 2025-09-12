#include "ui_object.hpp"




/** ****************************************************
*
* @brief:			дефолтный конструктор класса
*
* ***************************
* @description:	    инициализирует размер, позицию и цвет
*/
UIButton::UIButton() :
	size(sf::Vector2f(200.f, 50.f)),
	position(sf::Vector2f(0.f, 0.f)),
	color(sf::Color::Cyan)
{
	this->shape.setSize(this->size);			// инициализация размеров кнопки 
	this->shape.setFillColor(this->color);		// инициализация цвета кнопки
	this->shape.setPosition(this->position);	// инициализация позиции кнопки

	/**
	* @brief:	создание лога о создании объекта класса	
	*/
	objectULogManager.AddLogMessage(config_logger::text::USER_INTERFACE_BUTTON, config_logger::text::CONSTRUCTOR_DEFAULT_WAS_CREATED);
}







/** ****************************************************
*
* @brief:			конструктор класса
*
* ***************************
* @description:	    добавлена перегрузка размера и позиции.
*/
UIButton::UIButton(sf::Vector2f size, sf::Vector2f position) :
	size(size),
	position(position),
	color(sf::Color::Cyan)
{
	this->shape.setSize(this->size);			// инициализация размеров кнопки 
	this->shape.setFillColor(this->color);		// инициализация цвета кнопки
	this->shape.setPosition(this->position);	// инициализация позиции кнопки

	/**
	*	@brief:		создание лога о создании объекта класса
	*/
	objectULogManager.AddLogMessage(config_logger::text::USER_INTERFACE_BUTTON, config_logger::text::CONSTRUCTOR_DEFAULT_WAS_CREATED);
}







/** ****************************************************
*
* @brief:			конструктор класса
*
* ***************************
* @description:	    добавлена перегрузка размера, позиции и цвета.
*/
UIButton::UIButton(sf::Vector2f size, sf::Vector2f position, sf::Color color) :
	size(size),
	position(position),
	color(color)
{

	this->shape.setSize(this->size);			// инициализация размеров кнопки 
	this->shape.setFillColor(this->color);		// инициализация цвета кнопки
	this->shape.setPosition(this->position);	// инициализация позиции кнопки

	/**
	*	@brief:		создание лога о создании объекта класса
	*/
	objectULogManager.AddLogMessage(config_logger::text::USER_INTERFACE_BUTTON, config_logger::text::CONSTRUCTOR_DEFAULT_WAS_CREATED);
}








/** ****************************************************
*
* @brief:			функция
*
* ***************************
* @description:	    отрисовывает кнопку на экране
*/
void UIButton::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);
}








/** ****************************************************
*
* @brief:           функция
*
* ***************************
* @description:     проверяет, находится ли
*                   курсор мыши над кнопкой
* 
* @return:			возвращает true, если
*					курсор мыши находится 
*					над кнопкой
*/
bool UIButton::isMouseOver(sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);
	sf::FloatRect bounds = shape.getGlobalBounds();
	return bounds.contains(mousePosF);
}








/** ****************************************************
*
* @brief:           функция
*
* ***************************
* @description:     проверяет, была ли нажата
*                   клавиша, когда курсор
*                   был над кнопкой
*/
bool UIButton::isLClicked(sf::RenderWindow& window, sf::Event& event) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (isMouseOver(window)) {
			return true;
		}
	}
	return false;
}








/** ****************************************************
*
* @brief:           функция
*
* ***************************
* @description:     проверяет, была ли нажата
*                   клавиша, когда курсор
*                   был над кнопкой
*/
bool UIButton::isRClicked(sf::RenderWindow& window, sf::Event& event) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
		if (isMouseOver(window)) {
			return true;
		}
	}
	return false;
}







/** ****************************************************
*
* @brief:           функция - сеттер
*
* ***************************
* @description:     инициализирует размер
*/
void UIButton::setSize(sf::Vector2f& size)
{
	this->size = size;
}








/** ****************************************************
*
* @brief:           функция - сеттер
*
* ***************************
* @description:     инициализирует размер
*/
void UIButton::setPosition(sf::Vector2f& position)
{
	this->position = position;
}