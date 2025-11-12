#pragma once #include <string>
#include <chrono>

extern const std::string ADMIN_SECRET;
extern const char* DATA_DIR;

extern const int PORT;
extern const int TIMEOUT_SECONDS;

#define BUFFER_SIZE 1024

extern bool isAuthenticated;

struct ClientInfo {
    std::string key, ip;
    int port = 0;
    bool isAdmin = false;
    int messagesReceived = 0;
    int totalBytes = 0;
    std::chrono::steady_clock::time_point lastActive;
};