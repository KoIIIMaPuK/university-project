#include "utl_logger.hpp"


namespace ninotchka
{
    namespace logger 
    {
        /** ****************************************************
            *
            * @brief:			дефолтный конструктор класса
            *
            * ***************************
            * @description:	    базовый конструктор класса.
            */
        ULogManager::ULogManager() : objectFileULogManager(config_logger::FILE_TXT_PATH, std::ios::app) {
            if (!objectFileULogManager.is_open()) {
                std::cerr << "[Error] Failed to open file! -> ULogManager class constructor -> DEFAULT" << std::endl;
            }
            else {
                objectFileULogManager << "[Constructor] [" << getCurrentTimeString() << "] ULogManager class constructor created -> DEFAULT" << std::endl;
            }
            objectFileULogManager.close();
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
        ULogManager::ULogManager(std::string name) : objectFileULogManager(config_logger::FILE_TXT_PATH, std::ios::app), nameLog(name) {
            if (!objectFileULogManager.is_open()) {
                std::cerr << "[Error] Failed to open file! -> ULogManager class constructor -> ULogManager(std::string name)" << std::endl;
            }
            else {
                objectFileULogManager << "[Constructor] [" << getCurrentTimeString() << "] ULogManager class constructor created -> ULogManager(std::string name) -> <" << nameLog << ">" << std::endl;
            }
            objectFileULogManager.close();
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
        std::string ULogManager::getCurrentTimeString(const char* format) {
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
        void ULogManager::addLogMessage(std::string nameLog, std::string logMessage) {
            objectFileULogManager.open(config_logger::FILE_TXT_PATH, std::ios::app);

            if (!objectFileULogManager.is_open()) {
                std::cerr << "[Error] Failed to open file! -> ULogManager class function -> addLogMessage(std::string nameLog, std::string logMessage)" << std::endl;
            }
            else {
                objectFileULogManager << "[Log] [" << getCurrentTimeString() << "] " << "<" << nameLog << "> " << logMessage << std::endl;
            }

            objectFileULogManager.close();
        }








        /** ****************************************************
            *
            * @brief:			функция
            *
            * ***************************
            * @description:	    функция нужна для добавления лога из консоли.
            */
        void ULogManager::addLogMessageFromConsole() {
            std::string logMessage;
            std::cout << "[Log]->[CONSOLE]->[MESSAGE]: ";
            std::getline(std::cin, logMessage);

            addLogMessage("CONSOLE", logMessage);
        }








        /** ****************************************************
            *
            * @brief:			деструктор
            *
            * ***************************
            * @description:	    деструктор класса - на всякий случай закрывает рабочий файл.
            */
        ULogManager::~ULogManager() {
            objectFileULogManager.close();
        }
    }
}