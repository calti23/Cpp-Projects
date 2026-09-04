#include <iostream>
#include <windows.h>

void printMemoryUsage() {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);

    if (GlobalMemoryStatusEx(&statex)) {
        unsigned long long totalMemory = statex.ullTotalPhys / (1024 * 1024);
        unsigned long long availMemory = statex.ullAvailPhys / (1024 * 1024);
        unsigned long long usedMemory = totalMemory - availMemory;

        std::cout << "--- Sistem Bellek Durumu (Windows) ---\n";
        std::cout << "Toplam RAM: " << totalMemory << " MB\n";
        std::cout << "Kullanilan RAM: " << usedMemory << " MB\n";
        std::cout << "Bosta RAM: " << availMemory << " MB\n";
        std::cout << "Kullanim Orani: " << statex.dwMemoryLoad << " %\n";
    } else {
        std::cerr << "Bellek bilgisi alinamadi!\n";
    }
}

int main() {
    printMemoryUsage();
    return 0;
}
