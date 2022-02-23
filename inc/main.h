//
// Created by Mark on 17.02.2022.
//

#ifndef PROCESS_LAUNCHER_MAIN_H
#define PROCESS_LAUNCHER_MAIN_H

#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>

enum STATUS {
    RUNNING = 0,
    STOPPED,
    FAIL
};

class LauncherViewer {
private:
    std::string log_file_name;

public:
    void startProcess(ConfigFile cfg) {
        STATUS stat = RUNNING;
        int pid = fork();

        if(pid) {
            std::string path = cfg.get_processes()[0].get_executable_path();
            std::string arg = cfg.get_processes()[0].get_cmd_arguments()[0].get_option_name();


            execl(path.c_str(), arg.c_str(), (char *)NULL);

            stat = FAIL;
            std::cout << stat << std::endl;
        }

    }
};

#endif //PROCESS_LAUNCHER_MAIN_H


