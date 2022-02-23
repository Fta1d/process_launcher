//
// Created by Mark on 17.02.2022.
//


#include "config.cpp"
#include "main.h"

int main(void) {
    ConfigFile config_file;
    LauncherViewer viewer;
    config_file = parseYAMLConfig(loadYaml());
    viewer.startProcess(config_file);
//    std::cout << config_file.get_processes()[0].get_cmd_arguments()[0] << std::endl;
//    std::cout << config_file.get_processes()[1].get_stdout_config() << std::endl;
//    std::cout<<config_file<<std::endl;
}