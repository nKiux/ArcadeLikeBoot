#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <thread>
#include <conio.h>
using namespace std;

int main() {
    cout << "ALB Boot System @Kiux.Lab" << endl;
    cout << " ______     __         ______    " << endl;
    cout << "/\\  __ \\   /\\ \\       /\\  == \\   " << endl;
    cout << "\\ \\  __ \\  \\ \\ \\____  \\ \\  __<   " << endl;
    cout << " \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\ " << endl;
    cout << "  \\/_/\\/_/   \\/_____/   \\/_____/ " << endl;
    cout << "                                 " << endl;
    int freq = 0;
    system("taskkill /f /im explorer.exe");
    DISPLAY_DEVICE displayDevice;
    displayDevice.cb = sizeof(DISPLAY_DEVICE);

    EnumDisplayDevices(nullptr, 0, &displayDevice, 0);

    cout << "Checking Resolution..." << endl;
    cout << "Primary Display Information:" << endl;
    for(int i = 0 ; i < 500; i++)
    {
        DEVMODE devMode;
        devMode.dmSize = sizeof(DEVMODE);
        EnumDisplaySettings(displayDevice.DeviceName, ENUM_CURRENT_SETTINGS, &devMode);
        double Freq = devMode.dmDisplayFrequency;
        freq = devMode.dmDisplayFrequency;
        
        cout << "\rDisp: " << displayDevice.DeviceName;
        cout << " | Graph: " << displayDevice.DeviceString;
        cout << " | Res: " << devMode.dmPelsWidth << "x" << devMode.dmPelsHeight;
        cout << " | Refresh Rate: " << fixed << setprecision(3) << freq << " Hz";
        cout << " | Step " << i << " / 500";
        Sleep(10);
    }
    system("cls");
    cout << "Refresh Rate: " << freq << "Hz" << endl;
    cout << "Check Drive..." << endl;
    cout << " Checking C:" << endl;
    system("chkdsk c:");

    system("cls");

    cout << "Ready To Start" << endl;
    for(int i = 0 ; i < 11; i++)
    {
        cout << "\rPlease Wait " << 10-i << " seconds.";
        Sleep(1000);
    }
    cout << endl;
    system("C:/windows/Explorer.exe");
    return 0;
}