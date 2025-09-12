#include "utl_logger.hpp"




/** ****************************************************
*
* @brief:			дефолтный конструктор класса
*
* ***************************
* @description:	    базовый конструктор класса.
*/
ULogMaganer::ULogMaganer() : objectFileULogMaganer(config_logger::FILE_TXT_PATH, std::ios::app)
{
    if (!objectFileULogMaganer.is_open()) {
        std::cerr << "[Error] Ошибка открытия файла! -> ULogMaganer class constructor -> DEFAULT" << std::endl;
    }
    else {
        objectFileULogMaganer << "[Constructor] [" << GetCurrentTimeString() << "] ULogMaganer class constructor created -> DEFAULT" << std::endl;
    }
    objectFileULogMaganer.close();
}








/** ****************************************************
*
* @brief:			конструктор класса
*
* ***************************
* @description:	    перегразка конструктора класса.
*                   есть возможность дать имя логу.
* 
* [ 1 ] @param:   std::string name  -   имя лога
*/
ULogMaganer::ULogMaganer(std::string name) : objectFileULogMaganer(config_logger::FILE_TXT_PATH, std::ios::app), nameLog(name)
{
    if (!objectFileULogMaganer.is_open()) {
        std::cerr << "[Error] Ошибка открытия файла! -> ULogMaganer class constructor -> ULogMaganer(std::string name)" << std::endl;
    }
    else {
        objectFileULogMaganer << "[Constructor] [" << GetCurrentTimeString() << "] ULogMaganer class constructor created -> ULogMaganer(std::string name) -> <" << nameLog << ">" << std::endl;
    }
    objectFileULogMaganer.close();
}








/** ****************************************************
*
* @brief:			функция
*
* ***************************
* @description:	    функция нужна для получения текущего времени.
* 
* @return:          возвращает текущее время 
*                   в читабельном формате:
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
* @brief:			функция
*
* ***************************
* @description:	    функция нужна для добавления лога.
*/
void ULogMaganer::AddLogMessage(std::string nameLog, std::string logMessage)
{
    objectFileULogMaganer.open(config_logger::FILE_TXT_PATH, std::ios::app);

    if (!objectFileULogMaganer.is_open()) {
        std::cerr << "[Error] Ошибка открытия файла! -> ULogMaganer class function -> AddLogMessage(std::string LogMessage)" << std::endl;
    }
    else {
        objectFileULogMaganer << "[Log] [" << GetCurrentTimeString() << "] " << "<" << nameLog << "> " << logMessage << std::endl;
    }

    objectFileULogMaganer.close();
}








/** ****************************************************
*
* @brief:			функция
*
* ***************************
* @description:	    функция нужна для добавления лога из консоли.
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
* @brief:			деструктор
*
* ***************************
* @description:	    деструктор класса - на всякий случай закрывает рабочий файл.
*/
ULogMaganer::~ULogMaganer()
{
	objectFileULogMaganer.close();
}