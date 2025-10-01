#include "utl_logger.hpp"


namespace ninotchka
{
    namespace logger 
    {
        /** ****************************************************
            *
            * @brief:			��������� ����������� ������
            *
            * ***************************
            * @description:	    ������� ����������� ������.
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
            * @brief:			����������� ������
            *
            * ***************************
            * @description:	    ���������� ������������ ������.
            *                   ���� ����������� ���� ��� ����.
            *
            * [ 1 ] @param:   std::string name  -   ��� ����
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
            * @brief:			�������
            *
            * ***************************
            * @description:	    ������� ����� ��� ���������� ����.
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
            * @brief:			�������
            *
            * ***************************
            * @description:	    ������� ����� ��� ���������� ���� �� �������.
            */
        void ULogManager::addLogMessageFromConsole() {
            std::string logMessage;
            std::cout << "[Log]->[CONSOLE]->[MESSAGE]: ";
            std::getline(std::cin, logMessage);

            addLogMessage("CONSOLE", logMessage);
        }








        /** ****************************************************
            *
            * @brief:			����������
            *
            * ***************************
            * @description:	    ���������� ������ - �� ������ ������ ��������� ������� ����.
            */
        ULogManager::~ULogManager() {
            objectFileULogManager.close();
        }
    }
}