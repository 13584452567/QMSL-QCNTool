#include <CLI11.hpp>
#include "QCLoader.h"
#include <iostream>
#include <String>
#include <chrono>
#include <codecvt>
#include <locale>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

void SetLibraryMode()
{
    std::cout << "\nSetting QPST mode...";
    QLIB_SetLibraryMode(0);
    std::cout << " OK";
}

bool ConnectPort(DiagInfo &info)
{
    std::cout << "\nConnecting to phone...";
    info.hndl = QLIB_ConnectServer(info.portnum);
    unsigned int a = QLIB_IsPhoneConnected(info.hndl);
    if (a)
    {
        std::cout << " OK";
        unsigned long _iMSM_HW_Version = 0;
        unsigned long _iMobModel = 0;
        char _sMobSwRev[512];
        char _sModelStr[512];
        unsigned char bOk;
        bOk = QLIB_DIAG_EXT_BUILD_ID_F(info.hndl, &_iMSM_HW_Version, &_iMobModel, _sMobSwRev, _sModelStr);
        if (bOk)
        {
            std::cout << "\nMSM-HW ver : ";
            std::cout << std::to_string(_iMSM_HW_Version) << std::endl;
            std::cout << "\nMobModel : ";
            std::cout << std::to_string(_iMobModel) << std::endl;
            std::cout << "\nSoftware : ";
            std::cout << _sMobSwRev << std::endl;
        }
        return true;
    }
    else
    {
        std::cout << " error";
        std::cout << "\nPlease select a valid diag port!";
        return false;
    }
}
bool SetSIMDual(DiagInfo &info, bool dual)
{
    std::cout << "\nSet Multi Sim...";
    if (dual)
    {
        unsigned char res = QLIB_NV_SetTargetSupportMultiSIM(info.hndl, true);
        if (res)
        {
            std::cout << " 2";
            return true;
        }
        else
        {
            std::cout << " error";
            return false;
        }
    }
    else
    {
        if (QLIB_NV_SetTargetSupportMultiSIM(info.hndl, false))
        {
            std::cout << " 1";
            return true;
        }
        else
        {
            std::cout << " error";
            return false;
        }
    }
}

bool SyncEFS(DiagInfo &info)
{
    std::cout << "\nSyncing EFS...";
    unsigned char b = 0;
    unsigned char b2 = 0;
    b = 47;
    b2 = 4;
    try
    {
        QLIB_EFS2_SyncWithWait(info.hndl, &b, 2000, &b2);
    }
    catch (...)
    {
        std::cout << " error";
        std::cout << "\nCan not sync EFS";
        return false;
    }
    std::cout << " OK";
    return true;
}

bool RebootNormal(DiagInfo &info)
{
    std::cout << "Rebooting phone...";
    QLIB_DIAG_CONTROL_F(info.hndl, MODE_OFFLINE_D_F);
    Sleep(2000);
    QLIB_DIAG_CONTROL_F(info.hndl, MODE_RESET_F);
    std::cout << " OK";
    return true;
}

typedef struct
{
    std::wstring imei;
    std::wstring tac;
    std::wstring fac;
    std::wstring snr;
    std::wstring svn;
    std::wstring luhnCode;
} Imei_Info;

string ReadIMEI(DiagInfo &info, int index)
{
    unsigned char array[128];
    std::wstring array2[15];
    int array3[15];
    unsigned short num1 = 4;
    unsigned char res = QLIB_DIAG_NV_READ_EXT_F(info.hndl, NV_UE_IMEI_I, array, index, 128, &num1);
    if (!res)
        return "000000000000000";
    int num = 0;
    for (int i = 1; i <= 8; i++)
    {
        if (i != 8)
        {
            array3[num] = static_cast<int>(array[i]);
            array3[num] &= 240;
            array3[num] >>= 4;
            array3[num + 1] = static_cast<int>(array[i + 1] & 15);
        }
        else
        {
            array3[num] = static_cast<int>(array[i]);
            array3[num] &= 240;
            array3[num] >>= 4;
        }
        num += 2;
    }
    Imei_Info imeiinfo;
    for (int j = 0; j < 15; j++)
    {
        array2[j] = std::to_wstring(array3[j]);
        if (j < 6)
        {
            imeiinfo.tac += array2[j];
        }
        else if (j >= 6 && j <= 7)
        {
            imeiinfo.fac += array2[j];
        }
        else if (j >= 7 && j <= 13)
        {
            imeiinfo.snr += array2[j];
        }
    }
    imeiinfo.luhnCode = array2[14];
    imeiinfo.imei = imeiinfo.tac + imeiinfo.fac + imeiinfo.snr + imeiinfo.luhnCode;
    if (imeiinfo.imei.size() != 15)
    {
        return "000000000000000";
    }
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    std::string utf8_imei = myconv.to_bytes(imeiinfo.imei);
    return utf8_imei;
}

