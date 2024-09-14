#include "头文件/智能小车.hpp"
#include <iostream>
#include <vector>

std::vector<智能小车> 车库;

int main(){
    // Main函数中实现小车信息录入、分配、保存和屏幕显示
    // 小车各模块的保存和显示分别通过相应对象的操作完成
    while(true){
        system("clear");
        std::cout << "1. 读取 🚗 信息从文件" << std::endl;
        std::cout << "2. 保存 🚕 信息到文件" << std::endl;
        std::cout << "3. 查看 🚙 信息" << std::endl;
        std::cout << "4. 新建一辆 🚎" << std::endl;
        std::cout << "5. 编辑一辆 🚛" << std::endl;
        std::cout << "\n输入你的选择: ";
        std::string 选择; std::cin >> 选择;
        system("clear");

        switch (stoi(选择)){
            case 1:{
                std::cout << "输入 🚗 文件路劲:";
                std::string 文件路径; std::cin >> 文件路径;
                std::ifstream ifs(文件路径);
                if(ifs.is_open()){
                    while(!ifs.eof()){
                        智能小车 小车("NULL", "NULL", "NULL", "NULL");
                        小车.文件读到内存(ifs);
                        
                        if(小车.获取智能小车编号() != "NULL"){
                            车库.push_back(小车);
                        }else{
                            break;
                        }
                    }
                    ifs.close();
                } else {
                    std::cout << "文件打开失败" << std::endl;
                }
                break;
            }
            case 2:{
                std::cout << "输入 🚕 文件路劲:";
                std::string 文件路径; std::cin >> 文件路径;
                std::ofstream ofs(文件路径);
                if(ofs.is_open()){
                    for(int i = 0; i < 车库.size(); i++){
                        车库[i].内存写到文件(ofs);
                    }
                    ofs.close();
                } else {
                    std::cout << "文件打开失败" << std::endl;
                }
                break;
            }
            case 3:{
                for(int i = 0; i<车库.size();){
                    车库[i].打印设备信息();

                    std::cout << "\n上一辆车[p] | 下一辆车[n]: ";
                    char 操作; std::cin >> 操作;
                    
                    if(操作 == 'p'){
                        if(i == 0){
                            system("clear");
                            std::cout << "提示：按 p 无效\n" << std::endl;
                        }else{
                            system("clear");
                            i--;
                        }
                    }else if(操作 == 'n'){
                        if(i == 车库.size() - 1){
                            system("clear");
                            std::cout << "提示：按 n 无效\n" << std::endl;
                        }else{
                            system("clear");
                            i++;
                        }
                    }else{
                        break;
                    }
                }
                break;
            }
            case 4:{
                std::string 车辆编号, 底盘编号, 学号, 姓名;
                std::cout << "(1/4)输入 🚎 编号: "; std::cin >> 车辆编号;
                std::cout << "(2/4)输入 🚎 底盘编号: "; std::cin >> 底盘编号;
                std::cout << "(3/4)输入 🚎 所属学生学号: "; std::cin >> 学号;
                std::cout << "(4/4)输入 🚎 所属学生姓名: "; std::cin >> 姓名;
                车库.push_back(智能小车(车辆编号, 底盘编号, 学号, 姓名));
                break;
            }
            case 5:{
                std::string 车辆编号;
                std::cout << "输入 🚛 编号以进入修改: "; std::cin >> 车辆编号;
                for(int i = 0; i < 车库.size(); i++)
                    while(车库[i].获取智能小车编号() == 车辆编号){
                        system("clear");
                        车库[i].打印设备信息();

                        std::cout << "\n 1. 修改 🚎 编号" << std::endl;
                        std::cout << " 2. 修改 🛠️ 底盘编号" << std::endl;
                        std::cout << " 3. 修改 🛠️ 底盘型号" << std::endl;
                        std::cout << " 4. 修改 🛠️ 底盘轴距" << std::endl;
                        std::cout << " 5. 修改 🛠️ 底盘轮距" << std::endl;
                        std::cout << " 6. 修改 🛠️ 底盘最小离地间隙" << std::endl;
                        std::cout << " 7. 修改 🛠️ 底盘最小转弯半径" << std::endl;
                        std::cout << " 8. 修改 🛠️ 底盘驱动形式" << std::endl;
                        std::cout << " 9. 修改 🛠️ 底盘最大行程" << std::endl;
                        std::cout << "10. 修改 🛞 轮胎型号" << std::endl;
                        std::cout << "11. 修改 🛞 轮胎尺寸" << std::endl;
                        std::cout << "12. 修改 ⏳ 九轴陀螺仪型号" << std::endl;
                        std::cout << "13. 修改 ⏳ 九轴陀螺仪厂家" << std::endl;
                        std::cout << "14. 修改 🖥️ 液晶显示屏型号" << std::endl;
                        std::cout << "15. 修改 🖥️ 液晶显示屏尺寸" << std::endl;
                        std::cout << "16. 修改 🤓 AGX套件型号" << std::endl;
                        std::cout << "17. 修改 🤓 AGX套件AI" << std::endl;
                        std::cout << "18. 修改 🤓 AGX套件CUDA核心" << std::endl;
                        std::cout << "19. 修改 🤓 AGX套件TensorCORE" << std::endl;
                        std::cout << "20. 修改 🤓 AGX套件显存" << std::endl;
                        std::cout << "21. 修改 🤓 AGX套件存储" << std::endl;
                        std::cout << "22. 修改 🔋 电池模块参数" << std::endl;
                        std::cout << "23. 修改 🔋 电池模块对外供电" << std::endl;
                        std::cout << "24. 修改 🔋 电池模块充电时长" << std::endl;
                        std::cout << "25. 修改 🔭 双目摄像头型号" << std::endl;
                        std::cout << "26. 修改 🔭 双目摄像头摄像头" << std::endl;
                        std::cout << "27. 修改 🔭 双目摄像头RGB帧分辨率" << std::endl;
                        std::cout << "28. 修改 🔭 双目摄像头RGB帧率" << std::endl;
                        std::cout << "29. 修改 🔭 双目摄像头FOV" << std::endl;
                        std::cout << "30. 修改 🔭 双目摄像头深度帧率" << std::endl;
                        std::cout << "31. 修改 🏔️ 多线激光雷达型号" << std::endl;
                        std::cout << "32. 修改 🏔️ 多线激光雷达通道数" << std::endl;
                        std::cout << "33. 修改 🏔️ 多线激光雷达测试范围" << std::endl;
                        std::cout << "34. 修改 🏔️ 多线激光雷达功耗" << std::endl;
                        std::cout << "35. 修改 😗 学生姓名" << std::endl;
                        std::cout << "36. 修改 😗 学生学号" << std::endl;

                        std::cout << "\n输入你的选择: ";
                        std::string 选择; std::cin >> 选择;
                        if(!(stoi(选择) >= 1 && stoi(选择) <= 36)) break;
                        
                        switch(stoi(选择)){
                            case 1:{
                                std::string 编号;
                                std::cout << "输入 🚎 编号: "; std::cin >> 编号;
                                车库[i].设置智能小车编号(编号);
                                break;
                            }
                            case 2:{
                                std::string 编号;
                                std::cout << "输入 🛠️ 底盘编号: "; std::cin >> 编号;
                                车库[i].设置底盘编号(编号);
                                break;
                            }
                            case 3:{
                                std::string 型号;
                                std::cout << "输入 🛠️ 底盘型号: "; std::cin >> 型号;
                                车库[i].设置底盘型号(型号);
                                break;
                            }
                            case 4:{
                                std::string 轴距;
                                std::cout << "输入 🛠️ 底盘轴距: "; std::cin >> 轴距;
                                车库[i].设置底盘轴距(轴距);
                                break;
                            }
                            case 5:{
                                std::string 轮距;
                                std::cout << "输入 🛠️ 底盘轮距: "; std::cin >> 轮距;
                                车库[i].设置底盘轮距(轮距);
                                break;
                            }
                            case 6:{
                                std::string 最小离地间隙;
                                std::cout << "输入 🛠️ 底盘最小离地间隙: "; std::cin >> 最小离地间隙;
                                车库[i].设置底盘最小离地间隙(最小离地间隙);
                                break;
                            }
                            case 7:{
                                std::string 最小转弯半径;
                                std::cout << "输入 🛠️ 底盘最小转弯半径: "; std::cin >> 最小转弯半径;
                                车库[i].设置底盘最小转弯半径(最小转弯半径);
                                break;
                            }
                            case 8:{
                                std::string 驱动形式;
                                std::cout << "输入 🛠️ 底盘驱动形式: "; std::cin >> 驱动形式;
                                车库[i].设置底盘驱动形式(驱动形式);
                                break;
                            }
                            case 9:{
                                std::string 最大行程;
                                std::cout << "输入 🛠️ 底盘最大行程: "; std::cin >> 最大行程;
                                车库[i].设置底盘最大行程(最大行程);
                                break;
                            }
                            case 10:{
                                std::string 型号;
                                std::cout << "输入 🛞 轮胎型号: "; std::cin >> 型号;
                                车库[i].设置轮胎型号(型号);
                                break;
                            }
                            case 11:{
                                std::string 尺寸;
                                std::cout << "输入 🛞 轮胎尺寸: "; std::cin >> 尺寸;
                                车库[i].设置轮胎尺寸(尺寸);
                                break;
                            }
                            case 12:{
                                std::string 型号;
                                std::cout << "输入 ⏳ 九轴陀螺仪型号: "; std::cin >> 型号;
                                车库[i].设置九轴陀螺仪型号(型号);
                                break;
                            }
                            case 13:{
                                std::string 厂家;
                                std::cout << "输入 ⏳ 九轴陀螺仪厂家: "; std::cin >> 厂家;
                                车库[i].设置九轴陀螺仪厂家(厂家);
                                break;
                            }
                            case 14:{
                                std::string 型号;
                                std::cout << "输入 🖥️ 液晶显示屏型号: "; std::cin >> 型号;
                                车库[i].设置液晶显示屏型号(型号);
                                break;
                            }
                            case 15:{
                                std::string 尺寸;
                                std::cout << "输入 🖥️ 液晶显示屏尺寸: "; std::cin >> 尺寸;
                                车库[i].设置液晶显示屏尺寸(尺寸);
                                break;
                            }
                            case 16:{
                                std::string 型号;
                                std::cout << "输入 🤓 AGX套件型号: "; std::cin >> 型号;
                                车库[i].设置AGX套件型号(型号);
                                break;
                            }
                            case 17:{
                                std::string AI;
                                std::cout << "输入 🤓 AGX套件AI: "; std::cin >> AI;
                                车库[i].设置AGX套件AI(AI);
                                break;
                            }
                            case 18:{
                                std::string CUDA核心;
                                std::cout << "输入 🤓 AGX套件CUDA核心: "; std::cin >> CUDA核心;
                                车库[i].设置AGX套件CUDA核心(CUDA核心);
                                break;
                            }
                            case 19:{
                                std::string TensorCORE;
                                std::cout << "输入 🤓 AGX套件TensorCORE: "; std::cin >> TensorCORE;
                                车库[i].设置AGX套件TensorCORE(TensorCORE);
                                break;
                            }
                            case 20:{
                                std::string 显存;
                                std::cout << "输入 🤓 AGX套件显存: "; std::cin >> 显存;
                                车库[i].设置AGX套件显存(显存);
                                break;
                            }
                            case 21:{
                                std::string 存储;
                                std::cout << "输入 🤓 AGX套件存储: "; std::cin >> 存储;
                                车库[i].设置AGX套件存储(存储);
                                break;
                            }
                            case 22:{
                                std::string 参数;
                                std::cout << "输入 🔋 电池模块参数: "; std::cin >> 参数;
                                车库[i].设置电池模块参数(参数);
                                break;
                            }
                            case 23:{
                                std::string 对外供电;
                                std::cout << "输入 🔋 电池模块对外供电: "; std::cin >> 对外供电;
                                车库[i].设置电池模块对外供电(对外供电);
                                break;
                            }
                            case 24:{
                                std::string 充电时长;
                                std::cout << "输入 🔋 电池模块充电时长: "; std::cin >> 充电时长;
                                车库[i].设置电池模块充电时长(充电时长);
                                break;
                            }
                            case 25:{
                                std::string 型号;
                                std::cout << "输入 🔭 双目摄像头型号: "; std::cin >> 型号;
                                车库[i].设置双目摄像头型号(型号);
                                break;
                            }
                            case 26:{
                                std::string 摄像头;
                                std::cout << "输入 🔭 双目摄像头摄像头: "; std::cin >> 摄像头;
                                车库[i].设置双目摄像头摄像头(摄像头);
                                break;
                            }
                            case 27:{
                                std::string RGB帧分辨率;
                                std::cout << "输入 🔭 双目摄像头RGB帧分辨率: "; std::cin >> RGB帧分辨率;
                                车库[i].设置双目摄像头RGB帧分辨率(RGB帧分辨率);
                                break;
                            }
                            case 28:{
                                std::string RGB帧率;
                                std::cout << "输入 🔭 双目摄像头RGB帧率: "; std::cin >> RGB帧率;
                                车库[i].设置双目摄像头RGB帧率(RGB帧率);
                                break;
                            }
                            case 29:{
                                std::string FOV;
                                std::cout << "输入 🔭 双目摄像头FOV: "; std::cin >> FOV;
                                车库[i].设置双目摄像头FOV(FOV);
                                break;
                            }
                            case 30:{
                                std::string 深度帧率;
                                std::cout << "输入 🔭 双目摄像头深度帧率: "; std::cin >> 深度帧率;
                                车库[i].设置双目摄像头深度帧率(深度帧率);
                                break;
                            }
                            case 31:{
                                std::string 型号;
                                std::cout << "输入 🏔️ 多线激光雷达型号: "; std::cin >> 型号;
                                车库[i].设置多线激光雷达型号(型号);
                                break;
                            }
                            case 32:{
                                std::string 通道数;
                                std::cout << "输入 🏔️ 多线激光雷达通道数: "; std::cin >> 通道数;
                                车库[i].设置多线激光雷达通道数(通道数);
                                break;
                            }
                            case 33:{
                                std::string 测试范围;
                                std::cout << "输入 🏔️ 多线激光雷达测试范围: "; std::cin >> 测试范围;
                                车库[i].设置多线激光雷达测试范围(测试范围);
                                break;
                            }
                            case 34:{
                                std::string 功耗;
                                std::cout << "输入 🏔️ 多线激光雷达功耗: "; std::cin >> 功耗;
                                车库[i].设置多线激光雷达功耗(功耗);
                                break;
                            }
                            case 35:{
                                std::string 姓名;
                                std::cout << "输入 😗 学生姓名: "; std::cin >> 姓名;
                                车库[i].设置学生姓名(姓名);
                                break;
                            }
                            case 36:{
                                std::string 学号;
                                std::cout << "输入 😗 学生学号: "; std::cin >> 学号;
                                车库[i].设置学生学号(学号);
                                break;
                            }
                            default:{
                                break;
                            }
                        }
                    }
                break;
            }
            default:{
                std::cout << "嘻嘻 🛫 拜拜" << std::endl;
                return 0;
            }
        }

    }
    return 0;
}