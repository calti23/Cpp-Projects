#include <iostream>
#include <string>
#include <chrono>
#include <windows.h>

unsigned long long getDirectorySize(const std::string& path, unsigned long long& fileCount) {
    unsigned long long totalSize = 0;
    std::string searchPath = path + "\\*";
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA(searchPath.c_str(), &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
        return 0;
    }

    do {
        std::string fileName = findData.cFileName;

        if (fileName == "." || fileName == "..") {
            continue;
        }

        std::string fullPath = path + "\\" + fileName;

        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            totalSize += getDirectorySize(fullPath, fileCount);
        } 
        else {
            unsigned long long fileSize = ((unsigned long long)findData.nFileSizeHigh << 32) + findData.nFileSizeLow;
            totalSize += fileSize;
            fileCount++;
        }

    } while (FindNextFileA(hFind, &findData) != 0);

    FindClose(hFind);
    return totalSize;
}

int main() {
    std::string targetPath = "C:\\Users\\Calti23\\Documents";

    unsigned long long fileCount = 0;
    std::cout << "Tarama basladi, lutfen bekleyin...\n";
    
    auto start = std::chrono::high_resolution_clock::now();
    unsigned long long totalSize = getDirectorySize(targetPath, fileCount);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    std::cout << "\n--- Sonuclar ---\n";
    std::cout << "Toplam Boyut: " << (totalSize / (1024 * 1024)) << " MB\n";
    std::cout << "Dosya Sayisi: " << fileCount << "\n";
    std::cout << "Gecen Sure: " << duration.count() << " saniye\n";

    return 0;
}
