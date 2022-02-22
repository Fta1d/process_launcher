#ifndef CONFIG_H
#define CONFIG_H
#include <vector>
#include <string>
#include <yaml-cpp/yaml.h>
#include <iostream>

class CmdArgument {
public:
    CmdArgument(){};
    ~CmdArgument(){};

private:
    std::string option_name;

public:
    const std::string& get_option_name() const;
    void set_option_name(const std::string& value);
    friend std::ostream& operator<<(std::ostream& Str, CmdArgument const& v);
};

class StdoutConfig {
public:
    StdoutConfig(){};
    ~StdoutConfig(){};

private:
    std::string file;
    std::string mode;

public:
    const std::string& get_file() const;
    void set_file(const std::string& value);
    const std::string& get_mode() const;
    void set_mode(const std::string& value);
    friend std::ostream& operator<<(std::ostream& Str, StdoutConfig const& v);    
};

class Process {
public:
    Process(){};
    ~Process(){};

private:
    std::string name;
    std::string executable_path;
    StdoutConfig stdout_config;
    std::vector<CmdArgument> cmd_arguments;

public:
    const std::string& get_name() const;
    void set_name(const std::string& value);
    const std::string& get_executable_path() const;
    void set_executable_path(const std::string& value);
    const StdoutConfig& get_stdout_config() const;
    void set_stdout_config(const StdoutConfig& value);
    const std::vector<CmdArgument>& get_cmd_arguments() const;
    void set_cmd_arguments(const std::vector<CmdArgument>& value);
    friend std::ostream& operator<<(std::ostream& Str, Process const& v);    
};

class ConfigFile {
public:
    ConfigFile(){};
    ~ConfigFile(){};

private:
    std::vector<Process> processes;
    YAML::Node config_file; 
    std::string yaml_file_name="config.yaml";

public:
    const std::vector<Process>& get_processes() const;
    void set_processes(const std::vector<Process>& value);
    friend std::ostream& operator<<(std::ostream& Str, ConfigFile const& v);
    
    const Process getOneProcess( int process_id);
    const std::vector <Process> getAllProcesses();
    const std::vector <CmdArgument> getProcessArguments( Process process );
    const StdoutConfig getProcessStdout( Process process);
};
#endif