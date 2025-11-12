#include <iostream>
#include "shared.h"
#include <filesystem>
#include <sstream>
#include <fstream>

using namespace std;

bool isAuthenticated = false;
const char* DATA_DIR = "data";

listFiles();
 readFile(const string& name);
 deleteFile(const string& name);
 searchFiles(const string& key);
fileInfo(const string& name);
uploadFile(const string& name, const string& content);
downloadFile(const string& name);

handleCommand(const std::string& cmd);



string listFiles() {
    stringstream ss;

    for (const auto& entry : filesystem::directory_iterator(DATA_DIR)) {
        ss << entry.path().filename().string() << "\n";
    }
    return ss.str();
}
std::string readFile(const string& filename) {
    ifstream file(DATA_DIR + string("/") + filename);
    if (!file) return "Gabim: Fajlli nuk ekziston.";

    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

string deleteFile(const string& filename) {
    string path = string(DATA_DIR) + "/" + filename;

    if (!std::filesystem::exists(path))
        return "Gabim: Fajlli nuk ekziston.";

    std::filesystem::remove(path);
    return "Fajlli u fshi me sukses.";
}
string searchFiles(const string& keyword) {
    std::stringstream ss;

    for (const auto& entry : filesystem::directory_iterator(DATA_DIR)) {
        std::string name = entry.path().filename().string();
        if (name.find(keyword) != string::npos)
            ss << name << "\n";
    }
    return ss.str();
}
string fileInfo(const string& filename) {
    string path = string(DATA_DIR) + "/" + filename;
    if (filesystem::exists(path))
        return "Gabim:nuk egziston.";

    auto fsize = filesystem::file_size(path);
    auto time = filesystem::last_write_time(path);
    
    stringstream ss;
    ss << "Madhesia:" << fsize << "bytes\n";
    ss << "Modifikuar:" << chrono::duration_cast<chrono:seconds>(
        time.time_since_epoch()).count() << "(epoch seconds)\n";
    return ss.str();
}