#pragma once


#pragma comment(lib,"wininet")
#include <windows.h>
#include <wininet.h>
#include <string.h>

class Ftp {
public:
    Ftp(const char* ftpHost, const char* userId, const char* password);
    ~Ftp();
public:
    bool connectToHost(const char* ftpHost, const char* userId, const char* password);
    void close();
    bool cd(const char* dir);
    bool put(const char* filePath, const char* fileName);
    bool deleteFile(const char* fileName);
    bool renameFile(const char* fileOld, const char* fileNew);
    bool get(const char* fileName);

private:
    HINTERNET internet;
    HINTERNET ftpSession;
    char host[256];
};