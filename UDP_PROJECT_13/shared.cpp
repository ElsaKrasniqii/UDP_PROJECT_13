#include <iostream>
#include "shared.h"
#include <filesystem>
#include <sstream>
#include <fstream>

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
std::string readFile(const std::string& filename) {
    std::ifstream file(DATA_DIR + std::string("/") + filename);
    if (!file) return "Gabim: Fajlli nuk ekziston.";

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
std::string deleteFile(const std::string& filename) {
    std::string path = std::string(DATA_DIR) + "/" + filename;

    if (!std::filesystem::exists(path))
        return "Gabim: Fajlli nuk ekziston.";

    std::filesystem::remove(path);
    return "Fajlli u fshi me sukses.";
}
std::string searchFiles(const std::string& keyword) {
    std::stringstream ss;

    for (const auto& entry : std::filesystem::directory_iterator(DATA_DIR)) {
        std::string name = entry.path().filename().string();
        if (name.find(keyword) != std::string::npos)
            ss << name << "\n";
    }
    return ss.str();
}
