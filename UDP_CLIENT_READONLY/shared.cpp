#include <iostream>
#include "shared.h"
#include <filesystem>
#include <sstream>

bool isAuthenticated = false;
const char* DATA_DIR = "data";

std::string listFiles();
std::string readFile(const std::string& name);
std::string deleteFile(const std::string& name);
std::string searchFiles(const std::string& key);
std::string fileInfo(const std::string& name);
std::string uploadFile(const std::string& name, const std::string& content);
std::string downloadFile(const std::string& name);

std::string handleCommand(const std::string& cmd);



std::string listFiles() {
    std::stringstream ss;

    for (const auto& entry : std::filesystem::directory_iterator(DATA_DIR)) {
        ss << entry.path().filename().string() << "\n";
    }
    return ss.str();
}
