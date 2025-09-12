#pragma once
#include "cfg_config.hpp"

class ULogMaganer
{
private:
	std::fstream objectFileULogMaganer;
	std::string nameLog;

public:
	/** ****************************************************
	*
	* @brief:			Constructor class -> DEFAULT
	*
	* ***************************
	* @description:	    базовый конструктор класса.
	*/
	ULogMaganer();

	/** ****************************************************
	*
	* @brief:			Constructor class -> ULogMaganer(std::string name)
	*
	* ***************************
	* @description:	    перегразка конструктора класса.
	*                   есть возможность дать имя логу.
	*
	* [ 1 ] @param:   std::string name  -   имя лога
	*/
	ULogMaganer(std::string name);




	/** ****************************************************
	*
	* @brief:			функция - GetCurrentTimeString(const char* format)
	*
	* ***************************
	* @description:	    функция нужна для получения текущего времени.
	*
	* @return:          возвращает текущее время
	*                   в читабельном формате:
	*
	*                       oss.str();
	*/
	std::string GetCurrentTimeString(const char* format = "%F %T");

	/** ****************************************************
	*
	* @brief:			функция - AddLogMessage(std::string logMessage)
	*
	* ***************************
	* @description:	    функция нужна для добавления лога.
	*/
	void AddLogMessage(std::string nameLog, std::string logMessage);

	/** ****************************************************
	*
	* @brief:			function
	*
	* ***************************
	* @description:	    функция нужна для добавления лога из консоли.
	*/
	void AddLogMessageConsole();




	/** ****************************************************
	*
	* @brief:			destructor
	*
	* ***************************
	* @description:	    деструктор класса - на всякий случай закрывает рабочий файл.
	*/
	~ULogMaganer();
};