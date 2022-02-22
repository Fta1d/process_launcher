
//For compile parser: g++ parser.cpp /usr/local/lib/libyaml-cpp.a -o parser

#include "config.cpp"
using namespace std;

int main()
{  
    ConfigFile config_file;
    config_file = parseYAMLConfig(loadYaml());    
    std::cout << config_file.get_processes()[1] << std::endl; 
    std::cout << config_file.get_processes()[1].get_stdout_config() << std::endl;     
    std::cout<<config_file<<std::endl;
}

