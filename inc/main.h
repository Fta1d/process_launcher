//
// Created by Mark on 17.02.2022.
//

#ifndef PROCESS_LAUNCHER_MAIN_H
#define PROCESS_LAUNCHER_MAIN_H

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

class Process {
private:
    std::string executable_path;
    std::vector<std::string> cmd_args {"privet"};
public:
    Process() : executable_path("../apps/a.out") {

    }

    std::string &get_path(void) {
        return executable_path;
    }

    std::string &get_args(void) {
        return cmd_args[0];
    }
};


class LauncherViewer {
private:
    std::string log_file_name;

public:
    void startProcess(Process process) {
        STATUS stat = RUNNING;
        int pid = fork();

        if(pid) {
            const char *path = process.get_path().c_str();
            const char *arg = process.get_args().c_str();

            execl(path, arg, (char *)NULL);

            stat = FAIL;
            std::cout << stat << std::endl;
        }

    }
};

#endif //PROCESS_LAUNCHER_MAIN_H


