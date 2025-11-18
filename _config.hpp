#pragma once

// #########################################################
// 
//                  Include SFML libs
// 
// #########################################################
#include <SFML/Graphics.hpp>   
#include <SFML/Network.hpp>     
#include <SFML/System.hpp>      
#include <SFML/Window.hpp>     
#include <SFML/Audio.hpp>       




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
#include <ctime>
#include <map>





// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// 
// @brief:			Namespace config window <config_window>
// 
// +-+-+-+-+-+-+-+-+-+-+-+-+-+
// @description:	пространство имен с конфигурацией
//					главного окна
// 
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
namespace config_window
{
	/**
	*	@brief Configuration constants for the SFML window
	*/
	constexpr unsigned int WINDOW_WIDTH = 912;		// window width
	constexpr unsigned int WINDOW_HEIGHT = 480;		// window height
	constexpr const char* WINDOW_TITLE = "Ninotchka Hub";	// window title

	/** 
	*	@brief Exit codes for the application.
	*/ 
	namespace application_exit_code {
		constexpr int WINDOW_COMPLETE = 0;	// if programm completed without error(-s)
		constexpr int WINDOW_ERROR = 1;		// if programm completed with error(-s)
	}

	namespace fonts
	{
		constexpr const char* FONT_MONOCRAFT = "utl-font/Monocraft.otf";
	}
}






// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// 
// @brief:			Namespace config logger <config_logger>
// 
// +-+-+-+-+-+-+-+-+-+-+-+-+-+
// @description:	???????????? ????, ??????? ????????
//					????????? ??? ?????? ? ??????.
// 
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
namespace config_logger
{
	constexpr const char* FILE_TXT_PATH = "txt-files/utl_logger.txt";
	
	/**
	*	@brief:		
	*/
	namespace text
	{
		constexpr const char* USER_INTERFACE_BUTTON = "UIButton";
		constexpr const char* USER_INTERFACE_CALCULATOR = "UICalculator";
		constexpr const char* CONSTRUCTOR_DEFAULT_WAS_CREATED = "дефолтный конструктор класса был создан";
		constexpr const char* FONT_WAS_NOT_LOADED = "шрифт не был загружен";
	}
}






// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// 
// @brief:			Namespace config graphics <config_graphics>
// 
// +-+-+-+-+-+-+-+-+-+-+-+-+-+
// @description:	
// 
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
namespace config_graphics
{
	// PASS
}