bool SendSPC(DiagInfo &info, const std::string &SPC)
{
    std::cout << "\nSending SPC...";
    unsigned char piSPC_Result;
    // 将SPC复制到unsigned char数组
    unsigned char test2[6];
    std::memcpy(test2, SPC.c_str(), SPC.size());
    if (QLIB_DIAG_SPC_F(info.hndl, test2, &piSPC_Result))
    {
        std::cout << " OK";
        // 假设ReadIMEI返回std::string类型
        std::string IMEI1 = ReadIMEI(info, 0);
        std::string IMEI2 = ReadIMEI(info, 1);
        std::cout << "\nPhone IMEI1 : ";
        std::cout << IMEI1;
        std::cout << "\nPhone IMEI2 : ";
        std::cout << IMEI2;
        return true;
    }
    else
    {
        std::cout << " error";
    }
    return false;
}

bool ConnectDevice(DiagInfo &info)
{
    SetLibraryMode();
    if (!ConnectPort(info))
    {
        return false;
    }
    if (!SendSPC(info, "000000"))
    {
        return false;
    }

    if (!SetSIMDual(info, !(ReadIMEI(info, 0) == ReadIMEI(info, 1))))
    {
        return false;
    }
    return true;
}

std::string createFilePath(const std::string &current_path)
{
    if (current_path.empty())
    {
        return "";
    }

    time_t time_seconds = time(0);
    struct tm now_time;
    localtime_s(&now_time, &time_seconds);
    std::ostringstream timestamp;
    timestamp << std::put_time(&now_time, "%Y%m%d%H%M%S");
    std::string file_path = current_path + "/" + "QCN_" + timestamp.str() + ".qcn";
    std::replace(file_path.begin(), file_path.end(), ':', '_');
    std::replace(file_path.begin(), file_path.end(), ' ', '_');
    return file_path;
}

int main(int argc, char **argv)
{
    CLI::App app{"QCNTool"};
    app.set_version_flag("--version", "1.5.0", "A tool to download/flash qcn from/to your phone");
    app.set_help_flag("-h,--help", "a tool to download/flash qcn from/to your phone");
    bool writeqcn = false;
    bool readqcn = false;
    int targetport = 0;
    std::string targetpath;
    app.add_flag("--write, -w", writeqcn, "Write qcn to your phone");
    app.add_flag("--read, -r", readqcn, "Backup qcn from your phone");
    app.add_option("--port, -p", targetport, "Set 901D port number")->required();
    app.add_option("--file, -f", targetpath, "QCN file path");
    CLI11_PARSE(app, argc, argv);
    // 创建DiagInfo实例并赋值
    DiagInfo info;
    info.portnum = targetport;
    if (writeqcn == readqcn)
    {
        std::cout << "Invalid function quest";
        return 1;
    }
    std::cout << "a small free tool to flash/backup qcn into/from your phone\n";
    if (!ConnectDevice(info))
    {
        QLIB_DisconnectServer(info.hndl);
        return 1;
    }
    if (writeqcn)
    {
        if (targetpath == "")
        {
            std::cout << "please input file path";
            QLIB_DisconnectServer(info.hndl);
            return 1;
        }
        std::cout << "\nLoading Data File...";
        int get1 = -1;
        int get2 = -1;
        if (!QLIB_NV_LoadNVsFromQCN(info.hndl, targetpath.c_str(), &get1, &get2))
        {
            std::cout << " error";
            QLIB_DisconnectServer(info.hndl);
            return 1;
        }
        else
        {
            std::cout << " OK";
            std::cout << "\nWriting Data File to phone...";
            int res2;
            if (!QLIB_NV_WriteNVsToMobile(info.hndl, &res2))
            {
                std::cout << " error";
                QLIB_DisconnectServer(info.hndl);
                return 1;
            }
            else
            {
                std::cout << " OK";
            }
        }
    }
    if (readqcn)
    {
        if (targetpath.empty())
        {
            targetpath = createFilePath(argv[0]);
        }
        else
        {
            std::cerr << "file path should be null" << std::endl;
            return 1;
        }
        int renas2;
        char *inputpath = const_cast<char *>(targetpath.c_str());
        std::cout << "\nReading QCN from phone...";
        if (!QLIB_BackupNVFromMobileToQCN(info.hndl, inputpath, &renas2))
        {
            std::cout << " error";
            QLIB_DisconnectServer(info.hndl);
            return 1;
        }
        else
        {
            std::cout << " OK";
            std::cout << "\nBackup file : ";
            std::cout << targetpath;
            std::cout << "\n";
        }
    }
    QLIB_DisconnectServer(info.hndl);
    return 0;
}