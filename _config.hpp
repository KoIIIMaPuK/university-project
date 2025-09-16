#pragma once

// #########################################################
// 
//                  Include SFML libs
// 
// #########################################################
#include <SFML/Graphics.hpp>    // Графика
#include <SFML/Network.hpp>     // Сеть
#include <SFML/System.hpp>      // Системные функции
#include <SFML/Window.hpp>      // Окна и ввод
#include <SFML/Audio.hpp>       // Аудио




// #########################################################
// 
//                  Include C++ libs
// 
// #########################################################
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <chrono>
#include <format>
#include <map>






// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// 
// @brief:			Namespace config window <config_window>
// 
// +-+-+-+-+-+-+-+-+-+-+-+-+-+
// @description:	пространство имен, которое содержит
//					базовые характеристики окна.
// 
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
namespace config_window
{
	/**
	*	@brief Configuration constants for the SFML window
	*/
	constexpr unsigned int WINDOW_WIDTH = 400;		// window width
	constexpr unsigned int WINDOW_HEIGHT = 600;		// window height
	constexpr const char* WINDOW_TITLE = "SFML Project University";	// window title

	/** 
	*	@brief Exit codes for the application.
	*/ 
	namespace application_exit_code {
		constexpr int WINDOW_COMPLETE = 0;	// if programm completed without error(-s)
		constexpr int WINDOW_ERROR = 1;		// if programm completed with error(-s)
	}

	namespace fonts
	{
		constexpr const char* FONT_MONOCRAFT = "UTL-Font/Monocraft.otf";
	}
}






// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// 
// @brief:			Namespace config logger <config_logger>
// 
// +-+-+-+-+-+-+-+-+-+-+-+-+-+
// @description:	пространство имен, которое содержит
//					настройки для работы с логами.
// 
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
namespace config_logger
{
	constexpr const char* FILE_TXT_PATH = "TXT-Files/utl_logger.txt";
	
	/**
	*	@brief:		пространство имен содержащие текст для логгов
	*/
	namespace text
	{
		constexpr const char* USER_INTERFACE_BUTTON = "UIButton";
		constexpr const char* CONSTRUCTOR_DEFAULT_WAS_CREATED = "конструктор был создан - переменные успешно инициализированы";
		constexpr const char* FONT_WAS_NOT_LOADED = "шрифт не был загружен";
	}
}