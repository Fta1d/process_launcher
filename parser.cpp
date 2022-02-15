//For comptle parser g++ parser.cpp /usr/local/lib/libyaml-cpp.a -o parser
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <yaml-cpp/yaml.h>
#include <fstream>
#include "config.cpp"
using namespace std;
ConfigFile parseYAMLConfig(YAML::Node config){
    std::vector < Process > processes;
    ConfigFile config_file;
    for (std::size_t i=0;i<config["processes"].size();i++) {
        Process process;
        YAML::Node yaml_process = config["processes"][i];
        const std::string name = yaml_process["name"].as<std::string>();
        const std::string executable_path = yaml_process["executable-path"].as<std::string>();
        process.set_name(name);
        process.set_executable_path(executable_path);
       
        StdoutConfig stdout_config;
        const std::string stdout_file = yaml_process["stdout-config"]["file"].as<std::string>();
        const std::string stdout_mode = yaml_process["stdout-config"]["mode"].as<std::string>();
        stdout_config.set_file(stdout_file);
        stdout_config.set_mode(stdout_mode);
        process.set_stdout_config(stdout_config);

        std::vector < CmdArgument > cmd_arguments;
        for (std::size_t i=0;i<yaml_process["cmd-arguments"].size();i++) {
            CmdArgument cmd_argument;
            const std::string arg_option_name= yaml_process["cmd-arguments"][i]["option-name"].as<std::string>();
            cmd_argument.set_option_name(arg_option_name);
            cmd_arguments.push_back(cmd_argument);
        }
        process.set_cmd_arguments(cmd_arguments);
        //std::cout<<process<<std::endl;
        processes.push_back(process);
    }
    config_file.set_processes(processes);
    return config_file;
}
int main() {
    YAML::Node config = YAML::LoadFile("config.yaml");
    
    /*if (config["processes"]) {
        std::cout << "processes:" << config["processes"]<< "\n";
    }*/
    ConfigFile config_file;
    config_file=parseYAMLConfig(config);
    std::cout<<config_file.get_processes()[0].get_cmd_arguments()[0]<<std::endl;
    std::ofstream fout("parsed_config.txt");
    fout << config_file;
}