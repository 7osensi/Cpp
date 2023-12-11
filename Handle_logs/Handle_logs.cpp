#include<iostream>
#include <vector>
#include <string>

using namespace std;

enum class LogLevel { 
    INFO,
    WARNING,
    ERROR
};

class LOG {
    private:
        std::vector<std::pair<LogLevel, std::string>> logBuffer;
    public:
        void Log(LogLevel level, const std::string& message) {
            logBuffer.push_back(std::make_pair(level, message));
        }
        
        void Dump(void) {
            for (const auto& entry : logBuffer) {
            std::string levelStr;
            switch (entry.first) {
                case LogLevel::INFO:
                    levelStr = "INFO";
                    break;
                case LogLevel::WARNING:
                    levelStr = "WARNING";
                    break;
                case LogLevel::ERROR:
                    levelStr = "ERROR";
                    break;
            }
            std::cout << "[" << levelStr << "] " << entry.second << std::endl;
            }
        }

        void Clear(void) {
            logBuffer.clear();
        }
};

int main() {
    LOG logger;

    logger.Log(LogLevel::INFO, "Info");
    logger.Log(LogLevel::WARNING, "Warning");
    logger.Log(LogLevel::ERROR, "Error");

    logger.Dump();
    logger.Clear();

    return 0;
}