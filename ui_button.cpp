#include "ui_button.hpp"

namespace ninotchka
{
	namespace user_interface
	{
		/** ****************************************************
			*
			* @brief:			��������� ����������� ������
			*
			* ***************************
			* @description:	    �������������� ������, ������� � ����
			*/
		UIButton::UIButton() :
			size(sf::Vector2f(200.f, 50.f)),
			position(sf::Vector2f(0.f, 0.f)),
			color(sf::Color::Cyan)
		{
			this->shape.setSize(this->size);			// ������������� �������� ������ 
			this->shape.setFillColor(this->color);		// ������������� ����� ������
			this->shape.setPosition(this->position);	// ������������� ������� ������

			/**
			* @brief:	�������� ���� � �������� ������� ������
			*/
			objectULogManager.addLogMessage(config_logger::text::USER_INTERFACE_BUTTON, config_logger::text::CONSTRUCTOR_DEFAULT_WAS_CREATED);
		}







		/** ****************************************************
			*
			* @brief:			����������� ������
			*
			* ***************************
			* @description:	    ��������� ���������� ������� � �������.
			*/
		UIButton::UIButton(sf::Vector2f size, sf::Vector2f position) :
			size(size),
			position(position),
			color(sf::Color::Cyan)
		{
			this->shape.setSize(this->size);			// ������������� �������� ������ 
			this->shape.setFillColor(this->color);		// ������������� ����� ������
			this->shape.setPosition(this->position);	// ������������� ������� ������

			/**
			*	@brief:		�������� ���� � �������� ������� ������
			*/
			objectULogManager.addLogMessage(config_logger::text::USER_INTERFACE_BUTTON, config_logger::text::CONSTRUCTOR_DEFAULT_WAS_CREATED);
		}







		/** ****************************************************
			*
			* @brief:			����������� ������
			*
			* ***************************
			* @description:	    ��������� ���������� �������, ������� � �����.
			*/
		UIButton::UIButton(sf::Vector2f size, sf::Vector2f position, sf::Color color) :
			size(size),
			position(position),
			color(color)
		{
			this->shape.setSize(this->size);			// ������������� �������� ������ 
			this->shape.setFillColor(this->color);		// ������������� ����� ������
			this->shape.setPosition(this->position);	// ������������� ������� ������

			/**
			*	@brief:		�������� ���� � �������� ������� ������
			*/
			objectULogManager.addLogMessage(config_logger::text::USER_INTERFACE_BUTTON, config_logger::text::CONSTRUCTOR_DEFAULT_WAS_CREATED);
		} 






		   
		/** ****************************************************
			*
			* @brief:			����������� ������
			*
			* ***************************
			* @description:	    ��������� ���������� �������, ������� � ���� � ��������.
			*/
		UIButton::UIButton(sf::Vector2f size, sf::Vector2f position, const std::string& texturePath) :
			size(size),
			position(position),
			color(sf::Color::Cyan)
		{
			if (!this->texture.loadFromFile(texturePath)) 
			{
				objectULogManager.addLogMessage(config_logger::text::USER_INTERFACE_BUTTON, "Failed to load texture from path: " + texturePath);
			}
			else 
			{
				this->sprite.setTexture(this->texture);
				this->sprite.setPosition(this->position);
				if (this->texture.getSize().x > 0 && this->texture.getSize().y > 0) 
				{
					this->sprite.setScale(this->size.x / this->texture.getSize().x, this->size.y / this->texture.getSize().y);
				}
			}

			this->shape.setSize(this->size);			// ������������� �������� ������ (�� ������ fallback)
			this->shape.setFillColor(this->color);		// ������������� ����� ������
			this->shape.setPosition(this->position);	// ������������� ������� ������

			/**
			*	@brief:		�������� ���� � �������� ������� ������
			*/
			objectULogManager.addLogMessage(config_logger::text::USER_INTERFACE_BUTTON, config_logger::text::CONSTRUCTOR_DEFAULT_WAS_CREATED);
		}








		/** ****************************************************
			*
			* @brief:			�������
			*
			* ***************************
			* @description:	    ������������ ������ �� ������
			*/
		void UIButton::draw(sf::RenderWindow& window)
		{
			if (this->sprite.getTexture() != nullptr) {
				window.draw(this->sprite);
			}
			else {
				window.draw(this->shape);
			}
		}








		/** ****************************************************
			*
			* @brief:           �������
			*
			* ***************************
			* @description:     ���������, ��������� ��
			*                   ������ ���� ��� �������
			*
			* @return:			���������� true, ����
			*					������ ���� ���������
			*					��� �������
			*/
		bool UIButton::isMouseOver(sf::RenderWindow& window)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);
			sf::FloatRect bounds;
			if (this->sprite.getTexture() != nullptr) {
				bounds = this->sprite.getGlobalBounds();
			}
			else {
				bounds = this->shape.getGlobalBounds();
			}
			return bounds.contains(mousePosF);
		}








		/** ****************************************************
			*
			* @brief:           �������
			*
			* ***************************
			* @description:     ���������, ���� �� ������
			*                   �������, ����� ������
			*                   ��� ��� �������
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
			* @brief:           �������
			*
			* ***************************
			* @description:     ���������, ���� �� ������
			*                   �������, ����� ������
			*                   ��� ��� �������
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
			* @brief:           ������� - ������
			*
			* ***************************
			* @description:     �������������� ������
			*/
		void UIButton::setSize(sf::Vector2f& size)
		{
			this->size = size;
			this->shape.setSize(this->size);
			if (this->texture.getSize().x > 0 && this->texture.getSize().y > 0) {
				this->sprite.setScale(this->size.x / this->texture.getSize().x, this->size.y / this->texture.getSize().y);
			}
		}








		/** ****************************************************
			*
			* @brief:           ������� - ������
			*
			* ***************************
			* @description:     �������������� ������
			*/
		void UIButton::setPosition(sf::Vector2f& position)
		{
			this->position = position;
			this->shape.setPosition(this->position);
			this->sprite.setPosition(this->position);
		}








		/** ****************************************************
			*
			* @brief:           ������� - ������
			*
			* ***************************
			* @description:     �������������� �������� �� ���� � �����
			*/
		void UIButton::setTexture(const std::string& texturePath)
		{
			if (!this->texture.loadFromFile(texturePath)) {
				objectULogManager.addLogMessage(config_logger::text::USER_INTERFACE_BUTTON, "Failed to load texture from path: " + texturePath);
				return;
			}
			this->sprite.setTexture(this->texture);
			this->sprite.setPosition(this->position);
			if (this->texture.getSize().x > 0 && this->texture.getSize().y > 0) {
				this->sprite.setScale(this->size.x / this->texture.getSize().x, this->size.y / this->texture.getSize().y);
			}
		}







		/** ****************************************************
			*
			* @brief:           ������� - ������
			*
			* ***************************
			* @description:     �������������� ������� �������
			*/
		void UIButton::setScale(sf::Vector2f& scale)
		{
			this->sprite.setScale(scale);
		}
	}
}