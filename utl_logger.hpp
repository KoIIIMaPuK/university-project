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
	* @description:	    ������� ����������� ������.
	*/
	ULogMaganer();

	/** ****************************************************
	*
	* @brief:			Constructor class -> ULogMaganer(std::string name)
	*
	* ***************************
	* @description:	    ���������� ������������ ������.
	*                   ���� ����������� ���� ��� ����.
	*
	* [ 1 ] @param:   std::string name  -   ��� ����
	*/
	ULogMaganer(std::string name);




	/** ****************************************************
	*
	* @brief:			������� - GetCurrentTimeString(const char* format)
	*
	* ***************************
	* @description:	    ������� ����� ��� ��������� �������� �������.
	*
	* @return:          ���������� ������� �����
	*                   � ����������� �������:
	*
	*                       oss.str();
	*/
	std::string GetCurrentTimeString(const char* format = "%F %T");

	/** ****************************************************
	*
	* @brief:			������� - AddLogMessage(std::string logMessage)
	*
	* ***************************
	* @description:	    ������� ����� ��� ���������� ����.
	*/
	void AddLogMessage(std::string nameLog, std::string logMessage);

	/** ****************************************************
	*
	* @brief:			function
	*
	* ***************************
	* @description:	    ������� ����� ��� ���������� ���� �� �������.
	*/
	void AddLogMessageConsole();




	/** ****************************************************
	*
	* @brief:			destructor
	*
	* ***************************
	* @description:	    ���������� ������ - �� ������ ������ ��������� ������� ����.
	*/
	~ULogMaganer();
};