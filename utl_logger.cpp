#include "utl_logger.hpp"




/** ****************************************************
*
* @brief:			��������� ����������� ������
*
* ***************************
* @description:	    ������� ����������� ������.
*/
ULogMaganer::ULogMaganer() : objectFileULogMaganer(config_logger::FILE_TXT_PATH, std::ios::app)
{
    if (!objectFileULogMaganer.is_open()) {
        std::cerr << "[Error] ������ �������� �����! -> ULogMaganer class constructor -> DEFAULT" << std::endl;
    }
    else {
        objectFileULogMaganer << "[Constructor] [" << GetCurrentTimeString() << "] ULogMaganer class constructor created -> DEFAULT" << std::endl;
    }
    objectFileULogMaganer.close();
}








/** ****************************************************
*
* @brief:			����������� ������
*
* ***************************
* @description:	    ���������� ������������ ������.
*                   ���� ����������� ���� ��� ����.
* 
* [ 1 ] @param:   std::string name  -   ��� ����
*/
ULogMaganer::ULogMaganer(std::string name) : objectFileULogMaganer(config_logger::FILE_TXT_PATH, std::ios::app), nameLog(name)
{
    if (!objectFileULogMaganer.is_open()) {
        std::cerr << "[Error] ������ �������� �����! -> ULogMaganer class constructor -> ULogMaganer(std::string name)" << std::endl;
    }
    else {
        objectFileULogMaganer << "[Constructor] [" << GetCurrentTimeString() << "] ULogMaganer class constructor created -> ULogMaganer(std::string name) -> <" << nameLog << ">" << std::endl;
    }
    objectFileULogMaganer.close();
}








/** ****************************************************
*
* @brief:			�������
*
* ***************************
* @description:	    ������� ����� ��� ��������� �������� �������.
* 
* @return:          ���������� ������� ����� 
*                   � ����������� �������:
*                   
*                       oss.str();
*/
std::string ULogMaganer::GetCurrentTimeString(const char* format)
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm tm;
#if defined(_WIN32) || defined(_WIN64)
    localtime_s(&tm, &now_c);
#else
    localtime_r(&now_c, &tm);
#endif

    std::ostringstream oss;
    oss << std::put_time(&tm, format);
    return oss.str();
}







/** ****************************************************
*
* @brief:			�������
*
* ***************************
* @description:	    ������� ����� ��� ���������� ����.
*/
void ULogMaganer::AddLogMessage(std::string nameLog, std::string logMessage)
{
    objectFileULogMaganer.open(config_logger::FILE_TXT_PATH, std::ios::app);

    if (!objectFileULogMaganer.is_open()) {
        std::cerr << "[Error] ������ �������� �����! -> ULogMaganer class function -> AddLogMessage(std::string LogMessage)" << std::endl;
    }
    else {
        objectFileULogMaganer << "[Log] [" << GetCurrentTimeString() << "] " << "<" << nameLog << "> " << logMessage << std::endl;
    }

    objectFileULogMaganer.close();
}








/** ****************************************************
*
* @brief:			�������
*
* ***************************
* @description:	    ������� ����� ��� ���������� ���� �� �������.
*/
void ULogMaganer::AddLogMessageConsole()
{
    std::string LogMessage;
    std::cout << "[Log]->[CONSOLE]->[MESSAGE]: ";
    std::getline(std::cin, LogMessage);

    AddLogMessage("CONSOLE", LogMessage);
}







/** ****************************************************
*
* @brief:			����������
*
* ***************************
* @description:	    ���������� ������ - �� ������ ������ ��������� ������� ����.
*/
ULogMaganer::~ULogMaganer()
{
	objectFileULogMaganer.close();
}